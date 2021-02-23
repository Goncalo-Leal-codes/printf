/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:39:33 by gleal             #+#    #+#             */
/*   Updated: 2021/02/23 21:01:58 by gleal            ###   ########.fr       */
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

char	*ft_itoa_hex(unsigned long ptr_nbr,t_vars *var)
{
	if (nb < length)
		ft_putchar(base[nb]);
	else
	{
		display((nb / length), length, base);
		nb %= length;
		ft_putchar(base[nb]);
	}
}
/* continuar aqui ir buscar a strdup*/
