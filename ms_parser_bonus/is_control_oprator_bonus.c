/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_control_oprator_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:02:14 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

int	is_control_oprator(char *ptr)
{
	if (ft_strncmp("||", ptr, 2) == 0)
		return (2);
	if (ft_strncmp("&&", ptr, 2) == 0)
		return (2);
	if (ft_strncmp("&", ptr, 1) == 0)
		return (1);
	if (ft_strncmp(";;&", ptr, 3) == 0)
		return (3);
	if (ft_strncmp(";;", ptr, 2) == 0)
		return (2);
	if (ft_strncmp(";&", ptr, 2) == 0)
		return (2);
	if (ft_strncmp(";", ptr, 1) == 0)
		return (1);
	if (ft_strncmp("|&", ptr, 2) == 0)
		return (2);
	if (ft_strncmp("|", ptr, 1) == 0)
		return (1);
	return (0);
}

int	is_limited_control_operator(char *ptr)
{
	if (ft_strncmp("||", ptr, 2) == 0)
		return (1);
	if (ft_strncmp("&&", ptr, 2) == 0)
		return (1);
	if (ft_strncmp("|", ptr, 1) == 0)
		return (1);
	if (ft_strncmp("(", ptr, 1) == 0)
		return (1);
	if (ft_strncmp(")", ptr, 1) == 0)
		return (1);
	if (ft_strncmp("&", ptr, 1) == 0)
		return (1);
	if (ft_strncmp(";", ptr, 1) == 0)
		return (1);
	if (*ptr == '\0')
		return (1);
	if (*ptr == '<')
		return (1);
	if (*ptr == '>')
		return (1);
	return (0);
}
