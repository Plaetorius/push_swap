/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:08:19 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 18:34:45 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_list	*get_instructs(void)
{
	char	*instruct;
	t_list	*tmp;
	t_list	*head;

	head = NULL;
	while (1)
	{
		instruct = get_next_line(0);
		if (!instruct)
			break ;
		tmp = ft_lstnew(instruct);
		if (!tmp)
			return (free_checker_lst(head), NULL);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*instructs;
	t_stack	stack;

	stack.len = 0;
	stack.head = NULL;
	if (ac == 1)
		return (EXIT_FAILURE);
	instructs = get_instructs();
	ft_print_int_tab(parsing_to_stack(ac, av, &stack), ac - 1);
	// execute_instructs(instructs, stack);
}
