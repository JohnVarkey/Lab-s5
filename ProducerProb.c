#include<stdio.h>
#include<unistd.h>
#define MAX 10

int n=0, mutex=1, full=0, empty;

int wait(int key){
    while(key<=0){
        printf("Entered Infinite Wait");
        sleep(5);
    };
    return --key;
}

int signal(int key){
    return ++key;
}

void producer(){
    
    empty = wait(empty);
    mutex = wait(mutex);
    ++n;
    mutex = signal(mutex);
    full = signal(full);
}

void consumer(){
    full = wait(full);
    mutex = wait(mutex);
    --n;
    mutex = signal(mutex);
    empty = signal(empty);
}

void main(){

    int op=1, buffersize;
    printf("Enter the Buffer Capacity");
    scanf("%d",&buffersize);
    empty=buffersize;
    while(op==1){
        printf("Enter the operation to perform \n 1-> Add,  2->Release, 3-> Exit:  ");
        scanf("%d",&op);
        switch(op){
            case 1: producer();
                    break;
            case 2: consumer();
                    op=1; //to re-enter the while loop
                    break;
            case 3: op=0;
                    break;
            default:
                    printf("Enter from the List");
                    break;
        }

        printf("\n\nN= %d\n\n", n);
    }
}