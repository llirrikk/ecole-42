/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:40:25 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/11 13:47:35 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	argc_old;
	int	skip_from_start;

	skip_from_start = 1;
	argc_old = argc + skip_from_start;
	while (argc > 0 + skip_from_start)
	{
		ft_putstr(argv[argc_old - argc]);
		ft_putchar('\n');
		argc--;
	}
	return (0);
}
