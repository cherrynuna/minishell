/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tree_all_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:37:42 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

void	delete_tree_node(t_pars_tree **tree)
{
	if (tree == NULL || *tree == NULL)
		return ;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
	{
		if ((*tree)->type == 2)
			unlink((*tree)->word);
		if ((*tree)->word != NULL)
			free((*tree)->word);
		free(*tree);
		(*tree) = NULL;
		return ;
	}
	if ((*tree)->right != NULL)
		delete_tree_node(&(*tree)->right);
	if ((*tree)->left != NULL)
		delete_tree_node(&(*tree)->left);
	if ((*tree)->type == 2)
		unlink((*tree)->word);
	if ((*tree)->word != NULL)
		free((*tree)->word);
	if (*tree != NULL)
	{
		free(*tree);
		*tree = NULL;
	}
}
