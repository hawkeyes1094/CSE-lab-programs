//OS Lab week 4, example 2

//OS Lab week 4, example 5

//By - Teja Juluru

//Example fork() program 2
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	char* message;
	int n;
	printf("fork program starting\n");
	pid = fork();
	
	switch(pid) {
		case -1 : 
			perror("fork failed\n");
			exit(1);
		case 0 :
			message = "This is the child";
			n = 3;
			break;
		default :
			message = "This is the parent";
			n = 5;
			break;
	}
	for(;n > 0;n--) {
		printf("%s n = %d\n",message,n);
		sleep(1);
	}
	exit(0);

	return 0;
}