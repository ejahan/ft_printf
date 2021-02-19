/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:41:35 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 23:08:14 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_struct
{
	int		field_width;
	int		precision;
	char	*str_flag;
	int		k;
	int		neg;
	int		minus;
	int		zero;
	int		point;
	int		width;
}				t_struct;

int				ft_printf(const char *format, ...);
char			*str_flags(const char *format, int i, int j, t_struct *s);
int				check_valid(const char *format, t_struct *s, int i);
int				fonction(t_struct *s, const char *format, int k, va_list ap);
void			init_struct(t_struct *s);
void			init_struct2(t_struct *s);
int				check_flag(char c, t_struct *s);
void			recup_arg(t_struct *s, va_list ap, char *flags);
void			recup_nbr_p(t_struct *s, char *flags);
void			recup_nbr_w(t_struct *s, char *flags);
void			recup_width(t_struct *s, va_list ap, char *f);
char			*flag_point_char(t_struct *s, char *str);
void			flag_point_int(t_struct *s, int i);
int				check_convert(char c);
void			convert(va_list ap, char c, t_struct *s);
void			convert_x(va_list ap, t_struct *s);
void			convert_u(va_list ap, t_struct *s);
void			convert_percent(t_struct *s);
void			convert_p(va_list ap, t_struct *s);
void			convert_d(va_list ap, t_struct *s);
void			convert_d_neg(int j, t_struct *s);
void			convert_x_maj(va_list ap, t_struct *s);
void			convert_s(va_list ap, t_struct *s);
void			convert_c(va_list ap, t_struct *s);
void			ft_putchar(char c, t_struct *s);
void			ft_putchar2(unsigned char c, t_struct *s);
int				ft_putstr_i(char *str, t_struct *s);
void			ft_putnbr_base(int nbr, char *base, t_struct *s);
void			putnbr_base_p(unsigned long nbr, char *base, t_struct *s);
int				error(char *base);
int				count_putnbr_base(int j, int nbr, char *base, t_struct *s);
int				base_p(int j, unsigned long nbr, char *base, t_struct *s);
char			*ft_itoa(int i);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa2(long n);
int				convert_norm(t_struct *s, int k);
int				convert_xu(t_struct *s, int k, char *base, unsigned int j);
void			recup_width2(t_struct *s, int a);
void			recup_nbr_p2(char *str, t_struct *s, int j, char *nbr);
void			convert_d_neg_norm(t_struct *s, char *str);
char			*convert_d_norm(t_struct *s, int j);
int				convert_d_norm2(t_struct *s, int j, char *str);
void			convert_p_0(t_struct *s);
int				convert_p_re(t_struct *s, int i);

#endif
