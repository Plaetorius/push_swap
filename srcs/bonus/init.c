/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:25:10 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/23 13:51:03 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	init(char **av, int ac, t_push_swap *vars)
{
	t_node	*node;
	int		*table;

	if (!av || ac == 1 || !vars)
		return (1);
	table = parsing(ac, av, vars);
	if (!table)
		return (1);
	if (ft_is_int_tab_sorted(table, vars->stack_a->len) && vars->insts == NULL)
		return (free(table), write(1, "OK\n", 3), 1);
	node = convert(table, vars->stack_a->len, vars);
	if (!node)
		return (free(table), 1);
	vars->stack_a->head = node;
	free(table);
	return (0);
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

int	new_instruct(int val, t_push_swap *vars)
{
	t_instruct	*instruct;
	t_instruct	*tmp;

	instruct = malloc(sizeof(t_instruct));
	if (!instruct)
		return (1);
	instruct->val = val;
	instruct->next = NULL;
	tmp = vars->insts;
	if (vars->insts == NULL)
		vars->insts = instruct;
	else
	{
		while (vars->insts->next)
			vars->insts = vars->insts->next;
		vars->insts->next = instruct;
		vars->insts = tmp;
	}
	return (0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*node;
	size_t	i;

	node = stack->head;
	i = 0;
	while (i < stack->len - 1)
	{
		if (node->val > node->next->val)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
