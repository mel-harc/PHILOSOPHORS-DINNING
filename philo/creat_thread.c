/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:44:51 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/03 20:06:53 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_thread(t_philo *philo)
{
	t_philo	*tmp;
	
	tmp = philo->head;
	philo->time_init = get_timer();
	while (tmp)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->thread, NULL, routine, tmp);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
	return ;
}

void	*routine(void *philo)
{
	t_philo	*ph;
	ph = (t_philo *)philo;
	if (ph->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eat(ph);
	// 	sleep(ph);
	// 	think(ph);
	}
	return (NULL);
}