//OS Lab week 4, Q4

//Created on - 4/11/19
//By - Teja Juluru

//Create a zombie process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		printf("Error\n");
		exit(-1);
	}
	if(pid == 0) { //child process
		// printf("child process\n");
		exit(0);
	}
	else { //parent process
		sleep(2);
		// printf("parent process\n");
	}
	return 0;
}