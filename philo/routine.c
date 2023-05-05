/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:22:10 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/05 22:58:41 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	size_t	time_now;
	
	time_now = get_timer();
	pthread_mutex_lock(&ph->fork);
	printing(ph, time_now - ph->time_init , "has taken a fork");
	pthread_mutex_lock(&ph->next->fork);
	printing(ph, time_now - ph->time_init, "has taken a fork");
	printing(ph, time_now - ph->time_init, "is eating");
	waiting(ph, time_now, 'e');
	ph->cnt_eat++;
	ph->last_eating = get_timer();
	pthread_mutex_unlock(&ph->next->fork);
	pthread_mutex_unlock(&ph->fork);
}

void	sleeping(t_philo *philo)
{
	printing(philo, get_timer() - philo->time_init, "is sleeping");
	waiting(philo, get_timer(), 's');
}

void	thinking(t_philo *philo)
{
	printing(philo, get_timer() - philo->time_init, "is thinking");
}

void	waiting(t_philo *ph, int time, char type)
{
	while (1)
	{
		if (type == 'e')
		{
			if (get_timer() - time >= ph->data->time_to_eat)
				break ;
		}
		else
		{
			if (get_timer() - time >= ph->data->time_to_sleep)
				break ;
		}
		usleep(200);
	}
}

void	printing(t_philo *ph, size_t time, char *str)
{	
	pthread_mutex_lock(&ph->data->write);
	printf("%zu\t%d\t%s\n", time, ph->id, str);
	pthread_mutex_unlock(&ph->data->write);
}