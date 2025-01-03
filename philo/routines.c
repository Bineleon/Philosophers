/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:53:03 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/03 18:01:01 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void eat(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&data->forks[philo->r_fork_idx]);
    print_status(philo, "has taken a fork");
    if (data->nb_of_philos == 1)
    {
        ft_usleep(data->time_to_die);
        pthread_mutex_unlock(&data->forks[philo->r_fork_idx]);
        return;
    }
    pthread_mutex_lock(&data->forks[philo->l_fork_idx]);
    print_status(philo, "has taken a fork");
    philo->action = eating;
    philo->last_meal = get_time();
    print_status(philo, "is eating");
    ft_usleep(data->time_to_eat);
    philo->meal_count++;
    pthread_mutex_unlock(&data->forks[philo->l_fork_idx]);
    pthread_mutex_unlock(&data->forks[philo->r_fork_idx]);
}

void sleep_philo(t_philo *philo)
{
    philo->action = sleeping;
    print_status(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep);
}

void think(t_philo *philo)
{
    philo->action = thinking;
    print_status(philo, "is thinking");
    ft_usleep(philo->time_to_think);
}

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
		    ft_usleep(philo->data->time_to_eat - 100);
    while (!philo->data->end_philo)
    {
        eat(philo);
        sleep_philo(philo);
        think(philo);
    }
    return (NULL);
}
