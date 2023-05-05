/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:25:36 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/05 23:30:00 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_died(t_philo *philo)
{
	t_philo *tmp;
	
	tmp = NULL;
	tmp = philo->head;
	while (1)
	{
		usleep(1000);
		if (check_nb_eat(philo->head))
			return ;
		if (get_timer() - tmp->last_eating >= tmp->data->time_to_die)
		{
			printing(tmp, get_timer() - tmp->time_init, "died");
			return ;
		}
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
	while (tmp && tmp != head)
	{
		if (tmp->cnt_eat == tmp->data->nb_eat)
		{
			tmp = tmp->next;
			i++;
		}
		else
			return (0);
	}
	if (i == head->data->nbr_philo)
		return (1);
	return (0);
}