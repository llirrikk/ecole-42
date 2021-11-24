/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:53:53 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/24 15:07:56 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *in, ...);
void	ft_putchar(char c, int *count_symbols);
int		ft_strlen(const char *str);
void	ft_putstr(char *str, int *count_symbols);
char	*ft_itoa(int n);
char	*ft_ltoa(long long int n);
void	ft_putnbr_base(unsigned int nbr, char *base, int *count_symbols);
char	*pointer_to_str(unsigned long p);

#endif