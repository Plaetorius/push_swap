/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:48:55 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 15:05:50 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*initialize(int ac, int *table, t_stack *stack,
	t_push_swap *vars)
{
	int		i;
	t_node	*begin;

	begin = stack->head;
	i = 2;
	while (i < ac)
	{
		stack->head->next = ft_stack_new(table[i - 1], NULL, stack->head, -1);
		if (!stack->head->next)
			return (ft_free_circular_stack(begin, i + 1), NULL);
		stack->head = stack->head->next;
		i++;
	}
	stack->head->next = begin;
	begin->prev = stack;
	vars->len_a = ac - 1;
	vars->head_a = begin;
	return (begin);
}

static t_stack	*ind_stack(t_stack *stack, int *table, size_t len)
{
	size_t	i;
	size_t	j;
	t_stack	*begin;

	if (!stack)
		return (NULL);
	i = -1;
	table = ft_sort_int_tab(table, len);
	begin = stack;
	while (++i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack->val == table[i])
			{
				stack->ind = i;
				break ;
			}
			stack = stack->next;
			j++;
		}
		stack = begin;
	}
	return (stack);
}

t_stack	*convert(int ac, int *table, t_push_swap *vars)
{
	t_stack	*stack;

	if (!table || !vars)
		return (NULL);
	stack = ft_stack_new(table[0], NULL, NULL, -1);
	if (!stack)
		return (NULL);
	if (ac == 2)
	{
		vars->len_a = 1;
		stack->ind = 0;
		vars->head_a = stack;
		return (ft_stack_endings(stack, stack, stack), stack);
	}
	return (ind_stack(initialize(ac, table, stack, vars), table, ac - 1));
}
