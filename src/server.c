/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:16:17 by anblanco          #+#    #+#             */
/*   Updated: 2024/08/13 22:03:49 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

typedef struct s_bitargument
{
	int 	c;
	int		recive;
}			t_bitargument;

t_bitargument g_bitargument;

void	handler_bit(int bit)
{
	if (bit == SIGUSR1)
		g_bitargument.c = (g_bitargument.c << 1) | 1;
	else if (bit == SIGUSR2)
		g_bitargument.c = (g_bitargument.c << 1) | 0;
	g_bitargument.recive++;
	if (g_bitargument.recive == 8)
	{
		if (g_bitargument.c == '\0')
	        ft_printf("\n");
		else 
			ft_printf("%c", g_bitargument.c);
		g_bitargument.c = 0;
		g_bitargument.recive = 0;
	}
	
}

int	main(void)
{
	ft_printf("Andrew's server\n");
	ft_printf("Server PID: %i\n", getpid());
	signal(SIGUSR1, handler_bit);
	signal(SIGUSR2, handler_bit);
	while (1)
		;;
	return (0);
}
