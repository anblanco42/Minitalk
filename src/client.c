/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:16:12 by anblanco          #+#    #+#             */
/*   Updated: 2024/08/13 21:51:36 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	send_signal(int pid, char *msg)
{
	int	i;
	int	bit;

	i = 0;	
	while (msg[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[i] >> (7 - bit) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		send_signal(pid, msg);
	}
	else
		ft_printf("Sintax: %s [PID_servidor] [Mensage]", argv[0]);
}
