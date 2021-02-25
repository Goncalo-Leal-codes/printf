/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:23:32 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 17:49:48 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	restart_fids(t_vars *var)
{
	var->justif_left = 0;
	var->zero_pad = 0;
	var->min_width = 0;
	var->prec = 0;
	var->precision_check = 0;
	var->var_str = 0;
}

void	start_list(t_vars *var)
{
	var->i = 0;
	var->count = 0;
	var->error = 0;
	var->justif_left = 0;
	var->zero_pad = 0;
	var->min_width = 0;
	var->prec = 0;
	var->precision_check = 0;
	var->var_str = 0;
}

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
	input[var->i] == 's' ? ft_print_spd(var) : 0;
	input[var->i] == 'p' ? ft_print_spd(var) : 0;
	input[var->i] == 'd' ? ft_print_spd(var) : 0;
	input[var->i] == 'i' ? ft_print_spd(var) : 0;
	input[var->i] == 'u' ? ft_print_spd(var) : 0;
	input[var->i] == 'x' ? ft_print_spd(var) : 0;
	input[var->i] == 'X' ? ft_print_spd(var) : 0;
	input[var->i] == '%' ? ft_print_pct(var) : 0;
}
