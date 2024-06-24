/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tree_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:58:54 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

t_pars_tree	*new_tree_node(int type, char *word)
{
	t_pars_tree	*new;

	new = (t_pars_tree *)malloc(sizeof(t_pars_tree) * 1);
	if (new == NULL)
		error_handler(word, NULL, 5);
	new->word = word;
	new->type = type;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	tree_nodeadd_back(t_pars_tree **head, t_pars_tree *new)
{
	t_pars_tree	*tem;

	if ((*head) == NULL)
		*head = new;
	else
	{
		tem = *head;
		while (tem != NULL)
		{
			if (tem->left == NULL)
				break ;
			tem = tem->left;
		}
		tem->left = new;
	}
}
