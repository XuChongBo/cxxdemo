#include <stdio.h>
#define MOD 1000000007

char str1[]="advertise";
char str2[]="does not matter";
char str3[]="do not advertise";

char *fun(int a,int b, int c){
    int profit = b-c;
    if(a<profit)
        return str1;
    if(a>profit)
        return str3;
    return str2;
}

int main(){
	int a,b,c;
    int n;
    scanf("%d",&n);
	while(n--){
        scanf("%d%d%d",&a,&b,&c);
		printf("%s\n",fun(a,b,c));
	}
	return 0;
}
