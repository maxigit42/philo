/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:36:01 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/26 15:32:14 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_nbr(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
		return (ft_init_error("Invalid Nº of args"));
	i = 0;
	if (!check_args(argv))
		return (ft_init_error("Only numbers"));
	init_args(&data, argv, argc);
	if (data.nbr_philos == 1)
		init_one_philo(&data);
	else
		init_threads(&data);
	while (i < data.nbr_philos)
	{
		printf("%d\n", data.philo[i].meals);
		i++;
	}
	ft_destroy(&data);
	return (0);
}
