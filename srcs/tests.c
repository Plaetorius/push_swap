/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:02:07 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 23:45:4 by tgernez          ###   ########.fr       */
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

void stack_burner_long(t_node *node)
{
	int i;
	t_node *tmp;

	if (!node)
		return ;
	tmp = node;
	i = 0;
	ft_printf("%s>>>STACK BURNING<<<\n%s", RED, RES);
	ft_printf("Going Next to Next\n");
	while (i < 40)
	{
		ft_printf("VAL %d /VAL\n", tmp->val);
		tmp = tmp->next;
		i++;
	}
	ft_printf("Going Prev to Prev\n");
	while (i < 80)
	{
		ft_printf("VAL %d /VAL\n", tmp->val);
		tmp = tmp->prev;
		i++;
	}
}

void stack_burner(t_node *node)
{
	int i;
	t_node *tmp;

	if (!node)
		return ;
	tmp = node;
	i = 0;
	ft_printf("%s>>>STACK BURNING<<<\n%s", RED, RES);
	ft_printf("Going Next to Next\n");
	while (i < 15)
	{
		ft_printf("VAL %d /VAL\n", tmp->val);
		tmp = tmp->next;
		i++;
	}
	ft_printf("Going Prev to Prev\n");
	while (i < 30)
	{
		ft_printf("VAL %d /VAL\n", tmp->val);
		tmp = tmp->prev;
		i++;
	}
}


void stack_burner_ind(t_node *node)
{
	int i;
	t_node *tmp;

	if (!node)
		return ;
	tmp = node;
	i = 0;
	ft_printf("%s>>>STACK BURNING IND<<<\n%s", RED, RES);
	ft_printf("Going Next to Next\n");
	while (i < 15)
	{
		ft_printf("IND %d /IND for val %d\n", tmp->ind, tmp->val);
		tmp = tmp->next;
		i++;
	}
	ft_printf("Going Prev to Prev\n");
	while (i < 30)
	{
		ft_printf("IND %d /IND for val %d\n", tmp->ind, tmp->val);
		tmp = tmp->prev;
		i++;
	}
}

void	success(int passed)
{
	if (passed)
		ft_printf("%spassed!%s\n", GRE, RES);
	else
		ft_printf("%sfailed!%s\n", RED, RES);
}

void	tab_checker(size_t len, int *correct, t_node *node, int *passed)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (VERBOSE)
		{
			ft_printf("correct[%d] =	%d	:	%d	= stack for ind %d\n", node->ind, correct[i], node->val, node->ind);
		}
		if (correct[i] != node->val)
			*passed = 0;
		i++;
		node = node->next;
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
	success(passed);
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
	success(passed);
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
	success(passed);
	ft_free_strs(av);
	free(entry);
}

void test_05()
{
	int			passed;
	t_stack		stack;
	t_push_swap	vars;

	ft_printf("=====Test 05=====\n");
	ft_printf("Testing Stack Creation, containing %s1%s...", YEL, RES);
	passed = 1;
	stack.head = ft_node_new(1, NULL, NULL, 0);
	ft_node_endings(stack.head, stack.head, stack.head);
	stack.len = 1;
	vars.stack_a = &stack;
	if (stack.head->val != 1 && stack.head->ind != 0)
		passed = 0;
	if (VERBOSE)
		ft_printf("\nHead:	%p\nVal:	%d\nNext:	%p\nPrev:	%p\nInd:	%d\n",
			vars.stack_a->head,
			vars.stack_a->head->val,
			vars.stack_a->head->next,
			vars.stack_a->head->prev,
			vars.stack_a->head->ind);
	success(passed);
	ft_free_circular_nodes(vars.stack_a->head);
}

void test_06()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 06=====\n");
	ft_printf("Testing Stack Creation using %s1%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 2;
	entry = ft_strdup("push_swap 1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	correct[0] = 1;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	if (VERBOSE)
		ft_printf("\n");
	tab_checker(ac - 1, correct, node, &passed);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(node);
}

void test_07()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 07=====\n");
	ft_printf("Testing Stack Creation using %s5263566 30 -356274 0 -1%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 6;
	entry = ft_strdup("push_swap 5263566 30 -356274 0 -1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[0] = 5263566;
	correct[4] = -1;
	correct[3] = 0;
	correct[1] = 30;
	correct[2] = -356274;
	if (VERBOSE)
		ft_printf("\n");
	tab_checker(ac - 1, correct, node, &passed);
	if (VERBOSE)
		stack_burner(node);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(node);
}


void test_08()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		sender;
	t_stack		receiver;
	t_node		*node;
	t_push_swap	vars;
	t_instruct	*instructs;
	int			i;
	int			correct[5];

	ft_printf("=====Test 08=====\n");
	ft_printf("Testing Push %s-1 0 56%s entry on NULL stack...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 4;
	entry = ft_strdup("push_swap -1 0 56");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	sender.len = ac - 1;
	receiver.len = 0;
	instructs = NULL;
	vars.insts = instructs;
	vars.stack_a = &sender;
	node = convert(table, sender.len, &vars);
	sender.head = node;
	receiver.head = NULL;
	vars.stack_a = &sender;
	vars.stack_b = &receiver;
	sender = *vars.stack_a;
	node = sender.head;
	correct[0] = 0;
	correct[1] = 1;
	push(&receiver, &sender, &vars);
	if (VERBOSE)
	{
		stack_burner(sender.head);
		stack_burner(receiver.head);
	}
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(sender.head);
	ft_free_circular_nodes(receiver.head);
	ft_free_stack(vars.insts);
}

void test_09()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 09=====\n");
	ft_printf("Testing Swap using %s5263566 30%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 3;
	entry = ft_strdup("push_swap 5263566 30");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	vars.insts = NULL;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[0] = 30;
	correct[1] = 5263566;
	if (VERBOSE)
		ft_printf("\n");
	swap(&stack, &vars);
	tab_checker(ac - 1, correct, vars.stack_a->head, &passed);
	if (VERBOSE)
		stack_burner(vars.stack_a->head);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(vars.stack_a->head);
	ft_free_stack(vars.insts);
}

void test_10()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 10=====\n");
	ft_printf("Testing Swap using %s5263566 30 -356274 0 -1%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 6;
	entry = ft_strdup("push_swap 5263566 30 -356274 0 -1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	vars.insts = NULL;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[1] = 5263566;
	correct[4] = -1;
	correct[3] = 0;
	correct[0] = 30;
	correct[2] = -356274;
	if (VERBOSE)
		ft_printf("\n");
	swap(&stack, &vars);
	tab_checker(ac - 1, correct, vars.stack_a->head, &passed);
	if (VERBOSE)
		stack_burner(vars.stack_a->head);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(vars.stack_a->head);
	ft_free_stack(vars.insts);
}

void test_11()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		sender;
	t_stack		receiver;
	t_node		*node;
	t_push_swap	vars;
	t_instruct	*instructs;
	int			i;
	int			correct[5];

	ft_printf("=====Test 11=====\n");
	ft_printf("Testing Push %s-1%s entry on NULL stack...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 2;
	entry = ft_strdup("push_swap -1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	sender.len = ac - 1;
	receiver.len = 0;
	instructs = NULL;
	vars.insts = instructs;
	vars.stack_a = &sender;
	node = convert(table, sender.len, &vars);
	sender.head = node;
	receiver.head = NULL;
	vars.stack_a = &sender;
	vars.stack_b = &receiver;
	sender = *vars.stack_a;
	node = sender.head;
	correct[0] = 0;
	correct[1] = 1;
	push(&receiver, &sender, &vars);
	if (VERBOSE)
	{
		ft_printf("\nSENDER ADDR %p /SENDER ADDR\n", sender.head);
		ft_printf("SENDER LEN %d /SENDER LEN\n", sender.len);
		stack_burner(receiver.head);
	}
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(sender.head);
	ft_free_circular_nodes(receiver.head);
	ft_free_stack(vars.insts);
}

void test_12()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 12=====\n");
	ft_printf("Testing Rotate using %s5263566 30 -356274 0 -1%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 6;
	entry = ft_strdup("push_swap 5263566 30 -356274 0 -1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	vars.insts = NULL;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[4] = 5263566;
	correct[3] = -1;
	correct[2] = 0;
	correct[0] = 30;
	correct[1] = -356274;
	if (VERBOSE)
		ft_printf("\n");
	rotate(&stack, &vars);
	tab_checker(ac - 1, correct, vars.stack_a->head, &passed);
	if (VERBOSE)
		stack_burner(vars.stack_a->head);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(vars.stack_a->head);
	ft_free_stack(vars.insts);
}

void test_13()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 13=====\n");
	ft_printf("Testing Rotate using %s5263566%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 2;
	entry = ft_strdup("push_swap 5263566");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	vars.insts = NULL;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[0] = 5263566;
	if (VERBOSE)
		ft_printf("\n");
	rotate(&stack, &vars);
	tab_checker(ac - 1, correct, vars.stack_a->head, &passed);
	if (VERBOSE)
		stack_burner(vars.stack_a->head);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(vars.stack_a->head);
	ft_free_stack(vars.insts);
}

void test_14()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 14=====\n");
	ft_printf("Testing Rev Rotate using %s5263566 30 -356274 0 -1%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 6;
	entry = ft_strdup("push_swap 5263566 30 -356274 0 -1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	vars.insts = NULL;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[1] = 5263566;
	correct[0] = -1;
	correct[4] = 0;
	correct[2] = 30;
	correct[3] = -356274;
	if (VERBOSE)
		ft_printf("\n");
	rev_rotate(&stack, &vars);
	tab_checker(ac - 1, correct, vars.stack_a->head, &passed);
	if (VERBOSE)
		stack_burner(vars.stack_a->head);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(vars.stack_a->head);
	ft_free_stack(vars.insts);
}

void test_15()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack;
	t_node		*node;
	t_push_swap	vars;
	int			i;
	int			correct[5];

	ft_printf("=====Test 15=====\n");
	ft_printf("Testing Rev Rotate using %s5263566%s entry...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 2;
	entry = ft_strdup("push_swap 5263566");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
	stack.len = ac - 1;
	vars.stack_a = &stack;
	vars.insts = NULL;
	node = convert(table, stack.len, &vars);
	stack.head = node;
	vars.stack_a = &stack;
	stack = *vars.stack_a;
	node = stack.head;
	correct[0] = 5263566;
	if (VERBOSE)
		ft_printf("\n");
	rev_rotate(&stack, &vars);
	tab_checker(ac - 1, correct, vars.stack_a->head, &passed);
	if (VERBOSE)
		stack_burner(vars.stack_a->head);
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(vars.stack_a->head);
	ft_free_stack(vars.insts);
}

void test_16()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack_a;
	t_stack		stack_b;
	t_node		*node;
	t_push_swap	vars;
	t_instruct	*instructs;
	int			i;
	int			correct[27];

	ft_printf("=====Test 16=====\n");
	ft_printf("Testing Phase 2 with %s646 -1 64 36 -265 0 56 1362316 97752 -939682 3235 2864357 136 75 -473 -974 -1426 87592 751 -252 737 58165 7195601 4806 -8651 836%s entry on NULL stack...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 27;
	entry = ft_strdup("push_swap 646 -1 64 36 -265 0 56 1362316 97752 -939682 3235 2864357 136 75 -473 -974 -1426 87592 751 -252 737 58165 7195601 4806 -8651 836");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	stack_a.len = ac - 1;
	stack_b.len = 0;
	instructs = NULL;
	vars.insts = instructs;
	vars.stack_a = &stack_a;
	node = convert(table, stack_a.len, &vars);
	stack_a.head = node;
	stack_b.head = NULL;
	vars.stack_a = &stack_a;
	vars.stack_b = &stack_b;
	stack_a = *vars.stack_a;
	node = stack_a.head;
	while (i < ac - 1)
	{
		correct[i] = i;
		i++;
	}
	i = 0;
	phase_2(&stack_a, &stack_b, &vars);
	if (VERBOSE)
	{
		stack_burner_long(stack_a.head);
		stack_burner_long(stack_b.head);
		ft_printf("Len Stack A: %d\n", stack_a.len);
		ft_printf("Len Stack B: %d\n", stack_b.len);
		stack_burner_ind(stack_a.head);

	}
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(stack_a.head);
	ft_free_circular_nodes(stack_b.head);
	ft_free_stack(vars.insts);
}

void test_17()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack_a;
	t_stack		stack_b;
	t_node		*node;
	t_push_swap	vars;
	t_instruct	*instructs;
	int			i;
	int			correct[24];

	ft_printf("=====Test 17=====\n");
	ft_printf("Testing Phase 2 with %s646 -1 64 10 17 %s entry on NULL stack...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 8;
	entry = ft_strdup("push_swap 646 -1 64 10 17 46 235");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	stack_a.len = ac - 1;
	stack_b.len = 0;
	instructs = NULL;
	vars.insts = instructs;
	vars.stack_a = &stack_a;
	node = convert(table, stack_a.len, &vars);
	stack_a.head = node;
	stack_b.head = NULL;
	vars.stack_a = &stack_a;
	vars.stack_b = &stack_b;
	stack_a = *vars.stack_a;
	node = stack_a.head;
	while (i < ac - 1)
	{
		correct[i] = i;
		i++;
	}
	i = 0;
	phase_2(&stack_a, &stack_b, &vars);
	if (VERBOSE)
	{
		stack_burner_long(stack_a.head);
		stack_burner_long(stack_b.head);
		ft_printf("Len Stack A: %d\n", stack_a.len);
		ft_printf("Len Stack B: %d\n", stack_b.len);
		stack_burner_ind(stack_a.head);

	}
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(stack_a.head);
	ft_free_circular_nodes(stack_b.head);
	ft_free_stack(vars.insts);	
}

void test_18()
{
	char		*entry;
	char		**av;
	int			ac;
	int			*table;
	int			passed;
	t_stack		stack_a;
	t_stack		stack_b;
	t_node		*node;
	t_push_swap	vars;
	t_instruct	*instructs;
	size_t			i;
	int			correct[24];

	ft_printf("=====Test 18=====\n");
	ft_printf("Testing Phase 3 with %s646 -1 64 10 17 %s entry on NULL stack...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 8;
	entry = ft_strdup("push_swap 646 -1 64 10 17 46 235");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	stack_a.len = ac - 1;
	stack_b.len = 0;
	instructs = NULL;
	vars.insts = instructs;
	vars.stack_a = &stack_a;
	node = convert(table, stack_a.len, &vars);
	stack_a.head = node;
	stack_b.head = NULL;
	vars.stack_a = &stack_a;
	vars.stack_b = &stack_b;
	stack_a = *vars.stack_a;
	node = stack_a.head;
	while (i < (size_t)(ac - 1))
	{
		correct[i] = i;
		i++;
	}
	i = 0;
	phase_2(&stack_a, &stack_b, &vars);
	phase_3(&stack_a, &stack_b, &vars);
	node = stack_a.head;
	if (VERBOSE)
		ft_printf("\n");
	while (i < stack_a.len && VERBOSE)
	{
		ft_printf("Rank: %d, Val: %d\n", node->ind, node->val);
		node = node->next;
		i++;
	}
	instructions_shower(vars.insts);
	// if (VERBOSE)
	// {
	// 	stack_burner_long(stack_a.head);
	// 	stack_burner_long(stack_b.head);
	// 	ft_printf("Len Stack A: %d\n", stack_a.len);
	// 	ft_printf("Len Stack B: %d\n", stack_b.len);
	// 	stack_burner_ind(stack_a.head);

	// }
	
	success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(stack_a.head);
	ft_free_circular_nodes(stack_b.head);
	ft_free_stack(vars.insts);	
}
