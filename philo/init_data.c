/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:12:38 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/03 20:05:12 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_timer *timer_data, char **av)
{
	timer_data->nbr_philo = ft_atoi(av[1]);
	timer_data->time_to_die = ft_atoi(av[2]);
	timer_data->time_to_eat = ft_atoi(av[3]);
	timer_data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		if (ft_atoi(av[5]) == 0)
			return (1);
		timer_data->nb_eat = ft_atoi(av[5]);
	}
	else
		timer_data->nb_eat = -1;
	pthread_mutex_init(&timer_data->write, NULL);
	return (0);
}