/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:17:36 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 18:03:32 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void  init_data(t_data *data, t_philo *philos, char **av, pthread_mutex_t *forks)
{
		data->nb_of_philos = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);

    if (av[5])
		    data->nb_of_meals = ft_atoi(av[5]);
    else
        data->nb_of_meals = -1;
		data->philos = philos;
    data->end_philo = false;
    init_forks(data, forks);
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
    {
        print_error("Error: pthread_mutex_init()\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_mutex_init(&data->end_mutex, NULL) != 0)
    {
        print_error("Error: pthread_mutex_init()\n");
        exit(EXIT_FAILURE);
    }
    data->start_time = get_time();
    data->forks = forks;
    // printf("DEBUG: Pointer to philos = %p\n", (void *)data->philos);
}

void  init_forks(t_data *data, pthread_mutex_t *forks)
{
    size_t i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
        {
            print_error("Error: pthread_mutex_init()\n");
            exit(EXIT_FAILURE);
        }
        // printf("Forks %zu : Initialized\n", i);
        i++;
    }
}

void  init_philos(t_data *data)
{
		size_t i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].meal_count = 0;
        data->philos[i].l_fork_idx = i;
        data->philos[i].r_fork_idx = (i + 1) % data->nb_of_philos;
        data->philos[i].time_to_think = ((data->time_to_die - (data->time_to_eat + data->time_to_sleep)) / 2);
        if (data->philos[i].time_to_think < 0)
            data->philos[i].time_to_think = 0;
        data->philos[i].action = no_action;
        data->philos[i].data = data;
        if (pthread_mutex_init(&data->philos[i].meal, NULL) != 0)
        {
            print_error("Error: pthread_mutex_init()\n");
            exit(EXIT_FAILURE);
        }
        data->philos[i].last_meal = get_time();
        i++;
    }
}
