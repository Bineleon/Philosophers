/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:20:43 by bineleon          #+#    #+#             */
/*   Updated: 2024/12/28 20:14:24 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./constants.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


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
	int							id;
	int					time_to_think;
	size_t					meal_count;
	int							l_fork_idx;
	int							r_fork_idx;
	t_action				action;
	pthread_t				philo;

}									t_philo;

typedef struct s_data
{
	int   						nbr_of_meals;
	size_t						nbr_of_philos;
  size_t						time_to_die;
	size_t						time_to_eat;
	size_t						time_to_sleep;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	t_philo				*philos;

}					t_data;

/* ╔════════════════════════════════════╗ */
/* ║	          FUNCTIONS             ║ */
/* ╚════════════════════════════════════╝ */

/* Utils */

int				ft_isdigit(int c);
t_bool    is_num(char *str);
long      ft_atoi(const char *nptr);
t_bool    valid_args(char **av);
t_bool    valid_num_args(int ac, char **av);
void      print_error(char *str);
int       ft_putstr_fd(char *s, int fd);

/* Time */

int ft_usleep(size_t sleep_time);
long int get_current_time(void);

/* Init struct */

void  init_forks(t_data *data, pthread_mutex_t *forks);
void  init_data(t_data *data, t_philo *philos, char **av, pthread_mutex_t *forks);
void  init_philos(t_data *data);
#endif
