/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:10:42 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/17 15:09:53 by tgernez          ###   ########.fr       */
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
	t_node	*tmp;
	t_node	*ptr;

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

void	ft_free_stack(t_instruct *stack)
{
	t_instruct	*ptr;
	t_instruct	*tmp;

	if (!stack)
		return ;
	ptr = stack;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
	stack = NULL;
}

int	max_val_circular_nodes(t_node *node)
{
	t_node	*tmp;
	t_node	*ptr;
	int		max;
	int		ind;

	if (!node)
		return (-1);
	max = node->val;
	ind = node->ind;
	ptr = node->next;
	while (ptr != node)
	{
		if (ptr->val > max)
		{
			ind = ptr->ind;
			max = ptr->val;
		}
		ptr = ptr->next;
	}
	return (ind);
}
