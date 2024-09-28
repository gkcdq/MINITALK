#include "minitalk.h"

void	bit_signal(int bit)
{
	if (bit == SIG_BIT_0)
		ft_printf("Signal SIGUSR1:\n");
	else if (bit == SIG_BIT_1)
		ft_printf("Signal SIGUSR2:\n");
}

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\n	PID : %d\n", pid);
	signal(SIG_BIT_0, bit_signal);
	signal(SIG_BIT_1, bit_signal);
	while(1)
	{
		pause();
	}
	return (0);
}
