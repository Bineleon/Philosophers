/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:41:46 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 22:31:56 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static t_bool	is_overflow(t_data *data, char **av)
{
	char	*res;
	int		i;
	int		values[5];

	i = 0;
	values[0] = data->nb_of_philos;
	values[1] = data->time_to_die;
	values[2] = data->time_to_eat;
	values[3] = data->time_to_sleep;
	if (av[5])
		values[4] = data->nb_of_meals;
	else
		values[4] = -1;
	while (i < 4 || (i == 4 && av[5]))
	{
		res = ft_itoa(values[i]);
		if (!res || ft_strcmp(res, av[i + 1]) != 0)
		{
			free(res);
			return (true);
		}
		free(res);
		i++;
	}
	return (false);
}

static void	parsing(t_data *data, char **av)
{
	data->nb_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_of_meals = ft_atoi(av[5]);
	else
		data->nb_of_meals = -1;
}

int	init_data(t_data *data, t_philo *philos, char **av, pthread_mutex_t *forks)
{
	parsing(data, av);
	if (is_overflow(data, av))
		return (-1);
	data->philos = philos;
	data->end_philo = false;
	init_forks(data, forks);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		print_error("Error: pthread_mutex_init()\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->end_mutex, NULL) != 0)
	{
		print_error("Error: pthread_mutex_init()\n");
		return (-1);
	}
	data->start_time = get_time();
	data->forks = forks;
	return (0);
}

int	init_forks(t_data *data, pthread_mutex_t *forks)
{
	size_t	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			print_error("Error: pthread_mutex_init()\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].l_fork_idx = i;
		data->philos[i].r_fork_idx = (i + 1) % data->nb_of_philos;
		data->philos[i].time_to_think = ((data->time_to_die - (data->time_to_eat
						+ data->time_to_sleep)) / 2);
		if (data->philos[i].time_to_think < 0)
			data->philos[i].time_to_think = 0;
		data->philos[i].action = no_action;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
		{
			print_error("Error: pthread_mutex_init()\n");
			return (-1);
		}
		data->philos[i].last_meal = get_time();
		i++;
	}
	return (0);
}
