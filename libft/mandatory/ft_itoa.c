/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:00:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/05/01 10:43:57 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

static char	*ft_fill_str(char *str, int len, int n, int n_bak)
{
	str[len] = '\0';
	while (len-- > 0)
	{
		if (len > 0 || n_bak >= 0)
			str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char	*ft_allocate_str(char *str, int len, int n, int n_bak)
{
	if (n >= 0)
	{
		str = (char *)malloc(len + 1);
		if (str == NULL)
			return (NULL);
	}
	else if (n < 0 && n != -2147483648)
	{
		str = (char *)malloc(++len + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	else
	{
		str = (char *)malloc(12);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (ft_fill_str(str, len, n, n_bak));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		n_bak;

	n_bak = n;
	len = ft_nbrlen(n, 10);
	str = NULL;
	str = ft_allocate_str(str, len, n, n_bak);
	if (str == NULL)
		return (NULL);
	return (str);
}
