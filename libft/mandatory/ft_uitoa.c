/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:00:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/05/09 17:17:23 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

static char	*ft_allocate(char *str, int len, unsigned int n, unsigned int n_bak)
{
	if (n_bak == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	n_bak;

	n_bak = n;
	len = ft_nbrlen(n, 10);
	str = NULL;
	str = ft_allocate(str, len, n, n_bak);
	if (str == NULL)
		return (NULL);
	return (str);
}
