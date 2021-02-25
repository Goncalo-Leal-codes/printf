/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:49:54 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 15:15:17 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	restart_fids(t_vars *var)
{
	var->justif_left = 0;
	var->zero_pad = 0;
	var->min_width = 0;
	var->prec = 0;
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
	var->prec = 0;
	var->precision_check = 0;
	var->var_str = 0;
}
