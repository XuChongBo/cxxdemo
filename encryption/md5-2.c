#include<stdio.h>
#include<openssl/md5.h>
#include<string.h>

int main( int argc, char **argv )
{
unsigned char *data = "123";
unsigned char md[16];
int i;
char tmp[3]={'\0'},buf[33]={'\0'};
MD5(data,strlen(data),md);
for (i = 0; i < 16; i++){
sprintf(tmp,"%2.2x",md[i]);
strcat(buf,tmp);
}
printf("%s\n",buf);
return 0;
}

void md5_for_filename()
{
    //# calc md5 for filename 
    unsigned char md[16];  //16*8 bits
    MD5((unsigned char*)filename,strlen(filename),md);
    printContent(md,16);
}
