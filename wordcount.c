#include <stdio.h>
#include <string.h>
#include<malloc.h>
int countWord(char *filename);
int countCount(char *filename);

void main(int argc,char* a[]){
	int totalchar;//���ַ��� 
	int totalword;//�ܵ����� 
      if(!strcmp(a[1],"-w")) 
        countWord(a[2]);                
      else if(!strcmp(a[1],"-c"))//�Ƿ�ƥ�� 
        countCount(a[2]);                        
}

int countWord(char *filename){
	FILE *fp=NULL;  
    char c; 
	int aword;
    int totalword=0; 
    fp=fopen(filename, "rb");
    while(!feof(fp))//feof ����Ƿ��ļ��Ľ���λ��
    {
	c=fgetc(fp);//��ȡ�����ַ�
	if((c!=' '&&c!=','))
		aword=1;
	else if(aword)//��⵽�����ַ�
	{
		totalword++;
		aword=0;
	}
    }
	fclose(fp);
    printf("������:%d ",totalword);
	return 0;
}
	

int countCount(char *filename){
	
	FILE *fp=NULL;
    char c;  
    int isLastBlank = 0; 
	int totalchar=0;
	fp=fopen(filename, "rb"); 
	while(!feof(fp))//feof ����Ƿ��ļ��Ľ���λ��
	{
		c=fgetc(fp);
		if(c!=' ' && c!= '\n' && c!='\t')
			totalchar++; //�ж��Ƿ�Ϊ�ַ�
	}
	fclose(fp);
    printf("�ַ���:%d",totalchar);
	
    return 0;
}
