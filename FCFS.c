#include<stdio.h>

void main(){
	int nop,i,burstT[50],completionT[50],waitingT[50],turnAroundT[50];
	float totalTurnAroundT=0, totalWaitingT=0;
	printf("Enter Number of Processes: ");
	scanf("%d",&nop);
	
	printf("Enter the burst time for Process\n");
	for(i=0;i<nop;i++){
		printf("Process #%d: ",i+1);
		scanf("%d",&burstT[i]);
	}
	
	completionT[0]=burstT[0];
	waitingT[0]=0;
	turnAroundT[0]=burstT[0];
	totalTurnAroundT=burstT[0];
	for(i=1;i<nop;i++){
		completionT[i]=burstT[i]+completionT[i-1];
		turnAroundT[i]=completionT[i]; // TurnAroundTime = completionTime - arrivalTime; but here arrivalTime is 0
		waitingT[i]=turnAroundT[i]-burstT[i];
		totalTurnAroundT+=turnAroundT[i];
		totalWaitingT+=waitingT[i];
	}
	
	
	printf("#Process  Burst Time  Completion Time  Turn Around Time  Waiting Time\n\n");
	for(i=0;i<nop;i++){	
		printf("%8d%12d%17d%18d%14d\n",i,burstT[i],completionT[i],turnAroundT[i],waitingT[i]);
	}
	
	printf("\n\nAverage Waiting Time: %f \n",(totalWaitingT/nop));
	printf("Average Turnaround Time: %f",(totalTurnAroundT/nop));
	
}



