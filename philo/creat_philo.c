/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:09:14 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/04 21:29:47 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creat_philo(t_philo *philo, t_timer *timer_data)
{
	int	i;
	
	i = 1;
	philo->head = NULL;
	while (i <= timer_data->nbr_philo)
		if (lst_add_back(timer_data, philo, lstnew_philo(timer_data, i++)))
			return (1);
	return (0);
}

t_philo	*lstnew_philo(t_timer *data, int i)
{
	t_philo	*init_philo;
	
	init_philo = (t_philo *)malloc(sizeof(t_philo));
	if (!init_philo)
		return (NULL);
	init_philo->id = i;
	init_philo->data = data;
	init_philo->cnt_eat = 0;
	init_philo->next = NULL;
	return (init_philo);
}

int	lst_add_back(t_timer *timer, t_philo *philo, t_philo *new_philo)
{
	t_philo *tmp;

	tmp = NULL;
	if (!new_philo)
		return (1);
	if (!philo->head)
		philo->head = new_philo;
	else
	{
		tmp = philo->head;
		while (tmp)
		{
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp->next = new_philo;
		if (new_philo->id == timer->nbr_philo)
			new_philo->next = philo->head;
	}
	return (0);
}