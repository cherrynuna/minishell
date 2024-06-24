/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_lst_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:01:35 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

void	print_env_lst(t_env_lst *lst)
{
	while (lst != NULL)
	{
		if (lst->name != NULL && lst->content != NULL)
		{
			printf ("%s", lst->name);
			printf ("=%s\n", lst->content);
		}
		lst = lst->next;
	}
}
