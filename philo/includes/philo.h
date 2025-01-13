/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:41:25 by neleon            #+#    #+#             */
/*   Updated: 2025/01/09 21:10:52 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./constants.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* ╔════════════════════════════════════╗ */
/* ║             STRUCTURES             ║ */
/* ╚════════════════════════════════════╝ */

typedef enum e_bool
{
	false,
	true
}					t_bool;

typedef enum e_action
{
	no_action,
	eat,
	taken_fork,
	dead
}					t_action;

typedef struct s_philo
{
	int				id;
	int				time_to_think;
	int				l_fork_idx;
	int				r_fork_idx;
	size_t			meal_count;
	size_t			last_meal;
	t_action		action;
	pthread_mutex_t	meal_mutex;
	pthread_t		philo;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_of_meals;
	long			start_time;
	t_bool			end_philo;
	size_t			nb_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
	t_philo			*philos;
	pthread_t		monitor;

}					t_data;

/* ╔════════════════════════════════════╗ */
/* ║             FUNCTIONS              ║ */
/* ╚════════════════════════════════════╝ */

/* Utils */

int					ft_isdigit(int c);
t_bool				is_num(char *str);
long				ft_atoi(const char *nptr);
t_bool				valid_args(char **av);
t_bool				valid_num_args(int ac, char **av);
void				print_error(char *str);
int					ft_putstr_fd(char *s, int fd);
void				print_status(t_philo *philo, char *status);
void				full_clean(t_data *data);
int					clean_philo(t_data *data);
char				*ft_itoa(int n);
int					ft_strcmp(const char *s1, const char *s2);

/* Time */

int					ft_usleep(size_t sleep_time);
long int			get_time(void);

/* Safe */

int					mutex_lock(pthread_mutex_t *mutex);
int					mutex_unlock(pthread_mutex_t *mutex);
int					mutex_destroy(pthread_mutex_t *mutex);
int					thread_create(pthread_t *thread, void *(*routine)(void *),
						void *arg);
int					thread_join(pthread_t thread);

/* Init struct */

int					init_forks(t_data *data, pthread_mutex_t *forks);
int					init_data(t_data *data, t_philo *philos, char **av,
						pthread_mutex_t *forks);
int					init_philos(t_data *data);

/* Routines */

void				*monitor_routine(void *arg);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);
void				*philo_routine(void *arg);

/* Threads */

int					init_threads(t_data *data);

#endif
