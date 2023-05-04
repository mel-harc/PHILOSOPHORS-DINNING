/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:44:51 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/04 23:42:05 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_thread(t_philo *philo, t_timer *timer)
{
	t_philo	*tmp;
	
	tmp = philo->head;
	while (tmp)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->thread, NULL, routine, tmp);
		pthread_detach(tmp->thread);
		if (tmp->id == timer->nbr_philo)
			break ;
		tmp = tmp->next;
	}
	return ;
}

void	*routine(void *philo)
{
	t_philo	*ph;
	ph = philo;
	ph->time_init = get_timer();
	ph->last_eating = get_timer();
	if (ph->id % 2 == 0)
		usleep(100);
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}