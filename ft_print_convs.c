/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:58:21 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 15:52:35 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spd(t_vars *var)
{
	if (var->justif_left)
	{
		if (var->var_str)
			ft_putstr_pf(var->var_str, var);
		if (var->min_width > var->prec)
		{
			while (var->min_width - var->prec)
			{
				ft_putchar_pf(' ', var);
				var->min_width--;
			}
		}
	}
	else
	{
		if (var->min_width > var->prec)
		{
			while (var->min_width - var->prec)
			{
				ft_putchar_pf(' ', var);
				var->min_width--;
			}
		}
		if (var->var_str)
		ft_putstr_pf(var->var_str, var);
	}
	if (var->var_str)
		free(var->var_str);
}

void	ft_print_c(t_vars *var)
{
	if (var->justif_left)
	{
		ft_putchar_pf(var->var_str[0], var);
		if (var->min_width > 1)
		{
			while (var->min_width - 1)
			{
				ft_putchar_pf(' ', var);
				var->min_width--;
			}
		}
	}
	else
	{
		if (var->min_width > 1)
		{
			while (var->min_width - 1)
			{
				ft_putchar_pf(' ', var);
				var->min_width--;
			}
		}
		ft_putchar_pf(var->var_str[0], var);
	}
	if (var->var_str)
		free(var->var_str);
}
