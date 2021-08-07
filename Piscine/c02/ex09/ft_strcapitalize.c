/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:53:48 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/07 13:54:05 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	is_aord(char c)
{
	if ((is_alpha(c)) || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	is_upcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	to_upcase(char c)
{
	return (c - 32);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	t;

	if (is_upcase(*(str + 0)))
	{
		i = 1;
	}
	else
	{
		i = 0;
		if (is_alpha(*(str + 0)))
			*(str + 0) = to_upcase(*(str + 0));
	}
	while (*(str + i) != '\0')
	{
		t = *(str + i);
		if (!is_aord(*(str + i - 1)) && !is_upcase(t) && is_alpha(t))
		{
			*(str + i) = to_upcase(t);
		}
		i++;
	}
	return (str);
}
