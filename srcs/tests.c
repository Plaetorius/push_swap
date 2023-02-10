/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:02:07 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 18:40:50 by tgernez          ###   ########.fr       */
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
