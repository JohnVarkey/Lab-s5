#include<stdio.h>


struct Process{
	int id; 
	int burstT;
	int completionT;
	int turnAroundT;
	int waitingT;
};


void main(){
	struct Process p[20],temp;
	int nop,i,j;
	float totalTurnAroundT=0,totalWaitingT=0;
	
	printf("Enter The Number of Processes: ");
	scanf("%d",&nop);
	
	
	printf("Enter The Burst Time for each Processes\n\n");
	for(i=0;i<nop;i++){
		p[i].id=i;
		printf("#%d: ",i+1);
		scanf("%d",&p[i].burstT);
	}
	
	
	for(i=0;i<nop;i++){
		for(j=i+1;j<nop;j++){
			if(p[i].burstT>p[j].burstT){
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	
	
	p[0].completionT=p[0].burstT;
	p[0].waitingT=0;
	p[0].turnAroundT=p[0].burstT;
	totalTurnAroundT=p[0].burstT;
	for(i=1;i<nop;i++){
		p[i].completionT=p[i].burstT+p[i-1].completionT;
		p[i].turnAroundT=p[i].completionT; // TurnAroundTime = completionTime - arrivalTime; but here arrivalTime is 0
		p[i].waitingT=p[i].turnAroundT-p[i].burstT;
		totalTurnAroundT+=p[i].turnAroundT;
		totalWaitingT+=p[i].waitingT;
	}
	
	
	
	printf("#Process  Burst Time  Completion Time  Turn Around Time  Waiting Time\n\n");
	for(i=0;i<nop;i++){	
		printf("%8d%12d%17d%18d%14d\n",p[i].id+1,p[i].burstT,p[i].completionT,p[i].turnAroundT,p[i].waitingT);
	}
	
	printf("\n\nAverage Waiting Time: %f \n",(totalWaitingT/nop));
	printf("Average Turnaround Time: %f",(totalTurnAroundT/nop));
//	for(i=0;i<nop;i++){
//		printf("#%d: ",i);
//		printf("%d \n",p[i].burstT);
//	}

}
