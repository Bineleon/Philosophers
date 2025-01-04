/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:51:15 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/04 15:21:28 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

t_bool    is_num(char *str)
{
    int i;

    i = 0;
    if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
        return (false);
    i++;
    while (str[i])
    {
      if (!ft_isdigit(str[i]))
          return (false);
      i++;
    }
    return (true);
}

t_bool  valid_num_args(int ac, char **av)
{
    if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 200)
    {
        printf("%sNumber of philos should be between 1 and 200%s\n", RED, RESET);
        return (false);
    }
    else if (ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
    {
        printf("%sTime to die, eat or sleep should be supperior to 0ms%s\n", RED, RESET);
        return (false);
    }
    else if (ac == 6 && ft_atoi(av[5]) < 0)
    {
        printf("%sNumbers of meals should be supperior or equal to 0%s\n", RED, RESET);
        return (false);
    }
    return (true);

}

t_bool    valid_args(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        if (!is_num(av[i]))
            return (false);
        i++;
    }
    return (true);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
