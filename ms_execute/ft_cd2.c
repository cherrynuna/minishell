/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:49:01 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/15 08:53:34 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

char	*is_cdcmd_optional(int flag, t_execute *ms_exe)
{
	t_env_lst	*curpwd;

	curpwd = NULL;
	if (flag == 1)
		curpwd = ft_getenv_from_node(ms_exe->builtin_env_lst, "HOME");
	else if (flag == 2)
		curpwd = ft_getenv_from_node(ms_exe->builtin_env_lst, "OLDPWD");
	if (curpwd != NULL)
		return (curpwd->content);
	return (NULL);
}

static int	cd_error_check(int stage, char *str, char *dst)
{
	if (access(dst, F_OK) == -1)
	{
		if (stage == 1)
			ft_fprintf (2, "diveshell: cd: %s: %s", str, \
						"No such file or directory\n");
		return (-1);
	}
	if (access(dst, X_OK) == -1)
	{
		if (stage == 1)
			ft_fprintf (2, "diveshell: cd: %s: %s", str, \
						"Permission denied\n");
		return (-1);
	}
	return (0);
}

char	*cd_getdst(int flag, char **argv, t_execute *ms_exe)
{
	char	*temp;
	char	*dst;

	if (flag != 0)
		return (is_cdcmd_optional(flag, ms_exe));
	if (argv[1] == NULL)
		return (NULL);
	dst = getcwd(NULL, 0);
	if (dst == NULL)
		dst = ft_strdup("");
	temp = ft_strjoin(dst, "/");
	free(dst);
	dst = ft_strjoin(temp, argv[1]);
	free (temp);
	if (cd_error_check(0, argv[1], dst) == -1)
	{
		free(dst);
		dst = NULL;
		if (cd_error_check(1, argv[1], argv[1]) == -1)
			return (NULL);
		dst = ft_strdup(argv[1]);
	}
	return (dst);
}

static t_env_lst	*pathcpy(char *name, t_execute *ms_exe)
{
	t_env_lst	*builtin_lev;
	t_env_lst	*env_lev;

	builtin_lev = ft_getenv_from_node(ms_exe->builtin_env_lst, name);
	if (builtin_lev == NULL)
		return (NULL);
	env_lev = ft_getenv_from_node(ms_exe->env_lst, builtin_lev->name);
	if (env_lev == NULL)
		return (builtin_lev);
	free (env_lev->content);
	env_lev->content = NULL;
	env_lev->content = ft_strdup(builtin_lev->content);
	return (builtin_lev);
}

void	cd_after_organize(int flag, char *dst, t_execute *ms_exe)
{
	t_env_lst	*cur_pwd;

	cur_pwd = NULL;
	cur_pwd = pathcpy("PWD", ms_exe);
	pathcpy("OLDPWD", ms_exe);
	if (flag == 2 && cur_pwd != NULL && cur_pwd->content != NULL)
		printf ("%s\n", cur_pwd->content);
	if (flag == 0)
		free(dst);
}
