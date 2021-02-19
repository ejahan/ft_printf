/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:00:12 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/17 22:34:16 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len_int(long n)
{
	int	len_int;

	len_int = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		len_int++;
	}
	return (len_int + 1);
}

char		*ft_itoa(int n)
{
	char	*dst;
	long	nb;
	int		len;

	nb = n;
	len = ft_len_int(nb) + (nb < 0);
	if ((dst = malloc(sizeof(char) * len + 1 + (n < 0))) == NULL)
		return (NULL);
	if (nb < 0 && (nb = -nb))
		*dst = '-';
	dst[len--] = '\0';
	while (len >= (n < 0))
	{
		dst[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}

char		*ft_itoa2(long n)
{
	char	*dst;
	long	nb;
	int		len;

	nb = n;
	len = ft_len_int(nb) + (nb < 0);
	if ((dst = malloc(sizeof(char) * len + 1 + (n < 0))) == NULL)
		return (NULL);
	if (nb < 0 && (nb = -nb))
		*dst = '-';
	dst[len--] = '\0';
	while (len >= (n < 0))
	{
		dst[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int i;
	int n;
	int nb;

	i = 0;
	n = 0;
	nb = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		n = 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (n == 1)
		nb = -nb;
	return (nb);
}
