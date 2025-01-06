/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:53:03 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 17:00:18 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void  assign_fork(t_philo *philo, int *first_fork, int *snd_fork)
{
    if (philo->l_fork_idx < philo->r_fork_idx)
    {
        *first_fork = philo->l_fork_idx;
        *snd_fork = philo->r_fork_idx;
    }
    else
    {
        *first_fork = philo->r_fork_idx;
        *snd_fork = philo->l_fork_idx;
    }
}

t_bool single_philo(t_data *data, t_philo *philo, int first_fork)
{
    if (data->nb_of_philos == 1)
    {
        philo->action = taken_fork;
        ft_usleep(data->time_to_die);
        mutex_unlock(&data->forks[first_fork]);
        return (true);
    }
    return (false);
}

void philo_eat(t_philo *philo)
{
    t_data *data;
    int first_fork;
    int snd_fork;

    data = philo->data;
    assign_fork(philo, &first_fork, &snd_fork);
    if (mutex_lock(&data->forks[first_fork]) != 0)
        return;
    print_status(philo, "has taken a fork");
    if (single_philo(data, philo, first_fork))
        return;
    if (mutex_lock(&data->forks[snd_fork]) != 0)
    {
        mutex_unlock(&data->forks[first_fork]);
        return;
    }
    print_status(philo, "has taken a fork");
    mutex_lock(&philo->meal);
    philo->last_meal = get_time();
    mutex_unlock(&philo->meal);
    print_status(philo, "is eating");
    ft_usleep(data->time_to_eat);
    philo->meal_count++;
    mutex_unlock(&data->forks[snd_fork]);
    mutex_unlock(&data->forks[first_fork]);
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
