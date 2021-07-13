/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:43:07 by aperez-b          #+#    #+#             */
/*   Updated: 2021/07/08 09:49:17 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

int	ft_print_c_pct(t_format f, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		count += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	count += ft_putchar_fd(c, 1);
	if (f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (count);
}

int	ft_print_s(t_format f, va_list ap)
{
	char	*string;
	int		count;
	int		has_malloc;

	count = 0;
	has_malloc = 0;
	string = va_arg(ap, char *);
	if (!string)
	{
		string = malloc(sizeof(char) * 7);
		has_malloc = 1;
		ft_strlcpy(string, "(null)", 7);
	}
	if (!f.dot || f.precision > (int)ft_strlen(string) || f.precision < 0)
		f.precision = ft_strlen(string);
	if (!f.minus && f.width > f.precision && f.zero && (!f.dot || f.neg_prec))
		count += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	count += ft_putstrn_fd(string, 1, f.precision);
	if (f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	if (has_malloc)
		free(string);
	return (count);
}
