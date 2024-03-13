/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:20:36 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/11 12:47:10 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_leaks(void)
{
	system("leaks -q push_swap");
}atexit(ft_leaks); */

/*void	lst_print_list_s(t_list *lst)
{
	int	num_len;

	num_len = ft_strlen(ft_itoa(lst->value));
	ft_printf("%i", lst->value);
	while (num_len < 3)
	{
		ft_printf(" ");
		num_len++;
	}
	ft_printf("    %i     %i ", lst->index, lst->position);
	ft_printf("    %i    ", lst->t_position);
	num_len = ft_strlen(ft_itoa(lst->cost_a));
	while (num_len < 3)
	{
		ft_printf(" ");
		num_len++;
	}
	ft_printf("%i   ", lst->cost_a);
	num_len = ft_strlen(ft_itoa(lst->cost_b));
	while (num_len < 3)
	{
		ft_printf(" ");
		num_len++;
	}
	ft_printf("%i    ", lst->cost_b);
	ft_printf("%i\n", lst->t_cost);
}

void	lst_print_structs(t_list **lst_a, t_list **lst_b)
{
	t_list	*pos_a;
	t_list	*pos_b;

	pos_a = *lst_a;
	pos_b = *lst_b;
	ft_printf("\n** Stack A **\n");
	ft_printf("NUM   IND   POS   TAR   C-A   C-B    T-C\n");
	while (pos_a)
	{
		lst_print_list_s(pos_a);
		pos_a = pos_a->next;
	}
	ft_printf("\n** Stack B **\n");
	ft_printf("NUM   IND   POS   TAR   C-A   C-B    T-C\n");
	while (pos_b)
	{
		lst_print_list_s(pos_b);
		pos_b = pos_b->next;
	}
	ft_printf("\n");
}lst_print_structs(&data->lst_a, &data->lst_b); */

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
	if (check_order(data) == 0)
		exit (EXIT_FAILURE);
	select_algorithm(data);
	exit (EXIT_SUCCESS);
}
