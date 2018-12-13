#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct movInfo{
	
    char name[200];
    float score;
    int runTime;
    char madeIn[10];
    struct movInfo *next;

} movinfo; // 영화 정보를 읽기 위해 구조체 생성  

int main(int argc, char *argv[]) {
	
	FILE *fp=fopen("movie.dat","r");
    movinfo *node, *prev, *first, *now; 
   
    int num=0; // 사용자가 선택하는 숫자를 입력받기 위한 변수 
    
    char searchco[10]; // 사용자가 검색하는 country를 가리키는 변수 
    float searchsc; // 사용자가 검색하는 score를 가리키는 변수 
    int searchrun; // 사용자가 검색하는 runtime을 가리키는 변수 
    
    int mark; // 조건에 해당하는 영화의 수를 세기 위한 변수
    
    while(!feof(fp))
	{
		node=(movinfo*)malloc(sizeof(movinfo)); // node에 메모리를 할당 
        node->next=NULL; 
        fscanf(fp,"%s %s %d %f\n", node->name, node->madeIn, &node->runTime, &node->score);
    
        if(first==NULL)
		{
			first=node;
		}
		
		else
		{
			prev->next=node;
		}
		
        node->next=NULL;
        prev=node;
    }
	// movie.dat를 읽고 전역 변수 first에 그 정보를 저장하는 while문
    
    fclose(fp);
    
	return 0;
}
