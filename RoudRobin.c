#include<stdio.h>
#define MAX 50


struct Process{
	int id; 
	int burstT;
	int arrivalT;
	int completionT;
	int turnAroundT;
	int waitingT;
	int remainingT;
}p[MAX];

// values for the queue put as Global
int rear = - 1;
int front = - 1;
int quantum = 0;
int currentT = 0;
int queue_array[MAX]; // store index of processes

void enqueue(int index)
{
    if (rear == MAX - 1){
    	printf("Queue Overflow \n");
    	return;
	}
    
    if (front == - 1) 
    	front = 0;
    queue_array[++rear] = index;
    
}

int dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    
    return queue_array[front++];
    
    
}

int RoundRobinLogic(int index){
	
	if (p[index].remainingT>quantum){

		p[index].remainingT-=quantum;
		enqueue(index);
		currentT+=quantum;
		return 0;		

	}else{

	 	if(p[index].remainingT==quantum)
			currentT+=quantum;
		else
			currentT+=p[index].remainingT;
		p[index].remainingT=0;
		return 1;

	}

}


void main(){
	struct Process temp;
	int nop,i,j;
	float totalTurnAroundT=0,totalWaitingT=0;
	
	//printf("Enter The Number of Processes: ");
	scanf("%d",&nop);
	
	
	//printf("Enter Details for each Processes\n\n");
	for(i=0;i<nop;i++){
		p[i].id=i;
		//printf("#%d: \n",i+1);
		//printf("	Arrival Time:  ");
		scanf("%d",&p[i].arrivalT);
		//printf("	Burst Time:  ");
		scanf("%d",&p[i].burstT);
		p[i].remainingT=p[i].burstT;
	}
	
	//printf("Enter Time Quantum : ");
	scanf("%d",&quantum);
	
	
	
	//sorting according to arrival time
	for(i=0;i<nop;i++){
		for(j=i+1;j<nop;j++){
			if(p[i].arrivalT>p[j].arrivalT){
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	
	
	// inserting into queue
	for(i=0;i<nop;i++){
		enqueue(i);
	}
	
	//Round Robin Logic
	while(front != - 1 && front <= rear){ // loops till the queue is empty
		j=dequeue(); // stores index of the removed element
		i=RoundRobinLogic(j); // stores completion status: 0-> not completed , 1-> completed
		if(i=1)
			p[j].completionT=currentT;
	}
	
	// computing TAT and WT
	for(i=0;i<nop;i++){
		p[i].turnAroundT=p[i].completionT-p[i].arrivalT; // TurnAroundTime = completionTime - arrivalTime; but here arrivalTime is 0
		p[i].waitingT=p[i].turnAroundT-p[i].burstT;
		totalTurnAroundT+=p[i].turnAroundT;
		totalWaitingT+=p[i].waitingT;
	}

	
	for(i=0;i<nop;i++){
	printf("#Process  Arrival Time  Burst Time  Completion Time  Turn Around Time  Waiting Time\n\n");
		for(i=0;i<nop;i++){	
			printf("%8d%14d%12d%17d%18d%14d\n",p[i].id+1,p[i].arrivalT,p[i].burstT,p[i].completionT,p[i].turnAroundT,p[i].waitingT);
		}
	}
	
	printf("\n\nAverage Waiting Time: %.3f \n",(totalWaitingT/nop));
	printf("Average Turnaround Time: %.3f",(totalTurnAroundT/nop));
}


	
