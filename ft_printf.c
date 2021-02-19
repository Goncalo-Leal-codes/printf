/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:22:50 by gleal             #+#    #+#             */
/*   Updated: 2021/02/19 21:27:33 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(const char *input, va_list args, int *count)
{
	char *var_to_print;

	return (end);
}

int		ft_printf(const char *input, ...)
{
	t_vars	var;
    va_list	args;
	int	i;

    va_start(args, fmt);
    while (*input) 
	{
		if (*input == '%')
		{
			check_valid(&input[i], args, var)
			input += ft_print_arg(&input[i], args, var);
		}
		var.count += ft_putchar(input[i]);
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
