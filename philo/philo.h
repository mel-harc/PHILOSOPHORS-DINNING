/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:31:30 by mel-harc          #+#    #+#             */
/*   Updated: 2023/05/05 23:23:59 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<libc.h>
# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<pthread.h>
# include   <sys/time.h>

typedef	struct s_timer
{
	int	nbr_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	nb_eat;	
	pthread_mutex_t	write;
} t_timer;

typedef struct  s_philo
{
	int			id;
	pthread_mutex_t	fork;
	pthread_t		thread;
	struct s_philo	*next;
	struct s_timer	*data;
	int				time_init;
	struct s_philo	*head;
	int				cnt_eat;
	int				last_eating;
} t_philo;

int		parsing(char *str);
void	error(void);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		init_data(t_timer *data, char **av);
int		creat_philo(t_philo *philo, t_timer *timer_data);
void	init_mutex(t_philo *philo);
int		lst_add_back(t_timer *timer, t_philo *philo, t_philo *new_philo);
t_philo	*lstnew_philo(t_timer *philo, int i);
void	*routine(void *philo);
int		get_timer();
void	eating(t_philo *ph);
void	sleeping(t_philo *philo);
void	creat_thread(t_philo *philo, t_timer *timer);
void	waiting(t_philo *ph, int time, char type);
void	thinking(t_philo *philo);
void	printing(t_philo *ph, size_t time, char *str);
void	check_is_died(t_philo *philo);
int	check_nb_eat(t_philo *head);

#endif