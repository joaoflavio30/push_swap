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

#include <stdlib.h>
#include <stdio.h>

void	valid_input(char **argv)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;

	while (argv[++i])
	{
		j = -1;
		flag = 0;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && (flag < 2))
			{
				if (flag == 1 || (flag == 0 && j != 0))
					exit(1);
				flag++;
				continue ;
			}
			if ((argv[i][j] != 32 && argv[i][j] != '\t') && (argv[i][j] < '0'
			|| argv[i][j] > '9'))
				exit(1);
			if (argv[i][j] == 32)
				flag = 0;
		}
	}

}

int	main(int argc, char **argv)
{
	// int	*stack1;
	// int	*stack2;

	if (argc == 1)
		return (1);

	valid_input(argv);
	printf("validação correta\n");
}
