/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:08:47 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/18 11:08:51 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_s_re(t_struct *s, int i)
{
	while ((s->field_width - i) > 0)
	{
		ft_putchar(' ', s);
		s->field_width--;
	}
}

void	convert_s(va_list ap, t_struct *s)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	if ((s->precision) >= 0)
		str = flag_point_char(s, str);
	if (s->field_width != -1 && ft_strlen(str) <= s->field_width)
	{
		if (s->minus <= 0)
			convert_s_re(s, ft_strlen(str));
		ft_putstr_i(str, s);
		if (s->minus > 0)
			convert_s_re(s, ft_strlen(str));
	}
	if (ft_strlen(str) > s->field_width)
		ft_putstr_i(str, s);
	if (s->neg == 2)
		free(str);
}

void	convert_p(va_list ap, t_struct *s)
{
	unsigned long	ptr;
	static int		i = 0;

	ptr = (unsigned long)va_arg(ap, void*);
	if (ptr == 0 && s->precision == 0)
	{
		convert_p_0(s);
		return ;
	}
	i = base_p(i, ptr, "0123456789abcdef", s);
	if (s->minus > 0)
	{
		ft_putstr_i("0x", s);
		putnbr_base_p(ptr, "0123456789abcdef", s);
	}
	if (s->field_width > -1)
		i = convert_p_re(s, i);
	if (s->minus <= 0)
	{
		ft_putstr_i("0x", s);
		putnbr_base_p(ptr, "0123456789abcdef", s);
	}
	i = 0;
}

int		convert_p_re(t_struct *s, int i)
{
	if (s->field_width > (i + 2))
	{
		i = s->field_width - i - 2;
		while (i-- > 0)
			ft_putchar(' ', s);
	}
	return (i);
}

void	convert_p_0(t_struct *s)
{
	int	i;

	i = 3;
	if (s->minus > 0)
		ft_putstr_i("0x", s);
	if (s->field_width > -1)
	{
		if (s->field_width > 2)
		{
			s->field_width--;
			while (i-- > 0)
				ft_putchar(' ', s);
		}
	}
	if (s->minus <= 0)
		ft_putstr_i("0x", s);
	i = 0;
}
