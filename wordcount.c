#include <stdio.h>
#include <string.h>
#include<malloc.h>
int countWord(char *filename);
int countCount(char *filename);

void main(int argc,char* a[]){
	int totalchar;//总字符数 
	int totalword;//总单词数 
      if(!strcmp(a[1],"-w")) 
        countWord(a[2]);                
      else if(!strcmp(a[1],"-c"))//是否匹配 
        countCount(a[2]);                        
}

int countWord(char *filename){
	FILE *fp=NULL;  
    char c; 
	int aword;
    int totalword=0; 
    fp=fopen(filename, "rb");
    while(!feof(fp))//feof 检查是否到文件的结束位置
    {
	c=fgetc(fp);//获取单个字符
	if((c!=' '&&c!=','))
		aword=1;
	else if(aword)//检测到不是字符
	{
		totalword++;
		aword=0;
	}
    }
	fclose(fp);
    printf("单词数:%d ",totalword);
	return 0;
}
	

int countCount(char *filename){
	
	FILE *fp=NULL;
    char c;  
    int isLastBlank = 0; 
	int totalchar=0;
	fp=fopen(filename, "rb"); 
	while(!feof(fp))//feof 检查是否到文件的结束位置
	{
		c=fgetc(fp);
		if(c!=' ' && c!= '\n' && c!='\t')
			totalchar++; //判断是否为字符
	}
	fclose(fp);
    printf("字符数:%d",totalchar);
	
    return 0;
}
