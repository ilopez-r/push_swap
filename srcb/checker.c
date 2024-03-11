/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:20:12 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/11 14:30:04 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_leaks(void)
{
	system("leaks -q checker");
}atexit(ft_leaks); */

static int	operation(char *line, t_data *data)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (swap(data, 'a', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "sb\n", 3))
		return (swap(data, 'b', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "ss\n", 3))
		return (swap(data, 's', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "pa\n", 3))
		return (push(data, 'a', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "pb\n", 3))
		return (push(data, 'b', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "ra\n", 3))
		return (rotate(data, 'a', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "rb\n", 3))
		return (rotate(data, 'b', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "rr\n", 3))
		return (rotate(data, 'r', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "rra\n", 4))
		return (r_rotate(data, 'a', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (r_rotate(data, 'b', 0), EXIT_SUCCESS);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (r_rotate(data, 'r', 0), EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	checker(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (operation(line, data) == 1)
			return (free (line), ft_printf("Error\n"), EXIT_FAILURE);
		free (line);
		line = get_next_line(0);
	}
	if (check_order(data) == 0 && data->lst_b == NULL)
		return (ft_printf("OK\n"), EXIT_SUCCESS);
	return (ft_printf("KO\n"), EXIT_FAILURE);
}

static void	init_struct(t_data *data)
{
	data->lst_a = NULL;
	data->lst_b = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit (EXIT_FAILURE);
	init_struct (data);
	if (check_arguments (argc, argv, data) == 1)
		exit (EXIT_FAILURE);
	if (check_numbers(-1, 0, 0, data) == 1)
		exit (EXIT_FAILURE);
	fill_and_assign(data);
	if (checker(data) == 1)
		exit(EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}
