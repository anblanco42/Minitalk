/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formato.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:22:38 by anblanco          #+#    #+#             */
/*   Updated: 2023/11/20 20:01:56 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formato(const char type, va_list args)
{
	if (type == 'c')
		return (ft_paint_char(va_arg(args, int)));
	if (type == 's')
		return (ft_paint_string(va_arg(args, char *)));
	if (type == 'i')
		return (ft_paint_nbr(va_arg(args, int)));
	if (type == 'd')
		return (ft_paint_nbr(va_arg(args, int)));
	if (type == 'u')
		return (ft_paint_absolut(va_arg(args, unsigned int)));
	if (type == 'x')
		return (ft_hexaiszero(args, 0));
	if (type == 'X')
		return (ft_hexaiszero(args, 1));
	if (type == 'p')
		return (ft_hexapoin(args));
	if (type == '%')
		return (ft_paint_char('%'));
	return (0);
}

int	ft_hexaiszero(va_list args, int m)
{
	unsigned long	x;

	x = (unsigned long)va_arg(args, unsigned int);
	if (x == 0)
		return (ft_paint_char('0'));
	else
		return (ft_paint_hexa(x, m));
	return (0);
}

int	ft_hexapoin(va_list args)
{
	size_t	x;
	int		i;

	x = va_arg(args, size_t);
	i = ft_paint_string("0x");
	if (x == 0)
		i += ft_paint_char('0');
	else
		i += ft_paint_hexa(x, 0);
	return (i);
}
