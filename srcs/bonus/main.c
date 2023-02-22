/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:08:19 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 11:16:3 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	instruct_atoi(char *instruct)
{
	if (!ft_strncmp(instruct, "ra", 5))
		return (free(instruct), ROTATE_A);
	else if (!ft_strncmp(instruct, "rb", 5))
		return (free(instruct), ROTATE_B);
	else if (!ft_strncmp(instruct, "sa", 5))
		return (free(instruct), SWAP_A);
	else if (!ft_strncmp(instruct, "sb", 5))
		return (free(instruct), SWAP_B);
	else if (!ft_strncmp(instruct, "rra", 5))
		return (free(instruct), REV_ROTATE_A);
	else if (!ft_strncmp(instruct, "rrb", 5))
		return (free(instruct), REV_ROTATE_B);
	else if (!ft_strncmp(instruct, "pa", 5))
		return (free(instruct), PUSH_A);
	else if (!ft_strncmp(instruct, "pb", 5))
		return (free(instruct), PUSH_B);
	else if (!ft_strncmp(instruct, "rr", 5))
		return (free(instruct), RR);
	else if (!ft_strncmp(instruct, "rrr", 5))
		return (free(instruct), RRR);
	else if (!ft_strncmp(instruct, "ss", 5))
		return (free(instruct), SS);
	return (free(instruct), -1);
}

int	get_instructs(t_push_swap *vars)
{
	char		*instruct;
	t_instruct	*tmp;
	int			val_instruct;

	while (1)
	{
		instruct = get_next_line(0);
		if (!instruct)
			break ;
		val_instruct = instruct_atoi(instruct);
		if (val_instruct == -1 || new_instruct(val_instruct, vars))
			return (1);
	}
	return (0);
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
	free(table);
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	vars;
	t_stack		stack_a;
	t_stack		stack_b;
	t_instruct	*instructs;

	stack_a.head = NULL;
	stack_a.len = 0;
	stack_b.head = NULL;
	stack_b.len = 0;
	instructs = NULL;
	vars.stack_a = &stack_a;
	vars.stack_b = &stack_b;
	vars.insts = instructs;
	if (ac == 1)
		return (EXIT_FAILURE);
	if (get_instructs(&vars))
		return (memory_cleaning(&vars), write(2, "Error\n", 6), EXIT_FAILURE);
	if (init(av, ac, &vars) == 1)
		return (memory_cleaning(&vars), write(2, "Error\n", 6), EXIT_FAILURE);
	if (execute_instructs(&vars) == 1)
		return (memory_cleaning(&vars), write(2, "Error\n", 6), EXIT_FAILURE);
	if (is_stack_sorted(vars.stack_a) && vars.stack_b == NULL
		&& vars.stack_b->len == 0)
		return (memory_cleaning(&vars), write(1, "OK\n", 3), EXIT_SUCCESS);
	return (memory_cleaning(&vars), write(1, "KO\n", 3), EXIT_SUCCESS);
}
