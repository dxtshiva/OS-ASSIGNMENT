#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 
int num; 
void *Prime(void *vargp) 
{ 
int i,j,flag;
	for(i=2;i<=num;i++){
		flag=0;
		for(j=2;j<i;j++){
			if(i%j==0){
		flag=1;
		break;
			}
		}
		if(flag==0)
		printf("%d ",i);
		}
		printf("\nare the prime numbers less than or equal to %d",num);
} 
   
int main() 
{ 	
	printf("Before Thread Execution\n\nEnter the number to get primes: "); 
	scanf("%d",&num);
	if(num<=0)
	printf("Number must be greater than or equal to 1.");
	else if(num==1)
	printf("1 is neither prime nor composite number.");
	else{
    pthread_t tid; 
    printf("\nThread execution started with thread id %d\n\n",tid);
    pthread_create(&tid, NULL, Prime, NULL); 
    pthread_join(tid, NULL); 
    printf("\n\nThread Execution Completed.\n"); 
	}
    getch();
    exit(0); 
    
}
