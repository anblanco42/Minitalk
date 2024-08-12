/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:28:43 by anblanco          #+#    #+#             */
/*   Updated: 2023/11/20 20:04:18 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);
int		ft_formato(const char type, va_list args);
int		ft_paint_string(char *str);
int		ft_paint_char(char c);
int		ft_paint_decimal(int num);
int		ft_paint_nbr(int n);
int		ft_paint_absolut(unsigned int i);
int		ft_paint_hexa(unsigned long n, int m);
int		ft_hexaiszero(va_list args, int m);
int		ft_hexapoin(va_list args);

#endif