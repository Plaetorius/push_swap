/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:45:37 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/23 14:03:23 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numbers_counter(char *arg, int *numbers_count)
{
	char	**strs;
	int		i;
	int		j;

	strs = ft_split(arg, ' ');
	if (!strs)
		return (1);
	i = 0;
	while (strs[i])
	{
		j = 0;
		if (strs[i][j] == '-')
			j++;
		while (('0' <= strs[i][j] && strs[i][j] <= '9' && strs[i][j]))
			j++;
		if (strs[i][j] != '\0')
			return (ft_free_strs(strs), 1);
		(*numbers_count)++;
		i++;
	}
	ft_free_strs(strs);
	return (0);
}

static int	arguments_checker(int ac, char **av)
{
	int	i;
	int	numbers_count;

	i = 1;
	numbers_count = 0;
	while (i < ac && av[i])
	{
		if (numbers_counter(av[i], &numbers_count) == 1)
			return (-1);
		i++;
	}
	return (numbers_count);
}

static int	fill_table(int ac, char **av, int **table)
{
	int		i;
	char	**strs;
	int		j;
	int		current;

	i = 1;
	current = 0;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		if (!strs)
			return (1);
		j = 0;
		while (strs[j])
		{
			if (get_arg_number(strs[j], table, &current) == 1)
				return (ft_free_strs(strs), 1);
			j++;
		}
		i++;
		ft_free_strs(strs);
	}
	return (0);
}

static int	check_doubles(int len, int *table)
{
	int	i;
	int	j;

	i = 0;
	if (!table)
		return (1);
	if (len > 1 && table[0] == table[1])
		return (1);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (table[i] == table[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parsing(int ac, char **av, t_push_swap *vars)
{
	int	*tab;
	int	len;

	if (ac == 1)
		return (NULL);
	len = arguments_checker(ac, av);
	if (len == -1 || len == 0)
		return (write(2, "Error\n", 6), NULL);
	tab = ft_calloc(sizeof(int), len);
	if (!tab)
		return (NULL);
	vars->stack_a->len = len;
	if (fill_table(ac, av, &tab))
		return (free(tab), write(2, "Error\n", 6), NULL);
	if (check_doubles(len, tab) == 1)
		return (free(tab), write(2, "Error\n", 6), NULL);
	return (tab);
}
