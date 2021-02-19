/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:37:09 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 22:56:46 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char c, t_struct *s)
{
	if (c == '-')
	{
		s->minus = 1;
		return (1);
	}
	if (c == '0')
	{
		s->zero = 1;
		return (2);
	}
	if (c == '.')
	{
		s->point = 1;
		return (3);
	}
	if (c == '*')
	{
		if (s->width == 1)
			s->width = 2;
		else
			s->width = 1;
		return (4);
	}
	return (0);
}

void	recup_nbr_p2(char *str, t_struct *s, int j, char *nbr)
{
	int	i;

	i = 0;
	while (str[j + i] >= '0' && str[j + i] <= '9')
	{
		nbr[i] = str[i + j];
		i++;
	}
	nbr[i] = '\0';
	s->precision = ft_atoi(nbr);
	j++;
}

void	recup_nbr_p(t_struct *s, char *str)
{
	int		j;
	char	*nbr;

	j = 0;
	if (!(nbr = malloc(sizeof(char) * 11)))
		return ;
	while (str[j] && str[j] != '.')
		j++;
	if (str[j] != '\0')
		j++;
	if (check_convert(str[j]) != 0)
		s->precision = 0;
	if (str[j] >= '0' && str[j] <= '9')
		recup_nbr_p2(str, s, j, nbr);
	free(nbr);
}

void	recup_nbr_w(t_struct *s, char *str)
{
	int		i;
	int		j;
	char	*nbr;

	j = 0;
	i = 0;
	nbr = malloc(sizeof(char) * 11);
	if (!nbr)
		return ;
	while (str[j] && (str[j] <= 48 || str[j] > 57) && str[j] != '.')
		j++;
	if ((str[j] >= '0' && str[j] <= '9') && str[j - 1] != '.' && str[j + i])
	{
		while (str[j + i] >= '0' && str[j + i] <= '9')
		{
			nbr[i] = str[i + j];
			i++;
		}
		nbr[i] = '\0';
		s->field_width = ft_atoi(nbr);
	}
	free(nbr);
}

void	recup_arg(t_struct *s, va_list ap, char *flags)
{
	int	j;
	int	a;

	j = 0;
	a = 1;
	recup_width(s, ap, flags);
	recup_nbr_w(s, flags);
	recup_nbr_p(s, flags);
	while (flags[j] && check_convert(flags[j]) == 0)
		j++;
	if (s->precision < -1 && s->zero > 0
			&& (flags[j] == 'd' || flags[j] == 'i'))
	{
		s->zero = 1;
		a = 1;
	}
	else if (s->precision != -1)
		s->zero = 0;
	if (a == 1 && s->minus != 0)
		s->zero = 0;
	convert(ap, flags[j], s);
}
