/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:58 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 15:53:45 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_c(va_list args, t_vars *var)
{
   char *stri;

   stri = (char *)malloc(sizeof(char) * 2);
   if (!stri)
   {
	   var->error++;
	   return (0);
   }
   stri[0] = va_arg(args, int);
   stri[1] = '\0';
   return (stri);
}
