/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:54:38 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/15 10:37:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	is_filetype(char *str)
{
	if (str[0] != '.')
		return (4);
	return (1);
}

static int	dp_turnout(int type, struct dirent *dir, char *input)
{
	int	s_len;
	int	p_len;
	int	result;

	s_len = 0;
	p_len = 0;
	result = 0;
	s_len = ft_strlen(dir->d_name);
	if (input != NULL)
		p_len = ft_strlen(input);
	if (type == 5 && s_len != 0 && is_filetype(dir->d_name) == 4)
		result = dp(dir->d_name, input, s_len, p_len);
	if (type == 1 && s_len != 0 && is_filetype(dir->d_name) == 1)
		result = dp(dir->d_name, input, s_len, p_len);
	if (type != 1 && s_len != 0 && is_filetype(dir->d_name) == 4)
		result = dp(dir->d_name, input, s_len, p_len);
	return (result);
}

static int	wildcard(DIR *ptr, t_pars_tree **head, t_pars_tree *tree)
{
	struct dirent	*dir;
	t_pars_tree		*new;
	int				type;

	if (ptr == NULL)
		return (0);
	type = get_wildcard_type(tree);
	while (1)
	{
		dir = readdir(ptr);
		if (dir == NULL)
			break ;
		if (dp_turnout(type, dir, tree->word))
		{
			if (type == 5 && dir->d_type != 4)
				continue ;
			if (type == 5 && dir->d_type == 4)
				new = new_tree_node(1, ft_strjoin(dir->d_name, "/"));
			else
				new = new_tree_node(1, ft_strdup(dir->d_name));
			tree_nodeadd_back(head, new);
		}
	}
	return (close_and_replace(ptr, head, tree, type));
}

static int	is_redi_prev_node(t_pars_tree *prev)
{
	int	flag;

	if (prev == NULL)
		return (0);
	flag = get_type_flag(prev->type);
	if (flag == REDIRECTION)
		return (TRUE);
	return (FALSE);
}

int	wildcard_phase(t_pars_tree *tree, t_pars_tree *prev, t_pars_tree *cur)
{
	DIR			*ptr;
	t_pars_tree	*head;
	int			wildcard_flag;
	int			prev_flag;

	head = NULL;
	ptr = wildcard_preprocess(tree);
	if (ptr == NULL)
		return (0);
	prev_flag = is_redi_prev_node(prev);
	wildcard_flag = wildcard(ptr, &head, cur);
	if (prev_flag == TRUE && wildcard_flag == TRUE)
		return (-1);
	return (0);
}
