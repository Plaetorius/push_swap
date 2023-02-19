/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:24:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/19 17:22:16 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_elements_in_b(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int		i;
	int		val;
	int		len_a;

	len_a = (int)stack_a->len;
	i = 0;
	while (stack_a->len > (size_t)(len_a / vars->splits) && stack_a->len > 3)
	{
		if (stack_a->head->ind < len_a / vars->splits)
			val = rotate(stack_a, vars);
		else if (stack_a->head->ind >= len_a / vars->splits
			&& stack_a->head->ind < ((len_a / vars->splits) * 2))
		{
			val = push(stack_b, stack_a, vars);
		}
		else if (stack_a->head->ind >= ((len_a / vars->splits) * 2))
		{
			val = push_bottom(stack_b, stack_a, vars);
		}
		if (val == 1)
			return (1);
	}
	return (0);
}

int	sort_three(t_stack *stack, t_push_swap *vars)
{
	const int	nb_1 = stack->head->val;
	const int	nb_2 = stack->head->next->val;
	const int	nb_3 = stack->head->next->next->val;

	if (nb_1 > nb_2 && nb_2 > nb_3)
	{
		if (swap(stack, vars))
			return (1);
		return (rev_rotate(stack, vars));
	}
	else if (nb_1 > nb_2 && nb_2 < nb_3 && nb_1 < nb_3)
		return (swap(stack, vars));
	else if (nb_1 > nb_2 && nb_2 < nb_3 && nb_1 > nb_3)
		return (rotate(stack, vars));
	else if (nb_1 < nb_2 && nb_2 < nb_3)
		return (0);
	else if (nb_1 < nb_2 && nb_2 > nb_3 && nb_1 < nb_3)
	{
		if (swap(stack, vars))
			return (1);
		return (rotate(stack, vars));
	}
	else if (nb_1 < nb_2 && nb_2 > nb_3 && nb_1 > nb_3)
		return (rev_rotate(stack, vars));
	return (1);
}

int	shortest_to_top(t_stack *stack, int ind)
{
	size_t	travelled;
	t_node	*node;

	node = stack->head;
	travelled = 0;
	while (travelled < stack->len && node->ind != ind)
	{
		travelled++;
		node = node->next;
	}
	if (travelled < stack->len - travelled)
		return (travelled);
	return (-(stack->len - travelled));
}

int	next_ind_present(t_stack *stack, int i)
{
	size_t	j;
	t_node	*node;

	if (!stack)
		return (0);
	i++;
	node = stack->head;
	j = 0;
	while (j < stack->len)
	{
		if (node->ind == i)
			return (1);
		node = node->next;
		j++;
	}
	return (0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*node;
	size_t		i;

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