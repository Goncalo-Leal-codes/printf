/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:22:50 by gleal             #+#    #+#             */
/*   Updated: 2021/02/20 19:48:54 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int	ft_print_arg(const char *input, va_list args, int *count)
{
	char *var_to_print;

	while()
	return (end);
}
*/
int	valid_conv(const char *input, t_vars var)
{
	var.i++;
	while (contains(input[var.i], "-0") && input[var.i])
		var.i++;
	if (input[var.i] == '*')
		var.i++;
	else if (contains(input[var.i], "0123456789")&& input[var.i])
	{
		while (contains(input[var.i], "0123456789"))
			var.i++;
	}
	if (input[var.i] == '.')
	{
		var.i++;
		if (input[var.i] == '*')
			var.i++;
		else if (contains(input[var.i], "0123456789"))
		{
			while (contains(input[var.i], "0123456789"))
				var.i++;
		}
	}
	if (contains(input[var.i], "cspdiuxX%"))
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
			if(!valid_conv(input, var));
				return (-1);
			get_conv_info();
			/*input += ft_print_arg(&input[i], args, &var);*/
		}
		/*var.count += ft_putchar(input[i]);*/
		var.i++;
    }
    /*va_end(args);*/
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
