#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAXSTRING 256 

int main()
{
	int select;
	int num;
	int check=0;
	char id[10];//long
	char pw[20];
	char name[10];
	char dept[20];
	FILE *f,*fp;
	char string[MAXSTRING];

	if((f=fopen("user_info.txt","a+"))==NULL)
	{
		puts("error");
		exit(0);
	}


	do{
	system("cls");
	printf("--------- ȸ������ ---------\n");
	check=0;
	for(num=0; num<1; num++)
		{
		printf("ID : ");
		gets(id);
		// �ߺ��˻�

		printf("pw : ");
		gets(pw);

		printf("�̸� : ");
		gets(name);

		printf("�а� : ");
		gets(dept);

		}

	// + �߸��� ���� �Է����� �� ����ó��

	printf("----------------------------\n");

	if((fp=fopen("user_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	while(fgets(string,MAXSTRING - 1,fp)) 
	{ 
		if(strstr(string, id))
		{
			check=1;
			break;
		}
	}

	// �ߺ��Ǿ��ٰ� �޽���

	}while(check);
	// �ٽ� ȸ����������
	fclose(fp);

	while(1)
	{
		printf("1. ���� ������ ����\n");
		printf("0. ù �������� ���ư���\n");

		scanf("%d",&select);

		if(select == 1)
		{
			for(num=0;num<1;num++)
			{
			fprintf(f,"%s	%s	%s	%s",id,pw,name,dept);
			fprintf(f,"\n");
			}
			break;
		}
		else if(select == 0)
		{
			printf("\n---- ���� ----\n");
			break;
		}
		else
			continue;
	}

	fclose(f);

	return 0;
}
