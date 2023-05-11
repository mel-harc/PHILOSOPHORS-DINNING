/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:52:15 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/10 18:05:58 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(void)
{
	write(1, "Error : invalid args\n", 21);
	return ;
}

void	printing(t_philo *ph, size_t time, char *str)
{	
	pthread_mutex_lock(&ph->data->write);
	printf("%zu\t%d\t%s\n", time, ph->id, str);
	pthread_mutex_unlock(&ph->data->write);
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
