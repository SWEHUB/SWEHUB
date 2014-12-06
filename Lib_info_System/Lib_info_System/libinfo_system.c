#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAXSTRING 256

struct BookInfo{
	char title[100];
	char authors[20];
	char publisher[20];
	char isbn[20];
	char availability[10];
	char renting[10];// long
	};

void join();
void Update();
void Delete();
char *login(void);
void bookadd();
void lib_menu();
void stu_menu(char *aa);
void main_menu();

void main(){
	main_menu();
}

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
void Update(){
	char str[1000][180] = {0,};//천줄까지 읽어들일수 있음(한줄은 256자 까지) 
    int line= 0;//읽어들인 줄 갯수 카운트 
    int i, n,m,a;//조작을 위한 임시 변수들 
    FILE *fp = fopen("book_info.txt", "r");//파일을 읽기 모드로 열기(파일명은 data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);//파일 닫기 
    //읽어들인 문자열 출력 
  /* for(i=0;i < line;i++) 
   { 
      printf("%d : %s", i+1, str[i]); 
   } */
	/*printf("삭제할 라인:"); 
    scanf("%d", &n); 
	getchar();
	printf("수정하고자 하는 정보");
	scanf("%d", &m);
	getchar();
	a=n-1;
	if(m==1){
		printf("책 제목: =>");
		scanf("%s",str[a][0]);
		getchar();
	}*/
    fp = fopen("book_info.txt", "w");//파일을 저장 모드로 열기 
	for(i=0;i < line;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	//fp = fopen("book_info.txt", "a");
	//fclose(fp);

}
void Delete(){
	 char str[1000][180] = {0,};//천줄까지 읽어들일수 있음(한줄은 256자 까지) 
   int line= 0;//읽어들인 줄 갯수 카운트 
   int i, n;//조작을 위한 임시 변수들 
   FILE *fp = fopen("book_info.txt", "r");//파일을 읽기 모드로 열기(파일명은 data.txt) 
   while(1) 
   { 
      if(fgets(str[line], 180, fp) == NULL)//파일에서 한줄 읽어오기 
      break;//읽어들인게 없으면 루프 종료   
      line++;//읽어들인 줄 갯수 카운트 
   } 
   fclose(fp);//파일 닫기 
   //읽어들인 문자열 출력 
  /* for(i=0;i < line;i++) 
   { 
      printf("%d : %s", i+1, str[i]); 
   } */
   printf("삭제할 라인:"); 
   scanf("%d", &n); 
   fp = fopen("book_info.txt", "w");//파일을 저장 모드로 열기 
   for(i=0;i < line;i++) 
   { 
      if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
      fprintf(fp, "%s", str[i]);  
   } 
   fclose(fp); 
}
char *login(void){
	//int select;
	int num;
	static char id[10];
	char pw[20];
	char cmp_id[10];
	char cmp_pw[20];
	//char name[10];
	//char dept[20];
	int check=0;
	char *pch;
	int str_ck=1;

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
		str_ck=1;
		pch = strtok(string,"	");
		while (pch != NULL)
		{
			if(str_ck==1)
			strcpy(cmp_id,pch);
			else if(str_ck==2)
			strcpy(cmp_pw,pch);

			str_ck++;
			pch = strtok(NULL,"	");
			//id=pch;
		}
		
		if(!strcmp(cmp_id, id) && !strcmp(cmp_pw, pw))
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

	if(check==0){
		system("cls");
		getchar();
		join();
		return("");
	}
		//printf("\n======== 회원 가입 =========\n");

	fclose(f);
	return (id);
}
void bookadd(){
	int select;
	int num;
	FILE *f;
	struct BookInfo Book;

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
		gets(Book.title);

		printf("저자 : ");
		gets(Book.authors);

		printf("출판사 : ");
		gets(Book.publisher);

		printf("ISBN : ");
		gets(Book.isbn);

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
		system("cls");
		getchar();

		if(select == 1)
		{
			for(num=0;num<1;num++)
			{
			fprintf(f,"%s	%s	%s	%s	대출가능	-",Book.title,Book.authors,Book.publisher,Book.isbn,Book.availability,Book.renting);
			// 기본으로 대출가능, -
			fprintf(f,"\n");
			}
			break;
		}
		else if(select == 0)
		{
			break;
		}
		else
			continue;
	}

	fclose(f);
}
void lib_menu(){
	int lib_menu;
	while(1){
					printf("========사서========\n");
					printf("1.검색\n");
					printf("2.책등록\n\n");
					printf("0.로그아웃\n");
					printf("---------------------\n");
					printf("==>");
					scanf("%d", &lib_menu);
					system("CLS");
					getchar();
					if(lib_menu==1){
						Update();
						continue;
					}
					else if(lib_menu==2){
						bookadd();
						continue;
					}
					else if(lib_menu==0){
						break;
					}
					else
						printf("0~2사이의 메뉴번호를 입력해주세요\n");
						continue;

				}

}
void stu_menu(char *aa){
	int stu_menu;

	while(1){
					printf("========학생(%s)========\n", aa);
					printf("1.검색\n");
					printf("2.내가 대출한 도서\n\n");
					printf("0.로그아웃\n");
					printf("---------------------\n");
					printf("==>");
					scanf("%d", &stu_menu);
					system("CLS");
					getchar();
					if(stu_menu==1){
						printf("fsdf");
						continue;
					}
					else if(stu_menu==2){
						//bookadd();
						continue;
					}
					else if(stu_menu==0){
						break;
					}
					else
						printf("0~2사이의 메뉴번호를 입력해주세요\n");
						continue;
				}
}
void main_menu(){
	int menu;
	char *aa;
	char lib_id[10]="7654321";
	

	while(1){
		printf("========도서관리========\n");
		printf("1.로그인\n");
		printf("2.회원가입\n");
		printf("==>");

		scanf("%d", &menu);
		system("CLS");
		getchar();
		if(menu==1){
			aa=login();
			system("cls");
			if(!strcmp(lib_id,aa)==TRUE){
				lib_menu();
			}
			else{
				stu_menu(aa);
			}
			continue;
		}
		else if(menu=2){
			system("cls");
			join();
			continue;
		}
		else
			continue;
	}
}