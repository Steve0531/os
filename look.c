#include<stdio.h>
#include<stdlib.h>

int main()
{
    int head, move, n,temp,seek=0,current_head_pos;
    float avg_seek_time;
    
    printf("Enter initial head position : ");
    scanf("%d",&head);
    
    printf("Enter the direction (0 for left 1 for right) : ");
    scanf("%d",&move);
    
    printf("Enter the number of disk requests : ");
    scanf("%d",&n);
    
    int q[n];
    
    printf("Enter the disk queue : ");
    for (int i=0;i<n;i++)
    {
         scanf("%d",&q[i]);
    }    
    for (int i=0;i<n-1;i++)
    {
         for (int j=0;j<n-1;j++)
         {
              if (q[j]>q[j+1])
              {
                  temp = q[j];
                  q[j]=q[j+1];
                  q[j+1]=temp;
              }
         }
    }
    
    int index;
    for ( int i=0;i<n;i++)
    {
         if (head<q[i])
          {

             index=i;
             break;
          }
    }
    
    current_head_pos=head;
    
    if (move==1)
    {
        for (int j=index;j<n;j++)
        {
             seek+=abs(q[j]-current_head_pos);
             current_head_pos = q[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
        for (int j=index-1;j>=0;j--)
        {
             seek+=abs(q[j]-current_head_pos);
             current_head_pos=q[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
    }
    else
    {
        for (int j=index-1;j>=0;j--)
        {
             seek+=abs(q[j]-current_head_pos);
             current_head_pos=q[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
        for (int j=index;j<n;j++)
        {
             seek+=abs(q[j]-current_head_pos);
             current_head_pos = q[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
    }
    printf("Total seek movement : %d\n",seek);
    
    return 0;
}

/**

ty56@pc16:~/ty56/ty_OS2_56/Assignment 3$ cc look.c
ty56@pc16:~/ty56/ty_OS2_56/Assignment 3$ ./a.out 
Enter initial head position : 53
Enter the direction (0 for left 1 for right) : 0
Enter the number of disk requests : 8
Enter the disk queue : 98 183 37 122 14 124 65 67
Head Moving towards 37
Head Moving towards 14
Head Moving towards 65
Head Moving towards 67
Head Moving towards 98
Head Moving towards 122
Head Moving towards 124
Head Moving towards 183
Total seek movement : 208


ty56@pc16:~/ty56/ty_OS2_56/Assignment 3$ cc look.c
ty56@pc16:~/ty56/ty_OS2_56/Assignment 3$ ./a.out 
Enter initial head position : 53
Enter the direction (0 for left 1 for right) : 1
Enter the number of disk requests : 7
Enter the disk queue : 82
170
43
140
24
16
190
Head Moving towards 82
Head Moving towards 140
Head Moving towards 170
Head Moving towards 190
Head Moving towards 43
Head Moving towards 24
Head Moving towards 16
Total seek movement : 311


**/
