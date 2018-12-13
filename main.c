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

} movinfo; // ��ȭ ������ �б� ���� ����ü ����  

int main(int argc, char *argv[]) {
	
	FILE *fp=fopen("movie.dat","r");
    movinfo *node, *prev, *first, *now; 
   
    int num=0; // ����ڰ� �����ϴ� ���ڸ� �Է¹ޱ� ���� ���� 
    
    char searchco[10]; // ����ڰ� �˻��ϴ� country�� ����Ű�� ���� 
    float searchsc; // ����ڰ� �˻��ϴ� score�� ����Ű�� ���� 
    int searchrun; // ����ڰ� �˻��ϴ� runtime�� ����Ű�� ���� 
    
    int mark; // ���ǿ� �ش��ϴ� ��ȭ�� ���� ���� ���� ����
    
    while(!feof(fp))
	{
		node=(movinfo*)malloc(sizeof(movinfo)); // node�� �޸𸮸� �Ҵ� 
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
	// movie.dat�� �а� ���� ���� first�� �� ������ �����ϴ� while��
    
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
			} // movie.dat�� ��� ��ȭ ������ print�ϱ� ���� while��  
			
            printf("\nTotally %d movies are listed!\n", mark);
        }
        
        else if(num==2)
		{
        	printf("select a country :");
            scanf("%s",searchco);
            getchar(); // country�� ���� �� �� ���ھ� ���ϱ� ���� �Լ� 
            
			while(now!=NULL)
			{ 
            	if(!strcmp(now->madeIn,searchco)) 
				{
            		printf("\nNAME : %s(%s)\n",now->name,now->madeIn);
                    printf("running time: %d, score: %f\n",now->runTime,now->score);
                    printf("----------------------");
                    
                    mark++;
				} // ���ڿ� ���ؼ� ����ڰ� �Է��� ���� ��½�Ű�� if�� 
				now=now->next;
			}	
            printf("\nTotally %d movies are listed!\n", mark);
		}
		
		else
		{
			printf("wrong number!\n");
		} // 1~5������ ���ڰ� �Էµ��� ���� ��� 
    }
		    
    return 0;
}
