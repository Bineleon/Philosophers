/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:48:16 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/03 16:02:07 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

t_bool check_args(int ac, char **av)
{
    if (ac < 5 || ac > 6)
    {
        print_error("Program should have 4 or 5 arguments\n");
        return (false);
    }
    if (!valid_args(av))
    {
        print_error("Numeric arguments requiered%s\n");
        return (false);
    }
    if (!valid_num_args(ac, av))
        return (false);
    return (true);
}

void  init_struct(t_data *data, t_philo *philos, pthread_mutex_t *forks, char **av)
{
    init_data(data, philos, av, forks);
    init_philos(data);
}

void print_init(t_data *data)
{
    size_t i;

    i = 0;
    printf("=== Philo init ===\n");
    printf("nb of philos: %zu\n", data->nb_of_philos);
    printf("Time to die: %zu\n", data->time_to_die);
    printf("Time to eat: %zu\n", data->time_to_eat);
    printf("Time to sleep: %zu\n", data->time_to_sleep);
    printf("nb of meals: %d\n\n", data->nb_of_meals);
    while (i < data->nb_of_philos)
    {
        printf("Philo %d:\n", data->philos[i].id);
        printf("  Left fork: %d\n", data->philos[i].l_fork_idx);
        printf("  Right fork: %d\n", data->philos[i].r_fork_idx);
        printf("  Number of meals: %zu\n", data->philos[i].meal_count);
        printf("  Time to think: %d\n", data->philos[i].time_to_think);
        printf("\n");
        i++;
    }
}


int main(int ac, char **av)
{
    t_data            data;
    t_philo           philos[201];
    pthread_mutex_t   forks[201];

    if (!check_args(ac, av))
      exit(EXIT_FAILURE);
    init_struct(&data, philos, forks, av);
    print_init(&data);
    return (0);
}
