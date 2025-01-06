/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:53:03 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 18:51:58 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void    assign_fork(t_philo *philo, int *first_fork, int *sd_fork)
{
    if (philo->l_fork_idx < philo->r_fork_idx)
    {
        *first_fork = philo->l_fork_idx;
        *sd_fork = philo->r_fork_idx;
    }
    else
    {
        *first_fork = philo->r_fork_idx;
        *sd_fork = philo->l_fork_idx;
    }
}

t_bool    single_philo(t_data *data, t_philo *philo, int first_fork)
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

void    close_mutex(t_philo *philo, t_data *data, int sd_fork, int first_fork)
{
    mutex_unlock(&philo->meal_mutex);
    mutex_unlock(&data->forks[sd_fork]);
    mutex_unlock(&data->forks[first_fork]);
}

void    philo_eat(t_philo *philo)
{
    t_data *data;
    int first_fork;
    int sd_fork;

    data = philo->data;
    assign_fork(philo, &first_fork, &sd_fork);
    if (mutex_lock(&data->forks[first_fork]) != 0)
        return;
    print_status(philo, "has taken a fork");
    if (single_philo(data, philo, first_fork))
        return;
    if (mutex_lock(&data->forks[sd_fork]) != 0)
    {
        mutex_unlock(&data->forks[first_fork]);
        return;
    }
    print_status(philo, "has taken a fork");
    mutex_lock(&philo->meal_mutex);
    philo->last_meal = get_time();
    mutex_unlock(&philo->meal_mutex);
    print_status(philo, "is eating");
    ft_usleep(data->time_to_eat);
    mutex_lock(&philo->meal_mutex);
    philo->meal_count++;
    close_mutex(philo, data, sd_fork, first_fork);
}
