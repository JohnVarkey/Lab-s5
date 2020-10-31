#include <stdio.h>


void main() {
	//code
	int n, queue[30], head, i, j, temp, SeekTime;
	printf("Enter the number of pages in the disk queue : ");
	scanf("%d", &n);
	printf("Enter the pages in disk queue : ");
	for (i=0; i<n; i++)
	{
		scanf("%d", &queue[i]);
	}
	printf("\n");
	printf("Enter the initial disk head position : ");
	scanf("%d", &head);
    
	queue[n] = head;

	for (i=0; i<n+1; i++)
	{
		for (j=i+1; j<n+1; j++)
		{
			if (queue[i]>queue[j])
			{
				temp = queue[i];
				queue[i] = queue[j];
				queue[j] = temp;
			}
		}
		
	}


	SeekTime = (head-queue[0])+(queue[n+1]-head);
	printf("\n\nTotal Seek Time = %d", SeekTime);
}
