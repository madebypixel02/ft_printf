/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:09:32 by aperez-b          #+#    #+#             */
/*   Updated: 2021/04/12 11:30:32 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_unsigned;

	c_unsigned = (unsigned char)c;
	if (c_unsigned == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == c_unsigned)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
