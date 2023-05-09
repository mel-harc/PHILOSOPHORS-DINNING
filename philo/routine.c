/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:22:10 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/09 22:11:13 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork);
	printing(ph, get_timer() - ph->data->time_init , "has taken a fork");
	if (!ph->next)
	{
		waiting(ph, get_timer(), 'm');
		return ;
	}
	pthread_mutex_lock(&ph->next->fork);
	printing(ph, get_timer() - ph->data->time_init, "has taken a fork");
	printing(ph, get_timer() - ph->data->time_init, "is eating");
	waiting(ph, get_timer(), 'e');
	
	count(ph);
	lasteat(ph);
	
	pthread_mutex_unlock(&ph->next->fork);
	pthread_mutex_unlock(&ph->fork);
}

void	lasteat(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->lst);
	ph->last_eating = get_timer();
	pthread_mutex_unlock(&ph->data->lst);
}

void	count(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->nbr);
	ph->cnt_eat++;
	pthread_mutex_unlock(&ph->data->nbr);
}

void	sleeping(t_philo *philo)
{
	printing(philo, get_timer() - philo->data->time_init, "is sleeping");
	waiting(philo, get_timer(), 's');
}

void	thinking(t_philo *philo)
{
	printing(philo, get_timer() - philo->data->time_init, "is thinking");
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
		else if (type == 'm')
		{
			if (get_timer() - time >= ph->data->time_to_die)
				break ;
		}
		else if (type == 's')
		{
			if (get_timer() - time >= ph->data->time_to_sleep)
				break ;
		}
		usleep(500);
	}
}

void	printing(t_philo *ph, size_t time, char *str)
{	
	pthread_mutex_lock(&ph->data->write);
	printf("%zu\t%d\t%s\n", time, ph->id, str);
	pthread_mutex_unlock(&ph->data->write);
}