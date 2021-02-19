/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:08:57 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/18 11:09:02 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_x_maj(va_list ap, t_struct *s)
{
	unsigned int	j;
	static int		k;

	j = (unsigned int)va_arg(ap, int);
	k = count_putnbr_base(k, j, "0123456789ABCDEF", s);
	if (s->field_width != -1)
	{
		if (convert_xu(s, k, "0123456789ABCDEF", j) == 0)
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
			ft_putnbr_base(j, "0123456789ABCDEF", s);
	}
	k = 0;
}

int		convert_norm(t_struct *s, int k)
{
	int i;

	i = 0;
	if (s->precision != -1 && s->precision > k)
		i = s->field_width - s->precision;
	else if (s->precision != -1 && s->precision <= k)
		i = s->field_width - k;
	else if (s->precision == -1)
		i = s->field_width - k;
	while (s->minus == 0 && i-- > 0)
	{
		if (s->zero > 0)
			ft_putchar('0', s);
		else
			ft_putchar(' ', s);
	}
	return (i);
}

int		convert_xu(t_struct *s, int k, char *base, unsigned int j)
{
	int	i;

	i = convert_norm(s, k);
	flag_point_int(s, k);
	if (s->precision == 0 && j == 0 && s->field_width < 1)
		return (0);
	else if (s->precision == 0 && j == 0)
		ft_putchar(' ', s);
	else
		ft_putnbr_base(j, base, s);
	while (s->minus != 0 && i-- > 0)
		ft_putchar(' ', s);
	return (1);
}

void	convert_c(va_list ap, t_struct *s)
{
	unsigned char	c;
	int				i;

	i = s->field_width;
	c = (unsigned char)va_arg(ap, int);
	if (s->minus > 0)
		ft_putchar2(c, s);
	if (s->field_width > -1)
	{
		while (i > 1)
		{
			ft_putchar(' ', s);
			i--;
		}
	}
	if (s->minus <= 0)
		ft_putchar2(c, s);
}
