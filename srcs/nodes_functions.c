/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:10:42 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/11 15:52:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int val, t_node *next, t_node *prev, int ind)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
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
	ptr = node->next;
	while (ptr != node)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
	free(node);
	node = NULL;
}

void	ft_node_endings(t_node *elem, t_node *next, t_node *prev)
{
	if (!elem)
		return ;
	if (next)
	{
		elem->next = next;
		next->prev = elem;
	}
	if (prev)
	{
		elem->prev = prev;
		prev->next = elem;
	}
}