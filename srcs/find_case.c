/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:17:58 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/17 19:52:51 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int case_1(t_stack *stack_a, t_node *node , int **pos_element, t_push_swap *vars)
{
	int	last_of_a;
	int	first_of_a;
	int	elem_of_b;

	last_of_a = stack_a->head->prev->val;
	first_of_a = stack_a->head->val;
	elem_of_b = node->val;
	if ((first_of_a < elem_of_b && elem_of_b < last_of_a)
		|| (last_of_a < elem_of_b && elem_of_b < first_of_a))
	{
		(*pos_element)[0] = 0;
		(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
		return (0);
	}
	return (1);
}

static int case_2(t_stack *stack_a, t_node *node, int **pos_element, t_push_swap *vars)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	while ((size_t)i <= stack_a->len / 2)
	{
		if ((tmp->val < node->val && node->val < tmp->next->val)
			|| (tmp->next->val < node->val && node->val < tmp->val))
		{
			(*pos_element)[0] = i;
			(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
			return (0);
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static int case_3(t_stack *stack_a, t_node *node, int **pos_element, t_push_swap *vars)
{
	int		i;
	t_node	*tmp;

	i = stack_a->len - 1;
	tmp = stack_a->head;
	while ((size_t)i > stack_a->len / 2)
	{
		if ((tmp->val < node->val && node->val < tmp->next->val)
			|| (tmp->next->val < node->val && node->val < tmp->val))
		{
			(*pos_element)[0] = i - stack_a->len;
			(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
			return (0);
		}
		tmp = tmp->next;
		i--;
	}
	return (1);
}

static int case_4(t_stack *stack_a, t_node *node, int **pos_element, t_push_swap *vars)
{
	int	path;
	int	var;

	var =  max_val_circular_nodes(stack_a->head);
	if (var == -1)
		return (1);
	path = shortest_to_top(stack_a, var);
	(*pos_element)[0] = path;
	(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
	return (0);
}

int **case_test(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int		**pos;
	int		i;
	t_node	*node;

	if (!stack_a || !stack_b || !vars)
		return (ft_printf("Problem in input\n"), NULL);
	pos = ft_ints(stack_b->len, 2);
	if (!pos)
		return (ft_printf("Problem in pos\n"), NULL);
	i = 0;
	node = stack_b->head;
	while ((size_t)i < stack_b->len)
	{
		if (!(case_1(stack_a, node, pos + i, vars)
			&& case_2(stack_a, node, pos + i, vars)
			&& case_3(stack_a, node, pos + i, vars)))
				;
		else
			case_4(stack_a, node, pos + i, vars);

		node = node->next;
		i++;
	}
	return (pos);
}
		// if (case_1(stack_a, node, pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);
		// else if (case_2(stack_a, node,  pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);
		// else if (case_3(stack_a, node, pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);
		// else if (case_4(stack_a, node, pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);