/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:53:03 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 12:09:02 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void philo_eat(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    if (mutex_lock(&data->forks[philo->r_fork_idx]) != 0)
        return;
    print_status(philo, "has taken a fork");
    if (data->nb_of_philos == 1)
    {
        ft_usleep(data->time_to_die);
        mutex_unlock(&data->forks[philo->r_fork_idx]);
        return;
    }
    if (mutex_lock(&data->forks[philo->l_fork_idx]) != 0)
    {
        mutex_unlock(&data->forks[philo->r_fork_idx]);
        return;
    }
    print_status(philo, "has taken a fork");
    philo->action = eat;
    mutex_lock(&philo->meal);
    philo->last_meal = get_time();
    mutex_unlock(&philo->meal);
    print_status(philo, "is eating");
    ft_usleep(data->time_to_eat);
    philo->meal_count++;
    mutex_unlock(&data->forks[philo->l_fork_idx]);
    mutex_unlock(&data->forks[philo->r_fork_idx]);
}

void philo_sleep(t_philo *philo)
{
    philo->action = sleepy;
    print_status(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep);
}

void philo_think(t_philo *philo)
{
    philo->action = think;
    print_status(philo, "is thinking");
    ft_usleep(philo->time_to_think);
}

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
		    ft_usleep(100);
    while (!philo->data->end_philo)
    {
        philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
    }
    return (NULL);
}
