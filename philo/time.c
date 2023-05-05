/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:44:48 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/05 08:19:14 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timer()
{
	int	time_now;
	struct  timeval time;

	if (gettimeofday(&time, NULL))
		printf("gettimeofday is Faillure\n");
	time_now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_now);
}
