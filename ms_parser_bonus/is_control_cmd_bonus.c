/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_control_cmd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:03:12 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

int	is_control_cmd(char *ptr)
{
	if (ft_strncmp("||", ptr, 2) == 0)
		return (1);
	if (ft_strncmp("&&", ptr, 2) == 0)
		return (1);
	return (0);
}
