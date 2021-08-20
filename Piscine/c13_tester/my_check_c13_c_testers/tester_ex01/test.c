/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:43:09 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/20 20:15:29 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = malloc(sizeof(t_btree));
	if (tree == NULL)
		return ((void *)0);
	tree->item = item;
	tree->left = (void *)0;
	tree->right = (void *)0;
	return (tree);
}

void	applyf(void *item)
{
	printf("%s\n", item);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));

int main(void)
{
	t_btree	*tree;

	tree = btree_create_node("item root");
	tree->left = btree_create_node("item left");
	tree->left->left = btree_create_node("item left left");
	tree->left->right = btree_create_node("item left right");
	tree->right = btree_create_node("item right");
	tree->right->right = btree_create_node("item right right");
	tree->right->left = btree_create_node("item right left");

	btree_apply_prefix(tree, &applyf);
}
