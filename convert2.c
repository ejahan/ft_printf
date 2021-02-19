/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:55:21 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 23:02:57 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_u(va_list ap, t_struct *s)
{
	unsigned int	j;
	static int		k;

	j = (unsigned int)va_arg(ap, int);
	k = count_putnbr_base(k, j, "0123456789", s);
	if (s->field_width != -1)
	{
		if (convert_xu(s, k, "0123456789", j) == 0)
			return ;
	}
	else
	{
		flag_point_int(s, k);
		if (s->precision == 0 && j == 0 && s->field_width < 1)
			return ;
		else if (s->precision == 0 && j == 0)
			ft_putchar(' ', s);
		else
			ft_putnbr_base(j, "0123456789", s);
	}
	k = 0;
}

void	convert_x(va_list ap, t_struct *s)
{
	unsigned int	j;
	static int		k;

	j = (unsigned int)va_arg(ap, int);
	k = count_putnbr_base(k, j, "0123456789abcdef", s);
	if (s->field_width != -1)
	{
		if (convert_xu(s, k, "0123456789abcdef", j) == 0)
			return ;
	}
	else
	{
		flag_point_int(s, k);
		if (s->precision == 0 && j == 0 && s->field_width < 1)
			return ;
		else if (s->precision == 0 && j == 0)
			ft_putchar(' ', s);
		else
			ft_putnbr_base(j, "0123456789abcdef", s);
	}
	k = 0;
}

void	convert_percent(t_struct *s)
{
	unsigned char	c;
	int				i;

	i = s->field_width;
	c = '%';
	if (s->minus > 0)
		ft_putchar2(c, s);
	if (s->field_width > -1)
	{
		while (i > 1)
		{
			if (s->zero > 0 && s->minus < 1)
				ft_putchar('0', s);
			else
				ft_putchar(' ', s);
			i--;
		}
	}
	if (s->minus <= 0)
		ft_putchar2(c, s);
}

void	convert(va_list ap, char c, t_struct *s)
{
	int		i;

	i = check_convert(c);
	if (i == 1)
		convert_c(ap, s);
	else if (i == 12)
		convert_s(ap, s);
	else if (i == 13)
		convert_p(ap, s);
	else if (i == 4)
		convert_d(ap, s);
	else if (i == 5)
		convert_u(ap, s);
	else if (i == 6)
		convert_x(ap, s);
	else if (i == 7)
		convert_x_maj(ap, s);
	else if (i == 8)
		convert_percent(s);
}

int		check_convert(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (12);
	if (c == 'p')
		return (13);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	return (0);
}
