/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:26:12 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 15:53:43 by gleal            ###   ########.fr       */
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
	if (input[var->i] == 'c')
	{
		if (var->justif_left)
		{
			ft_putstr_pf(var->var_str, var);
			
		}
		else
			ft_putstr_pf(var->var_str, var);
	}
	if (var->var_str)
		free(var->var_str);
}
