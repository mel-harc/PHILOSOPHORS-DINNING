/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:25:36 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/08 17:50:22 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_died(t_philo *philo, t_timer *time_data)
{
	t_philo *tmp;
	
	tmp = NULL;
	tmp = philo->head;
	while (1)
	{
		usleep(1000);
		if (check_nb_eat(tmp))
		{
			burial_philo(tmp, time_data);
			return ;
		}
		if (get_timer() - tmp->last_eating >= tmp->data->time_to_die)
		{
			printing(tmp, get_timer() - tmp->data->time_init, "died");
			burial_philo(tmp, time_data);
			return ;
		}
		if (!tmp->next)
			tmp = philo->head;
		else
			tmp = tmp->next;
	}
}

int	check_nb_eat(t_philo *head)
{
	t_philo *tmp;
	int		i;

	tmp = NULL;
	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->cnt_eat == tmp->data->nb_eat)
			i++;
		tmp = tmp->next;
		if (!tmp)
			break ;
		if (tmp->id == tmp->data->nbr_philo)
			break ;
	}
	if (i == head->data->nbr_philo)
		return (1);
	return (0);
}

void	burial_philo(t_philo *head, t_timer *data_time)
{
	t_philo	*tmp;
	t_philo	*tmp_2;
	
	tmp = NULL;
	tmp_2 = NULL;
	tmp = head;
	while (tmp)
	{
		pthread_mutex_destroy(&tmp->fork);
		pthread_mutex_destroy(&tmp->data->write);
		tmp_2 = tmp;
		free(tmp);
		tmp = tmp_2->next;
		if (tmp == head)
			break ;
	}
	free(data_time);
	return ;
}