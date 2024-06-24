/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wo_q.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:02:54 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/14 21:08:44 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*expand_wo_q(char *eof, t_execute *ms_exe)
{
	t_pars_tree	*tree;
	int			start;

	tree = new_tree_node(1, eof);
	start = 0;
	while (eof[start] != '\0')
	{
		if (eof[start] == '$')
			replace_d(tree, ms_exe, &start, 1);
		start++;
	}
	free(tree);
	return (eof);
}
