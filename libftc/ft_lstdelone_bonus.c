/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:19:39 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/08 15:35:17 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	t_list	*new;

	new = lst;
	if (lst == 0 || del == 0)
		return ;
	del(lst->value);
	del(lst->index);
	del(lst->position);
	del(lst->t_position);
	del(lst->cost_a);
	del(lst->cost_b);
	del(lst->t_cost);
	lst = new->next;
	free(new);
}
