
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



int main()
{

	int pid = getpid(); 
	int status; 

	// #1
	printf("sneaky_process pid = %d\n", pid);

	// #2 
	status=system("ls");



	return 0; 
}