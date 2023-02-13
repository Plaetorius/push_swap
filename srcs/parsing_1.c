/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:45:37 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/13 13:22:04 by tgernez          ###   ########.fr       */
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
			return (1);
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
	}
	ft_free_strs(strs);
	return (0);
}

static int	check_doubles(int ac, int *table)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (table[i] == table[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parsing(int ac, char **av)
{
	int	*tab;
	int	len;

	if (ac == 1)
		return (NULL);
	len = arguments_checker(ac, av);
	if (len == -1)
		return (NULL);
	tab = ft_calloc(sizeof(int), len);
	if (!tab)
		return (NULL);
	ft_printf("Done\n");
	
	if (fill_table(ac, av, &tab))
		return (free(tab), NULL);
	if (check_doubles(ac, tab) == 1)
		return (free(tab), NULL);
	return (tab);
}
