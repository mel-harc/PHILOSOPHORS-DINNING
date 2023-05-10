/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:31:28 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/10 16:57:22 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		i;
	t_timer	*timer_data;
	t_philo	philo;

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
		if (init_data(timer_data, av) || creat_philo(&philo, timer_data))
			return (-1);
		creat_thread(&philo, timer_data);
		check_is_died(&philo, timer_data);
	}
	return (0);
}
