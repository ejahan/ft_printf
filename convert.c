/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:52:04 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 23:09:47 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_d_norm(t_struct *s, int j)
{
	char	*str;

	if (j == 0 && s->zero != 0 && s->field_width == 0)
	{
		ft_putchar('0', s);
		return (NULL);
	}
	if (j < 0)
	{
		convert_d_neg(j, s);
		return (NULL);
	}
	if (s->precision < -1 && s->zero > 0)
		s->precision = s->field_width;
	str = ft_itoa(j);
	if (s->precision == 0 && j == 0)
	{
		if (!(str = malloc(2)))
			return (NULL);
		str[0] = ' ';
		str[1] = '\0';
	}
	return (str);
}

int		convert_d_norm2(t_struct *s, int j, char *str)
{
	int	i;

	i = convert_norm(s, ft_strlen(str));
	flag_point_int(s, ft_strlen(str));
	if (s->precision == 0 && j == 0 && s->field_width < 1)
		return (0);
	else
		ft_putstr_i(str, s);
	while (s->minus != 0 && i-- > 0)
		ft_putchar(' ', s);
	return (1);
}

void	convert_d(va_list ap, t_struct *s)
{
	int		j;
	char	*str;

	j = va_arg(ap, int);
	if ((str = convert_d_norm(s, j)) == NULL)
		return ;
	if (s->field_width != -1)
	{
		if (convert_d_norm2(s, j, str) == 0)
		{
			free(str);
			return ;
		}
	}
	else
	{
		flag_point_int(s, ft_strlen(str));
		if (s->precision == 0 && j == 0 && s->field_width < 1)
			return ;
		ft_putstr_i(str, s);
	}
	free(str);
}

void	convert_d_neg_norm(t_struct *s, char *str)
{
	int	i;

	if (s->minus == 0 && s->zero > 0)
	{
		ft_putchar('-', s);
		s->neg = 0;
	}
	i = convert_norm(s, ft_strlen(str));
	flag_point_int(s, ft_strlen(str));
	ft_putstr_i(str, s);
	while (s->minus != 0 && i-- > 0)
		ft_putchar(' ', s);
}

void	convert_d_neg(int j, t_struct *s)
{
	char	*str;
	long	k;

	s->field_width--;
	if (s->precision < -1 && s->zero > 0)
		s->precision = s->field_width;
	s->neg = 1;
	k = -(long)j;
	str = ft_itoa2(k);
	if (s->field_width != -1)
		convert_d_neg_norm(s, str);
	else
	{
		flag_point_int(s, ft_strlen(str));
		ft_putstr_i(str, s);
	}
	free(str);
}
