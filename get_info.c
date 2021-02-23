/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:21:28 by gleal             #+#    #+#             */
/*   Updated: 2021/02/23 17:21:07 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag_info(const char *input, t_vars *var)
{
	while (ft_strchr(FLAGS, input[var->i]))
	{
		if (input[var->i] == '0')
			var->zero_pad++;
		if (input[var->i] == '-')
			var->justif_left++;
		var->i++;
	}
}

void	get_min_width_info(va_list args, const char *input, t_vars *var)
{
	if (input[var->i] == '*')
	{
			var->min_width = va_arg(args, int);
			if (var->min_width < 0)
			{
				var->min_width *= -1;
				var->justif_left++;
			}
			var->i++;
	}
	else if (ft_strchr(NBRS, input[var->i]) && input[var->i])
	{
		var->min_width = ft_atoi(&input[var->i]);
		while (ft_strchr(NBRS, input[var->i]) && input[var->i])
			var->i++;
	}
}

void	get_precision_info(va_list args, const char *input, t_vars *var)
{
	if (input[var->i] == '.')
	{
		var->precision_check++;
		var->i++;
		if (input[var->i] == '*')
		{
			var->precision = va_arg(args, int);
			if (var->precision < 0)
				var->precision_check = 0;
			var->i++;
		}
		else if (ft_strchr(NBRS,input[var->i]))
		{
			var->precision = ft_atoi(&input[var->i]);
			while (ft_strchr(NBRS, input[var->i]))
				var->i++;
		}
	}
}

void	get_str(va_list args, const char *input, t_vars *var)
{
	input[var->i] == 'c' ?  ft_conv_c(args, var) : 0;
	input[var->i] == 's' ?  ft_conv_s(args, var) : 0;
	if (var->error)
		return ;
}
