/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_arr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:32:59 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

static char	*get_env_str(t_env_lst	*cur)
{
	char	*result;
	char	*temp;

	result = NULL;
	if (cur != NULL && cur->content != NULL)
	{
		temp = ft_strjoin(cur->name, "=");
		if (temp == NULL)
			error_handler("alloc", NULL, 12);
		result = ft_strjoin(temp, cur->content);
		if (result == NULL)
			error_handler("alloc", NULL, 12);
		free (temp);
	}
	return (result);
}

char	**get_env_arr(t_env_lst *env)
{
	t_env_lst	*cur;
	char		**result;
	int			idx;

	cur = env;
	idx = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		idx++;
	}
	result = (char **)malloc(sizeof(char *) * (idx + 1));
	if (result == NULL)
		error_handler("get_env_arr", NULL, 12);
	result[idx] = NULL;
	cur = env;
	idx = 0;
	while (cur != NULL)
	{
		result[idx] = get_env_str(cur);
		cur = cur->next;
		idx++;
	}
	return (result);
}
