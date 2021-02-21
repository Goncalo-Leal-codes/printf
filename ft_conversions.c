/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:58 by gleal             #+#    #+#             */
/*   Updated: 2021/02/21 21:45:54 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_conv_c(va_list args, t_vars *var)
{
   char str;

   str = (char *)malloc(sizeof(char) * 2);
   if (!str)
   {
	   var->error++;
	   return (0);
   }
   str[0] = va_arg(args, char);
   str[1] = '\0';
   return (str);
}
