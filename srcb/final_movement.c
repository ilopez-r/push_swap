/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:50:02 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/08 20:00:20 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_movement(t_data *data)
{
	t_list	*a;
	int		mid;

	a = data->lst_a;
	mid = (ft_lstsize(a) / 2) + 1;
	while (a->index <= mid && a->index != 1)
	{
		r_rotate(data, 'a', 1);
		a = data->lst_a;
	}
	while (a->index > mid && a->index != 1)
	{
		rotate(data, 'a', 1);
		a = data->lst_a;
	}
}
