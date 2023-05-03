/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:31:28 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/03 19:44:59 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		i;
	t_timer	*timer_data;
	t_philo	philo;
	// t_philo	*tmp;
	
	i = 1;
	timer_data = NULL;
	if (ac == 5 || ac == 6)
	{
		while (av[i])
			if (parsing(av[i++]))
				return (error(), 1);
		timer_data = (t_timer *)malloc(sizeof(t_timer));
		if (!timer_data)
			return (-1);
		if(init_data(timer_data, av) || creat_philo(&philo, timer_data))
			return (-1);
		// init_mutex(&philo);
		creat_thread(&philo);
		return (0);	
	}
	else
		error();
	// printf("%d\n", timer_data->nbr_philo);
	// printf("%d\n", timer_data->time_to_die);
	// printf("%d\n", timer_data->time_to_eat);
	// printf("%d\n", timer_data->time_to_sleep);
	// printf("%d\n", timer_data->number_of_times_each_philosopher_must_eat);
	// tmp = philo.head;
	// while (tmp)
	// {
	// 	printf("id : %d\n", tmp->id);
	// 	tmp = tmp->next;
	// }
	return (0);
}