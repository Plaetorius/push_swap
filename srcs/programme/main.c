/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:41:07 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 14:24:41 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	vars.splits = 3;
	if (phase_1(av, ac, &vars) == 1)
		return (memory_cleaning(&vars), write(2, "Error\n", 6), EXIT_FAILURE);
	if (phase_2(vars.stack_a, vars.stack_b, &vars) == 1)
		return (memory_cleaning(&vars), write(2, "Error\n", 6), EXIT_FAILURE);
	if (phase_3(vars.stack_a, vars.stack_b, &vars) == 1)
		return (memory_cleaning(&vars), write(2, "Error\n", 6), EXIT_FAILURE);
	instructions_shower(vars.insts);
	memory_cleaning(&vars);
	return (EXIT_SUCCESS);
}
