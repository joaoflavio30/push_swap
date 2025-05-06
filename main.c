/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardoso <jcardoso@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:16:52 by jcardoso          #+#    #+#             */
/*   Updated: 2025/04/10 14:38:00 by jcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack **stack_a, char **argv)
{
	int		i;
	long	num;
	t_stack	*new;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(stack_a, NULL);
		new = ft_stacknew((int)num);
		if (!new)
			error_exit(stack_a, NULL);
		ft_stackadd_back(stack_a, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!valid_input(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stack(&stack_a, argv);
	if (check_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		ft_stackclear(&stack_a);
		return (1);
	}
	sort_stack(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
