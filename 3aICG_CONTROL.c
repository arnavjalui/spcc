#include<stdio.h>
#include<string.h>

void main()
{
    char str[10], sw[10][30];
    int n,i,k,index;
    printf("Enter the conditional expression: ");
    scanf("%s",str);
    printf("Enter the lines inside the loop: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",sw[i]);
    }
    index = 100;
    i=1;
    printf("%d\tL%d\tif %s goto L%d\n",index++,i,str,i+1);
    printf("%d\t\tgoto Last\n",index++);
    printf("%d\tL%d\t%s\n",index++,i+1,sw[0]);
    for(k=1;k<n;k++)
        printf("%d\t\t%s\n",index++,sw[k]);
    printf("%d\t\tgoto L%d\n",index++,i);
    printf("%d\tLast\n",index++);
}


/*
Enter the conditional expression: while
Enter the lines inside the loop: 2
i++
c--
100     L1      if while goto L2
101             goto Last
102     L2      i++
103             c--
104             goto L1
105     Last
*/