#include<stdio.h>
#include<pthread.h>

int number=1;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2=PTHREAD_MUTEX_INITIALIZER;
void *printEvenNum(void *tmp)
{
	while(number<100)
	{
		//pthread_mutex_lock(&mutex1);
		if(number%2==0)
		{
			printf("Sequence numbers(%s)=%d\n",(char *)tmp,number);
			number++;
		}
		//pthread_mutex_unlock(&mutex1);
	}
	pthread_exit(0);
}
void *printOddNum(void *tmp)
{
	while(number<100)
	{
		//pthread_mutex_lock(&mutex1);
		if(number%2!=0)
		{
			printf("Sequence numbers(%s)=%d\n",(char *)tmp,number);
			number++;
		}
		//pthread_mutex_unlock(&mutex1);
	}
	pthread_exit(0);
}

int main()
{
	pthread_t thread1,thread2;
	char *s1="even";
	char *s2="odd ";
	pthread_mutex_init(&mutex1,NULL);
	pthread_mutex_init(&mutex2,NULL);
	pthread_create(&thread1,NULL,(void *)printOddNum,(void *)s2);
	pthread_create(&thread2,NULL,(void *)printEvenNum,(void *)s1);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
}
