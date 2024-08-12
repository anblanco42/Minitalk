/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:24:12 by anblanco          #+#    #+#             */
/*   Updated: 2023/11/20 20:00:53 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	int		i;
	int		printed;
	va_list	args;

	va_start(args, s);
	printed = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			printed += ft_formato(s[i], args);
		}
		else
		{
			write (1, &s[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
