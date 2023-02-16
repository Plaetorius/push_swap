/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:02:22 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/16 20:30:06 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialisation(t_push_swap *vars)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_instruct	*instructs;
	
	stack_a.head = NULL;
	stack_a.len = 0;
	stack_b.head = NULL;
	stack_b.len = 0;	
	instructs = NULL;
	vars->stack_a = &stack_a;
	vars->stack_b = &stack_b;
	vars->insts = instructs;
}

int	phase_1(char **av, int ac, t_push_swap *vars)
{
	t_node	*node;
	int		*table;

	if (!av || ac == 1 || !vars)
		return (1);
	table = parsing(ac, av, vars);
	if (!table)
		return (1);
	node = convert(table, vars->stack_a->len, vars);
	if (!node)
		return (free(table), 1);
	vars->stack_a->head = node;
	splits_number(vars->stack_a->len, vars);
	free(table);
	return (0);
}

int	phase_2(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	while (stack_a->len > 3)
	{
		push_elements_in_b(stack_a, stack_b, vars);
	}
	if (stack_a->len == 0 || stack_a->len == 1)
		return (0);
	else if (stack_a->len == 2)
	{
		if (stack_a->head->ind < stack_a->head->next->ind)
		{
			if (rotate(stack_a, vars) == 1)
				return (1);
		}
	}
	else
	{
		(void)stack_b;
		if (sort_three(stack_a, vars) == 1)
			return (1);
	}
	ft_printf("Passed Phase 2\n");
	return (0);
}

int	phase_3(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int	i;
	int var;

	i = stack_a->len;
	var = 0;
	ft_printf("Beginning Phase 3\n");
	while ((size_t)i < stack_a->len + stack_b->len)
	{
		// if (i % 2)
		// 	rev_rotate(stack_b, vars);
		var = shortest_to_ind(stack_b, i, vars);
		var = push(stack_a, stack_b, vars);
		i++;		
	}

	// while (!(is_stack_sorted(stack_a) && stack_b->len == 0))
	// while (!(stack_b->len == 0)) //Check if A is sorted
	// {
	// 	if (stack_b->len > 0)
	// 	{
			
	// 		var = push(stack_a, stack_b, vars);
	// 	}
	// 	if (stack_a->head->ind != i && stack_b->len > 0)
	// 	{
	// 		var = rotate(stack_a, vars);
	// 		ft_printf("Value of Var after rotate %d\n", var);
	// 	}
	// 	else
	// 	{
	// 		while ((size_t)i < stack_a->len && next_ind_present(stack_a, i))
	// 			var = shortest_to_ind(stack_a, ++i, vars);
	// 		ft_printf("Value of Var after next ind present %d\n", var);
	// 	}
	// 	if (var)
	// 		return (ft_printf("Var is 1\n"), 1);
	// }
	
	// while (!(stack_b->len == 0)) //Check if A is sorted
	// {							
	// 	}
	// 	if (stack_a->head->ind != i && stack_b->len > 0)
	// 	{
	// 		var = rotate(stack_a, vars);
	// 		ft_printf("Value of Var after rotate %d\n", var);
	// 	}
	// 	else
	// 	{
	// 		while ((size_t)i < stack_a->len && next_ind_present(stack_a, i))
	// 			var = shortest_to_ind(stack_a, ++i, vars);
	// 		ft_printf("Value of Var after next ind present %d\n", var);
	// 	}
	// 	if (var)
	// 		return (ft_printf("Var is 1\n"), 1);
	// }
	// instructions_shower(vars->insts);
	return (0);
}

void	memory_cleaning(t_push_swap *vars)
{
	if (!vars)
		return ;
	ft_free_circular_nodes(vars->stack_a->head);
	ft_free_circular_nodes(vars->stack_b->head);
	ft_free_stack(vars->insts);
}
