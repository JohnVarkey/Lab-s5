#include<stdio.h>
#define MAX 4


// values for the queue put as Global
int rear = -1;
int front = -1;
int queue_array[MAX];



int isfull(){

    if((front == rear + 1) || (front == 0 && rear == MAX - 1))
       return 1; 
    return 0;

}

int isempty(){
    if(front == -1) 
        return 1;
    return 0;
}

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

int dequeue(){

    int element;
    if (isempty())
    {
        printf("Queue Underflow \n");
        return ;
    }

    element = queue_array[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } else 
      front = (front + 1) % MAX;
    return element;
}


int print(){
    int i;
    printf("Front:%d | ", front);
    for(i = 0;i< MAX; i++ )
        printf("%2d |", queue_array[i]);
    printf(" Rear:%d | ", rear);
    printf("\n");
}



int search(int key){

    int i, flag=0;
    if (isempty())
        return 0;
    for(i = 0; i<=MAX ; i++ ){
        if(key == queue_array[i]){
             flag=1;
             break;
        }
    }
    return (flag == 0 ? 0 : 1);
}

void main(){
	int num,i, refarr[30], count=0;
	
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
	
    //FIFO Logic
    for ( i = 0; i < num; i++)
    {
        /* code */
        printf("Val: %d ",refarr[i]);
        if (!search(refarr[i]))
        {
            /* code */
            if(isfull()){
               dequeue();
            }
            enqueue(refarr[i]);
            printf(" Swapped ");
            count++;
        }

        print();
     
    }

    printf("Total Number of Swaps: %d", count);
    
}


// 13	
//7   0   1   2   0   3   0   4   2   3   0   3   2
//output: 7