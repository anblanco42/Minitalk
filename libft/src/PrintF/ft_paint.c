/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:40:40 by anblanco          #+#    #+#             */
/*   Updated: 2024/07/31 23:47:15 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paint_string(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_paint_string("(null)"));
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_paint_char(char c)
{
	return (write (1, &c, 1));
}

int	ft_paint_nbr(int n)
{
	long int	x;
	int			i;

	i = 0;
	x = n;
	if (n < 0)
	{
		i += write(1, "-", 1);
		x = x * -1;
	}
	if (x > 9)
	{
		i += ft_paint_nbr(x / 10);
		i += ft_paint_char((x % 10) + 48);
	}
	else
	{
		i += ft_paint_char(x + 48);
	}
	return (i);
}

int	ft_paint_absolut(unsigned int n)
{
	long int	x;
	int			i;

	i = 0;
	x = n;

	if (x > 9)
	{
		i += ft_paint_nbr(x / 10);
		i += ft_paint_char((x % 10) + 48);
	}
	else
	{
		i += ft_paint_char(x + 48);
	}
	return (i);
}
