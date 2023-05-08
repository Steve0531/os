#include<stdio.h>
#include<stdlib.h>
int main()
{
    int q[100],i,j,n,seek=0,head,size=200,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&q[i]);
    printf("Enter initial head position\n");
    scanf("%d",&head);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);
    
    // logic for C-Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(q[j]>q[j+1])
            {
                int temp;
                temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(head<q[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            seek=seek+abs(q[i]-head);
            head=q[i];
        }
        //  last movement for max size 
        seek=seek+abs(size-q[i-1]-1);
        /*movement max to min disk */
        seek=seek+abs(size-1-0);
        head=0;
        for( i=0;i<index;i++)
        {
             seek=seek+abs(q[i]-head);
             head=q[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            seek=seek+abs(q[i]-head);
            head=q[i];
        }
        //  last movement for min size 
        seek=seek+abs(q[i+1]-0);
        /*movement min to max disk */
        seek=seek+abs(size-1-0);
        head =size-1;
        for(i=n-1;i>=index;i--)
        {
             seek=seek+abs(q[i]-head);
             head=q[i];
            
        }
    }
    
    printf("Total head movement is %d",seek);
    return 0;
}