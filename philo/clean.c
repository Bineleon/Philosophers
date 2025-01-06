/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:17:54 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 18:15:49 by bineleon         ###   ########.fr       */
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

int clean_forks(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        if (mutex_destroy(&data->forks[i]) != 0)
            return (-1);
        i++;
    }
    return (0);
}

int clean_meal(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        if (mutex_destroy(&data->philos[i].meal) != 0)
            return (-1);
        i++;
    }
    return (0);

}

void full_clean(t_data *data)
{
    if (clean_forks(data) != 0)
        return;
    if (mutex_destroy(&data->print_mutex) != 0)
        return;
    if (mutex_destroy(&data->end_mutex) != 0)
        return;
    clean_meal(data);
}
