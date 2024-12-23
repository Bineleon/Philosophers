/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:20:43 by bineleon          #+#    #+#             */
/*   Updated: 2024/12/23 12:54:48 by bineleon         ###   ########.fr       */
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
}							t_bool;


typedef struct s_philo
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;

}             t_philo;

/* ╔════════════════════════════════════╗ */
/* ║              FUNCTIONS             ║ */
/* ╚════════════════════════════════════╝ */

/* Utils */

int       ft_isdigit(int c);
t_bool    is_num(char *str);
long      ft_atoi(const char *nptr);
t_bool    valid_args(char **av);
t_bool    valid_num_args(int ac, char **av);
void      print_error(char *str);

#endif
