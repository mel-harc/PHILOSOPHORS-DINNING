/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:44:48 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/04 15:35:08 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_timer()
{
	size_t	time_now;
	struct  timeval time;

	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_now);
}
