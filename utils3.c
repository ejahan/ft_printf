/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:02:36 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/18 11:02:42 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_struct *s)
{
	write(1, &c, 1);
	s->k = s->k + 1;
}

void	ft_putchar2(unsigned char c, t_struct *s)
{
	write(1, &c, 1);
	s->k = s->k + 1;
}

int		ft_putstr_i(char *str, t_struct *s)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], s);
		i++;
	}
	return (i);
}

void	recup_width2(t_struct *s, int a)
{
	if (s->field_width < 0 && a == 1)
	{
		s->minus = 1;
		s->field_width = s->field_width * -1;
	}
}

void	recup_width(t_struct *s, va_list ap, char *flags)
{
	int	j;
	int	a;

	j = 0;
	a = 0;
	while (flags[j] && flags[j] != '*')
		j++;
	if (flags[j] == '*' && flags[j - 1] != '.')
	{
		s->field_width = va_arg(ap, int);
		a = 1;
		j++;
	}
	else if (flags[j] == '*' && flags[j - 1] == '.')
		s->precision = va_arg(ap, int);
	if (s->width == 2)
	{
		while (flags[j] && flags[j] != '*')
			j++;
		if (flags[j] == '*' && flags[j - 1] == '.')
			s->precision = va_arg(ap, int);
	}
	recup_width2(s, a);
}
