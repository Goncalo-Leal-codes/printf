/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:37:36 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 20:53:02 by gleal            ###   ########.fr       */
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
