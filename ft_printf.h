/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:31:16 by gleal             #+#    #+#             */
/*   Updated: 2021/02/22 15:53:50 by gleal            ###   ########.fr       */
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

int		contains(char input, char *format_ids);
void	start_list(t_vars *var);
void	restart_fids(t_vars *var);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_putchar_pf(char c, t_vars *var);
void	ft_putstr_pf(char *str, t_vars *var);
void	print_info(const char *input, t_vars *var);
char	*ft_conv_c(va_list args, t_vars *var);
void	get_str(va_list args, const char *input, t_vars *var);
void	get_precision_info(va_list args, const char *input, t_vars *var);
void	get_min_width_info(va_list args, const char *input, t_vars *var);
void	get_flag_info(const char *input, t_vars *var);
void	get_info(va_list args, const char *input, t_vars *var);
int		valid_conv(const char *input, t_vars var);
int		ft_printf(const char *input, ...);

#endif
