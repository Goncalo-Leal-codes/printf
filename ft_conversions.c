/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:58 by gleal             #+#    #+#             */
/*   Updated: 2021/02/24 21:27:14 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_d(va_list args, t_vars *var)
{
	int		n;
	char	*temp;
	n = va_arg(args, int);
	temp = ft_itoa(n);
	if (!temp)
	{
		var->error++;
		return ;
	}
	if (ft_strlen(var->var_str) > var->precision)
		var->precision = ft_strlen(var->var_str);
	if ((var->zero_pad && !var->justif_left) || var->precision_check)
	{
		if (var->zero_pad && !var->justif_left && !var->precision_check)
			var->precision = var->min_width;
		if (var->precision > ft_strlen(temp))
			ft_add_zeros(temp, var);
		if (!var->var_str)
		{
			var->error++;
			return ;
		}
	}
}

void	ft_conv_p(va_list args, t_vars *var)
{
	unsigned long	ptr_nbr;

	ptr_nbr = va_arg(args, unsigned long);
	var->var_str = ft_xtoa_p(ptr_nbr, var, "0123456789abcdef");
	if (!var->var_str)
		return ;
}

void	ft_conv_s(va_list args, t_vars *var)
{
	char *str;

	str = va_arg(args, char *);
	if (!str)
		var->var_str = ft_strndup_struct("(null)", var);
	else
		var->var_str = ft_strndup_struct(str, var);
}

void	ft_conv_c(va_list args, t_vars *var)
{
	var->var_str  = (char *)malloc(sizeof(char) * 2);
	if (!var->var_str)
	{
		var->error++;
		return ;
	}
	var->var_str[0] = va_arg(args, int);
	var->var_str[1] = '\0';
}
