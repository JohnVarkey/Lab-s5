#include <stdio.h>

void  main() {
	//code
	int n, queue[30], start=0, end=0, head, i, j, temp, SeekTime;
	printf("Enter the number of pages in the disk queue : ");
	scanf("%d", &n);
	printf("%d\n", n);
	printf("Enter the pages in disk queue : ");
	for (i=0; i<n; i++)
	{
		scanf("%d", &queue[i]);
	}
	printf("\n");
	printf("Enter the start and end of the disk : ");
	scanf("%d%d", &start, &end);
	printf("Enter the inital disk head position : ");
	scanf("%d", &head);
	printf("%d\n", head);
	queue[n] = head;
	queue[n+1] = start;
	queue[n+2] = end;
	for (i=0; i<n+3; i++)
	{
		for (j=i+1; j<n+3; j++)
		{
			if (queue[i]>queue[j])
			{
				temp = queue[i];
				queue[i] = queue[j];
				queue[j] = temp;
			}
		}
		//printf("%d ", queue[i]);
	}
	SeekTime = (end-head)+(end-queue[1]);
	printf("Total Seek Time = %d", SeekTime);
}

//https://ide.geeksforgeeks.org/iR51hA5LEg
