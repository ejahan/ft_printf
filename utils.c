/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:32:24 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 22:34:11 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		error(char *base)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base, t_struct *s)
{
	int		size;
	long	nb;

	size = ft_strlen(base);
	nb = (unsigned int)nbr;
	if (error(base) == 1)
		return ;
	if (nb < 0)
	{
		ft_putchar('-', s);
		nb = nb * -1;
	}
	if (nb < size)
		ft_putchar(base[nb], s);
	if (nb >= size)
	{
		ft_putnbr_base(nb / size, base, s);
		ft_putnbr_base(nb % size, base, s);
	}
}

void	putnbr_base_p(unsigned long nbr, char *base, t_struct *s)
{
	unsigned int	size;
	unsigned long	nb;

	size = ft_strlen(base);
	nb = nbr;
	if (error(base) == 1)
		return ;
	if (nb < 0)
	{
		ft_putchar('-', s);
		nb = nb * -1;
	}
	if (nb < size)
		ft_putchar(base[nb], s);
	if (nb >= size)
	{
		putnbr_base_p(nb / size, base, s);
		putnbr_base_p(nb % size, base, s);
	}
}

int		count_putnbr_base(int j, int nbr, char *base, t_struct *s)
{
	int			size;
	long		nb;
	static int	i = 0;

	i = j;
	size = ft_strlen(base);
	nb = (unsigned int)nbr;
	if (error(base) == 1)
		return (0);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	if (nb < size)
		i++;
	if (nb >= size)
	{
		count_putnbr_base(i, nb / size, base, s);
		count_putnbr_base(i, nb % size, base, s);
	}
	return (i);
}

int		base_p(int j, unsigned long nbr, char *base, t_struct *s)
{
	unsigned int	size;
	unsigned long	nb;
	static int		i = 0;

	i = j;
	size = ft_strlen(base);
	nb = nbr;
	if (error(base) == 1)
		return (0);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	if (nb < size)
		i++;
	if (nb >= size)
	{
		base_p(i, nb / size, base, s);
		base_p(i, nb % size, base, s);
	}
	return (i);
}
