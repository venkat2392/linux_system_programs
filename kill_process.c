#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main()
{
	char buff[50];
	system("ps -a");
	pid_t  pid = getpid();
	kill(pid,SIGINT);
	printf("reading data\n");
	close(0);
	int fd=read(0,buff,50);
	if(fd==-1)
	perror("");
	printf("%s\n",buff);
}

