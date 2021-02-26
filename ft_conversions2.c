/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:49:56 by gleal             #+#    #+#             */
/*   Updated: 2021/02/26 16:09:22 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_pct(t_vars *var)
{
	var->var_str = (char *)malloc(sizeof(char) * 2);
	if (!var->var_str)
	{
		var->error++;
		return ;
	}
	var->var_str[0] = '%';
	var->var_str[1] = '\0';
}

void	ft_conv_ux(va_list args, t_vars *var)
{
	unsigned int	n;
	char			*temp;

	n = va_arg(args, unsigned int);
	if ((var->prec > 0 || !var->precision_check) || n)
	{
		temp = ft_xtoa(n, var, "0123456789ABCDEF");
		if (!temp)
		{
			var->error++;
			return ;
		}
		ft_minus_zeropad(var, temp);
		if (var->error)
			return ;
	}
}

void	ft_conv_x(va_list args, t_vars *var)
{
	unsigned int	n;
	char			*temp;

	n = va_arg(args, unsigned int);
	if ((var->prec > 0 || !var->precision_check) || n)
	{
		temp = ft_xtoa(n, var, "0123456789abcdef");
		if (!temp)
		{
			var->error++;
			return ;
		}
		ft_minus_zeropad(var, temp);
		if (var->error)
			return ;
	}
}
