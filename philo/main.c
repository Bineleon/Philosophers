/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:42:09 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 21:03:27 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

t_bool	check_args(int ac, char **av)
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

int	init_struct(t_data *data, t_philo *philos, pthread_mutex_t *forks,
		char **av)
{
	if (init_data(data, philos, av, forks) != 0)
		return (-1);
	if (init_philos(data))
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[201];
	pthread_mutex_t	forks[201];

	if (!check_args(ac, av))
		return (1);
	if (init_struct(&data, philos, forks, av) != 0)
		return (1);
	if (init_threads(&data) != 0)
	{
		full_clean(&data);
		return (1);
	}
	full_clean(&data);
	return (0);
}
