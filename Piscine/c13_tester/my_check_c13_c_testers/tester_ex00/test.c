/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:22:28 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/19 18:30:53 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

t_btree	*btree_create_node(void *item);

int main(void)
{
	t_btree	*tree;

	tree = btree_create_node("test...");
	printf("%s\n", tree->item);
	printf("%s\n", tree->left == (void *)0 ? "it's null" : "KO <------");
	printf("%s\n", tree->right == (void *)0 ? "it's null" : "KO <------");
}
