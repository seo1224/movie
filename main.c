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
    
	return 0;
}
