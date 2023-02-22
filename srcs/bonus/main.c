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

int	instruct_atoi(char *instruct, int val)
{
	if (!ft_strncmp(instruct, "ra\n", 5))
		val = ROTATE_A;
	else if (!ft_strncmp(instruct, "rb\n", 5))
		val = ROTATE_B;
	else if (!ft_strncmp(instruct, "sa\n", 5))
		val = SWAP_A;
	else if (!ft_strncmp(instruct, "sb\n", 5))
		val = SWAP_B;
	else if (!ft_strncmp(instruct, "rra\n", 5))
		val = REV_ROTATE_A;
	else if (!ft_strncmp(instruct, "rrb\n", 5))
		val = REV_ROTATE_B;
	else if (!ft_strncmp(instruct, "pa\n", 5))
		val = PUSH_A;
	else if (!ft_strncmp(instruct, "pb\n", 5))
		val = PUSH_B;
	else if (!ft_strncmp(instruct, "rr\n", 5))
		val = RR;
	else if (!ft_strncmp(instruct, "rrr\n", 5))
		val = RRR;
	else if (!ft_strncmp(instruct, "ss\n", 5))
		val = SS;
	return (free(instruct), val);
}

int	get_instructs(t_push_swap *vars)
{
	char		*instruct;
	int			val_instruct;

	while (1)
	{
		instruct = get_next_line(0);
		if (!instruct)
			break ;
		val_instruct = instruct_atoi(instruct, -1);
		if (val_instruct == -1 || new_instruct(val_instruct, vars))
		{
			ft_printf("ca fait de la meerde %d val insutrcts\n", val_instruct);
			return (1);
		}
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
	if (is_stack_sorted(vars.stack_a) && vars.stack_b->len == 0)
		return (memory_cleaning(&vars), write(1, "OK\n", 3), EXIT_SUCCESS);
	return (memory_cleaning(&vars), write(1, "KO\n", 3), EXIT_SUCCESS);
}
