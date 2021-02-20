/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:17:09 by gleal             #+#    #+#             */
/*   Updated: 2021/02/20 19:48:58 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	start_list(t_vars *var)
{
	var->i = 0;
	var->count = 0;
}

int	contains(char input, char *format_ids)
{
	while (*format_ids)
	{
		if (input == *format_ids)
			return (1);
		format_ids++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = 0;
	while (s1[size])
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
