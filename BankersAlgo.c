#include<stdio.h>
#define N 3	//number of processes
#define M 3//number of resources
// Always use i with N and j with M



void EnterValues(int *arr, char message[50]){
	int i,j;
	printf("%s (%d*%d): \n",message, N,M);
	for (i=0;i<N;i++)
		for(j=0;j<M;j++)
			scanf("%d",&arr[i][j]);
	
}


void main(){
	int Max[N][M], Allocated[N][M], Need[N][M], Available[M], Finish[N]={0}, Total[M]; //0 - not finished: 1 - finished
	int i,j,flag=0;
	int *totalAllocated;  //later used to return an address of an array
	
			
	EnterValues(Max, "Enter the Max Number of Resources that can be allocated")		
			
	for (i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++)
			printf("%d ",Max[i][j]);
	}
	
}
