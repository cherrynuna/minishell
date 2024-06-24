/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:48:21 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/15 09:26:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

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
