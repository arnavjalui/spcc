#include<stdio.h>
#include<string.h>

int main() {
	int slash[20]={0},i=0,j=0,k=0,l=0,slash_no=0;
	char inp[50]={0},part1[50]={0};
	printf("Enter production in the form A-> aB1|aB2|.....\nA-> ");
	gets(inp);
	inp[strlen(inp)]='\0';
	for(i=0;inp[i];i++) {
        if(inp[i]=='|') {
            slash[slash_no]=i;
            slash_no++;
        }
	}
	for(i=0;i<slash_no;i++) {
        if(inp[0]!=inp[slash[i]+1]||(inp[0]<='a'&&inp[0]>='z')) { //accept only terminals (small case)
            printf("No LF");
            return 0;
        }
    }
    i=0;
    j=0;
    while(inp[i]) {
        for(i++;inp[i]!='|'&&inp[i]&&inp[i]!=inp[0];i++,j++)
            part1[j]=inp[i];
        if(inp[i]=='|')
            part1[j++]='|';
    }
    part1[++j]='\0';
    printf("A-> %cA'",inp[0]);
    printf("\nA'-> %s",part1);
	return 0;
}