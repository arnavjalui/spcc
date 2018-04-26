#include<stdio.h>
#include<string.h>

int main() {
	int i=0,j=0,k=0,l=0;
	char inp[50]={0},part1[50]={0},part2[50]={0};
	printf("Enter production in the form A-> Aa1|Aa2|...|b1|b2..\nA-> ");
	gets(inp);
	inp[strlen(inp)]='\0';
	if(inp[0]=='A') {
    abc:for(i++,j=0;inp[i]!='|';i++,l++)
			part1[l]=inp[i];
		part1[l]='A';
		part1[++l]='\'';
		part1[++l]='|';
		part1[++l]='\0';
		j=0;
		do {
		    k=i+1;
			if(inp[k]=='A') {
                i++;
                goto abc;
            } else {
                for(i++;inp[i]!='|'&&inp[i];i++,j++)
                    part2[j]=inp[i];
                if(inp[i]=='|') {
                    part2[j]='A';
                    part2[++j]='\'';
                    part2[++j]='|';
                    j++;
                }
            }
		} while(inp[i]);
		part2[j]='A';
        part2[++j]='\'';
		part2[++j]='\0';
		printf("A-> %s",part2);
		printf("\nA'-> %s",part1);
		printf("e\n");
	} else
		printf("No LR\n");
	return 0;
}