/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:10:42 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 18:56:36 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int val, t_node *next, t_node *prev, int ind)
{
	t_node	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->val = val;
	elem->next = next;
	elem->prev = prev;
	elem->ind = ind;
	return (elem);
}

void	ft_free_circular_nodes(t_node *node)
{
	t_node *begin;
	t_node *tmp;
	t_node *ptr;

	if (!node)
		return ;
	
}
