/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:26:31 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/09 12:59:44 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotates_simples(t_data *data, t_list *c)
{
	while (c->cost_a < 0)
	{
		r_rotate(data, 'a', 1);
		c->cost_a++;
	}
	while (c->cost_b < 0)
	{
		r_rotate(data, 'b', 1);
		c->cost_b++;
	}
	while (c->cost_a > 0)
	{
		rotate(data, 'a', 1);
		c->cost_a--;
	}
	while (c->cost_b > 0)
	{
		rotate(data, 'b', 1);
		c->cost_b--;
	}
}

t_list	*rotates_doubles(t_data *data, t_list *c)
{
	while (c->cost_a < 0 && c->cost_b < 0)
	{
		r_rotate(data, 'r', 1);
		c->cost_a++;
		c->cost_b++;
	}
	while (c->cost_a > 0 && c->cost_b > 0)
	{
		rotate(data, 'r', 1);
		c->cost_a--;
		c->cost_b--;
	}
	return (c);
}

t_list	*cheapest(t_list *b)
{
	t_list	*c;

	c = NULL;
	while (b != NULL)
	{
		if (b->cost_a >= 0 && b->cost_b >= 0 && b->cost_a >= b->cost_b)
			b->t_cost = b->cost_a;
		else if (b->cost_a >= 0 && b->cost_b >= 0 && b->cost_a < b->cost_b)
			b->t_cost = b->cost_b;
		else if (b->cost_a <= 0 && b->cost_b <= 0 && b->cost_a >= b->cost_b)
			b->t_cost = b->cost_b * -1;
		else if (b->cost_a <= 0 && b->cost_b <= 0 && b->cost_a < b->cost_b)
			b->t_cost = b->cost_a * -1;
		else
		{
			if (b->cost_a < 0)
				b->t_cost = (b->cost_a * -1) + b->cost_b;
			if (b->cost_b < 0)
				b->t_cost = b->cost_a + (b->cost_b * -1);
		}
		if (c == NULL || b->t_cost < c->t_cost)
			c = b;
		b = b->next;
	}
	return (c);
}

void	costs(t_data *data)
{
	t_list	*a;
	t_list	*b;
	int		mid;

	a = data->lst_b;
	b = data->lst_b;
	mid = (ft_lstsize(data->lst_a) / 2) + 1;
	while (a != NULL)
	{
		if (a->t_position <= mid)
			a->cost_a = a->t_position - 1;
		else
			a->cost_a = (ft_lstsize(data->lst_a) - a->t_position + 1) * -1;
		a = a->next;
	}
	mid = (ft_lstsize(data->lst_b) / 2) + 1;
	while (b != NULL)
	{
		if (b->position <= mid)
			b->cost_b = b->position - 1;
		else
			b->cost_b = (ft_lstsize(data->lst_b) - b->position + 1) * -1;
		b = b->next;
	}
}

void	movement(t_data *data)
{
	t_list	*b;
	t_list	*c;
	t_list	*c_mod;

	b = data->lst_b;
	costs(data);
	c = cheapest(b);
	c_mod = rotates_doubles(data, c);
	rotates_simples(data, c_mod);
	push(data, 'a', 1);
}
