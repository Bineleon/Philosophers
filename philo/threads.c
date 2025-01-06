/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:11:34 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 15:11:23 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int init_threads(t_data *data)
{
    size_t i;

    i = 0;
    if (thread_create(&data->monitor, monitor_routine, data) != 0)
        return (-1);
    while (i < data->nb_of_philos)
    {
        if (thread_create(&data->philos[i].philo, philo_routine, &data->philos[i]) != 0)
            return (-1);
        i++;
    }
    thread_join(data->monitor);
    clean_philo(data);
    return (0);
}
