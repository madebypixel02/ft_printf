/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:09:50 by aperez-b          #+#    #+#             */
/*   Updated: 2021/04/20 09:44:24 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				last;
	unsigned char	c_unsigned;

	c_unsigned = (unsigned char)c;
	if (c_unsigned == '\0')
		return ((char *)&s[ft_strlen(s)]);
	last = ft_strlen(s) - 1;
	if (last < 0)
		return (NULL);
	while (last >= 0)
	{
		if (s[last] == c_unsigned)
			return ((char *)&s[last]);
		last--;
	}
	return (NULL);
}
