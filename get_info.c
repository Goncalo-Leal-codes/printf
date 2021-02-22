/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:21:28 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 15:53:40 by gleal            ###   ########.fr       */
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
		var->i++;
		if (input[var->i] == '*')
		{
			var->min_width = va_arg(args, int);
			var->i++;
		}
		else if (ft_strchr(NBRS,input[var->i]))
		{
			var->min_width = ft_atoi(&input[var->i]);
			while (ft_strchr(NBRS, input[var->i]))
				var->i++;
		}
	}
}

void	get_str(va_list args, const char *input, t_vars *var)
{
	char formats[1];
	char *(*convs[1])(va_list, t_vars *);
	int a;

	formats[0] = 'c';
	convs[0] = &ft_conv_c;
	a = 0;
	while (a < 1)
	{
		if (input[var->i] == formats[a])
			var->var_str = convs[a](args, var);
		if (var->error)
			return ;
		a++;
	}
}
