/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:48:16 by bineleon          #+#    #+#             */
/*   Updated: 2025/01/06 11:49:34 by bineleon         ###   ########.fr       */
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
        print_error("Numeric arguments requiered\n");
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

void test_ft_usleep(void)
{
    long start, end, diff;

    printf("Testing ft_usleep...\n");

    start = get_time();
    ft_usleep(100); // Pause de 100 ms
    end = get_time();

    diff = end - start;

    printf("DEBUG: Expected sleep time = 100ms, Actual sleep time = %ldms\n", diff);

    start = get_time();
    ft_usleep(1000); // Pause de 1000 ms
    end = get_time();

    diff = end - start;

    printf("DEBUG: Expected sleep time = 1000ms, Actual sleep time = %ldms\n", diff);
}


int main(int ac, char **av)
{
    printf("MAIN\n");
    fflush(stdout);
    t_data            data;
    t_philo           philos[201];
    pthread_mutex_t   forks[201];

    if (!check_args(ac, av))
      exit(EXIT_FAILURE);
    // test_ft_usleep();
    init_struct(&data, philos, forks, av);
    if (init_threads(&data) != 0)
    {
        full_clean(&data);
        return (EXIT_FAILURE);
    }
    full_clean(&data);
    // print_init(&data);
    return (0);
}
