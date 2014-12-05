#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAXSTRING 256

void join(){
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
			system("cls");
			printf("중복된 ID입니다.\n");
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
			system("cls");
			break;
		}
		else if(select == 0)
		{
			system("cls");
			break;
		}
		else
			continue;
	}

	fclose(f);
}
char *login(void){
	//int select;
	int num;
	static char id[10];
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
				
			}
			else
			{
				printf("\n======== 학생 메인 =========\n");
				check=1;
				strcpy(login_id,id);
				
			}
		}
			
	}

	if(check==0)
		printf("\n======== 회원 가입 =========\n");

	fclose(f);
	return (id);
}
void bookadd(){
	int select;
	int num;
	char title[100];
	char authors[20];
	char publisher[20];
	char isbn[20];
	char availability[10];
	char renting[10];// long
	FILE *f;

	if((f=fopen("book_info.txt","a+"))==NULL)
	{
		puts("error");
		exit(0);
	}

	printf("============ 사서 ============\n\n");
	printf("--------- 새 책 등록 ---------\n");

	for(num=0; num<1; num++)
		{
		printf("책 제목 : ");
		gets(title);

		printf("저자 : ");
		gets(authors);

		printf("출판사 : ");
		gets(publisher);

		printf("ISBN : ");
		gets(isbn);

		//대출여부 대출가능
		//대출학생 -
		}

	// + 잘못된 값을 입력했을 때 예외처리
	// + 화면 출력 포맷 정리

	printf("----------------------------\n");

	while(1)
	{
		printf("1. 변경사항 저장\n");
		printf("0. 메인화면\n");

		scanf("%d",&select);

		if(select == 1)
		{
			for(num=0;num<1;num++)
			{
			fprintf(f,"%s	%s	%s	%s	대출가능	-",title,authors,publisher,isbn,availability,renting);
			// 기본으로 대출가능, -
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
}

void main(){
	int menu;
	int menu_librarian;
	int menu_student;
	char *aa;
	

	while(1){
		printf("========도서관리========\n");
		printf("1.로그인\n");
		printf("2.회원가입\n");
		printf("==>");

		scanf("%d", &menu);
		system("CLS");
		getchar();
		if(menu==1){
			//printf("ASDFA");
			//로그인내용
			aa=login();
			printf("%s", aa);

			continue;
		}
		else if(menu=2){
			//회원가입
			system("cls");
			join();
			continue;
		}
		else
			continue;

		


	}
}