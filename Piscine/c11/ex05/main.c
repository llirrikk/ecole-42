/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:52:05 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/17 17:18:09 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
#define ERROR_RETURN -1
#define ZERO_DIVIDING_RETURN 1

int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

int		plus(int x, int y);
int		minus(int x, int y);
int		division(int x, int y);
int		multiply(int x, int y);
int		mod(int x, int y);

int	get_operator_id(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '/')
		return (2);
	if (c == '*')
		return (3);
	if (c == '%')
		return (4);
	return (ERROR_RETURN);
}

int	is_sign_correct(char *sign)
{
	int	operator_id;

	if (ft_strlen(sign) != 1)
		return (FALSE);
	else
	{
		operator_id = get_operator_id(sign[0]);
		if (operator_id == ERROR_RETURN)
			return (FALSE);
	}
	return (TRUE);
}

int	y_zero_exception(int y, int operator_id)
{
	if (y == 0)
	{
		if (operator_id == get_operator_id('/'))
		{
			ft_putstr("Stop : division by zero\n");
			return (ERROR_RETURN);
		}
		if (operator_id == get_operator_id('%'))
		{
			ft_putstr("Stop : modulo by zero\n");
			return (ERROR_RETURN);
		}
	}
	return (0);
}

int	calc(int x, int operator_id, int y)
{
	int	(*operations[5])(int x, int y);

	operations[0] = plus;
	operations[1] = minus;
	operations[2] = division;
	operations[3] = multiply;
	operations[4] = mod;
	if (y_zero_exception(y, operator_id) == ERROR_RETURN)
		return (ZERO_DIVIDING_RETURN);
	ft_putnbr(operations[operator_id](x, y));
	ft_putchar('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 4)
		return (1);
	else
	{
		if (is_sign_correct(argv[2]) != FALSE)
		{
			x = ft_atoi(argv[1]);
			y = ft_atoi(argv[3]);
			return (calc(x, get_operator_id(argv[2][0]), y));
		}
		else
		{
			ft_putstr("0\n");
			return (1);
		}
	}
}
