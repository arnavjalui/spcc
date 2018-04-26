#include<stdio.h>
#include<math.h>
#include<string.h>

char x[20];
int top=0;

void push(char a)
{
    x[top]=a;
    top++;
}

void pop()
{
    top--;
}

int main()
{
    int i,j,k,count=100;
    char a[30];
    printf("Enter the string without any spaces: ");
    scanf("%s",a);
    for(k=1,i=0;i<strlen(a);++i)
    {
        if(a[i]=='&' || a[i]=='|')
        {
                push(a[i]);
                i++;
                continue;
        }
        printf("%d: if %c%c%c goto %d\n", count,a[i],a[i+1],a[i+2],count+3);
        count++;
        printf("%d: t%d=0\n",count,k);
        count++;
        printf("%d: goto %d\n",count, count+2);
        count++;
        printf("%d: t%d=1\n",count,k);
        count++;
        k++;
        i+=2;
    }

    if(top!=0)
    {
        printf("%d: t%d=t1%c%ct2\n",count,k,x[0],x[0]);
        count++;
        k++;
    }

    for(count,k,j=3,i=1;i<top;++i,j++,count++,k++)
    {
        printf("%d: t%d=t%d%c%ct%d\n",count,k,k-1,x[i],x[i],j);
    }

    return 0;
}


/*
Enter the string without any spaces: p<q&&r<s||u<v
100: if p<q goto 103
101: t1=0
102: goto 104
103: t1=1
104: if r<s goto 107
105: t2=0
106: goto 108
107: t2=1
108: if u<v goto 111
109: t3=0
110: goto 112
111: t3=1
112: t4=t1&&t2
113: t5=t4||t3
*/