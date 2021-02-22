/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:58:21 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 20:52:53 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(t_vars *var)
{
/* continuar aqui */
}

void	ft_print_c(t_vars *var)
{
	if (var->justif_left)
	{
		ft_putstr_pf(var->var_str, var);
		if (var->min_width > ft_strlen (var->var_str))
		{
			while (var->min_width - ft_strlen(var->var_str))
			{
				ft_putchar_pf(' ', var);
				var->min_width--;
			}
		}
	}
	else
	{
		if (var->min_width > ft_strlen (var->var_str))
		{
			while (var->min_width - ft_strlen(var->var_str))
			{
				ft_putchar_pf(' ', var);
				var->min_width--;
			}
		}
		ft_putstr_pf(var->var_str, var);
	}
	if (var->var_str)
		free(var->var_str);
}
