/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:02:50 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 12:08:49 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void  check_if_dead(t_data *data)
{
    size_t  i;

    i = 0;
    while (i < data->nb_of_philos)
    {
        mutex_lock(&data->philos[i].meal);
        if ((get_time() - data->philos[i].last_meal) > data->time_to_die)
        {
            print_status(&data->philos[i], "is dead");
            data->end_philo = true;
            mutex_unlock(&data->philos[i].meal);
            return;
        }
        mutex_unlock(&data->philos[i].meal);
        i++;
    }
}

void  check_if_full(t_data *data)
{
    size_t  count;
    size_t  i;

    count = 0;
    i = 0;
    if (data->nb_of_meals != -1)
    {
        while (i < data->nb_of_philos)
        {
            if (data->philos[i].meal_count >= (size_t)data->nb_of_meals)
                count++;
            i++;
        }
        if (count == data->nb_of_philos)
            data->end_philo = true;
    }
}

void *monitor_routine(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    printf("DEBUG: Monitor starting at time %ld\n", get_time());
    while (!data->end_philo)
    {
        check_if_dead(data);
        check_if_full(data);
        usleep(1000);
    }
    return (NULL);
}
