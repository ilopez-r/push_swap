/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:37:04 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/09 13:00:42 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_data *data)
{
	t_list	*aux;
	int		i;

	aux = data->lst_b;
	i = 0;
	while (++i <= ft_lstsize(data->lst_b))
	{
		aux->position = i;
		aux = aux->next;
	}
	aux = data->lst_a;
	i = 0;
	while (++i <= ft_lstsize(data->lst_a))
	{
		aux->position = i;
		aux = aux->next;
	}
}

void	reset_t_position(t_data *data)
{
	t_list	*b;

	b = data->lst_b;
	while (b != NULL)
	{
		if (b->t_position != 0)
			b->t_position = 0;
		b = b->next;
	}
}

void	t_position(t_data *data, t_list *a, t_list *b)
{
	t_list	*max;
	t_list	*t;

	b = data->lst_b;
	while (b != NULL)
	{
		a = data->lst_a;
		max = NULL;
		t = NULL;
		while (a != NULL)
		{
			if (max == NULL || a->index > max->index)
				max = a;
			if (b->index < a->index && (t == NULL || a->index < t->index))
				t = a;
			a = a->next;
		}
		if (t == NULL && check_order(data) == 0)
			b->t_position = 1;
		else if (t == NULL && check_order(data) == 1)
			b->t_position = max->position + 1;
		else
			b->t_position = t->position;
		b = b->next;
	}
}

/*void	t_position(t_data *data, t_list *a, t_list *b)
{
	t_list	*max;

	b = data->lst_b;
	while (b != NULL)
	{
		a = data->lst_a;
		max = NULL;
		while (a != NULL && check_order(data) == 1 && b->t_position == 0)
		{
			if (b->value < a->value)
				b->t_position = a->position;
			if (b->value > a->value && a->next == NULL)
				b->t_position = 1;
			a = a->next;
		}
		while (a != NULL && check_order(data) == 0 && b->t_position == 0)
		{
			if (a->value > max->value || max == NULL)
				max = a;
			if (b->value > a->value && a->next && b->value < a->next->value)
				b->t_position = a->next->value;
			if (a->next == NULL && b->t_position == 0)
				b->t_position = 1;
			else if (b->value > a->value && a->next == NULL)
				b->t_position = max->position + 1;
			a = a->next;
		}
		b = b->next;
	}
}*/

/*void	t_position(t_data *data, t_list *a, t_list *b)
{
	t_list	*m;

	while (b != NULL)
	{
		a = data->lst_a;
		m = NULL;
		while (a != NULL && b->t_position == 0)
		{
			if (b->index < a->index && check_order(data) == 0)
				b->t_position = a->position;
			if (b->index > a->index && !a->next && check_order(data) == 0)
				b->t_position = 1;
			if ((m == NULL || a->index > m->index) && check_order(data) == 1)
				m = a;
			if (b->index > a->index && a->next && b->index < a->next->index
				&& check_order(data) == 1)
				b->t_position = a->next->position;
			if (a->next == NULL && b->t_position == 0 && check_order(data) == 1)
				b->t_position = 1;
			else if (b->index > a->index && !a->next && check_order(data) == 1)
				b->t_position = m->position + 1;
			a = a->next;
		}
		b = b->next;
	}
}*/
