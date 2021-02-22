/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:23:32 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 20:52:51 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, t_vars *var)
{
	write(1, &c, 1);
	var->count++;
}

void	ft_putstr_pf(char *str, t_vars *var)
{
	while (*str)
	{
		ft_putchar_pf(*str, var);
		str++;
	}
}

void	print_info(const char *input, t_vars *var)
{
	input[var->i] == 'c' ? ft_print_c(var) : 0;
	input[var->i] == 's' ? ft_print_s(var) : 0;
}
