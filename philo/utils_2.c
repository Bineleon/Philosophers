/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:46:25 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 22:09:20 by neleon           ###   ########.fr       */
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

void	print_error(char *str)
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

const char	*get_color(char *status)
{
	if (ft_strcmp(status, "is eating") == 0)
		return (SMGREEN);
	if (ft_strcmp(status, "has taken a fork") == 0)
		return (SMYELLOW);
	if (ft_strcmp(status, "is sleeping") == 0)
		return (SMCYAN);
	if (ft_strcmp(status, "is thinking") == 0)
		return (SMBLUE);
	if (ft_strcmp(status, "died") == 0)
		return (RED);
	return (RESET);
}

void	print_status(t_philo *philo, char *status)
{
	t_data		*data;
	const char	*color;
	long		current_time;

	data = philo->data;
	color = get_color(status);
	current_time = get_time();
	if (current_time < data->start_time)
		current_time = data->start_time;
	if (mutex_lock(&data->print_mutex) != 0)
		return ;
	if (mutex_lock(&data->end_mutex) != 0)
	{
		mutex_unlock(&data->print_mutex);
		return ;
	}
	if (!data->end_philo)
	{
		mutex_unlock(&data->end_mutex);
		printf("%s%ld\t%d\t%s%s\n", color, get_time() - data->start_time,
			philo->id, status, RESET);
	}
	else
		mutex_unlock(&data->end_mutex);
	mutex_unlock(&data->print_mutex);
}
