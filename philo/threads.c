/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:45:18 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 23:22:47 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
	ft_usleep(philo->time_to_think);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	while (1)
	{
		mutex_lock(&philo->data->end_mutex);
		if (philo->data->end_philo)
		{
			mutex_unlock(&philo->data->end_mutex);
			break ;
		}
		mutex_unlock(&philo->data->end_mutex);
		philo_eat(philo);
		if (philo->action == taken_fork)
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	init_threads(t_data *data)
{
	size_t	i;

	i = 0;
	if (thread_create(&data->monitor, monitor_routine, data) != 0)
		return (-1);
	while (i < data->nb_of_philos)
	{
		if (thread_create(&data->philos[i].philo, philo_routine,
				&data->philos[i]) != 0)
			return (-1);
		i++;
	}
	thread_join(data->monitor);
	clean_philo(data);
	return (0);
}
