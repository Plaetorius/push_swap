/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:07:12 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 18:48:26 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int initialize(size_t len, int *tab, t_node *node, t_push_swap *vars)
{
	size_t	i;
	t_node	*begin;

	begin = node;
	i = 1;
	while (i < len)
	{
		node->next = ft_node_new(tab[i], NULL, node, i);
		if (!node->next)
			return (ft_free_circular_stack(node->next), 1);
		node = node->next;
		++i;
	}
	node->next = begin;
	begin->prev = node;
	vars->stack_a->head = begin;
	vars->stack_a->size = len;
	return (0);
}

int	convert(int *tab, size_t len, t_push_swap *vars)
{
	t_node	*node;
	size_t	i;

	if (!tab || !vars)
		return (1);
	i = 0;
	tab = ft_sort_int_tab(tab, len);
	node = ft_node_new(tab[0], NULL, NULL, 0);
	if (!node)
		return (1);
	if (len == 1)
	{
		vars->stack_a->size = 1;
		vars->stack_a->head = node;
		return (ft_node_endings(node, node, node), 0);
	}
	return (initialize(len, tab, node, vars));
}
