/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:10 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/23 19:30:33 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <----------------

char	**read_console(void);

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 1)
		map = read_console();
	else if (argc > 1)
		//map = read_file(argc, argv);
	(void) argv;
}
