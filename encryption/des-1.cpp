#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/des.h>
#include<openssl/md5.h>
#include <iostream>
using  namespace std;


//注意
//1. 不支持超过1G的大文件
//2. len不含包含结尾\0符
void writeFile(const char *filename, const unsigned char *buffer, int len)
{
    FILE *pFile = fopen(filename, "wb"); 
    fwrite(buffer, 1, len, pFile);
    fclose(pFile); 
}

// 1.len不含包含结尾\0符
// 2.调用方需释放*ptr_buff指针
void readFile(const char *filename, unsigned char **ptr_buff, int *len)
{
    FILE *pFile=fopen(filename,"rb");
    //把指针移动到文件的结尾 ，获取文件长度
    fseek(pFile,0,SEEK_END); 
    //获取文件长度
    *len=ftell(pFile); 
    rewind(pFile); 
    *ptr_buff= (unsigned char *)malloc(*len);   //这里没有字符串的\0符
    //读文件
    fread(*ptr_buff,1,*len,pFile); 
    fclose(pFile); 
}

/*
unsigned char *data = "123";
unsigned char md[16];
int i;
char tmp[3]={'\0'},buf[33]={'\0'};
MD5(data,strlen(data),md);
for (i = 0; i < 16; i++){
sprintf(tmp,"%2.2x",md[i]);
strcat(buf,tmp);
*/

void printContent(unsigned char *buff, int len, int padding=0)
{
    printf("\n");
    printf("BINARY: ");
    /*
    for (int i = 0; i < len; i++) {
        printf("0x%.2X ", *(buff+ i));
    }
    */
    for (int i = 0; i < len; i++) {
        printf("0x%2.2X ", *(buff+ i));
        if (i==20 && len-padding-2>20){
            printf(" ... ");
            i = len-padding-2;
        }
    }
    printf("\n");
    printf("PADDING: %d\n", padding);
    char *tmp = (char *)malloc(len+1); 
    memcpy(tmp, buff, len-padding);
    tmp[len-padding] = '\0';
    printf("ASCII: %s\n", tmp);
    free(tmp);
}


/************************************************************************
 ** 本例采用：
 ** 3des-ecb加密方式；
 ** 24位密钥，不足24位的右补0x00；
 ** 加密内容8位补齐，补齐方式为：少1位补一个0x01,少2位补两个0x02,...
 ** 本身已8位对齐的，后面补八个0x08。
 ************************************************************************/
int main(void)
{
    int docontinue = 1;
    clock_t start, finish;
    double    duration;
    unsigned char *data = NULL; /* 明文 */
    int data_len = 0;
    char filename[] = "/home/hello/nuwa.tgz";
    readFile(filename,&data, &data_len);
    
    //# calc md5 for filename 
    unsigned char md[16];
    MD5((unsigned char*)filename,strlen(filename),md);
    printContent(md,16);

    //readFile("1.txt",&data, &data_len);
    if (NULL == data) {
        return -1;
    }
    printContent(data, data_len);
    cout<<data_len<<endl; 
    int data_rest;
    unsigned char ch;
    unsigned char *src = NULL; /* 补齐后的明文 */
    unsigned char *dst = NULL; /* 解密后的明文 */
    int len;
    unsigned char tmp[8];
    unsigned char in[8];
    unsigned char out[8];
    char k[] = "01234567899876543210"; /* 原始密钥 */
    int key_len;
    #define LEN_OF_KEY 24
    unsigned char key[LEN_OF_KEY]; /* 补齐后的密钥 */
    unsigned char block_key[9];
    DES_key_schedule ks,ks2,ks3;
    /* 构造补齐后的密钥 */
    key_len = strlen(k);
    memcpy(key, k, key_len);
    memset(key + key_len, 0x00, LEN_OF_KEY - key_len);
    /* 分析补齐明文所需空间及补齐填充数据 */
    data_rest = data_len % 8;
    len = data_len + (8 - data_rest);
    ch = 8 - data_rest;
    src = (unsigned char *)malloc(len);
    dst = (unsigned char *)malloc(len);
    if (NULL == src || NULL == dst)
    {
        docontinue = 0;
    }
    start = clock();
    if (docontinue)
    {
        int count;
        int i;
        /* 构造补齐后的加密内容 */
        memset(src, 0, len);
        memcpy(src, data, data_len);
        memset(src + data_len, ch, 8 - data_rest);
        /* 密钥置换 */
        memset(block_key, 0, sizeof(block_key));
        memcpy(block_key, key + 0, 8);
        DES_set_key_unchecked((const_DES_cblock*)block_key, &ks);
        memcpy(block_key, key + 8, 8);
        DES_set_key_unchecked((const_DES_cblock*)block_key, &ks2);
        memcpy(block_key, key + 16, 8);
        DES_set_key_unchecked((const_DES_cblock*)block_key, &ks3);
        printf("before encrypt:\n");

        printContent(src, len, 8-data_rest);
        /*
        for (i = 0; i < len; i++)
        {
            printf("0x%.2X ", *(src + i));
        }
        printf("\n");
        */
        /* 循环加密/解密，每8字节一次 */
        count = len / 8;
        for (i = 0; i < count; i++)
        {
            memset(tmp, 0, 8);
            memset(in, 0, 8);
            memset(out, 0, 8);
            memcpy(tmp, src + 8 * i, 8);
            /* 加密 */
            DES_ecb3_encrypt((const_DES_cblock*)tmp, (DES_cblock*)in, &ks, &ks2, &ks3, DES_ENCRYPT);
            /* 解密 */
            DES_ecb3_encrypt((const_DES_cblock*)in, (DES_cblock*)out, &ks, &ks2, &ks3, DES_DECRYPT);
            /* 将解密的内容拷贝到解密后的明文 */
            memcpy(dst + 8 * i, out, 8);
        }
        printf("after decrypt :\n");
        printContent(dst, len, 8-data_rest);
        writeFile("./en",dst,len);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    if (NULL != src) {
        free(src);
        src = NULL;
    }
    if (NULL != dst) {
        free(dst);
        dst = NULL;
    }

    if (NULL != data) {
        free(data);
        data = NULL;
    }

    return 0;
}
