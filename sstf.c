#include<stdio.h>
#include<stdlib.h>
int main()
{
  int q[25],i,n,j,seek=0,initial,count=0;
  printf("Enter the number of request:\n");
  scanf("%d",&n);
  printf("Enter the sequence of request:\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&q[i]);
  }
  printf("Enter initial head position:\n");
  scanf("%d",&initial);
  printf("\n\nSequence of request:\n");
  for(j=0;j<n;j++)
  {
     int min=1000,diff,index;
     for(i=0;i<n;i++)
     {
        diff=abs(q[i]-initial);
        if(min  >  diff)
        {
           min=diff;
           index=i;
        }
     }
     
     seek = seek+min;
     initial = q[index];
     printf("%d\n",q[index]);
     q[index]=1000;
  }
  printf("Total Head Movements=%d\n\n",seek);
}

/* OUTPUT

ty30@pc19:~/TY_30/OS-II/Assignment-3$ gcc q2.c
ty30@pc19:~/TY_30/OS-II/Assignment-3$ ./a.out
ENter the number of request:
8
Enter the sequence of request:
98
183
41
122
14
124
65
67
Enter initial head position:
53


Sequence of request:
65
67
41
14
98
122
124
183
Total Head Movements=236

ty30@pc19:~/TY_30/OS-II/Assignment-3$ 

*/
