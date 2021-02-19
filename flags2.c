/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:56:23 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 23:07:06 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_point_char(t_struct *s, char *str)
{
	int		i;
	char	*s1;

	i = 0;
	if (ft_strlen(str) > s->precision)
	{
		if (!(s1 = malloc(sizeof(s->precision + 1))))
			return (NULL);
		s->neg = 2;
		while (i < s->precision)
		{
			s1[i] = str[i];
			i++;
		}
		s1[i] = '\0';
		str = s1;
	}
	return (str);
}

void	flag_point_int(t_struct *s, int i)
{
	int		j;

	if (s->neg == 1)
		ft_putchar('-', s);
	if (i < s->precision)
	{
		j = s->precision - i;
		while (j-- > 0)
			ft_putchar('0', s);
	}
}

void	init_struct(t_struct *s)
{
	s->field_width = -1;
	s->precision = -1;
	s->str_flag = NULL;
	s->minus = 0;
	s->zero = 0;
	s->point = 0;
	s->width = 0;
	s->k = 0;
}

void	init_struct2(t_struct *s)
{
	s->field_width = -1;
	s->precision = -1;
	s->str_flag = NULL;
	s->minus = 0;
	s->zero = 0;
	s->point = 0;
	s->width = 0;
	s->neg = 0;
}
