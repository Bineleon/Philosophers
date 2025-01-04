/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:49 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/04 17:24:45 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int mutex_lock(pthread_mutex_t *mutex)
{
    if (pthread_mutex_lock(mutex) != 0)
    {
        print_error("Error: pthread_mutex_lock()\n");
        return (-1);
    }
    return (0);
}

int mutex_unlock(pthread_mutex_t *mutex)
{
    if (pthread_mutex_unlock(mutex) != 0)
    {
        print_error("Error: pthread_mutex_unlock()\n");
        return (-1);
    }
    return (0);
}

int mutex_destroy(pthread_mutex_t *mutex)
{
    if (pthread_mutex_destroy(mutex) != 0)
    {
        print_error("Error: pthread_mutex_destroy()\n");
        return (-1);
    }
    return (0);
}

int thread_create(pthread_t *thread, void *(*routine)(void *), void *arg)
{
    if (pthread_create(thread, NULL, routine, arg) != 0)
    {
        print_error("Error: pthread_create()\n");
        return (-1);
    }
    return (0);
}

int thread_join(pthread_t thread)
{
    if (pthread_join(thread, NULL) != 0)
    {
        print_error("Error: pthread_join()\n");
        return (-1);
    }
    return (0);
}