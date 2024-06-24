/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:33:13 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

void	get_variable(t_pars_tree *tree)
{
	char	*word;
	int		idx;

	if (tree->type > 4)
		return ;
	idx = 0;
	word = tree->word;
	while (word[idx] != '\0')
	{
		if (word[idx] == '$')
			ft_printf ("%s\n", tree->word);
		idx++;
	}
}
