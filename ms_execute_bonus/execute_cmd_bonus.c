/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:32:01 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

void	open_pipe(t_process *data)
{
	if (data->last_process == FALSE)
	{
		pipe(data->fd);
		data->pipe_num++;
	}
}

static void	search_d(t_pars_tree *tree, t_execute *ms_exe, int flag)
{
	int	start;

	while (tree != NULL)
	{
		start = 0;
		while (tree->word[start] != '\0')
		{
			if (tree->word[start] == '\"' && flag == 0)
				flag = 1;
			else if (tree->word[start] == '\"' && flag == 1)
				flag = 0;
			if (tree->word[start] == '\'' && flag == 0)
			{
				start++;
				while (tree->word[start] != '\'')
					start++;
			}
			if (tree->word[start] == '$')
				replace_d(tree, ms_exe, &start, 1);
			start++;
		}
		tree = tree->left;
	}
}

static t_pars_tree	*expand_call(t_pars_tree *tree, t_execute *ms_exe)
{
	t_pars_tree	*cur;
	int			flag;

	cur = tree;
	search_d(tree, ms_exe, 0);
	flag = search_w(tree, &cur);
	if (flag == -1)
	{
		ft_fprintf (2, "dive: %s: ambiguous redirect\n", cur->word);
		tree->type = INT_MAX;
		get_last_execute_exit_code(1, ms_exe);
		return (NULL);
	}
	return (tree);
}

t_pars_tree	*execute_cmd(t_pars_tree *tree, t_execute *ms_exe, t_process *data)
{
	int	process_flag;

	process_flag = 0;
	if (tree != NULL && (tree->type & SUB_SHELL) == SUB_SHELL)
		process_flag = 1;
	if (expand_call(tree, ms_exe) == NULL)
		return (NULL);
	get_token_line(&data->redirection, &data->argv, tree);
	if (process_flag == 1 || data->pipe_num != 0 \
		|| is_builtin_function(data->argv[0]) == 0)
	{
		data->process_num++;
		data->pid = fork();
		if (data->pid == -1)
			error_handler(data->argv[0], "forking failed", 1);
		if (data->pid != 0)
		{
			parent_process(data);
			return (NULL);
		}
	}
	child_process(data->pid, ms_exe, data);
	return (NULL);
}
