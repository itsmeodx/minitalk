/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:53:46 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 11:54:13 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			printf("1");
			kill(pid, SIGUSR1);
		}
		else
		{
			printf("0");
			kill(pid, SIGUSR2);
		}
		c >>= 1;
		usleep(100);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	int		pid;
	int		i;
	char	c;

	if (argc != 3)
	{
		printf("Usage: %s [PID] [Message]\n", argv[0]);
		return (1);
	}
	pid = atoi(argv[1]);
	if (pid < 1)
	{
		printf("Invalid PID\n");
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		c = argv[2][i];
		send_char(pid, c);
		i++;
	}
	// send_char(pid, '\0');
	return 0;
}
