/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:46:38 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/04 18:32:16 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	ft_putstr_fd(char *s, int fd)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void print_status(t_philo *philo, char *status)
{
    t_data *data;
    const char *color;

    data = philo->data;
    if (ft_strcmp(status, "is eating") == 0)
        color = SMGREEN;
    else if (ft_strcmp(status, "has taken a fork") == 0)
        color = SMYELLOW;
    else if (ft_strcmp(status, "is sleeping") == 0)
        color = SMCYAN;
    else if (ft_strcmp(status, "is thinking") == 0)
        color = SMBLUE;
    else if (ft_strcmp(status, "is dead") == 0)
        color = RED;
    else
        color = RESET;
    pthread_mutex_lock(&data->print_lock);
    if (!data->end_philo)
    {
        printf("%s", color);
        printf("%ld %d %s\n", get_time() - data->start_time, philo->id, status);
        printf(RESET);
    }
    pthread_mutex_unlock(&data->print_lock);
}
