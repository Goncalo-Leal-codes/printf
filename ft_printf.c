/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:22:50 by gleal             #+#    #+#             */
/*   Updated: 2021/02/24 12:15:48 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_info(va_list args, const char *input, t_vars *var)
{
	restart_fids(var);
	get_flag_info(input, var);
	get_min_width_info(args, input, var);
	get_precision_info(args, input, var);
	get_str(args, input, var);
	if (var->error)
		return ;
}

int		valid_conv(const char *input, t_vars var)
{
	while (ft_strchr(FLAGS, input[var.i])  && input[var.i])
		var.i++;
	if (input[var.i] == '*')
		var.i++;
	else if (ft_strchr(NBRS, input[var.i]) && input[var.i])
	{
		while (ft_strchr(NBRS, input[var.i]) && input[var.i])
			var.i++;
	}
	if (input[var.i] == '.')
	{
		var.i++;
		if (input[var.i] == '*')
			var.i++;
		else if (ft_strchr(NBRS,input[var.i]))
		{
			while (ft_strchr(NBRS, input[var.i]))
				var.i++;
		}
	}
	if (ft_strchr(CONVS, input[var.i]))
		return (1);
	else
		return (0);
}

int		ft_printf(const char *input, ...)
{
	t_vars	var;
    va_list	args;

	if (!input)
		return (0);
	va_start(args, input);
    start_list(&var);
    while (input[var.i]) 
	{
		if (input[var.i] == '%')
		{
			var.i++;
			if(!valid_conv(input, var))
				return (-1);
			get_info(args, input, &var);
			if (var.error)
				return (-1);
			print_info(input, &var);
		}
		else
			ft_putchar_pf(input[var.i], &var);
		var.i++;
    }
    va_end(args);
	return (var.count);
}
/*       if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
*/
