/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:23:40 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/20 21:18:04 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	if (*root)
	{
		if ((*cmpf)((*root)->item, item) > 0)
			btree_insert_data(&((*root)->left), item, cmpf);
		else
			btree_insert_data(&((*root)->right), item, cmpf);
	}
	else
	{
		*root = btree_create_node(item);
		return ;
	}
}
