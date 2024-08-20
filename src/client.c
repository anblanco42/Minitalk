/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:16:12 by anblanco          #+#    #+#             */
/*   Updated: 2024/08/20 17:06:44 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_signal(int pid, unsigned char *msg, size_t len)
{
	int	i;
	int	bit;

	i = 0;
	while (len > 0)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[i] >> (7 - bit) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(42);
		}
		i++;
		len--;
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = (unsigned char *)argv[2];
		send_signal(pid, msg, (ft_strlen((const char *)msg) + 1));
	}
	else
		ft_printf("Sintax: %s [PID_servidor] [Mensage]", argv[0]);
}
