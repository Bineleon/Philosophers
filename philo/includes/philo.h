/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:20:43 by bineleon          #+#    #+#             */
/*   Updated: 2024/12/27 20:20:29 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./constants.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

/* ╔════════════════════════════════════╗ */
/* ║             STRUCTURES             ║ */
/* ╚════════════════════════════════════╝ */

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef enum e_action
{
	eating,
	sleeping,
	thinking,
	dead
}			t_action;

typedef struct s_philo
{
	int			id;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		time_to_think;
	int			meal_count;
	int			l_fork;
	int			r_fork;
	t_action	action;
	pthread_t	philo;

}				t_philo;

typedef struct s_data
{
	size_t				nbr_of_philos;
	size_t				nbr_of_meals;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	t_philo				*philo;

}	 			t_data;

/* ╔════════════════════════════════════╗ */
/* ║	          FUNCTIONS             ║ */
/* ╚════════════════════════════════════╝ */

/* Utils */

int       ft_isdigit(int c);
t_bool    is_num(char *str);
long      ft_atoi(const char *nptr);
t_bool    valid_args(char **av);
t_bool    valid_num_args(int ac, char **av);
void      print_error(char *str);

#endif
