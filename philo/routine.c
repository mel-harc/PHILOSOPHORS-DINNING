/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:22:10 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/10 17:38:08 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork);
	printing(ph, get_timer() - ph->data->time_init, "has taken a fork");
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
