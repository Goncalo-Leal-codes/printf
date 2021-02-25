/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:39:33 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 20:46:21 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strlcat1(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (i + 1 < dstsize && src[j])
	{
		if (src[j] == '-')
			j++;
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

void	ft_add_zeros(char *temp, t_vars *var)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(temp);
	str = malloc(sizeof(char) * (var->prec + 1));
	if (!str)
	{
		var->error++;
		return ;
	}
	if (ft_strchr(temp, '-'))
	{
		str[0] = '-';
		len--;
		i++;
	}
	while (var->prec - len - i)
		str[i++] = '0';
	str[i] = '\0';
	ft_strlcat1(str, temp, var->prec + 1);
	var->var_str = str;
	free(temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	count = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	while (*s1)
		str[j++] = *(s1++);
	while (*s2)
		str[j++] = *(s2++);
	str[j] = '\0';
	return (str);
}

int		ft_ln_xtoa(unsigned long ptr_nbr)
{
	int count;

	count = 0;
	if (ptr_nbr == 0)
		count++;
	while (ptr_nbr)
	{
		ptr_nbr /= 16;
		count++;
	}
	return (count);
}

char	*ft_xtoa_p(unsigned long ptr_nbr, t_vars *var, char *base)
{
	char	*temp;
	char	*str;
	int		ln;

	ln = ft_ln_xtoa(ptr_nbr);
	temp = malloc(sizeof(char) * (ln + 1));
	if (!temp)
	{
		var->error++;
		return (0);
	}
	temp[ln] = '\0';
	if (ptr_nbr == 0)
		temp[0] = '0';
	while (ptr_nbr != 0)
	{
		ln--;
		temp[ln] = base[ptr_nbr % 16];
		ptr_nbr /= 16;
	}
	str = ft_strjoin("0x", temp);
	if (!str)
	{
		var->error++;
		return (0);
	}
	free(temp);
	var->prec = ft_strlen(str);
	return (str);
}
