/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:47:20 by gleal             #+#    #+#             */
/*   Updated: 2021/02/26 17:09:53 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_protect_mal(t_vars *var, char *str)
{
	if (!str)
	{
		var->error++;
		return ;
	}
}

void	ft_minus_zeropad(t_vars *var, char *temp)
{
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

void	ft_putzeros(t_vars *var, int n)
{
	while (var->min_width - n)
	{
		ft_putchar_pf('0', var);
		var->min_width--;
	}
}

void	ft_putspaces(t_vars *var, int n)
{
	while (var->min_width - n)
	{
		ft_putchar_pf(' ', var);
		var->min_width--;
	}
}

char	*ft_xtoa(unsigned long ptr_nbr, t_vars *var, char *base)
{
	char	*str;
	int		ln;

	ln = ft_ln_xtoa(ptr_nbr);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
	{
		var->error++;
		return (0);
	}
	str[ln] = '\0';
	if (ptr_nbr == 0)
		str[0] = '0';
	while (ptr_nbr != 0)
	{
		ln--;
		str[ln] = base[ptr_nbr % 16];
		ptr_nbr /= 16;
	}
	return (str);
}
