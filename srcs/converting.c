/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:07:12 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/12 15:46:42 by tgernez          ###   ########.fr       */
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
		node->next = ft_node_new(tab[i], NULL, node, -1);
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

static t_node	*ind_stack(t_node *node, int *table, size_t len)
{
	size_t	i;
	size_t	j;
	t_node 	*begin;

	if (!node)
		return (NULL);
	i = -1;
	table = ft_rev_int_tab(ft_sort_int_tab(table, len), len);
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_print_int_tab(table, len);
	begin = node;
	while (++i < len)
	{
		j = 0;
		while (j < len)
		{
			if (node->val == table[i])
			{
				node->ind = i;
				break ;
			}
			node = node->next;
			j++;
		}
		node = begin;
	}
	return (node);
}

t_node	*convert(int *tab, size_t len, t_push_swap *vars)
{
	t_node	*node;
	size_t	i;

	if (!tab || !vars)
		return (NULL);
	i = 0;
	node = ft_node_new(tab[0], NULL, NULL, -1);
	if (!node)
		return (NULL);	
	vars->stack_a->len = 1;
	vars->stack_a->head = node;
	if (len == 1)
	{
		node->ind = 0;
		return (ft_node_endings(node, node, node), node);
	}
	return (ind_stack(initialize(len, tab, node, vars), tab,
		vars->stack_a->len));
}
