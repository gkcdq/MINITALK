#include <minitalk.h>










int main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d\n," pid);
	while(1)
	{

		pause(100);
	}
	return (0);
}
