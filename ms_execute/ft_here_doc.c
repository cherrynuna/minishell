/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:41:23 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/15 21:15:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static char	*get_here_doc_tempfile(char *str, int idx)
{
	char	*file_path;
	char	*nbr;

	nbr = ft_itoa(idx);
	if (nbr == NULL)
		error_handler("alloc", NULL, 12);
	file_path = ft_strjoin(str, nbr);
	if (file_path == NULL)
		error_handler("alloc", NULL, 12);
	free(nbr);
	return (file_path);
}

char	*get_heredoc_path(void)
{
	char			*file_path;
	char			*tem;
	unsigned int	idx;

	idx = 1;
	file_path = NULL;
	tem = ft_strdup("/Users/jjhang/.temp");
	if (tem == NULL)
		error_handler("alloc", NULL, 12);
	while (1)
	{
		file_path = get_here_doc_tempfile(tem, idx);
		if (access(file_path, W_OK) != 0)
			break ;
		else
		{
			free(file_path);
			file_path = NULL;
		}
		idx++;
	}
	free(tem);
	return (file_path);
}

static void	ft_heredoc_child(int fd, t_pars_tree *limiter, t_execute *ms_exe)
{
	char	*eof;
	int		result;

	result = 0;
	eof = NULL;
	signal_on(1);
	while (1)
	{
		eof = readline("heredoc>> ");
		if (eof == NULL || ft_strcmp(eof, limiter->word) == 0)
			break ;
		if (ft_strchr(eof, '$'))
			eof = expand_wo_q(eof, ms_exe);
		ft_fprintf (fd, eof);
		ft_fprintf (fd, "\n");
		free(eof);
	}
	free(eof);
	close(fd);
	exit (result);
}

static int	ft_here_doc(t_pars_tree *limiter, t_process *data, \
												t_execute *ms_exe)
{
	pid_t	pid;
	int		filedesc;
	int		status;
	int		trap;

	trap = 0;
	data->here_doc_path = get_heredoc_path();
	filedesc = open(data->here_doc_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	signal_on(3);
	pid = fork();
	if (pid == -1)
		error_handler(NULL, "forking failed", 1);
	if (pid == 0)
		ft_heredoc_child(filedesc, limiter, ms_exe);
	wait(&status);
	trap = WEXITSTATUS(status);
	trap = get_wsignal(status, trap);
	close(filedesc);
	free(limiter->word);
	limiter->word = data->here_doc_path;
	limiter->type = 2;
	data->here_doc_path = NULL;
	return (trap);
}

int	check_here_doc(int trap, \
					t_pars_tree *tree, t_process *data, t_execute *ms_exe)
{
	int	flag;

	if (tree == NULL)
		return (trap);
	if (trap != 0)
		return (1);
	flag = get_type_flag(tree->type);
	if (flag == REDIRECTION && \
		ft_strcmp(tree->word, "<<") == 0 && tree->left != NULL)
		trap = ft_here_doc(tree->left, data, ms_exe);
	if (flag == REDIRECTION && \
		ft_strcmp(tree->word, "<<") != 0 && tree->left != NULL)
		tree->left->type = JUST_FILENAME;
	if (tree->left != NULL)
		trap = check_here_doc(trap, tree->left, data, ms_exe);
	if (tree->right != NULL)
		trap = check_here_doc(trap, tree->right, data, ms_exe);
	return (trap);
}
