/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:41:07 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/15 11:26:01 by tgernez          ###   ########.fr       */
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
		return (memory_cleaning(&vars), EXIT_FAILURE);
	if (phase_2(vars.stack_a, vars.stack_b, &vars) == 1)
		return (memory_cleaning(&vars), EXIT_FAILURE);
	if (phase_3(vars.stack_a, vars.stack_b, &vars) == 1)
		return (memory_cleaning(&vars), EXIT_FAILURE);
	print_stack(&stack_a);
	memory_cleaning(&vars);
	return (EXIT_SUCCESS);
}
/*
	test_01();
	test_02();
	test_03();
	test_04();
	test_05();
	test_06();
	test_07();
	test_08();
	test_09();
	test_10();
	test_11();
	test_12();
	test_13();
	test_14();
	test_15();
	test_16();
	test_17();
	test_18();
*/