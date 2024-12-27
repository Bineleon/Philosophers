/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:46:38 by bineleon          #+#    #+#             */
/*   Updated: 2024/12/25 13:06:51 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static int	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (-1);
	while (*s)
	{
		if (write(fd, s, 1) == -1)
			return (-1);
		s++;
	}
	return (0);
}

void  print_error(char *str)
{
    ft_putstr_fd(RED, 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd(RESET, 2);
}
