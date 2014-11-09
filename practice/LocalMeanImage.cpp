#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


//注意: 这里假设积分值不超过int范围
void CaculateIngegralImage(int width,int height, unsigned char *pImage,
                           int *pIntegral)
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int tmp=0;
            //add left
            if(j>0) //排除第一列
            {
                tmp += *(pIntegral-1);
            }
            //add upper top
            if( i>0)    //排除第一行
            {
                tmp += *(pIntegral-width);
            }

            //sub left top
            if( i>0 && j>0)   //排除第一行和第一列
            {
                tmp -= *(pIntegral-width-1);
            }
            //add current pixel. 
            (*pIntegral++) = tmp + (*pImage++);
        }
    }
 
}


void LocalMeanImage(int width,int height, 
                   int*pIntegral, 
                   //unsigned char *pMean,int r)
                   float *pMean,int r)
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int top=i-r;
            int bottom=i+r;
            int left=j-r;
            int right=j+r;
            //调整窗口的可行坐标
            if (top<0)
            {
                top=0;
            }
            if (left<0)
            {
                left=0;
            }
            if (right>width-1)
            {
                right=width-1;
            }
            if (bottom>height-1)
            {
                bottom=height-1;
            }
            //get <bottom,right>
            int tmp = *(pIntegral+bottom*width+right);
            if(top>0)
            {
                //sub <top-1,right>
                tmp -= *(pIntegral+(top-1)*width+right);
            }

            if(left>0)
            {
                //sub <bottom,left-1>
                tmp -= *(pIntegral+bottom*width+left-1);
            }
            if(top>0&&left>0)
            {
                //add<top-1,left-1>
                tmp += *(pIntegral+(top-1)*width+left-1);
            }
            int num= ((bottom-top+1)*(right-left+1));
            *pMean = tmp*1.0/num; //理论是不会出现除零的,也不会超过255
            pMean++;
        }
    }
}

//打印float data
void printFloatData(int width,int height, float *data)
{

    for(int i=0; i<height; i++)
    {
        float *pRow = data+i*width;
        for(int j=0; j<width; j++)
        {
            printf("%f ",*(pRow+j));
        }
        printf("\n");
    }
    printf("\n");
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
    printf("\n");
}

//打印integral
void printIntegral(int width,int height, int*data)
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
    printf("\n");
}




int main(){
    #define W 4 
    #define H 5 
    unsigned char data[W*H] = { 1,2,3,2,
                                1,2,4,0,
                                3,0,3,0,
                                5,1,5,0,
                                1,1,0,9};
    printf("original:\n");
    printData(W,H,data);


    //计算积分图
    int integralImage[W*H];
    CaculateIngegralImage(W,H, data, integralImage);
    printf("integral:\n");
    printIntegral(W,H,integralImage);


    //unsigned char mean[W*H]; 
    //memset(mean,0,sizeof(unsigned char)*W*H);
    float mean[W*H]; 
    memset(mean,0,sizeof(float)*W*H);
    int r=0;    // test: 0, 1, 2, 3
    //利用积分图求均值图
    LocalMeanImage(W,H, integralImage, mean,r);
    printf("meanImage(r=0):\n");
    printFloatData(W,H,mean);

    r=1;    // test: 0, 1, 2, 3
    //利用积分图求均值图
    LocalMeanImage(W,H, integralImage, mean,r);
    printf("meanImage(r=1):\n");
    printFloatData(W,H,mean);
	return 0;
}

