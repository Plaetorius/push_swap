/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:17:58 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 17:48:09 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	case_1(t_stack *stack_a, t_node *node, int **pos_elem,
	t_push_swap *vars)
{
	if (node->ind == 0)
	{
		(*pos_elem)[0] = shortest_to_top(stack_a, minimum_ind_stack(stack_a));
		(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
		return (0);
	}
	if (node->ind == (int)(stack_a->len + vars->stack_b->len - 1))
	{
		(*pos_elem)[0] = shortest_to_top(stack_a, maximum_ind_stack(stack_a));
		(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
		return (0);
	}
	return (1);
}

static int	case_2(t_stack *stack_a, t_node *node, int **pos_elem,
	t_push_swap *vars)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	if ((tmp->prev->val < node->val && node->val < tmp->val))
	{
		(*pos_elem)[0] = 0;
		(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
		return (0);
	}
	while (i <= stack_a->len / 2)
	{
		if ((tmp->val < node->val && node->val < tmp->next->val))
		{
			(*pos_elem)[0] = shortest_to_top(stack_a, tmp->next->ind);
			(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
			return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

static int	case_3(t_stack *stack_a, t_node *node, int **pos_elem,
	t_push_swap *vars)
{
	size_t	i;
	t_node	*tmp;

	i = stack_a->len -1;
	tmp = stack_a->head;
	while (i >= stack_a->len / 2)
	{
		if ((tmp->prev->val < node->val && node->val < tmp->val))
		{
			(*pos_elem)[0] = shortest_to_top(stack_a, tmp->ind);
			(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
			return (0);
		}
		i--;
		tmp = tmp->prev;
	}
	return (1);
}

int	**case_test(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int		**pos;
	int		i;
	t_node	*node;

	if (!stack_a || !stack_b || !vars)
		return (NULL);
	pos = ft_ints(stack_b->len, 2);
	if (!pos)
		return (NULL);
	i = -1;
	node = stack_b->head;
	while ((size_t)++i < stack_b->len)
	{
		if ((case_1(stack_a, node, pos + i, vars)
				&& case_2(stack_a, node, pos + i, vars)
				&& case_3(stack_a, node, pos + i, vars)))
		{
			pos[i][0] = shortest_to_top(stack_a, closest_ind(stack_a, node));
			pos[i][1] = shortest_to_top(vars->stack_b, node->ind);
		}
		node = node->next;
	}
	return (pos);
}
