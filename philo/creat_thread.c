/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:44:51 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/10 17:43:26 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	pthread_mutex_lock(&ph->data->lst);
	ph->last_eating = get_timer();
	pthread_mutex_unlock(&ph->data->lst);
	if (ph->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
}

void	creat_thread(t_philo *philo, t_timer *timer)
{
	t_philo	*tmp;

	tmp = philo->head;
	timer->time_init = get_timer();
	pthread_mutex_init(&tmp->data->nbr, NULL);
	pthread_mutex_init(&tmp->data->wait, NULL);
	pthread_mutex_init(&tmp->data->write, NULL);
	pthread_mutex_init(&tmp->data->lst, NULL);
	while (tmp)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		pthread_detach(tmp->thread);
		if (tmp->id == timer->nbr_philo)
			break ;
		tmp = tmp->next;
	}
	return ;
}
