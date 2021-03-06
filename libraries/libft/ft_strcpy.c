/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:52:19 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:06:19 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	if (!dst || !src)
		return ;
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
}
