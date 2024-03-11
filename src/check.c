/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:20:31 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/11 11:45:25 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arguments(int argc, char **argv, t_data *data)
{
	if (argc == 1)
		return (ft_printf("Number of arguments error\n"), EXIT_FAILURE);
	if (argc == 2)
		data->arg = ft_split (argv[1], ' ');
	if (argc > 2)
		data->arg = argv + 1;
	return (EXIT_SUCCESS);
}

int	check_numbers(int i, int j, int r, t_data *data)
{
	while (data->arg[++i] != NULL)
	{
		j = 0;
		if (data->arg[i][j] == '-' || data->arg[i][j] == '+')
			j++;
		while (data->arg[i][j] != '\0')
		{
			if (ft_isdigit(data->arg[i][j]) == 0)
				return (ft_printf("Not a number error\n"), EXIT_FAILURE);
			j++;
		}
		if (ft_atoi(data->arg[i]) > INT_MAX || ft_atoi(data->arg[i]) < INT_MIN)
			return (ft_printf("Out of INT limits error\n"), EXIT_FAILURE);
		r = 0;
		j = -1;
		while (data->arg[++j] != NULL)
		{
			if (ft_atoi(data->arg[i]) == ft_atoi(data->arg[j]))
				r++;
			if (r == 2)
				return (ft_printf("Repeated number error\n"), EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_order(t_data *data)
{
	t_list	*aux;
	int		i;

	i = 1;
	aux = data->lst_a;
	while (i <= ft_lstsize(data->lst_a))
	{
		if (aux->index == i)
		{
			aux = aux->next;
			i++;
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
