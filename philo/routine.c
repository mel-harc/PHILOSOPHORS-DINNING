/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:22:10 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/04 23:41:50 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	size_t	time_now;
	
	time_now = get_timer();
	pthread_mutex_lock(&ph->fork);
	printing(ph, time_now - ph->time_init , "take a fork left");
	pthread_mutex_lock(&ph->next->fork);
	printing(ph, time_now - ph->time_init, "take a fork right");
	printing(ph, time_now - ph->time_init, "is eating");
	waiting(ph, time_now);
	ph->cnt_eat++;
	ph->last_eating = get_timer();
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(&ph->next->fork);
	return ;
}

void	sleeping(t_philo *philo)
{
	size_t	time_now;
	
	time_now = get_timer();
	printing(philo, time_now - philo->time_init, "is sleeping");
	waiting(philo, time_now);
	return ;
}

void	thinking(t_philo *philo)
{
	size_t	time_now;
	
	time_now = get_timer();
	printing(philo, time_now - philo->time_init, "is thinking");
}

void	waiting(t_philo *ph, int time)
{
	size_t	time_now;

	time_now = get_timer();
	while (time_now - time < ph->data->time_to_eat)
		usleep(1);
	return ;
}

void	printing(t_philo *ph, size_t time, char *str)
{	
	pthread_mutex_lock(&ph->data->write);
	printf("%zu\t%d\t%s\n", time, ph->id, str);
	pthread_mutex_unlock(&ph->data->write);
}