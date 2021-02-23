/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:37:36 by gleal             #+#    #+#             */
/*   Updated: 2021/02/23 17:21:23 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	restart_fids(t_vars *var)
{
	var->justif_left = 0;
	var->zero_pad = 0;
	var->min_width = 0;
	var->precision = 0;
	var->precision_check = 0;
	var->var_str = 0;
}

void	start_list(t_vars *var)
{
	var->i = 0;
	var->count = 0;
	var->error = 0;
	var->justif_left = 0;
	var->zero_pad = 0;
	var->min_width = 0;
	var->precision = 0;
	var->precision_check = 0;
	var->var_str = 0;
}

char	*ft_strndup_struct(char *s1, t_vars *var)
{
	char	*str;

		if (var->precision_check)
		{
			if (ft_strlen(s1) < var->precision)
				var->precision = ft_strlen(s1);
		}
		else
		var->precision = ft_strlen(s1);
			str = (char *)malloc(sizeof(char) * (var->precision + 1));
		if (!str)
		{
			var->error++;
			return 0;
		}
		ft_strlcpy(str, s1, var->precision + 1);
	return (str);
}

