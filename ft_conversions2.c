/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:49:56 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 18:00:43 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_pct(t_vars *var)
{
	var->var_str  = (char *)malloc(sizeof(char) * 2);
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
	unsigned int		n;
	char	*temp;
	
	temp = 0;
	n = va_arg(args, unsigned int);
	if ((var->prec > 0 || !var->precision_check) || n)
	{
		temp = ft_xtoa(n, var, "0123456789ABCDEF");
		if (!temp)
		{
			var->error++;
			return ;
		}
	if (ft_strlen(temp) > var->prec)
		var->prec = ft_strlen(temp);
	if ((var->zero_pad && !var->justif_left) || var->precision_check)
	{
		if (var->zero_pad && !var->justif_left && !var->precision_check)
			var->prec = var->min_width;
		if (var->prec > ft_strlen(temp))
			ft_add_zeros(temp, var);
		else
			var->var_str = temp;
		if (!var->var_str)
		{
			var->error++;
			return ;
		}
	}
	else
		var->var_str = temp;
	}
}

void	ft_conv_x(va_list args, t_vars *var)
{
	unsigned int		n;
	char	*temp;
	
	temp = 0;
	n = va_arg(args, unsigned int);
	if ((var->prec > 0 || !var->precision_check) || n)
	{
		temp = ft_xtoa(n, var, "0123456789abcdef");
		if (!temp)
		{
			var->error++;
			return ;
		}
	if (ft_strlen(temp) > var->prec)
		var->prec = ft_strlen(temp);
	if ((var->zero_pad && !var->justif_left) || var->precision_check)
	{
		if (var->zero_pad && !var->justif_left && !var->precision_check)
			var->prec = var->min_width;
		if (var->prec > ft_strlen(temp))
			ft_add_zeros(temp, var);
		else
			var->var_str = temp;
		if (!var->var_str)
		{
			var->error++;
			return ;
		}
	}
	else
		var->var_str = temp;
	}
}
