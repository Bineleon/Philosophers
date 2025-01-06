/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:05:54 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 10:56:20 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

long int get_time(void)
{
    struct timeval t;

    if (gettimeofday(&t, NULL) != 0)
    {
        ft_putstr_fd("error : gettimeofday()\n", 2);
        return (-1);
    }
    return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int ft_usleep(size_t sleep_time)
{
    long int start_time;
    long int end_time;

    start_time = get_time();
    end_time = start_time + sleep_time;
    while (get_time() < end_time)
        usleep(100);
    return (0);
}
