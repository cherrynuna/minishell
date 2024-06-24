/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_preprocess_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:48:21 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:58 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand_bonus.h"

DIR	*wildcard_preprocess(t_pars_tree *tree)
{
	char	*dirbuf;
	DIR		*ptr;

	if (tree == NULL)
		return (NULL);
	dirbuf = getcwd(NULL, 0);
	if (dirbuf == NULL)
		error_handler("wildcard", NULL, 12);
	ptr = opendir(dirbuf);
	free(dirbuf);
	return (ptr);
}

int	get_wildcard_type(t_pars_tree *tree)
{
	if (tree->word[0] == '.')
		return (1);
	if (tree->word[ft_strlen(tree->word) - 1] == '/')
	{
		tree->word[ft_strlen(tree->word) - 1] = '\0';
		return (5);
	}
	return (0);
}
