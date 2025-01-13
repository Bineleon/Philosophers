/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:25 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 22:09:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	check_if_dead(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		mutex_lock(&data->philos[i].meal_mutex);
		if ((get_time() - data->philos[i].last_meal) > data->time_to_die)
		{
			print_status(&data->philos[i], "died");
			mutex_lock(&data->end_mutex);
			data->end_philo = true;
			mutex_unlock(&data->end_mutex);
			mutex_unlock(&data->philos[i].meal_mutex);
			return ;
		}
		mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
}

void	check_if_full(t_data *data)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (data->nb_of_meals != -1)
	{
		while (i < data->nb_of_philos)
		{
			mutex_lock(&data->philos[i].meal_mutex);
			if (data->philos[i].meal_count >= (size_t)data->nb_of_meals)
				count++;
			mutex_unlock(&data->philos[i].meal_mutex);
			i++;
		}
		if (count == data->nb_of_philos)
		{
			mutex_lock(&data->end_mutex);
			data->end_philo = true;
			mutex_unlock(&data->end_mutex);
		}
	}
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		mutex_lock(&data->end_mutex);
		if (data->end_philo)
		{
			mutex_unlock(&data->end_mutex);
			break ;
		}
		mutex_unlock(&data->end_mutex);
		check_if_dead(data);
		check_if_full(data);
		usleep(500);
	}
	return (NULL);
}
