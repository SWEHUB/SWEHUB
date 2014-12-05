#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAXSTRING 256 

int main()
{
	//int select;
	int num;
	char id[10];
	char pw[20];
	//char name[10];
	//char dept[20];
	int check=0;

	char lib_id[10]="7654321";
	char lib_pw[20]="Q1234";

	char login_id[10];
	char login_pw[20];
	char string[MAXSTRING]; 
	FILE *f;

	if((f=fopen("user_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}

	printf("--------- 로그인 ---------\n");

	for(num=0; num<1; num++)
		{
		printf("ID : ");
		scanf("%s",&id);

		printf("pw : ");
		scanf("%s",&pw);

		}

	// + 잘못된 값을 입력했을 때 예외처리

	printf("----------------------------\n");

	while(fgets(string,MAXSTRING - 1,f)) 
	{ 
		if(strstr( string, id) && strstr( string, pw))
		{
	
			if(!strcmp(id,lib_id) && !strcmp(pw,lib_pw))
			{
				printf("\n======== 사서 메인 =========\n");
				check=1;
				strcpy(login_id,id);
				printf( "%s\n", login_id);
			}
			else
			{
				printf("\n======== 학생 메인 =========\n");
				check=1;
				strcpy(login_id,id);
				printf( "%s\n", login_id);
			}
		}
			
	}

	if(check==0)
		printf("\n======== 회원 가입 =========\n");

	fclose(f);

	return 0;
}
