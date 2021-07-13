/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:11:41 by aperez-b          #+#    #+#             */
/*   Updated: 2021/07/08 22:27:56 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/lib/libft.h"
# include <stdarg.h>

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}			t_format;

# define INT_MIN -2147483648
# define UINT_MAX 4294967295

# define SPECIFIERS	"cspdiuxX%"

# define HEXALOW	"0123456789abcdef"
# define HEXAUP		"0123456789ABCDEF"

int			ft_printf(const char *str, ...);
t_format	ft_newformat(void);
int			ft_print_format(t_format f, va_list ap);
int			ft_print_c_pct(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_d_i_u(t_format f, va_list ap);
int			ft_print_x_X(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_parse(char *str, va_list	ap);

#endif
