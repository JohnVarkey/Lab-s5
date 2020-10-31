#include<stdio.h>
#include<unistd.h>
#define MAX 10

int chopstick[MAX], nop;

void wait(int key){
    while(chopstick[key]<=0){
        printf("Entered Infinite Wait");
        sleep(5);
    };
    --chopstick[key];
}

void signal(int key){
    ++chopstick[key];
}

void philosopher(int index){
    wait(index);
    wait(((index+1)%nop));
    printf("Philospher %d Eating ; ",index);
    signal(index);
    signal(((index+1)%nop));
    printf("Philospher %d Thinking",index);
}


void main(){

    int i;
    printf("Enter the Number of Philosophers");
    scanf("%d",&nop);
    for ( i = 0; i < nop; i++)
    {
        /* code */
        chopstick[i]=1;
    }
    
    for(i=0;i<nop;i++){
        printf("\n");
        philosopher(i);
    }
 
}