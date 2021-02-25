/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:23:32 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 15:37:09 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, t_vars *var)
{
	write(1, &c, 1);
	var->count++;
}

void	ft_putstr_pf(char *str, t_vars *var)
{
	while (*str)
	{
		ft_putchar_pf(*str, var);
		str++;
	}
}

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		ft_ln_itoa(int n)
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

char			*ft_itoa(int n)
{
	char	*str;
	int		ln;

	ln = ft_ln_itoa(n);
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

void	print_info(const char *input, t_vars *var)
{
	input[var->i] == 'c' ? ft_print_c(var) : 0;
	input[var->i] == 's' ? ft_print_spd(var) : 0;
	input[var->i] == 'p' ? ft_print_spd(var) : 0;
	input[var->i] == 'd' ? ft_print_spd(var) : 0;
}
