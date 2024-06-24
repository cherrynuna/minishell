/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_w_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:29:31 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:58 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand_bonus.h"

void	replace_w(t_pars_tree **head, t_pars_tree **tree)
{
	t_pars_tree	*last;
	t_pars_tree	*next;

	next = (*tree)->left;
	(*tree)->type = SKIP;
	last = *head;
	while (last != NULL)
	{
		if (last->left == NULL)
			break ;
		last = last->left;
	}
	last->left = next;
	(*tree)->left = *head;
}
