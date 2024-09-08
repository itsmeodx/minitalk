/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:43:56 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/10 00:37:15 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	Bye()
{
	printf("\nServer has been shut down\n");
	exit(0);
}

static void	handler(int signum)
{
	static int	i;
	static char	c;

	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 1)
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	pid = getpid();
	printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGINT, Bye);
	while (1)
	{
	}
	return (0);
}
