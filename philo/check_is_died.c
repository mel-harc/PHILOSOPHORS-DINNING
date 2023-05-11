/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:25:36 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/11 01:37:05 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_died(t_philo *philo, t_timer *time_data)
{
	t_philo	*tmp;

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
		pthread_mutex_lock(&tmp->data->lst);
		if (get_timer() - tmp->last_eating >= tmp->data->time_to_die)
		{
			printing(tmp, get_timer() - tmp->data->time_init, "died");
			pthread_mutex_unlock(&tmp->data->lst);
			burial_philo(tmp, time_data);
			return ;
		}
		pthread_mutex_unlock(&tmp->data->lst);
		if (!tmp->next)
			tmp = philo->head;
		tmp = tmp->next;
	}
}

int	check_nb_eat(t_philo *head)
{
	t_philo	*tmp;
	int		i;

	tmp = NULL;
	tmp = head;
	i = 0;
	while (tmp)
	{
		pthread_mutex_lock(&tmp->data->nbr);
		if (tmp->cnt_eat == tmp->data->nb_eat)
			i++;
		pthread_mutex_unlock(&tmp->data->nbr);
		tmp = tmp->next;
		if (tmp->id == tmp->data->nbr_philo)
			break ;
	}
	if (i == head->data->nbr_philo)
		return (1);
	else
		return (0);
}

void	burial_philo(t_philo *head, t_timer *data_time)
{
	t_philo	*tmp;
	t_philo	*tmp_2;

	tmp = NULL;
	tmp_2 = NULL;
	tmp = head->next;
	pthread_mutex_lock(&tmp->data->lst);
	pthread_mutex_destroy(&tmp->data->lst);
	pthread_mutex_lock(&tmp->data->nbr);
	pthread_mutex_destroy(&tmp->data->nbr);
	while (tmp)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		pthread_mutex_destroy(&tmp->fork);
		free(tmp_2);
		if (tmp == head)
			break ;
	}
	if (data_time->nbr_philo != 1)
		free(head);
	free(data_time);
	return ;
}
