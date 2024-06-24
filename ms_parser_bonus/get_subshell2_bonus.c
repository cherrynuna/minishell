/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_subshell2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:33 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

t_pars_tree	*add_new_subshell(t_pars_tree *new_node, t_pars_tree **ptr)
{
	t_pars_tree	*temp;

	if ((*ptr) == NULL)
		(*ptr) = new_node;
	else if ((*ptr)->type < 64)
	{
		temp = get_last_node(LEFT, *ptr);
		temp->left = new_node;
	}
	else
	{
		temp = get_last_node(RIGHT, *ptr);
		if (temp->type < PIPE)
		{
			temp = get_last_node(LEFT, temp);
			temp->left = new_node;
		}
		else
			temp->right = new_node;
	}
	return (new_node);
}
