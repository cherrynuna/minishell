/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_from_node_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:48:02 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

t_env_lst	*ft_getenv_from_node(t_env_lst *env_lst, char *name)
{
	while (env_lst != NULL)
	{
		if (ft_strcmp(env_lst->name, name) == 0)
			break ;
		env_lst = env_lst->next;
	}
	return (env_lst);
}
