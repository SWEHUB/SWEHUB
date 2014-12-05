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
	printf("--------- 회원가입 ---------\n");
	check=0;
	for(num=0; num<1; num++)
		{
		printf("ID : ");
		gets(id);
		// 중복검사

		printf("pw : ");
		gets(pw);

		printf("이름 : ");
		gets(name);

		printf("학과 : ");
		gets(dept);

		}

	// + 잘못된 값을 입력했을 때 예외처리

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

	// 중복되었다고 메시지

	}while(check);
	// 다시 회원가입으로
	fclose(fp);

	while(1)
	{
		printf("1. 위의 정보로 가입\n");
		printf("0. 첫 페이지로 돌아가기\n");

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
			printf("\n---- 메인 ----\n");
			break;
		}
		else
			continue;
	}

	fclose(f);

	return 0;
}
