#include <stdio.h>
int fun(int x)
{
    x = (x-1)%8;
    if(x<=4)
    {
        return x+1;
    }else
    {
        return 5-(x-4);
    }
}

int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		printf("%d\n",fun(a));
	}
	return 0;
}
