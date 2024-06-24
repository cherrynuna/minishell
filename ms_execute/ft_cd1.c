/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:47 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/15 08:53:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	flag_env_manager(char *type, t_execute *ms_exe)
{
	t_env_lst	*curpwd;

	curpwd = ft_getenv_from_node(ms_exe->builtin_env_lst, type);
	if (curpwd == NULL)
	{
		ft_fprintf (2, "cd: %s no set\n", type);
		return (-1);
	}
	return (0);
}

/*int chdir(const char *path)*/
static int	cd_preprocess(int *flag, char **argv, t_execute *ms_exe)
{
	int			idx;
	int			res;

	idx = 0;
	res = 0;
	while (argv[idx] != NULL)
	{
		if (idx == 1 && ft_strcmp(argv[idx], "-") == 0)
			*flag = 2;
		idx++;
	}
	if (idx == 1)
		*flag = 1;
	if (idx > 2)
		return (builtin_error_handler("cd", "too many arguments", -1));
	if (*flag == 1)
		res = flag_env_manager("HOME", ms_exe);
	else if (*flag == 2)
		res = flag_env_manager("OLDPWD", ms_exe);
	return (res);
}

static t_env_lst	*renew_pwd(char *env_name, char *path, t_execute *ms_exe)
{
	t_env_lst	*temp;
	char		*name;

	name = ft_strdup(env_name);
	if (name == NULL)
		error_handler(NULL, NULL, 12);
	temp = ft_getenv_from_node(ms_exe->builtin_env_lst, name);
	if (temp == NULL)
	{
		temp = ft_env_lstnew(name, NULL);
		ft_env_lstadd_back(&ms_exe->builtin_env_lst, temp);
	}
	else if (temp != NULL)
		free(name);
	if (temp != NULL && temp->content != NULL)
	{
		free(temp->content);
		temp->content = NULL;
	}
	temp->content = path;
	return (temp);
}

static int	go_to_pwd(char *path, t_execute *ms_exe)
{
	char		*cur_path;

	cur_path = getcwd(NULL, 0);
	if (cur_path == NULL)
	{
		ft_fprintf (2, "diveshell: cd: invaild path: go to ROOT directory\n");
		return (1);
	}
	if (chdir(path) != 0)
	{
		free(cur_path);
		return (builtin_error_handler("cd", "failed to change directory", 1));
	}
	renew_pwd("OLDPWD", cur_path, ms_exe);
	cur_path = NULL;
	cur_path = getcwd(NULL, 0);
	if (cur_path == NULL)
		return (builtin_error_handler("cd", "No such file or directory", 12));
	renew_pwd("PWD", cur_path, ms_exe);
	return (0);
}

int	ft_cd(char **argv, t_execute *ms_exe)
{
	char	*dst;
	int		check;
	int		flag;

	flag = 0;
	if (cd_preprocess(&flag, argv, ms_exe) < 0)
		return (1);
	dst = cd_getdst(flag, argv, ms_exe);
	if (dst == NULL)
		return (1);
	check = go_to_pwd(dst, ms_exe);
	if (check != 0)
	{
		chdir("/");
		check = go_to_pwd("/", ms_exe);
	}
	cd_after_organize(flag, dst, ms_exe);
	return (0);
}
