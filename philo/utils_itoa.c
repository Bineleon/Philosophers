/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:09:01 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 23:16:52 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static long	ft_nb_size(long nb)
{
	long	size;
	long	sign;

	size = 0;
	sign = 1;
	if (nb < 0)
	{
		sign = -sign;
		nb = -nb;
		size++;
	}
	else if (nb == 0)
		return (1);
	while (nb != 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static void	ft_nbr_to_str(long nb, char *itoa, long size)
{
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	if (nb > 9)
		ft_nbr_to_str(nb / 10, itoa, size - 1);
	itoa[size] = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	long	nb;
	long	size;
	char	*itoa;

	nb = n;
	size = ft_nb_size(nb);
	itoa = (char *)malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	if (nb < 0)
		itoa[0] = '-';
	ft_nbr_to_str(nb, itoa, size - 1);
	itoa[size] = '\0';
	return (itoa);
}
