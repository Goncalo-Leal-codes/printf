/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:58 by gleal             #+#    #+#             */
/*   Updated: 2021/02/23 21:01:58 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_p(va_list args, t_vars *var)
{
	unsigned long	ptr_nbr;

	ptr_nbr = va_arg(args, unsigned long);
	var->var_str = ft_itoa_hex(ptr_nbr, var);
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
