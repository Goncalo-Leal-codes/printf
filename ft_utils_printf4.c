/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:57:23 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 17:24:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xtoa(unsigned long ptr_nbr,t_vars *var, char *base)
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
