/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:49:54 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 16:56:40 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_ln_itoau(unsigned int n)
{
	int	ln;

	ln = 0;
	if (n == 0)
		ln++;
	while (n != 0)
	{
		ln++;
		n /= 10;
	}
	return (ln);
}

char			*ft_itoau(unsigned int n)
{
	char	*str;
	int		ln;

	ln = ft_ln_itoau(n);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (0);
	str[ln] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		ln--;
		str[ln] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		ft_ln_itoad(int n)
{
	int	ln;

	ln = 0;
	if (n <= 0)
		ln++;
	while (n != 0)
	{
		ln++;
		n /= 10;
	}
	return (ln);
}

char			*ft_itoad(int n)
{
	char	*str;
	int		ln;

	ln = ft_ln_itoad(n);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (0);
	str[ln] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		ln--;
		str[ln] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
