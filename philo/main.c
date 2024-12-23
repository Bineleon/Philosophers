/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:48:16 by bineleon          #+#    #+#             */
/*   Updated: 2024/12/23 12:51:23 by bineleon         ###   ########.fr       */
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

int main(int ac, char **av)
{
    if (!check_args(ac, av))
      exit(EXIT_FAILURE);
    return (0);
}
