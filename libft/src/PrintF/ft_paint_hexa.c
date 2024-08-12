/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:09:11 by anblanco          #+#    #+#             */
/*   Updated: 2023/11/20 20:02:47 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	letras_min(char x)
{
	if ((x >= 0) && (x <= 9))
		return (x + 48);
	else if (x == 10)
		return ('a');
	else if (x == 11)
		return ('b');
	else if (x == 12)
		return ('c');
	else if (x == 13)
		return ('d');
	else if (x == 14)
		return ('e');
	else if (x == 15)
		return ('f');
	return (0);
}

static int	letras_mayus(char x)
{
	if ((x >= 0) && (x <= 9))
		return (x + 48);
	else if (x == 10)
		return ('A');
	else if (x == 11)
		return ('B');
	else if (x == 12)
		return ('C');
	else if (x == 13)
		return ('D');
	else if (x == 14)
		return ('E');
	else if (x == 15)
		return ('F');
	return (0);
}

int	ft_paint_hexa(unsigned long n, int m)
{
	unsigned long	x;
	int				i;

	i = 0;
	x = n;
	if ((x > 0) && (m == 0))
	{
		i += ft_paint_hexa(x / 16, 0);
		i += ft_paint_char(letras_min(x % 16));
	}
	if ((x > 0) && (m == 1))
	{
		i += ft_paint_hexa(x / 16, 1);
		i += ft_paint_char(letras_mayus(x % 16));
	}
	return (i);
}
