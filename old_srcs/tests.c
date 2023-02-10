/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:02:07 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 13:29:26 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define VERBOSE		1
#define ADDRESSES	0
#define	RED			"\033[1;31m"
#define GRE			"\033[1;32m"
#define RES			"\033[0m"
#define YEL			"\033[1;33m"
#define CYA			"\033[1;36m"

t_stack	*stack_maker(int *tab, size_t len)
{
	size_t i;
	t_stack *stack;
	t_stack	*begin;

	i = 1;
	stack = ft_stack_new(tab[0], NULL, NULL, -1);
	begin = stack;
	while (i < len)
	{
		stack->next = ft_stack_new(tab[i], NULL, stack, -1);
		stack = stack->next;
		i++;
	}
	stack->next = begin;
	begin->prev = stack;
	return (begin);
}

void print_instructions(t_instruct *stack)
{
	while (stack)
	{
		ft_printf("INSTR VAL %d /INSTR VAL\n", stack->val);
		stack = stack->next;
	}
}

void stack_burner(t_stack *stack)
{
	int i;
	
	i = 0;
	ft_printf("%s>>>STACK BURNING<<<\n%s", RED, RES);
	ft_printf("Going Next to Next\n");
	while (i < 15)
	{
		ft_printf("VAL %d /VAL\n", stack->val);
		stack = stack->next;
		i++;
	}
	ft_printf("Going Prev to Prev\n");
	while (i < 30)
	{
		ft_printf("VAL %d /VAL\n", stack->val);
		stack = stack->prev;
		i++;
	}
}

void stack_burner_ind(t_stack *stack)
{
	int i;
	
	i = 0;
	ft_printf("%s>>>STACK BURNING IND<<<\n%s", RED, RES);
	ft_printf("Going Next to Next\n");
	while (i < 15)
	{
		ft_printf("VAL %d /VAL\n", stack->ind);
		stack = stack->next;
		i++;
	}
	ft_printf("Going Prev to Prev\n");
	while (i < 30)
	{
		ft_printf("VAL %d /VAL\n", stack->ind);
		stack = stack->prev;
		i++;
	}
}


void test_01()
{
	char	*entry;
	char	**av;
	int		ac;
	int		i;
	int		*table;
	int		correct[5];
	int		passed;

	ft_printf("=====Test 01=====\n");
	ft_printf("Testing Parsing with %s1 2 3 4%s entry...", YEL, RES);
	ac = 5;
	entry = ft_strdup("push_swap 1 2 3 4");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	i = 0;
	passed = 1;
	while (++i <= 4)
		correct[i - 1] = i;
	i = 0;
	if (VERBOSE)
		ft_printf("\n");
	while (i < 4)
	{
		if (VERBOSE == 1)
			ft_printf("correct[i]=%d : %d=table[i]\n", correct[i], table[i]);
		if (correct[i] != table[i])
			passed = 0;
		i++;
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
	free(table);
}

void test_02()
{
	char	*entry;
	char	**av;
	int		ac;
	int		*table;
	int		passed;

	ft_printf("=====Test 02=====\n");
	ft_printf("Testing Parsing with %sempty%s entry...", YEL, RES);
	ac = 1;
	entry = ft_strdup("push_swap");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	passed = table == NULL;
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
}

void test_03()
{
	char	*entry;
	char	**av;
	int		ac;
	int		*table;
	int		passed;

	ft_printf("=====Test 03=====\n");
	ft_printf("Testing Parsing with %s1 1 1 1 1%s entry...", YEL, RES);
	ac = 6;
	entry = ft_strdup("push_swap 1 1 1 1 1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	passed = table == NULL;
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
}

void test_04()
{
	char	*entry;
	char	**av;
	int		ac;
	int		*table;
	int		passed;

	ft_printf("=====Test 04=====\n");
	ft_printf("Testing Parsing with %s1 2 2 1 3%s entry...", YEL, RES);
	ac = 6;
	entry = ft_strdup("push_swap 1 2 3 1 3");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	passed = table == NULL;
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
}

void test_05()
{
	char	*entry;
	char	**av;
	int		ac;
	int		*table;
	int		passed;
	t_stack	*stack;
	t_push_swap vars;

	ft_printf("=====Test 05=====\n");
	ft_printf("Testing Stack Freeing with %s1 2 3 4 5%s entry...", YEL, RES);
	ac = 6;
	entry = ft_strdup("push_swap 1 2 3 4 5");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	stack = convert(ac, table, &vars);
	passed = 1;
	ft_free_circular_stack(stack, ac - 1);
	ft_printf("%spassed!%s\n", GRE, RES);
	ft_free_strs(av);
	free(table);
	free(entry);
}

void test_06()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		*stack;
	t_push_swap	vars;
	int			correct[5];
	int			i;

	ft_printf("=====Test 06=====\n");
	ft_printf("Testing Conversion with %s1 2 3 4 5 6%s entry...", YEL, RES);
	ac = 7;
	entry = ft_strdup("push_swap 1 2 3 4 5 6");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	stack = convert(ac, table, &vars);
	passed = 1;
	if (VERBOSE)
		ft_printf("\nGoing Next to Next\n");
	i = 0;
	while (++i <= 6)
		correct[i - 1] = i;
	i = 1;
	while (i < ac)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i - 1], stack->val);
		if (correct[i - 1] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack = stack->prev;
	while (--i >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i - 1], stack->val);
		if (correct[i - 1] != stack->val)
			passed = 0;
		stack = stack->prev;
	}
	stack = stack->next;
	if (VERBOSE)
		stack_burner(stack);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	ft_free_circular_stack(stack, vars.len_a);
	free(table);
	free(entry);
}

void test_07()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack;
	t_stack		*elem;
	int			correct[2];
	size_t			i;

	ft_printf("=====Test 07=====\n");
	ft_printf("Testing Stack Endings to create %s1 2%s rotative stack...", YEL, RES);
	stack = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	ft_stack_endings(stack, elem, elem); 
	passed = 1;
	vars.len_a = 2;
	vars.head_a = stack;
	if (VERBOSE)
		ft_printf("\nGoing Next to Next\n");
	i = 0;
	while (++i <= vars.len_a)
		correct[i - 1] = i;
	i = 0;
	while (i < vars.len_a)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack->val);
		if (correct[i] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack = stack->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack->val);
		if (correct[i] != stack->val)
			passed = 0;
		stack = stack->prev;
	}
	if (VERBOSE)
		stack_burner(stack);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack, vars.len_a);
}

void test_08()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack;
	t_stack		*elem;
	t_stack		*elem2;
	int			correct[3];
	size_t			i;

	ft_printf("=====Test 08=====\n");
	ft_printf("Testing Top to create %s1 2 3%s rotative stack...", YEL, RES);
	stack = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	elem2 = ft_stack_new(3, NULL, NULL, -1);
	ft_stack_endings(stack, elem, elem);
	ft_top(&stack, elem2, &vars.len_a);
	passed = 1;
	vars.len_a = 3;
	vars.head_a = stack;
	if (VERBOSE)
		ft_printf("\nGoing Next to Next\n");
	i = 0;
	while (++i <= vars.len_a)
		correct[i - 1] = i;
	i = 0;
	while (i < vars.len_a)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack->val);
		if (correct[i] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack = stack->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack->val);
		if (correct[i] != stack->val)
			passed = 0;
		stack = stack->prev;
	}
	if (VERBOSE)
		stack_burner(stack);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack, vars.len_a);
}

void test_09()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack;
	t_stack		*elem;
	t_stack		*elem2;
	int			correct[3];
	size_t			i;
	int			tmp;

	ft_printf("=====Test 09=====\n");
	ft_printf("Testing Swap to create %s2 1 3%s rotative stack...", YEL, RES);
	stack = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	elem2 = ft_stack_new(3, NULL, NULL, -1);
	ft_stack_endings(stack, elem, elem);
	ft_top(&stack, elem2, &vars.len_a);
	passed = 1;
	vars.len_a = 3;
	vars.head_a = stack;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	vars.head_b = NULL;
	swap(&stack, &vars);
	if (VERBOSE)
		ft_printf("\nGoing Next to Next\n");
	i = 0;
	while (++i <= vars.len_a)
		correct[i - 1] = i;
	tmp = correct[0];
	correct[0] =  correct[1];
	correct[1] = tmp;
	i = 0;
	while (i < vars.len_a)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack->val);
		if (correct[i] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack = stack->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack->val);
		if (correct[i] != stack->val)
			passed = 0;
		stack = stack->prev;
	}
	if (VERBOSE)
		stack_burner(stack);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack, vars.len_a);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}


void test_10()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*elem;
	t_stack		*elem2;
	int			correct[3];
	size_t			i;

	ft_printf("=====Test 10=====\n");
	ft_printf("Testing Push to create %s3 2 1%s rotative stack on empty Stack A...", YEL, RES);
	stack_a = NULL;
	stack_b = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	elem2 = ft_stack_new(3, NULL, NULL, -1);
	ft_stack_endings(stack_b, elem, elem);
	ft_top(&stack_b, elem2, &vars.len_b);
	passed = 1;
	vars.len_a = 0;
	vars.head_a = stack_a;
	vars.len_b = 3;
	vars.head_b = stack_b;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	push(&stack_a, &stack_b, 'b', &vars);	
	push(&stack_a, &stack_b, 'b', &vars);
	push(&stack_a, &stack_b, 'b', &vars);
	correct[0] = 3;
	correct[1] = 2;
	correct[2] = 1;
	if (VERBOSE)
	{
		ft_printf("\nLen A: %d\n", vars.len_a);
		ft_printf("Len B: %d\n", vars.len_b);
		ft_printf("Head A: %p\n", vars.head_a);
		ft_printf("Head B: %p\n", vars.head_b);
		ft_printf("VAL %d /VAL\n", stack_a->val);
	}
	i = 0;
	if (VERBOSE)
		ft_printf("Going Next to Next\n");
	while (i < vars.len_a)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack_a->val);
		if (ADDRESSES)
			ft_printf("STACK A %p /STACK A\n", stack_a);	
		if (correct[i] != stack_a->val)
			passed = 0;
		i++;
		stack_a = stack_a->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack_a = stack_a->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack_a->val);
		if (ADDRESSES)
			ft_printf("STACK A %p /STACK A\n", stack_a);
		if (correct[i] != stack_a->val)
			passed = 0;
		stack_a = stack_a->prev;
	}
	if (VERBOSE)
		stack_burner(stack_a);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack_a, vars.len_a);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}

void test_11()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			correct[1];
	size_t			i;

	ft_printf("=====Test 11=====\n");
	ft_printf("Testing Push to create %s1%s rotative stack on empty Stack A...", YEL, RES);
	stack_a = NULL;
	stack_b = ft_stack_new(1, NULL, NULL, -1);
	ft_stack_endings(stack_b, stack_b, stack_b);
	passed = 1;
	vars.len_b = 1;
	vars.head_b = stack_b;
	vars.len_a = 0;
	vars.head_a = stack_a;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	push(&stack_a, &stack_b, 'b', &vars);
	correct[0] = 1;
	if (VERBOSE)
	{
		ft_printf("\nLen A: %d\n", vars.len_a);
		ft_printf("Len B: %d\n", vars.len_b);
		ft_printf("Head A: %p\n", vars.head_a);
		ft_printf("Head B: %p\n", vars.head_b);
		ft_printf("VAL %d /VAL\n", stack_a->val);
	}
	i = 0;
	if (VERBOSE)
		ft_printf("Going Next to Next\n");
	while (i < vars.len_a)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack_a->val);
		if (ADDRESSES)
			ft_printf("STACK A %p /STACK A\n", stack_a);	
		if (correct[i] != stack_a->val)
			passed = 0;
		i++;
		stack_a = stack_a->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack_a = stack_a->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack_a->val);
		if (ADDRESSES)
			ft_printf("STACK A %p /STACK A\n", stack_a);	
		if (correct[i] != stack_a->val)
			passed = 0;
		stack_a = stack_a->prev;
	}
	if (VERBOSE)
		stack_burner(stack_a);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack_a, vars.len_a);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}

void test_12()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*elem;
	t_stack		*elem2;
	int			correct[3];
	size_t			i;

	ft_printf("=====Test 12=====\n");
	ft_printf("Testing Push to create %s3 2 1%s rotative stack on empty Stack B...", YEL, RES);
	stack_b = NULL;
	stack_a = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	elem2 = ft_stack_new(3, NULL, NULL, -1);
	ft_stack_endings(stack_a, elem, elem);
	ft_top(&stack_a, elem2, &vars.len_a);
	passed = 1;
	vars.len_a = 3;
	vars.head_a = stack_a;
	vars.len_b = 0;
	vars.head_b = stack_b;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	push(&stack_b, &stack_a, 'a', &vars);	
	push(&stack_b, &stack_a, 'a', &vars);
	push(&stack_b, &stack_a, 'a', &vars);
	correct[0] = 3;
	correct[1] = 2;
	correct[2] = 1;
	if (VERBOSE)
	{
		ft_printf("\nLen A: %d\n", vars.len_a);
		ft_printf("Len B: %d\n", vars.len_b);
		ft_printf("Head A: %p\n", vars.head_a);
		ft_printf("Head B: %p\n", vars.head_b);
		ft_printf("VAL %d /VAL\n", stack_b->val);
	}
	i = 0;
	if (VERBOSE)
		ft_printf("Going Next to Next\n");
	while (i < vars.len_b)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack_b->val);
		if (ADDRESSES)
			ft_printf("STACK B %p /STACK B\n", stack_b);
		if (correct[i] != stack_b->val)
			passed = 0;
		i++;
		stack_b = stack_b->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack_b = stack_b->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack_b->val);
		if (ADDRESSES)
			ft_printf("STACK B %p /STACK B\n", stack_b);
		if (correct[i] != stack_b->val)
			passed = 0;
		stack_b = stack_b->prev;
	}
	if (VERBOSE)
		stack_burner(stack_b);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack_b, vars.len_b);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}

void test_13()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*elem;
	t_stack		*elem2;
	int			correct[3];
	size_t			i;

	ft_printf("=====Test 13=====\n");
	ft_printf("Testing Rotate on %s3 2 1%s to get %s2 1 3%s...", YEL, RES, YEL, RES);
	stack_b = NULL;
	stack_a = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	elem2 = ft_stack_new(3, NULL, NULL, -1);
	ft_stack_endings(stack_a, elem, elem);
	ft_top(&stack_a, elem2, &vars.len_a);
	passed = 1;
	vars.len_a = 3;
	vars.head_a = stack_a;
	vars.len_b = 0;
	vars.head_b = stack_b;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	push(&stack_b, &stack_a, 'a', &vars);	
	push(&stack_b, &stack_a, 'a', &vars);
	push(&stack_b, &stack_a, 'a', &vars);
	rotate(&stack_b, &vars);
	correct[0] = 2;
	correct[1] = 1;
	correct[2] = 3;
	if (VERBOSE)
	{
		ft_printf("\nLen A: %d\n", vars.len_a);
		ft_printf("Len B: %d\n", vars.len_b);
		ft_printf("Head A: %p\n", vars.head_a);
		ft_printf("Head B: %p\n", vars.head_b);
		ft_printf("VAL %d /VAL\n", stack_b->val);
	}
	i = 0;
	if (VERBOSE)
		ft_printf("Going Next to Next\n");
	while (i < vars.len_b)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack_b->val);
		if (ADDRESSES)
			ft_printf("STACK B %p /STACK B\n", stack_b);
		if (correct[i] != stack_b->val)
			passed = 0;
		i++;
		stack_b = stack_b->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack_b = stack_b->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack_b->val);
		if (ADDRESSES)
			ft_printf("STACK B %p /STACK B\n", stack_b);
		if (correct[i] != stack_b->val)
			passed = 0;
		stack_b = stack_b->prev;
	}
	if (VERBOSE)
		stack_burner(stack_b);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack_b, vars.len_b);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}

void test_14()
{
	t_push_swap	vars;
	int			passed;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*elem;
	t_stack		*elem2;
	int			correct[3];
	size_t			i;

	ft_printf("=====Test 14=====\n");
	ft_printf("Testing Rev Rotate on %s3 2 1%s to get %s1 3 2%s...", YEL, RES, YEL, RES);
	stack_b = NULL;
	stack_a = ft_stack_new(1, NULL, NULL, -1);
	elem = ft_stack_new(2, NULL, NULL, -1);
	elem2 = ft_stack_new(3, NULL, NULL, -1);
	ft_stack_endings(stack_a, elem, elem);
	ft_top(&stack_a, elem2, &vars.len_a);
	passed = 1;
	vars.len_a = 3;
	vars.head_a = stack_a;
	vars.len_b = 0;
	vars.head_b = stack_b;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	push(&stack_b, &stack_a, 'a', &vars);	
	push(&stack_b, &stack_a, 'a', &vars);
	push(&stack_b, &stack_a, 'a', &vars);
	rev_rotate(&stack_b, &vars);
	correct[0] = 1;
	correct[1] = 3;
	correct[2] = 2;
	if (VERBOSE)
	{
		ft_printf("\nLen A: %d\n", vars.len_a);
		ft_printf("Len B: %d\n", vars.len_b);
		ft_printf("Head A: %p\n", vars.head_a);
		ft_printf("Head B: %p\n", vars.head_b);
		ft_printf("VAL %d /VAL\n", stack_b->val);
	}
	i = 0;
	if (VERBOSE)
		ft_printf("Going Next to Next\n");
	while (i < vars.len_b)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=stack at i\n", correct[i], stack_b->val);
		if (ADDRESSES)
			ft_printf("STACK B %p /STACK B\n", stack_b);
		if (correct[i] != stack_b->val)
			passed = 0;
		i++;
		stack_b = stack_b->next;
	}
	if (VERBOSE)
		ft_printf("Going Prev to Prev\n");
	stack_b = stack_b->prev;
	while ((i--) >= 1)
	{
		if (VERBOSE)
			ft_printf("correct[i]=%d : %d=stack at i\n", correct[i], stack_b->val);
		if (ADDRESSES)
			ft_printf("STACK B %p /STACK B\n", stack_b);
		if (correct[i] != stack_b->val)
			passed = 0;
		stack_b = stack_b->prev;
	}
	if (VERBOSE)
		stack_burner(stack_b);
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_circular_stack(stack_b, vars.len_b);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}

void test_15()
{
	t_push_swap	vars;
	t_instruct	*inst_a;
	t_instruct	*inst_b;
	int			passed;
	int			correct[5];
	size_t			i;

	ft_printf("=====Test 15=====\n");
	ft_printf("Testing %sInstructions%s...", YEL, RES);
	passed = 1;
	vars.len_a = 0;
	vars.head_a = NULL;
	vars.len_b = 0;
	vars.head_b = NULL;
	vars.inst_a = NULL;
	vars.inst_b = NULL;
	correct[0] = PUSH;
	correct[1] = PUSH;
	correct[2] = SWAP;
	correct[3] = ROTATE;
	correct[4] = REV_ROTATE;
	inst_a = new_instruct(REV_ROTATE, NULL);
	inst_a = new_instruct(ROTATE, inst_a);
	inst_a = new_instruct(SWAP, inst_a);
	inst_a = new_instruct(PUSH, inst_a);
	inst_a = new_instruct(PUSH, inst_a);
	inst_b = new_instruct(PUSH, NULL);
	inst_b = new_instruct(ROTATE, inst_b);
	vars.inst_a = inst_a;
	vars.inst_b = inst_b;
	if (VERBOSE)
	{
		instructions_destacker(inst_b, inst_a, 'b');
		instructions_destacker(inst_a, inst_b, 'a');
		ft_printf("\nInstructions for A:\n");
		print_instructions(inst_a);
		ft_printf("Instructions for B:\n");
		print_instructions(inst_b);
	}	
	i = 0;
	while (i < 5)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=inst_a at i\n", correct[i], inst_a->val);	
		if (correct[i] != inst_a->val)
			passed = 0;
		i++;
		inst_a = inst_a->next;
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);

}

void test_16()
{
	int		*tab;
	char	**av;
	char	*entry;
	int		ac;
	int		passed;
	int		correct[5];
	size_t	i;

	ft_printf("=====Test 16=====\n");
	ft_printf("Testing Sort On Entry %s5 4 3 2 1%s...", YEL, RES);
	ac = 6;
	entry = ft_strdup("push_swap 5 4 3 2 1");
	av = ft_split(entry, ' ');
	tab = parsing(ac, av);
	passed = 1;
	correct[0] = 1;
	correct[1] = 2;
	correct[2] = 3;
	correct[3] = 4;
	correct[4] = 5;
	i = 0;
	tab = ft_sort_int_tab(tab, 5);
	if (VERBOSE)
		ft_printf("\n");
	while (i < 5)
	{
		if (VERBOSE)
			ft_printf( "correct[i]=%d : %d=tab[i]\n", correct[i], tab[i]);	
		if (correct[i] != tab[i])
			passed = 0;
		i++;
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
	free(tab);
}

void test_17()
{
	int		*tab;
	char	**av;
	char	*entry;
	int		ac;
	int		passed;
	int		correct[5];
	t_stack *stack;
	t_push_swap vars;
	size_t	i;

	ft_printf("=====Test 17=====\n");
	ft_printf("Testing Indices %s35 67 1 -3 6%s...", YEL, RES);
	ac = 6;
	entry = ft_strdup("push_swap 35 67 1 -3 6");
	av = ft_split(entry, ' ');
	tab = parsing(ac, av);
	passed = 1;	
	correct[0] = -3;
	correct[1] = 1;
	correct[2] = 6;
	correct[3] = 35;
	correct[4] = 67;
	i = 0;
	stack = convert(ac, tab, &vars);
	if (VERBOSE)
		ft_printf("\n");
	while (i < 5)
	{
		if (VERBOSE)
			ft_printf("correct[%d] = %d	: %d = val for ind %d\n", stack->ind, correct[stack->ind], stack->val, stack->ind);	
		if (correct[stack->ind] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
	free(tab);
	ft_free_circular_stack(stack, 5);
}

void test_18()
{
	int	correct[5];
	int	i;
	int passed;
	t_instruct	*stack;
	t_instruct	*tmp;

	ft_printf("=====Test 18=====\n");
	ft_printf("Testing %sMass Instruction Addder%s...", YEL, RES);
	i = 0;
	stack = NULL;
	// stack = new_instruct(SWAP, NULL);
	passed = 1;
	while (i < 5)
	{
		correct[i] = ROTATE;
		i++;
	}
	stack = instructions_adder(ROTATE, 5, stack);
	tmp = stack;
	i = 0;
	if (VERBOSE)
		ft_printf("\n");
	while (i < 5)
	{
		if (VERBOSE)
			ft_printf("correct[%d] = %d	: %d = val for ind %d\n", i, correct[i], stack->val, i);	
		if (correct[i] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_stack(tmp);
}

void test_19()
{
	int		*tab;
	char	**av;
	char	*entry;
	int		ac;
	int		passed;
	int		correct[5];
	t_stack *stack;
	t_instruct *inst_a;
	t_push_swap vars;
	size_t	i;

	ft_printf("=====Test 19=====\n");
	ft_printf("Testing Shortest Path to Ind 0 on %s35 67 1 -3 6%s...", YEL, RES);
	ac = 6;
	entry = ft_strdup("push_swap 35 67 1 -3 6");
	av = ft_split(entry, ' ');
	tab = parsing(ac, av);
	passed = 1;	
	correct[0] = -3;
	correct[1] = 1;
	correct[2] = 6;
	correct[3] = 35;
	correct[4] = 67;
	i = 0;
	stack = convert(ac, tab, &vars);
	vars.head_a = stack;
	vars.len_a = ac- 1;
	inst_a = NULL;
	vars.inst_a = inst_a;
	passed = 2 == shortest_rotation_to_ind(&(vars.head_a), 0, 'a', &vars);
	// instructions_destacker(vars.inst_a, NULL, 'a');
	if (VERBOSE)
		ft_printf("\nVAL HEAD %d /VAL HEAD\n", vars.head_a->val);
	while (i < 5)
	{
		if (VERBOSE)
			ft_printf("correct[%d] = %d	: %d = val for ind %d\n", vars.head_a->ind, correct[vars.head_a->ind], vars.head_a->val, vars.head_a->ind);
		if (ADDRESSES)
		{
			ft_printf("STACK ADDRESS %p /STACK ADDRESS\n", vars.head_a);
		}
		if (correct[vars.head_a->ind] != vars.head_a->val)
			passed = 0;
		i++;
		vars.head_a = vars.head_a->next;
	}
	i = 0;
	inst_a = vars.inst_a;
	if (ADDRESSES)
	{
		while (inst_a)
		{
			ft_printf("INST ADDRESS %p /INST ADDRESS\n", inst_a);
			inst_a = inst_a->next;
		}
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
	free(tab);
	ft_free_circular_stack(vars.head_a, 5);
	ft_free_stack(vars.inst_a);
}

void test_20()
{
	int		*tab;
	char	**av;
	char	*entry;
	int		ac;
	int		passed;
	int		correct[1];
	t_stack *stack;
	t_push_swap vars;
	size_t	i;

	ft_printf("=====Test 20=====\n");
	ft_printf("Testing Shortest Path to Ind 0 on %s1%s...", YEL, RES);
	ac = 2;
	entry = ft_strdup("push_swap 1");
	av = ft_split(entry, ' ');
	tab = parsing(ac, av);
	passed = 1;	
	correct[0] = 1;
	i = 0;
	vars.len_a = 1;
	stack = convert(ac, tab, &vars);
	vars.head_a = stack;
	vars.head_a = stack;
	vars.len_a = ac - 1;
	passed = 0 == shortest_rotation_to_ind(&stack, 0, 'a', &vars);
	if (VERBOSE)
		ft_printf("\nVAL HEAD %d /VAL HEAD\n", stack->val);
	while (i < 1)
	{
		if (VERBOSE)
			ft_printf("correct[%d] = %d	: %d = val for ind %d\n", stack->ind, correct[stack->ind], stack->val, stack->ind);	
		if (correct[stack->ind] != stack->val)
			passed = 0;
		i++;
		stack = stack->next;
	}
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
	ft_free_strs(av);
	free(entry);
	free(tab);
	ft_free_circular_stack(stack, 1);
}

// void test_21()
// {
// 	int			*tab;
// 	char		**av;
// 	char		*entry;
// 	int			ac;
// 	int			passed;
// 	int			correct[1];
// 	t_stack		*stack_a;
// 	t_stack		*stack_b;
// 	t_instruct	*inst_a;
// 	t_instruct	*inst_b;
// 	t_push_swap vars;
// 	int			i;

// 	ft_printf("=====Test 21=====\n");
// 	ft_printf("Testing Clear Stack A on %sShort Input (15)%s...", YEL, RES);
// 	ac = 16;
// 	// entry = ft_strdup("push_swap 643 89804 -85 5768901 -3875 -3483958 25846 0 -2 99999999 -98754 -35913 285594 875225 2356762");
// 	// entry = ft_strdup("push_swap 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14");
// 	entry = ft_strdup("push_swap 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20");

// 	av = ft_split(entry, ' ');
// 	tab = parsing(ac, av);
// 	passed = 1;
// 	// -3483958, -98754, -35913, -3875, -85, -2, 0, 643, 25846, 89804, 285594, 875225, 2356762, 5768901, 99999999
// 	correct[0] = 1;
// 	i = 0;
// 	stack_a = convert(ac, tab, &vars);
// 	stack_b = NULL;
// 	vars.head_a = stack_a;
// 	vars.len_a = ac - 1;
// 	vars.head_b = stack_b;
// 	vars.len_b = 0;
// 	inst_a = NULL;
// 	inst_b = NULL;
// 	vars.inst_a = inst_a;
// 	vars.inst_b = inst_b;	
// 	// while (i < ac - 1)
// 	// {
// 	// 	ft_printf("IND %d FOR VALUE %d \n", stack_a->ind, stack_a->val);
// 	// 	i++;
// 	// 	stack_a = stack_a->next;
// 	// }
// 	ft_printf("VALUE OF CLEAR STACK %d /VALUE OF CLEAR STACK\n", clear_stack_a(&(vars.head_a), &(vars.head_b), vars.len_a, &vars));
// 	ft_printf("SEND BACK TO A %d /SEND BACK TO A\n", send_back_to_a(&(vars.head_a), &(vars.head_b), vars.len_b, &vars));
// 	instructions_destacker(vars.inst_a, vars.inst_b, 'a');
// 	instructions_destacker(vars.inst_b, vars.inst_a, 'b');

// 	// while (i < 15)
// 	// {
// 	// 	if (VERBOSE)
// 	// 		ft_printf("correct[%d] = %d	: %d = val for ind %d\n", stack->ind, correct[stack->ind], stack->val, stack->ind);	
// 	// 	if (correct[stack->ind] != stack->val)
// 	// 		passed = 0;
// 	// 	i++;
// 	// 	stack = stack->next;
// 	// }
// 		stack_burner(stack_a);
// 	if (VERBOSE)
// 	{
// 		// stack_burner(stack_b);
// 	}
// 	if (passed)
// 		ft_printf("%spassed!%s\n", GRE, RES);
// 	else
// 		ft_printf("%sfailed!%s\n", RED, RES);
// 	ft_free_strs(av);
// 	free(entry);
// 	free(tab);
// 	ft_free_circular_stack(stack_a, vars.len_a);
// 	ft_free_circular_stack(stack_b, vars.len_b);
// 	ft_free_stack(vars.inst_a);
// 	ft_free_stack(vars.inst_b);
// }

void test_21()
{
	int			*tab;
	char		**av;
	char		*entry;
	int			ac;
	int			passed;
	int			correct[1];
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_instruct	*inst_a;
	t_instruct	*inst_b;
	t_push_swap vars;
	size_t			i;

	ft_printf("=====Test 21=====\n");
	ft_printf("Testing Clear Stack A on %sShort Input (15)%s...", YEL, RES);
	ac = 16;
	// entry = ft_strdup("push_swap 643 89804 -85 5768901 -3875 -3483958 25846 0 -2 99999999 -98754 -35913 285594 875225 2356762");
	// entry = ft_strdup("push_swap 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14");
	entry = ft_strdup("push_swap 33 60 32 31 70 29 28 19 26 25 24 23 22 21 20");
	// entry = ft_strdup("push_swap 99 8 12 76 6 41 68 81 55 31 70 82 77 60 3 43 73 87 13 44 75 48 5 67 11 97 27 63 33 7 45 19 66 49 14 74 65 79 62 30 2 10 84 86 25 53 40 4 15 92 16 39 23 54 34 47 9 50 1 28 26 20 88 21 46 29 64 32 24 78 89 94 38 71 98 59 93 17 35 91 36 69 42 56 85 52 83 58 22 51 90 57 95 61 96 100 80 37 18 72");
	ft_printf("%d\n", ac);
	av = ft_split(entry, ' ');
	tab = parsing(ac, av);
	passed = 1;
	// -3483958, -98754, -35913, -3875, -85, -2, 0, 643, 25846, 89804, 285594, 875225, 2356762, 5768901, 99999999
	correct[0] = 1;
	i = 0;
	stack_a = convert(ac, tab, &vars);
	stack_b = NULL;
	vars.head_a = stack_a;
	vars.len_a = ac - 1;
	vars.head_b = stack_b;
	vars.len_b = 0;
	inst_a = NULL;
	inst_b = NULL;
	vars.inst_a = inst_a;
	vars.inst_b = inst_b;	
	// while (i < ac - 1)
	// {
	// 	ft_printf("IND %d FOR VALUE %d \n", stack_a->ind, stack_a->val);
	// 	i++;
	// 	stack_a = stack_a->next;
	// }
	// ft_printf("VALUE OF CLEAR STACK %d /VALUE OF CLEAR STACK\n",);
	// ft_printf("trying stack burning A\n");
	t_stack *tmp;
 	clear_stack_a(&(vars.head_a), &(vars.head_b), vars.len_a, &vars);
	// stack_burner(tmp);
	// tmp = vars.head_b;
	// ft_printf("stack burned A\n");
	// ft_printf("trying stack burning B\n");
	// stack_burner(tmp);
	// ft_printf("stack burned B\n");
	// ft_printf("SEND BACK TO A %d /SEND BACK TO A\n", );
	send_back_to_a(&(vars.head_a), &(vars.head_b), vars.len_b, &vars);
	rev_rotate(&(vars.head_a), &vars);
	rev_rotate(&(vars.head_a), &vars);
	tmp = vars.head_a;
	ft_printf("\n");
	instructions_destacker(vars.inst_a, vars.inst_b, 'a');
	instructions_destacker(vars.inst_b, vars.inst_a, 'b');
	ft_print_int_tab(tab, ac - 1);
	ft_printf("\n");
	while (i < vars.len_a)
	{
		ft_printf("%d, ", tmp->val);
		i++;
		tmp = tmp->prev;
	}
	ft_printf("\n");
	// while (i < 15)
	// {
	// 	if (VERBOSE)
	// 		ft_printf("correct[%d] = %d	: %d = val for ind %d\n", stack->ind, correct[stack->ind], stack->val, stack->ind);	
	// 	if (correct[stack->ind] != stack->val)
	// 		passed = 0;
	// 	i++;
	// 	stack = stack->next;
	// }
		// stack_burner(stack_a);
		// ft_printf("%p", stack_b);
		// stack_burner(stack_b);
	// if (VERBOSE)
	// {
		// stack_burner(stack_a);
	// }
	// if (passed)
		// ft_printf("%spassed!%s\n", GRE, RES);
	// else
		// ft_printf("%sfailed!%s\n", RED, RES);
	// stack_burner(stack_a);
	ft_free_strs(av);
	free(entry);
	free(tab);
	ft_free_circular_stack(vars.head_a, vars.len_a);
	ft_free_circular_stack(vars.head_b, vars.len_b);
	ft_free_stack(vars.inst_a);
	ft_free_stack(vars.inst_b);
}