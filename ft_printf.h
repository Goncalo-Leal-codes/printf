/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:31:16 by gleal             #+#    #+#             */
/*   Updated: 2021/02/26 17:11:46 by gleal            ###   ########.fr       */
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
	int		i;
	int		count;
	int		error;
	int		justif_left;
	int		zero_pad;
	int		min_width;
	int		precision_check;
	int		prec;
	char	*var_str;
}				t_vars;

void			ft_protect_mal(t_vars *var, char *str);
void			ft_minus_zeropad(t_vars *var, char *temp);
void			ft_putzeros(t_vars *var, int n);
void			ft_putspaces(t_vars *var, int n);
int				ft_strlen(const char *s);
int				contains(char input, char *format_ids);
void			start_list(t_vars *var);
void			restart_fids(t_vars *var);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
void			ft_putchar_pf(char c, t_vars *var);
void			ft_putstr_pf(char *str, t_vars *var);
void			print_info(const char *input, t_vars *var);
void			ft_conv_c(va_list args, t_vars *var);
void			get_str(va_list args, const char *input, t_vars *var);
void			get_precision_info(va_list args, const char *input,
				t_vars *var);
void			get_min_width_info(va_list args, const char *input,
				t_vars *var);
void			get_flag_info(const char *input, t_vars *var);
void			get_info(va_list args, const char *input, t_vars *var);
int				valid_conv(const char *input, t_vars var);
int				ft_printf(const char *input, ...);
void			ft_print_c(t_vars *var);
void			ft_convcpy(void (**fts)(t_vars *));
void			ft_convprints(void (**fts)(t_vars *));
int				ft_strlcpy(char *dst, const char *src, int dstsize);
void			ft_print_spd(t_vars *var);
void			ft_conv_s(va_list args, t_vars *var);
char			*ft_strndup_struct(char *s1, t_vars *var);
int				ft_ln_xtoa(unsigned long	ptr_nbr);
char			*ft_xtoa_p(unsigned long ptr_nbr, t_vars *var, char *base);
void			ft_conv_p(va_list args, t_vars *var);
char			*ft_itoad(int n);
void			ft_add_zeros(char *temp, t_vars *var);
void			ft_conv_d(va_list args, t_vars *var);
void			ft_strlcat1(char *dst, const char *src, size_t dstsize);
char			*ft_itoau(unsigned int n);
void			ft_conv_u(va_list args, t_vars *var);
char			*ft_xtoa(unsigned long ptr_nbr, t_vars *var, char *base);
void			ft_conv_x(va_list args, t_vars *var);
void			ft_conv_ux(va_list args, t_vars *var);
void			ft_conv_pct(t_vars *var);
void			ft_print_pct(t_vars *var);

#endif
