/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:51:18 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 20:51:22 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_u(va_list args, t_vars *var)
{
	unsigned int	n;
	char			*temp;

	temp = 0;
	n = va_arg(args, unsigned int);
	if ((var->prec > 0 || !var->precision_check) || n)
	{
		temp = ft_itoau(n);
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

void	ft_conv_d(va_list args, t_vars *var)
{
	int		n;
	char	*temp;

	temp = 0;
	n = va_arg(args, int);
	if ((var->prec > 0 || !var->precision_check) || n)
	{
		temp = ft_itoad(n);
		if (!temp)
		{
			var->error++;
			return ;
		}
		if (ft_strchr(temp, '-'))
			var->prec++;
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
	var->var_str = (char *)malloc(sizeof(char) * 2);
	if (!var->var_str)
	{
		var->error++;
		return ;
	}
	var->var_str[0] = va_arg(args, int);
	var->var_str[1] = '\0';
}
