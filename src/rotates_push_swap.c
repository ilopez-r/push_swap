/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:09:17 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/11 14:41:08 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation(t_list **lst, int flag)
{
	t_list	*aux;
	t_list	*last;

	aux = *lst;
	if (flag == 1 && ft_lstsize(aux) >= 2)
	{
		*lst = (*lst)->next;
		aux->next = NULL;
		ft_lstadd_back(lst, aux);
	}
	if (flag == 2 && ft_lstsize(aux) >= 2)
	{
		last = ft_lstlast(*lst);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(lst, last);
	}
	if (flag == 3 && ft_lstsize(aux) >= 2)
	{
		*lst = (*lst)->next;
		aux->next = (*lst)->next;
		(*lst)->next = aux;
	}
}

void	swap(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		operation(&data->lst_a, 3);
		if (flag)
			ft_printf("sa\n");
	}
	if (c == 'b')
	{
		operation(&data->lst_b, 3);
		if (flag)
			ft_printf("sb\n");
	}
	if (c == 's')
	{
		operation(&data->lst_a, 3);
		operation(&data->lst_b, 3);
		if (flag)
			ft_printf("ss\n");
	}
}

void	rotate(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		operation(&data->lst_a, 1);
		if (flag)
			ft_printf("ra\n");
	}
	if (c == 'b')
	{
		operation(&data->lst_b, 1);
		if (flag)
			ft_printf("rb\n");
	}
	if (c == 'r')
	{
		operation(&data->lst_a, 1);
		operation(&data->lst_b, 1);
		if (flag)
			ft_printf("rr\n");
	}
}

void	r_rotate(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		operation(&data->lst_a, 2);
		if (flag)
			ft_printf("rra\n");
	}
	if (c == 'b')
	{
		operation(&data->lst_b, 2);
		if (flag)
			ft_printf("rrb\n");
	}
	if (c == 'r')
	{
		operation(&data->lst_a, 2);
		operation(&data->lst_b, 2);
		if (flag)
			ft_printf("rrr\n");
	}
}

void	push(t_data *data, char c, int flag)
{
	t_list	*aux;
	t_list	**src;
	t_list	**dst;

	if (c == 'a' && ft_lstsize(data->lst_b) >= 1)
	{
		src = &data->lst_b;
		dst = &data->lst_a;
		aux = *src;
		*src = (*src)->next;
		ft_lstadd_front(dst, aux);
		if (flag)
			ft_printf("pa\n");
	}
	if (c == 'b' && ft_lstsize(data->lst_a) >= 1)
	{
		src = &data->lst_a;
		dst = &data->lst_b;
		aux = *src;
		*src = (*src)->next;
		ft_lstadd_front(dst, aux);
		if (flag)
			ft_printf("pb\n");
	}
}
