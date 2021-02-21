/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:31:16 by gleal             #+#    #+#             */
/*   Updated: 2021/02/21 21:45:58 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAGS "-0"
# define NBRS "0123456789"
# define CONVS "cspdiuxX%"

typedef struct	s_vars
{
	int	i;
	int	count;
	int error;
	int	justif_left;
	int zero_pad;
	int min_width;
	int	precision;
	char *var_str;

}				t_vars;

int	ft_printf(const char *, ...);
int	contains(char input, char *format_ids);
void	start_list(t_vars *var);
char	*ft_strdup(const char *s1);

#endif
