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

void stack_burner(t_node *node)
{
	int i;
	t_node *tmp;

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
	ft_printf("Testing Push %s56 0 -1%s entry on NULL stack...", YEL, RES);
	passed = 1;
	i = 0;
	ac = 4;
	entry = ft_strdup("push_swap 56 0 -1");
	av = ft_split(entry, ' ');
	table = parsing(ac, av);
	// ft_print_int_tab(table, 5);
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
	// if (VERBOSE)
	// 	ft_printf("\n");
	// tab_checker(sender.len, correct, sender.head, &passed);
	if (VERBOSE)
	{
		stack_burner(sender.head);
		stack_burner(receiver.head);
	}
	// success(passed);
	free(table);
	ft_free_strs(av);
	free(entry);
	ft_free_circular_nodes(sender.head);
	ft_free_circular_nodes(receiver.head);
	ft_free_stack(vars.insts);
}
