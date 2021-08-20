/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:23:59 by sserwyn           #+#    #+#             */
/*   Updated: 2021/08/20 21:17:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_btree.h"
// #include <stdio.h>

// #include <stdlib.h>

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (*(s1 + i) == *(s2 + i))
// 	{
// 		if (*(s1 + i) == '\0')
// 			return (*(s1 + i) - *(s2 + i));
// 		i++;
// 	}
// 	return (*(s1 + i) - *(s2 + i));
// }

// t_btree	*btree_create_node(void *item)
// {
// 	t_btree	*tree;

// 	tree = malloc(sizeof(t_btree));
// 	if (tree == NULL)
// 		return ((void *)0);
// 	tree->item = item;
// 	tree->left = (void *)0;
// 	tree->right = (void *)0;
// 	return (tree);
// }

// void	applyf(void *item)
// {
// 	printf("%s\n", item);
// }

// void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

// int main(void)
// {
// 	t_btree	*tree;

// 	tree = btree_create_node("item root");
// 	tree->left = btree_create_node("item left");
// 	tree->left->left = btree_create_node("item left left");
// 	tree->left->right = btree_create_node("item left right");
// 	tree->right = btree_create_node("item right");
// 	tree->right->right = btree_create_node("item right right");
// 	tree->right->left = btree_create_node("item right left");

// 	btree_insert_data(&tree, "item left left left", &ft_strcmp);
// }

#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

t_btree *btree_create_node(char *item)
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

void	applyf(char *item)
{
	printf("%s", item);
}

int	cmp(char *a, char *b)
{
	return (*a - *b);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(char *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	btree_apply_infix(root->right, applyf);
}

void	btree_insert_data(t_btree **root, char *item, int (*cmpf)(char *, char *));

int	main()
{
	t_btree *tree;
	tree = NULL;
	btree_insert_data(&tree, "5", &cmp);
	btree_insert_data(&tree, "3", &cmp);
	btree_insert_data(&tree, "8", &cmp);
	btree_insert_data(&tree, "9", &cmp);
	btree_insert_data(&tree, "7", &cmp);
	btree_insert_data(&tree, "1", &cmp);
	btree_apply_infix(tree, &applyf);
	free(tree);
	return (0);
}
