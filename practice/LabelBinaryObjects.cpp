#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <map>

//找pData中的连通量
int LabelBinaryObjects(int width,int height, unsigned char *pData, int *pLabelImage){
    int objectIndex=0;
    int *pLabel=pLabelImage;
    std::map <int,int> labelMap;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(255==(*pData))   //foreground
            {
                //取左边label
                if(j>0) //排除第一列
                {
                    *pLabel=*(pLabel-1);
                }
                //若label为0则取左上方
                if((0==*pLabel) &&  i>0 && j>0)   //排除第一行和第一列
                {
                    *pLabel=*(pLabel-width-1);
                }
                //若label仍为0则取正上方
                if( (0==*pLabel) && i>0)    //排除第一行
                {
                    *pLabel=*(pLabel-width);
                }
               
               //若存在右上方点
                if( i>0 && j<width-1)   
                {
                    int *pTopRight=(pLabel-width+1);

                    if( *pTopRight >0 )   
                    {
                        //若之前的check已获取到label,则说明当前点是两个连通量的连接点
                        if(*pLabel>0 && *pLabel!=*pTopRight)
                        {
                            int next_id=++objectIndex;
                            //TODO 若都存在过连接点,怎办
                            labelMap[*pLabel]=next_id;
                            labelMap[*pTopRight]=next_id;
                            *pLabel = next_id;  //连接点使用新label
                        }else
                        {
                            *pLabel = *pTopRight;
                        }
                        
                    }
                }
                //还没找到label,自增一个
                if(0==*pLabel)
                {
                    *pLabel=++objectIndex;
                }

            }

            pData++;
            pLabel++;
        }
    }
    //重置一边label
    pLabel=pLabelImage;
    //TODO:连通量个数
    //objectIndex=0;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
           std::map<int,int>::iterator iter = labelMap.find(*pLabel);
           if(iter!=labelMap.end())
           {
                *pLabel = iter->second;
           }
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
    #define W 5 
    #define H 6 
    unsigned char data[W*H] = { 0,  0, 255, 0,255,
                                255,0, 255, 0,255,
                                0,  0,  0,  255,0,
                                0, 255, 0,  255,0,
                                0, 255, 255,  0,255,
                                0, 255, 0,  255,0};





    int label[W*H]; 
    memset(label,0,sizeof(int)*W*H);
    printData(W,H,data);
    //找连通量
    int n = LabelBinaryObjects(W,H,data,label);
    printLabel(W,H,label);
    printf("total:%d\n",n);
	return 0;
}

