/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:17:54 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/04 18:11:55 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int clean_philo(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        if (thread_join(data->philos[i].philo) != 0)
            return (-1);
        i++;
    }
    return (0);
}

void clean_forks(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        mutex_destroy(&data->forks[i]);
        i++;
    }
}
void full_clean(t_data *data)
{
    thread_join(data->monitor);
    clean_philo(data);
    clean_forks(data);
    mutex_destroy(&data->print_lock);
}