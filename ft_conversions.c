/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:58 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 20:52:49 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_s(va_list args, t_vars *var)
{
	var->var_str = va_arg(args, char *);
	/* continuar aqui*/
}

void	ft_conv_c(va_list args, t_vars *var)
{
   var->var_str  = (char *)malloc(sizeof(char) * 2);
   if (!var->var_str)
   {
	   var->error++;
	   return ;
   }
   var->var_str[0] = va_arg(args, int);
   var->var_str[1] = '\0';
}
