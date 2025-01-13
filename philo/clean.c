/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:40:59 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 20:41:03 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	clean_philo(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (thread_join(data->philos[i].philo) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	clean_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (mutex_destroy(&data->forks[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	clean_meal(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (mutex_destroy(&data->philos[i].meal_mutex) != 0)
			return (-1);
		i++;
	}
	return (0);
}

void	full_clean(t_data *data)
{
	if (clean_forks(data) != 0)
		return ;
	if (mutex_destroy(&data->print_mutex) != 0)
		return ;
	if (mutex_destroy(&data->end_mutex) != 0)
		return ;
	clean_meal(data);
}
