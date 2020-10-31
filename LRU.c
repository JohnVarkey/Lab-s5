#include<stdio.h>
#define MAX 3


// values for the queue put as Global
int rear = -1;
int front = -1;
int queue_array[MAX];


/*
    checks if full
    //* return: 1 if full and 0 if not 
*/

int isfull(){

    if((front == rear + 1) || (front == 0 && rear == MAX - 1))
       return 1; 
    return 0;

}

/*
    checks if empty
    //* return: 1 if empty and 0 if not 
*/
int isempty(){
    if(front == -1) 
        return 1;
    return 0;
}

/*
    Enqueue into the Queue
*/
void enqueue(int val){

    if (isfull()){
    	
        printf(" OverFlow  ");
    	
	}else{
        if (front == - 1) 
    	    front = 0;
        rear = (rear + 1) % MAX;
        queue_array[rear] = val;
    }
}
/*
    used to Dequeue from Queue. This is not the standard Dequeue used for Queue. Changes have been made for the program
    //* @param: index of the value to be dequeue
*/

void dequeue(int index){

    unsigned int i;
    if (isempty())
    {
        printf("Queue Underflow \n");
        return ;
    }

    
    for(i=index+1;i<MAX;i++)
        queue_array[i-1]=queue_array[i];
    --rear;
}

/*
    used for printing the whole Queue Array
*/

void print(){

    unsigned int i;
    printf("Front:%d | ", front);
    for(i = 0;i< MAX; i++ )
        printf("%2d |", queue_array[i]);
    printf(" Rear:%d | ", rear);
    printf("\n");
}

/*  
    used for searching a value in the Queue
    //* @param key: val to be searched in the in the Queue
    //* return: return the location of the key in the Queue else -1 is returned
*/

int search(int key){

    unsigned int i;
    int flag=-1;
    if (isempty())
        return -1;
    for(i = 0; i<=MAX ; i++ ){
        if(key == queue_array[i]){
             flag=1;
             break;
        }
    }
    return (flag == -1 ? -1 : i);
}

/*
    used for find the Least Replaced Page in the Ref array
    //* @param: the index of the page to enqueued into the Queue
    //* return: returns the index of the page that must be Dequeued
*/

int findLRU(int current){
    unsigned int count=1;
    while(current>=0&&count<=MAX){
        --current;
        ++count;            
    }
    return current;
}



void main(){
	unsigned int num,i,refarr[30], val, fault=0;
	
	//initialise 

    for(i=0;i<MAX;i++)
        queue_array[i]=-1;
	printf("Enter The Number of elements in Reference Array: ");
	scanf("%d",&num);
	
	//inserting Reference Array
	printf("Enter Elements\n\n");
	for(i=0;i<num;i++){
		scanf("%d",&refarr[i]);
	}
	
    //LRU logic
    for ( i = 0; i < num; i++)
    {
        /* code */
        printf("Val: %d search: %d",refarr[i],search(refarr[i]));
        if (search(refarr[i])==-1){ // if return -1 then val not present 
            if (isfull()){
                /* code */
                val = findLRU(i);
                //printf("  deq: %d", val);
                dequeue(search(refarr[val]));
                enqueue(refarr[i]);
            }else
                enqueue(refarr[i]);
            ++fault;    
        }
        print();
        
    printf("\t Fault: %d", fault);
        printf("\n");
     
    }

    printf("Total Number of Swaps: %d", fault);
    
}


/*
    19
    3       2       1       3       4       1       6       2       4       3       4       2       1       4       5       2       1       3       4
*/