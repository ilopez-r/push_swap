/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:20:48 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/09 12:59:29 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libftc/libft.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	char	**arg;
	t_list	*lst_a;
	t_list	*lst_b;
}	t_data;

int		check_arguments(int argc, char **argv, t_data *data);
int		check_numbers(int i, int j, int r, t_data *data);
void	fill_and_assign(t_data *data);
int		check_order(t_data *data);
void	select_algorithm(t_data *data);
void	swap(t_data *data, char c, int flag);
void	r_rotate(t_data *data, char c, int flag);
void	rotate(t_data *data, char c, int flag);
void	push(t_data *data, char c, int flag);
void	position(t_data *data);
void	reset_t_position(t_data *data);
void	t_position(t_data *data, t_list *a, t_list *b);
void	movement(t_data *data);
void	final_movement(t_data *data);

#endif