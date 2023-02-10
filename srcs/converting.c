/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:07:12 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 22:24:19 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*initialize(size_t len, int *tab, t_node *node, t_push_swap *vars)
{
	size_t	i;
	t_node	*begin;

	begin = node;
	i = 1;
	while (i < len)
	{
		node->next = ft_node_new(tab[i], NULL, node, i);
		if (!node->next)
			return (ft_free_circular_nodes(node->next), NULL);
		node = node->next;
		++i;
	}
	node->next = begin;
	begin->prev = node;
	vars->stack_a->head = begin;
	vars->stack_a->len = len;
	return (begin);
}

t_node	*convert(int *tab, size_t len, t_push_swap *vars)
{
	t_node	*node;
	size_t	i;

	if (!tab || !vars)
		return (NULL);
	i = 0;
	tab = ft_sort_int_tab(tab, len);
	node = ft_node_new(tab[0], NULL, NULL, 0);
	if (!node)
		return (NULL);	
	vars->stack_a->len = 1;
	vars->stack_a->head = node;
	if (len == 1)
		return (ft_node_endings(node, node, node), node);
	return (initialize(len, tab, node, vars));
}
