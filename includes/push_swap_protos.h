/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protos.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:41:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 2 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PROTOS_H
# define PUSH_SWAP_PROTOS_H
# include "push_swap.h"
# include "push_swap_structs.h"

/* Tests */
void		test_01(void);
void		test_02(void);
void		test_03(void);
void		test_04(void);
void		test_05(void);
void		test_06(void);
void		test_07(void);
void		test_08(void);
void		test_09(void);
void		test_10(void);
void		test_11(void);
void		test_12(void);
void		test_13(void);
void		test_14(void);
void		test_15(void);
void		test_16(void);
void		test_17(void);
void		test_18(void);
void		test_19(void);
void		test_20(void);
void		test_21(void);
void		test_22(void);
void		test_23(void);
void		test_24(void);
void		test_25(void);
void		test_26(void);
void		test_27(void);
void		test_28(void);
void		stack_burner_ind(t_node *node);
void		print_stack(t_stack *stack);
void		stack_burner(t_node *node);

/*	Parsing	1*/
int			*parsing(int ac, char **av, t_push_swap *vars);
/*	Parsing 2*/
int			get_arg_number(char *arg, int **table, int *current);


/* Atoi Def */
long		atoi_def(const char *str);

/* Converting */
t_node		*convert(int *table, size_t len, t_push_swap *vars);

/* Node Functions */
t_node		*ft_node_new(int val, t_node *next, t_node *prev, int ind);
void		ft_node_endings(t_node *elem, t_node *next, t_node *prev);
void		ft_free_circular_nodes(t_node *node);
void		ft_free_stack(t_instruct *stack);
int			max_val_circular_nodes(t_node *node);

/* Instructions 1 */
int			swap(t_stack *stack, t_push_swap *vars);
int			push(t_stack *receiver, t_stack *sender, t_push_swap *vars);

/* Instructions 2 */
int			rotate(t_stack *stack, t_push_swap *vars);
int			rev_rotate(t_stack *stack, t_push_swap *vars);
int			push_bottom(t_stack *receiver, t_stack *sender, t_push_swap *vars);
int			splits_number(size_t len, t_push_swap *vars);

/* Sorting Functions */
int			push_elements_in_b(t_stack *stack_a, t_stack *stack_b,
				t_push_swap *vars);
int			sort_three(t_stack *stack, t_push_swap *vars);
int			shortest_to_top(t_stack *stack, int ind);
int			next_ind_present(t_stack *stack, int i);
int			is_stack_sorted(t_stack *stack);

/* Instruction Functions */
int			new_instruct(int val, t_push_swap *vars);
void		stack_association(t_stack *stack_a, t_stack *stack_b,
				t_push_swap *vars);
void		instructions_shower(t_instruct *stack);

/* Do Instructions */
int			do_rotate(t_stack *stack, int times, t_push_swap *vars);
int			do_rev_rotate(t_stack *stack, int times, t_push_swap *vars);

/* Phases */
int			phase_1(char **av, int ac, t_push_swap *vars);
int			phase_2(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars);
int			phase_3(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars);
void		memory_cleaning(t_push_swap *vars);

/* Utils */
int			zero_dist_max(int a, int b);
int			ft_abs(int a);


#endif
