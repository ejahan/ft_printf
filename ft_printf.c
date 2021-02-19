/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:42:51 by elisa             #+#    #+#             */
/*   Updated: 2021/02/17 23:06:10 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_valid(const char *format, t_struct *s, int i)
{
	int	j;

	j = 0;
	if (format[i] == '%')
		j++;
	while (check_flag(format[i + j], s) == 1
			|| check_flag(format[i + j], s) == 2)
		j++;
	if (check_flag(format[i + j], s) == 4)
		j++;
	else
		while (format[i + j] >= 48 && format[i + j] <= 57)
			j++;
	if (check_flag(format[i + j], s) == 3)
		j++;
	if (check_flag(format[i + j], s) == 4)
		j++;
	else
		while (format[i + j] >= 48 && format[i + j] <= 57)
			j++;
	if (check_convert(format[i + j]))
		return (i + j);
	else
		return (i);
}

char	*str_flags(const char *format, int i, int j, t_struct *s)
{
	char	*str;
	int		k;

	k = i;
	str = malloc(sizeof(char) * (j - k) + 1);
	if (!str)
		return (NULL);
	str[j - k] = '\0';
	while (j-- > k)
		str[j - k] = format[j + 1];
	s->str_flag = str;
	return (str);
}

int		fonction(t_struct *s, const char *format, int k, va_list ap)
{
	int		j;
	char	*f;
	int		i;

	i = k;
	init_struct2(s);
	if ((j = check_valid(format, s, i)) > i)
	{
		f = str_flags(format, i, j, s);
		recup_arg(s, ap, f);
		i = j;
		free(f);
	}
	else
		ft_putchar(format[i], s);
	i++;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int			i;
	t_struct	s;
	va_list		ap;

	i = 0;
	init_struct(&s);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		while (format[i] && format[i] != '%')
		{
			ft_putchar(format[i], &s);
			i++;
		}
		if (format[i] != '\0')
			i = fonction(&s, format, i, ap);
	}
	va_end(ap);
	return (s.k);
}
