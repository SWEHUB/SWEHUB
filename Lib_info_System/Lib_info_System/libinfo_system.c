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
void rent(char *aa,char *bb);
void Return();
char *login(void);
void bookadd();
void lib_menu();
void stu_menu(char *aa);
void main_menu();
void rentlsit(char *aa);

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
			/*
			현재 첫페이지로 돌아가기에서 학생 메인으로 넘어감
			일반 메인창으로 변경 할 것!
			*/
			main_menu();
			break;
		}
		else
			continue;
	}

	fclose(f);
}
void Update(char *bb){
	int select;
	int i;
	int str_ck;
	int book_num=0,book_num2=0;
	char cmp_ISBN[10];
	char ISBN[10];
	char string[MAXSTRING]; 
	char string2[MAXSTRING]; 
	char buffer[100];
	FILE *f,*fp;
	char *pch;
	char *booklist2;
	char *s_book;
	char booklist[100]="";
	char bookin[150]="";
	char title[100];//
	char authors[20];
	char publisher[20];
	char isbn[20];
	char title2[100];//
	char authors2[20];
	char publisher2[20];
	char isbn2[20];
	char availability[10];
	char renting[10];// long
	char str[1000][180] = {0,};//천줄까지 읽어들일수 있음(한줄은 256자 까지) 
	char std[1000][180] = {0,};
    int line= 0, line2= 0;//읽어들인 줄 갯수 카운트 
	int menu;

	fp = fopen("book_info.txt", "r");//파일을 읽기 모드로 열기(파일명은 data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);//파일 닫기 
	
	if((f=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	if((fp=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	while(fgets(string,MAXSTRING - 1,f)) 
	{ 
		str_ck=1;
		pch = strtok(string,"	,\n");// string에 ISBN이 들어감

		fgets(string2,MAXSTRING - 1,fp);
		while (pch != NULL)
		{
			if(str_ck==1){
				strcpy(title,pch);
			}
			else if(str_ck==2){
				strcpy(authors,pch);
			}
			else if(str_ck==3){
				strcpy(publisher,pch);
			}
			else if(str_ck==4)
			{
				strcpy(cmp_ISBN,pch);
				strcpy(ISBN,bb);
				if(!strcmp(cmp_ISBN,ISBN))
				{
					strcpy(isbn,pch);
					str_ck++;
					pch = strtok(NULL,"	,\n");
					strcpy(availability,pch);
					str_ck++;
					pch = strtok(NULL,"	,\n");
					strcpy(renting,pch);
					break;
				}
				book_num++;
			}

			str_ck++;			  
			pch = strtok(NULL,"	,\n");
		}
		if(book_num==book_num2)
			break;
		book_num2++;
	}
	fclose(fp);
	fp = fopen("book_info.txt", "r");
	 while(1) 
	{ 
		if(fgets(std[line2], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line2++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);
	while(1){
		printf("--------------------\n");
		printf("수정할 세부사항=>");
		scanf("%d",&select);
		getchar();
		
		if(select==1){
			printf("책제목: %s =>",title);
			scanf("%s",&title);
			getchar();
		}
		else if(select==2){
			printf("저자: %s =>",authors);
			scanf("%s",&authors);
			getchar();
		}
		else if(select==3){
			printf("출판사: %s =>",publisher);
			scanf("%s",&publisher);
			getchar();
		}
		else if(select==4){
			printf("ISBN: %s =>",isbn);
			scanf("%s",&isbn);
			getchar();
		}
		else
			continue;
		while(1){
			printf("--------------------\n");
			printf("1.변경사항 저장\n");
			printf("2.수정할 세부사항 재선택\n");
			printf("0.메인화면\n");
			printf("=>");
			scanf("%d",&menu);
			if(menu==1){
				 fp = fopen("book_info.txt", "w");//파일을 저장 모드로 열기 
	for(i=0;i < book_num;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	fp = fopen("book_info.txt", "a");
	fprintf(fp,"%s	%s	%s	%s	%s	%s",title,authors,publisher,isbn,availability,renting);
	fprintf(fp,"\n");
	fclose(fp);
	fp = fopen("book_info.txt", "a");
	for(i=book_num+1;i < line;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", std[i]);
	} 
	fprintf(fp,"\n");
	fclose(fp);
	break;
			}
			else if(menu==2){
				break;
			}
			else if(menu==0){
				lib_menu();
			}
			else
				continue;
		}
		
	}

}
void Delete(){//기능구현완료
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
void rent(char *bb){// 학번,ISBN 받아오기
	int select;
	int i;
	int str_ck;
	int book_num=0,book_num2=0;
	char cmp_ISBN[10];
	char ISBN[10];
	char string[MAXSTRING]; 
	char string2[MAXSTRING]; 
	char buffer[100];
	FILE *f,*fp;
	char *pch;
	char *booklist2;
	char *s_book;
	char booklist[100]="";
	char bookin[150]="";
	char title[100];//
	char authors[20];
	char publisher[20];
	char isbn[20];
	char renting[10];// long
	char str[1000][180] = {0,};//천줄까지 읽어들일수 있음(한줄은 256자 까지) 
	char std[1000][180] = {0,};
    int line= 0, line2= 0;//읽어들인 줄 갯수 카운트 
	int menu;
	//char booklist2[100]="";
	while(1){
		printf("==========도서대출==========\n");
		printf("대출학생 ID:");
		scanf("%s",&renting);
		getchar();
		printf("------------------------------\n");
		printf("1. %s에게 도서대출\n",renting);
		printf("2.대출 취소\n");
		printf("=>");
		scanf("%d",&select);
		getchar();
		if(select==1){
			fp = fopen("book_info.txt", "r");//파일을 읽기 모드로 열기(파일명은 data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);//파일 닫기 
	
	if((f=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	if((fp=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	while(fgets(string,MAXSTRING - 1,f)) 
	{ 
		str_ck=1;
		pch = strtok(string,"	,\n");// string에 ISBN이 들어감

		fgets(string2,MAXSTRING - 1,fp);
		while (pch != NULL)
		{
			if(str_ck==1){
				strcpy(title,pch);
				//strcat(title,string);

			}
			else if(str_ck==2){
				strcpy(authors,pch);
				//strcat(authors,string);
			}
			else if(str_ck==3){
				strcpy(publisher,pch);
				//strcat(publisher,string);
			}
			else if(str_ck==4)
			{
				strcpy(cmp_ISBN,pch);
				strcpy(ISBN,bb);
				if(!strcmp(cmp_ISBN,ISBN))
				{
					strcpy(isbn,pch);
					//strcat(isbn,string);
					break;
				}
				book_num++;
			}

			str_ck++;			  
			pch = strtok(NULL,"	,\n");
		}
		if(book_num==book_num2)
			break;
		book_num2++;
	}
	fclose(fp);
	fp = fopen("book_info.txt", "r");
	 while(1) 
	{ 
		if(fgets(std[line2], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line2++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);
    fp = fopen("book_info.txt", "w");//파일을 저장 모드로 열기 
	for(i=0;i < book_num;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	fp = fopen("book_info.txt", "a");
	fprintf(fp,"%s	%s	%s	%s	대출불가	%s",title,authors,publisher,isbn,renting);
	fprintf(fp,"\n");
	fclose(fp);
	fp = fopen("book_info.txt", "a");
	for(i=book_num+1;i < line;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", std[i]);
	} 
	fprintf(fp,"\n");
	fclose(fp);
			break;
		}
		else if(select==2){
			break;
		}
		else
			continue;
	}
	system("cls");
}
void Return(char *bb){
	int select;
	int i;
	int str_ck;
	int book_num=0,book_num2=0;
	char cmp_ISBN[10];
	char ISBN[10];
	char string[MAXSTRING]; 
	char string2[MAXSTRING]; 
	char buffer[100];
	FILE *f,*fp;
	char *pch;
	char *booklist2;
	char *s_book;
	char booklist[100]="";
	char bookin[150]="";
	char title[100];//
	char authors[20];
	char publisher[20];
	char isbn[20];
	char availability[10];
	char renting[10];// long
	char str[1000][180] = {0,};//천줄까지 읽어들일수 있음(한줄은 256자 까지) 
	char std[1000][180] = {0,};
    int line= 0, line2= 0;//읽어들인 줄 갯수 카운트 
	while(1){
		printf("==========도서반납==========\n");
		printf("반납하시겠습니까?\n");
		printf("1.반납\n");
		printf("2.취소\n");
		printf("=>");
		scanf("%d", &select);
		if(select==1){
			fp = fopen("book_info.txt", "r");//파일을 읽기 모드로 열기(파일명은 data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);//파일 닫기 
	
	if((f=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	if((fp=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}
	while(fgets(string,MAXSTRING - 1,f)) 
	{ 
		str_ck=1;
		pch = strtok(string,"	,\n");// string에 ISBN이 들어감

		fgets(string2,MAXSTRING - 1,fp);
		while (pch != NULL)
		{
			if(str_ck==1){
				strcpy(title,pch);
				//strcat(title,string);

			}
			else if(str_ck==2){
				strcpy(authors,pch);
				//strcat(authors,string);
			}
			else if(str_ck==3){
				strcpy(publisher,pch);
				//strcat(publisher,string);
			}
			else if(str_ck==4)
			{
				strcpy(cmp_ISBN,pch);
				strcpy(ISBN,bb);
				if(!strcmp(cmp_ISBN,ISBN))
				{
					strcpy(isbn,pch);
					//strcat(isbn,string);
					break;
				}
				book_num++;
			}

			str_ck++;			  
			pch = strtok(NULL,"	,\n");
		}
		if(book_num==book_num2)
			break;
		book_num2++;
	}
	fclose(fp);
	fp = fopen("book_info.txt", "r");
	 while(1) 
	{ 
		if(fgets(std[line2], 180, fp) == NULL)//파일에서 한줄 읽어오기 
			break;//읽어들인게 없으면 루프 종료   
		line2++;//읽어들인 줄 갯수 카운트 
   } 
	fclose(fp);
    fp = fopen("book_info.txt", "w");//파일을 저장 모드로 열기 
	for(i=0;i < book_num;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	fp = fopen("book_info.txt", "a");
	fprintf(fp,"%s	%s	%s	%s	대출가능	-",title,authors,publisher,isbn);
	fprintf(fp,"\n");
	fclose(fp);
	fp = fopen("book_info.txt", "a");
	for(i=book_num+1;i < line;i++){ 
		//if(n != (i+1))//삭제할 라인이 아니면 파일에 저장 
			fprintf(fp, "%s", std[i]);
	} 
	fprintf(fp,"\n");
	fclose(fp);
			break;

		}
		else if(select==2){
			//bookinfo.c
			break;
		}
		else
			continue;

	}
	system("cls");
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

void rentlist(char *aa){
	int select;
	int str_ck;
	int book_num=1;
	char cmp_id[10];
	char id[10];
	char string[MAXSTRING]; 
	char string2[MAXSTRING]; 
	char buffer[100];
	FILE *f,*fp;
	char *pch;
	char *booklist2;
	char *s_book;
	char booklist[100]="";
	//char booklist2[100]="";

	if((f=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}

	if((fp=fopen("book_info.txt","r"))==NULL)
	{
		puts("error");
		exit(0);
	}

	printf("========학생(%s)========\n", aa);
	/// 현재 대출한 자료
	//printf("책 제목   |   저자   |   출판사   |   ISBN   |   대출상황   |   대출학생\n");
	printf("번호 | 책 제목\n");

	while(fgets(string,MAXSTRING - 1,f)) 
	{ 
		str_ck=1;
		pch = strtok(string,"	,\n");

		fgets(string2,MAXSTRING - 1,fp);
		while (pch != NULL)
		{
			if(str_ck==6)
			{
				strcpy(cmp_id,pch);
				strcpy(id,aa);
				if(!strcmp(cmp_id,id))
				{
					s_book = itoa(book_num,buffer,10);
					strcat(booklist,s_book);
					strcat(booklist,"	");
					strcat(booklist,string);
					strcat(booklist,"\n");

					printf("%d	%s\n",book_num,string);
					book_num++;
				}
			}

			str_ck++;			  
			pch = strtok(NULL,"	,\n");

		}
	}

	printf("\n------------------------\n");
	//printf("0. 메인화면\n");
	printf("책 번호 : ");
	scanf("%d",&select);

	if(select !=0)
	{

		booklist2 = strtok(booklist,"	,\n");
		while (booklist2 != NULL)
		{
			if(!strcmp(s_book,booklist2)){
			
				//입력받은 책 번호와 매칭되는 책 정보 출력
				// 도서 상세 정보 창
			printf("%s 책정보\n",booklist2);
			}
			booklist2 = strtok(NULL,"	,\n");
		}
	}

	// + 다른거 선택 예외처리

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
						Update("45423323");
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
						rentlist(aa);
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