/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:58:44 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/14 17:58:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <-------------------------------

void	ft_putchar(char c);
void	ft_putstr(char *str);

#define EXIT_ERROR_CODE 1
#define TRUE 1
#define FALSE 0

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	is_space(char c)
{
	if (c == ' ')
		return (TRUE);
	return (FALSE);
}

int	is_argc_valid(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Error! -> 'argc' is not valid!\n");
		return (EXIT_ERROR_CODE);
	}
	return (0);
}

int	is_argv_valid(char **argv)
{
	int	i;
	int	digit_counter;

	digit_counter = 0;
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!is_digit(argv[1][i]))
				return (EXIT_ERROR_CODE);
			else
				digit_counter++;
		}
		if (i % 2 == 1 && !is_space(argv[1][i]))
			return (EXIT_ERROR_CODE);
		i++;
	}
	if (digit_counter <= 0 || !is_digit(argv[1][i - 1]))
		return (EXIT_ERROR_CODE);
	if (digit_counter != 16 && digit_counter != 25)
		return (EXIT_ERROR_CODE);
	return (0);
}

int	input_validation(int argc, char **argv)
{
	if (is_argc_valid(argc) == EXIT_ERROR_CODE)
		return (EXIT_ERROR_CODE);
	if (is_argv_valid(argv) == EXIT_ERROR_CODE)
		return (EXIT_ERROR_CODE);
	return (0);
}

typedef struct	s_viewers
{
	int	*top;
	int	*bottom;
	int	*left;
	int	*right;
}	t_viewers;

int	viewers_malloc_check(t_viewers viewers)
{
	if (viewers.left == NULL || viewers.right == NULL)
		return (EXIT_ERROR_CODE);
	if (viewers.top == NULL || viewers.bottom == NULL)
		return (EXIT_ERROR_CODE);
	return (0);
}

void	fill_viewers(t_viewers *viewers, char **argv)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < 16 * 2 - 1)
	{
		if (is_digit(argv[1][i]))
		{
			if (i < 4 * 2)
				viewers->top[k++] = argv[1][i];
			else if (i < 8 * 2)
				viewers->bottom[k++ - 4] = argv[1][i];
			else if (i < 12 * 2)
				viewers->left[k++ - 8] = argv[1][i];
			else
				viewers->right[k++ - 12] = argv[1][i];
		}
		i++;
	}
}

// int	*create_permut(void)
// {
// 	int *result;
// 	int	i;

// 	i = 0;
// 	result = (int *)malloc(sizeof(int) * 24);
// 	while (i < 24)
// 	{
// 		while
// 		i++;
// 	}
// }

void swap(int *a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

int NextSet(int *a, int n)
{
	int	j;
	int k;
	
	j = n - 2;
	while (j != -1 && a[j] >= a[j + 1])
		j--;
	if (j == -1)
		return (FALSE); // больше перестановок нет
	k = n - 1;
	while (a[j] >= a[k])
		k--;
	swap(a, j, k);
	int l = j + 1;
	int r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r)
		swap(a, l++, r--);
	return (TRUE);
}

void print_res(int *n)
{
	for (int i = 0; i < 4; i++)
		printf("%d", n[i]);
	printf("\n");
}


int	is_col_correct(int **grid, int n, t_viewers viewers)
{
	int top = FALSE;
	int bottom = FALSE;
	int max = 0;
	int hmtmch = 0;
	for (int i = 0; i < 4; i++)
	{
		if (grid[i][n] > max)
		{
			max = grid[i][n];
			hmtmch++;
		}
	}
	if (viewers.top[n] == hmtmch)
		top = TRUE;

	max = 0;
	hmtmch = 0;
	for (int i = 0; i < 4; i++)
	{
		if (grid[3-i][n] > max)
		{
			max = grid[3-i][n];
			hmtmch++;
		}
	}
	if (viewers.bottom[n] == hmtmch)
		bottom = TRUE;


	if (bottom && top)
		return (TRUE);
	return (FALSE);
}


int is_line_correct(int **grid, int n, t_viewers viewers)
{
	int left = FALSE;
	int right = FALSE;

	int max = 0;
	int hmtmch = 0;
	for (int i = 0; i < 4; i++)
	{
		if (grid[n][i] > max)
		{
			max = grid[n][i];
			hmtmch++;
		}
	}
	if (viewers.left[n] == hmtmch)
		left = TRUE;

	max = 0;
	hmtmch = 0;
	for (int i = 0; i < 4; i++)
	{
		if (grid[n][3-i] > max)
		{
			max = grid[n][3-i];
			hmtmch++;
		}
	}
	if (viewers.right[n] == hmtmch)
		right = TRUE;

	if (left && right)
		return (TRUE);
	return (FALSE);
}



int	main(int argc, char **argv)
{
	t_viewers	viewers;

	if (input_validation(argc, argv) == EXIT_ERROR_CODE)
	{
		ft_putstr("ERROR\n");
		return (EXIT_ERROR_CODE);
	}
	viewers.top = (int *)malloc(sizeof(int) * 4);
	viewers.bottom = (int *)malloc(sizeof(int) * 4);
	viewers.left = (int *)malloc(sizeof(int) * 4);
	viewers.right = (int *)malloc(sizeof(int) * 4);
	if (viewers_malloc_check(viewers))
		return (EXIT_ERROR_CODE);
	fill_viewers(&viewers, argv);



	// ПЕРЕСТАНОВКИ
	int *a;
	int	**permuts;

	permuts = (int **)malloc(sizeof(int *) * 24);
	
	
	a = malloc(sizeof(int) * 4);



	int q;

	q = 0;
	permuts[q] = (int *)malloc(sizeof(int) * 4);
	for (int i = 0; i < 4; i++) // первая перестановка
	{
		a[i] = i + 1;
		permuts[q][i] = a[i];
	}

	q++;



	while (NextSet(a, 4))
	{
		permuts[q] = (int *)malloc(sizeof(int) * 4);
		for (int i = 0; i < 4; i++)
		{
			permuts[q][i] = a[i];
		}
		q++;
	}
	// for (int i = 0; i < 24; i++)
	// {
	// 	for (int j = 0; j < 4; j++)
	// 	{
	// 		printf("%d", permuts[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// ПЕРЕСТАНОВКИ


	int	**grid;
	grid = (int **)malloc(sizeof(int *) * 4);

	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		grid[i] = (int *)malloc(sizeof(int) * 4);
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}




	// i = 0;
	// while (i < 4)
	// {
	// 	j = 0;
	// 	while (j < 24)
	// 	{
	// 		grid[i][j] = permuts[i][j];
	// 		j++;
	// 	}
	// 	i++;
	// }

	int	i1;
	int i2;
	int i3;
	int i4;

	int o;
	//int x;
	// int y;

	// int f;
	// int z;
	//int max;
	//int hmtm[4] = {0, 0, 0, 0};



	int result_found = FALSE;

	// int	is_top_ok = FALSE;
	// int	is_bottom_ok = FALSE;
	// int	is_left_ok = FALSE;
	// int	is_right_ok = FALSE;


	//int need_next = FALSE;

	i1 = 0;
	while (i1 < 24 && !result_found)
	{
		i2 = 0;
		while (i2 < 24)
		{
			i3 = 0;
			while (i3 < 24)
			{
				i4 = 0;
				while (i4 < 24)
				{
					// helper = 0;
					// print_res(STOP_LOOPS);

					// for (int i = 0; i < 16; i++)
					// {
					// 	if (STOP_LOOPS[i] == TRUE)
					// 		helper++;
					// }
					// if (helper == 4)
					// {
					// 	result_found = TRUE;
					// 	printf("YES!\n");
					// }


					o = 0;
					while (o < 4)
					{

						// ЗАПОЛНЕНИЕ СЕТКИ
						grid[0][o] = permuts[i1][o];
						grid[1][o] = permuts[i2][o];
						grid[2][o] = permuts[i3][o];
						grid[3][o] = permuts[i4][o];
						// ЗАПОЛНЕНИЕ СЕТКИ
						
						

						// ПРОВЕРКА ЗРИТЕЛЯ


						
						if (is_col_correct(grid, 0, viewers) && is_col_correct(grid, 1, viewers) 
						&& is_col_correct(grid, 2, viewers) && is_col_correct(grid, 3, viewers) 
						&& is_line_correct(grid, o, viewers))
							result_found = TRUE;





						// hmtm = 0;
						// max = 0;
						// f = 0;
						// while (f < 4)
						// {
						// 	z = 0;
						// 	while (z < 4)
						// 	{
						// 		if (grid[z][f] > max)
						// 		{
						// 			max = grid[z][f];
						// 			hmtm++;
						// 		}
						// 		z++;
						// 	}
						// 	//printf("hmtm = %d\n", hmtm);
							
						// 	if (viewers.top[f] == hmtm)
						// 	{
						// 		need_next = FALSE;
						// 		is_top_ok = TRUE;
						// 		break;
						// 	}
						// 	else
						// 	{
						// 		break;
						// 		need_next = TRUE;
						// 	}
						// 	max = 0;
						// 	hmtm = 0;
						// 	f++;
						// }

						

						// if (is_top_ok)
						// 	printf("is_top_ok = %d\n", is_top_ok);
						
						// hmtm = 0;
						// max = 0;
						// f = 0;
						// while (f < 4)
						// {
						// 	z = 0;
						// 	while (z < 4)
						// 	{
						// 		if (grid[3 - z][f] > max)
						// 		{
						// 			max = grid[3 - z][f];
						// 			hmtm++;
						// 		}
						// 		z++;
						// 	}
						// 	if (viewers.bottom[f] == hmtm)
						// 	{
						// 		//need_next = TRUE;
						// 		is_bottom_ok = TRUE;
								
						// 	}
						// 	else
						// 		need_next = TRUE;
						// 	f++;
						// }

						// hmtm = 0;
						// max = 0;
						// f = 0;
						// while (f < 4)
						// {
						// 	z = 0;
						// 	while (z < 4)
						// 	{
						// 		if (grid[f][z] > max)
						// 		{
						// 			max = grid[f][z];
						// 			hmtm++;
						// 		}
						// 		z++;
						// 	}
						// 	if (viewers.left[f] == hmtm)
						// 	{
						// 		//need_next = TRUE;
						// 		is_left_ok = TRUE;
						// 	}
						// 	else
						// 		need_next = TRUE;
						// 	f++;
						// }
						
						// hmtm = 0;
						// max = 0;
						// f = 0;
						// while (f < 4)
						// {
						// 	z = 0;
						// 	while (z < 4)
						// 	{
						// 		if (grid[f][3 - z] > max)
						// 		{
						// 			hmtm++;
						// 			max = grid[f][3 - z];
						// 		}
						// 		z++;
						// 	}
						// 	if (viewers.top[f] == hmtm)
						// 	{
						// 		//need_next = TRUE;
						// 		is_right_ok = TRUE;
						// 	}
						// 	else
						// 		need_next = TRUE;
						// 	f++;
						// }
						// ПРОВЕРКА ЗРИТЕЛЯ



						o++;
					}
					



					i4++;
				}
				//need_next = FALSE;
				i3++;
			}
			i2++;
		}
		i1++;
	}



	printf("\nFINAL:\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}


	return (0);
}

