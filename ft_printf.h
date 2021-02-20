/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:31:16 by gleal             #+#    #+#             */
/*   Updated: 2021/02/20 19:49:00 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_vars
{
	int	i;
	int	count;
	int	conv_c;
}				t_vars;

int	ft_printf(const char *, ...);
int	contains(char input, char *format_ids);
void	start_list(t_vars *var);
char	*ft_strdup(const char *s1);

#endif
