/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:17:09 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 15:53:48 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	restart_fids(t_vars *var)
{
	var->justif_left = 0;
	var->zero_pad = 0;
	var->min_width = 0;
	var->precision = 0;
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
	var->var_str = 0;
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (0);
}

int		ft_atoi(const char *str)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * sign);
}
