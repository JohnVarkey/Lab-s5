#include<stdio.h>
#include<math.h>
#define MAX 10



void main(){

    int n, pages[MAX+1], head, i, AccessTime=0;
    printf("Enter the Number of Elements in the Disk Queue : ");
    scanf("%d",&n);
    printf("Enter Elements in the order of Access : ");
    for( i = 1; i <= n; i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("Enter Starting Position : ");
    scanf("%d", &pages[0]);
    for ( i = 0; i < n; i++)
    {
        AccessTime+=abs(pages[i+1]-pages[i]);
    }
    printf("Access Time : %d", AccessTime);

}


/https://ide.geeksforgeeks.org/qAF6Jhk0OR