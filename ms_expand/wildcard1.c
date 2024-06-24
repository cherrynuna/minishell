/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:15:06 by inryu             #+#    #+#             */
/*   Updated: 2024/06/15 10:56:45 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	move_next_node(t_pars_tree **cur, t_pars_tree **prev)
{
	*prev = *cur;
	*cur = (*cur)->left;
}

int	search_w(t_pars_tree *tree, t_pars_tree **cur)
{
	t_pars_tree	*tem;
	t_pars_tree	*prev;
	int			flag;

	prev = *cur;
	while (*cur != NULL)
	{
		flag = get_type_flag((*cur)->type);
		if (0 <= flag && flag < PIPE)
			search_quote(&((*cur)->word));
		if ((ft_strchr((*cur)->word, -1 * '*') || \
			ft_strchr((*cur)->word, -1 * '?')))
		{
			tem = (*cur)->left;
			if (wildcard_phase(tree, prev, *cur) == -1)
				return (-1);
			(*cur) = tem;
		}
		else
			move_next_node(cur, &prev);
	}
	return (0);
}
