/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:22:10 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/03 20:07:32 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork);
	// ft_write(ph, "take a fork", get_timer() - ph->time_init);
	pthread_mutex_lock(&ph->next->fork);
	// // ft_write(ph, "take a fork", get_timer() - ph->time_init);
	// // wait_for_eat(ph, get_timer());
	// pthread_mutex_unlock(&ph->fork);
	// pthread_mutex_unlock(&ph->next->fork);
	return ;
}

// void	sleep(t_philo *philo, t_timer *time)
// {
// 	pthread_mutex_lock(&philo->fork);
// 	printf("id : %d\tsleeping\n");
// 	ft_usleep(time->time_to_sleep);
// 	pthread_mutex_unlock(&philo->fork);
// 	return ;
// }

void	wait_for_eat(t_philo *ph, int time)
{
	while (1)
	{
		if (get_timer() - time < ph->timer->time_to_eat)
			usleep(1);
		else
			return ;
	}
	return ;
}

void	ft_write(t_philo *ph, char *str, size_t time)
{
	pthread_mutex_lock(&ph->timer->write);
	printf("%zu\t%d\t%s\n", time,ph->id, str);
	pthread_mutex_unlock(&ph->timer->write);
}