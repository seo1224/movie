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
    
    while(1)
	{	
    	printf("\n>>MENU<<\n1.print all the movies\n2.search for specific country movies\n3.search for specific runtime movies\n4.search for specific score movies\n5.exit\n>>MENU<<\n");
        printf("\n--select an option :");
        scanf("%d",&num);
        
        getchar(); 
        
        now=(movinfo*)malloc(sizeof(movinfo));
        now=first;
        mark=0;
        
        if(num==1)
		{
        	while(now!=NULL) 
			{
        		printf("\nNAME : %s(%s)\n",now->name,now->madeIn);
                printf("running time: %d, score: %f\n",now->runTime,now->score);
                printf("----------------------");
                mark++;
                now = now->next;
			} // movie.dat의 모든 영화 정보를 print하기 위한 while문  
			
            printf("\nTotally %d movies are listed!\n", mark);
        }
        
        else if(num==2)
		{
        	printf("select a country :");
            scanf("%s",searchco);
            getchar(); // country를 비교할 때 한 문자씩 비교하기 위한 함수 
            
			while(now!=NULL)
			{ 
            	if(!strcmp(now->madeIn,searchco)) 
				{
            		printf("\nNAME : %s(%s)\n",now->name,now->madeIn);
                    printf("running time: %d, score: %f\n",now->runTime,now->score);
                    printf("----------------------");
                    
                    mark++;
				} // 문자열 비교해서 사용자가 입력한 나라만 출력시키는 if문 
				now=now->next;
			}	
            printf("\nTotally %d movies are listed!\n", mark);
		}
		
		else
		{
			printf("wrong number!\n");
		} // 1~5까지의 숫자가 입력되지 않을 경우 
    }
		    
    return 0;
}
