/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:05:34 by aperez-b          #+#    #+#             */
/*   Updated: 2021/04/09 19:24:07 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (src < dest)
			d[n - i - 1] = s[n - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}
