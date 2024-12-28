/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:17:36 by bineleon          #+#    #+#             */
/*   Updated: 2024/12/28 20:25:28 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void  init_data(t_data *data, t_philo *philos, char **av, pthread_mutex_t *forks)
{
		data->nbr_of_philos = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
		    data->nbr_of_meals = ft_atoi(av[5]);
    else
        data->nbr_of_meals = -1;
		data->philos = philos;
    init_forks(data, forks);
    data->forks = forks;
}

void  init_forks(t_data *data, pthread_mutex_t *forks)
{
    size_t i;

    i = 0;
    printf("=== Init Forks ===\n");
    while (i < data->nbr_of_philos)
    {
      pthread_mutex_init(&forks[i], NULL);
      printf("Forks %zu : Initialized\n", i);
      i++;
    }
    printf("\n");
}

void  init_philos(t_data *data)
{
		size_t i;

    i = 0;
    while (i < data->nbr_of_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].meal_count = 0;
        data->philos[i].l_fork_idx = i;
        data->philos[i].r_fork_idx = (i + 1) % data->nbr_of_philos;
        data->philos[i].time_to_think = ((data->time_to_die - (data->time_to_eat + data->time_to_sleep)) / 2);
        if (data->philos[i].time_to_think < 0)
            data->philos[i].time_to_think = 0;
        i++;
    }
}
