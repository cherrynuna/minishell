/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:04:29 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

t_pars_tree	*get_last_node(int way, t_pars_tree *tree)
{
	t_pars_tree	*temp;

	temp = tree;
	if (temp == NULL)
		return (temp);
	if (way == LEFT)
	{
		while (temp->left != NULL)
			temp = temp->left;
	}
	else if (way == RIGHT)
	{
		while (temp->right != NULL)
			temp = temp->right;
	}
	return (temp);
}
