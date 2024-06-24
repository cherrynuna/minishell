/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_quote1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:22:41 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:58 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand_bonus.h"

void	search_quote(char **src)
{
	char	*tem;
	char	*dst;
	int		len;

	tem = *src;
	len = get_strlen(&tem);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		error_handler("quote", NULL, 12);
	dst = str_presscpy(dst, *src, len);
	dst[len] = '\0';
	free(*src);
	*src = dst;
}
