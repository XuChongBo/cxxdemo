#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//找pData中的连通量
int LabelBinaryObjects(int width,int height, unsigned char *pData, int *pLabel){
    int objectIndex=0;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(255==(*pData))   //foreground
            {
                //check left
                if(j>0) //排除第一列
                {
                    *pLabel=*(pLabel-1);
                }
                //check left top
                if((0==*pLabel) &&  i>0 && j>0)   //排除第一行和第一列
                {
                    *pLabel=*(pLabel-width-1);
                }
                //check upper top
                if( (0==*pLabel) && i>0)    //排除第一行
                {
                    *pLabel=*(pLabel-width);
                }
                //check right top
                if((0==*pLabel)&& i>0 && j<width-1)   //排除第一行和最后一列
                {
                    *pLabel=*(pLabel-width+1);
                }
                //还没找到已有标签,自增一个
                if(0==*pLabel)
                {
                    *pLabel=++objectIndex;
                }

            }

            pData++;
            pLabel++;
        }
    }
    return objectIndex;
}

//打印data
void printData(int width,int height, unsigned char *data)
{

    for(int i=0; i<height; i++)
    {
        unsigned char *pRow =(unsigned char *) data+i*width;
        for(int j=0; j<width; j++)
        {
            printf("%d ",*(pRow+j));
        }
        printf("\n");
    }
}

//打印label
void printLabel(int width,int height, int*data)
{

    for(int i=0; i<height; i++)
    {
        //char *pRow =(char *) data+i*width;
        int*pRow = data+i*width;
        for(int j=0; j<width; j++)
        {
            printf("%d ",*(pRow+j));
        }
        printf("\n");
    }
}




int main(){
/*    #define W 3
    #define H 3
    unsigned char data[W*H] = {0,0,0,
                        0,255,0,
                        0,0,0};
    #define W 3
    #define H 3
    unsigned char data[W*H] = {255,255,255,
                                255,255,255,
                                0,255,0};
*/
    #define W 4 
    #define H 5 
    unsigned char data[W*H] = { 0,0,255,255,
                                255,0,255,0,
                                0,0,0,0,
                                0,255,0,0,
                                0,255,0,255};





    int label[W*H]; 
    memset(label,0,sizeof(int)*W*H);
    printData(W,H,data);
    //找连通量
    int n = LabelBinaryObjects(W,H,data,label);
    printLabel(W,H,label);
    printf("total:%d\n",n);
	return 0;
}

