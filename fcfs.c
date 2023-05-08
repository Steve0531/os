#include<stdio.h>
#include<stdlib.h>
int main()
{
	int q[20],head,n,j,i,seek=0,max=200,diff;
	printf("\n Enter size of queue request:");
	scanf("%d",&n);
	printf("\n Enter queue disk position to be read:");
	for(i=1;i<=n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter initial head position:");
	scanf("%d",&head);
	q[0]=head;
	for(j=0;j<=n-1;j++)
	{
		diff=abs(q[j+1]-q[j]);
		seek+=diff;
		printf("Disk head moves from %d to %d with seek %d\n",q[j],q[j+1],diff);
	}
	printf("Total head movement is %d\n",seek);
	return 0;
}