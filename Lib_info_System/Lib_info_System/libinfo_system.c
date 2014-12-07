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
void Update(char *isbn);
void Delete();
void rent(char *isbn);
void Return(char *isbn);
char *login(void);
void bookadd();
void lib_menu();
void stu_menu(char *id);
void main_menu();
void rentlsit(char *id);
void bookinfo_list( char *id, char *isbn);

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
			system("cls");
			printf("�ߺ��� ID�Դϴ�.\n");
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
			system("cls");
			break;
		}
		else if(select == 0)
		{
			system("cls");
			/*
			���� ù�������� ���ư��⿡�� �л� �������� �Ѿ
			�Ϲ� ����â���� ���� �� ��!
			*/
			main_menu();
			break;
		}
		else
			continue;
	}

	fclose(f);
}
void Update(char *isbn){
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
	char isbn2[20];
	char availability[10];
	char renting[10];// long
	char str[1000][180] = {0,};//õ�ٱ��� �о���ϼ� ����(������ 256�� ����) 
	char std[1000][180] = {0,};
    int line= 0, line2= 0;//�о���� �� ���� ī��Ʈ 
	int menu;

	fp = fopen("book_info.txt", "r");//������ �б� ���� ����(���ϸ��� data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
			break;//�о���ΰ� ������ ���� ����   
		line++;//�о���� �� ���� ī��Ʈ 
   } 
	fclose(fp);//���� �ݱ� 
	
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
		pch = strtok(string,"	,\n");// string�� ISBN�� ��

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
				strcpy(ISBN,isbn);
				if(!strcmp(cmp_ISBN,ISBN))
				{
					strcpy(isbn2,pch);
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
		if(fgets(std[line2], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
			break;//�о���ΰ� ������ ���� ����   
		line2++;//�о���� �� ���� ī��Ʈ 
   } 
	fclose(fp);
	while(1){
		printf("--------------------\n");
		printf("������ ���λ���=>");
		scanf("%d",&select);
		getchar();
		
		if(select==1){
			printf("å����: %s =>",title);
			scanf("%s",&title);
			getchar();
		}
		else if(select==2){
			printf("����: %s =>",authors);
			scanf("%s",&authors);
			getchar();
		}
		else if(select==3){
			printf("���ǻ�: %s =>",publisher);
			scanf("%s",&publisher);
			getchar();
		}
		else if(select==4){
			printf("ISBN: %s =>",isbn2);
			scanf("%s",&isbn2);
			getchar();
		}
		else
			continue;
		while(1){
			printf("--------------------\n");
			printf("1.������� ����\n");
			printf("2.������ ���λ��� �缱��\n");
			printf("0.����ȭ��\n");
			printf("=>");
			scanf("%d",&menu);
			if(menu==1){
				 fp = fopen("book_info.txt", "w");//������ ���� ���� ���� 
	for(i=0;i < book_num;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	fp = fopen("book_info.txt", "a");
	fprintf(fp,"%s	%s	%s	%s	%s	%s",title,authors,publisher,isbn2,availability,renting);
	fprintf(fp,"\n");
	fclose(fp);
	fp = fopen("book_info.txt", "a");
	for(i=book_num+1;i < line;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
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
void Delete(){//��ɱ����Ϸ�
	 char str[1000][180] = {0,};//õ�ٱ��� �о���ϼ� ����(������ 256�� ����) 
   int line= 0;//�о���� �� ���� ī��Ʈ 
   int i, n;//������ ���� �ӽ� ������ 
   FILE *fp = fopen("book_info.txt", "r");//������ �б� ���� ����(���ϸ��� data.txt) 
   while(1) 
   { 
      if(fgets(str[line], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
      break;//�о���ΰ� ������ ���� ����   
      line++;//�о���� �� ���� ī��Ʈ 
   } 
   fclose(fp);//���� �ݱ� 
   //�о���� ���ڿ� ��� 
  /* for(i=0;i < line;i++) 
   { 
      printf("%d : %s", i+1, str[i]); 
   } */
   printf("������ ����:"); 
   scanf("%d", &n); 
   fp = fopen("book_info.txt", "w");//������ ���� ���� ���� 
   for(i=0;i < line;i++) 
   { 
      if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
      fprintf(fp, "%s", str[i]);  
   } 
   fclose(fp); 
}
void rent(char *isbn){// �й�,ISBN �޾ƿ���
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
	char isbn2[20];
	char renting[10];// long
	char str[1000][180] = {0,};//õ�ٱ��� �о���ϼ� ����(������ 256�� ����) 
	char std[1000][180] = {0,};
    int line= 0, line2= 0;//�о���� �� ���� ī��Ʈ 
	int menu;
	//char booklist2[100]="";
	while(1){
		printf("==========��������==========\n");
		printf("�����л� ID:");
		scanf("%s",&renting);
		getchar();
		printf("------------------------------\n");
		printf("1. %s���� ��������\n",renting);
		printf("2.���� ���\n");
		printf("=>");
		scanf("%d",&select);
		getchar();
		if(select==1){
			fp = fopen("book_info.txt", "r");//������ �б� ���� ����(���ϸ��� data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
			break;//�о���ΰ� ������ ���� ����   
		line++;//�о���� �� ���� ī��Ʈ 
   } 
	fclose(fp);//���� �ݱ� 
	
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
		pch = strtok(string,"	,\n");// string�� ISBN�� ��

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
				strcpy(ISBN,isbn);
				if(!strcmp(cmp_ISBN,ISBN))
				{
					strcpy(isbn2,pch);
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
		if(fgets(std[line2], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
			break;//�о���ΰ� ������ ���� ����   
		line2++;//�о���� �� ���� ī��Ʈ 
   } 
	fclose(fp);
    fp = fopen("book_info.txt", "w");//������ ���� ���� ���� 
	for(i=0;i < book_num;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	fp = fopen("book_info.txt", "a");
	fprintf(fp,"%s	%s	%s	%s	����Ұ�	%s",title,authors,publisher,isbn2,renting);
	fprintf(fp,"\n");
	fclose(fp);
	fp = fopen("book_info.txt", "a");
	for(i=book_num+1;i < line;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
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
void Return(char *isbn){
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
	char isbn2[20];
	char availability[10];
	char renting[10];// long
	char str[1000][180] = {0,};//õ�ٱ��� �о���ϼ� ����(������ 256�� ����) 
	char std[1000][180] = {0,};
    int line= 0, line2= 0;//�о���� �� ���� ī��Ʈ 
	while(1){
		printf("==========�����ݳ�==========\n");
		printf("�ݳ��Ͻðڽ��ϱ�?\n");
		printf("1.�ݳ�\n");
		printf("2.���\n");
		printf("=>");
		scanf("%d", &select);
		if(select==1){
			fp = fopen("book_info.txt", "r");//������ �б� ���� ����(���ϸ��� data.txt) 
    while(1) 
	{ 
		if(fgets(str[line], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
			break;//�о���ΰ� ������ ���� ����   
		line++;//�о���� �� ���� ī��Ʈ 
   } 
	fclose(fp);//���� �ݱ� 
	
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
		pch = strtok(string,"	,\n");// string�� ISBN�� ��

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
				strcpy(ISBN,isbn);
				if(!strcmp(cmp_ISBN,ISBN))
				{
					strcpy(isbn2,pch);
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
		if(fgets(std[line2], 180, fp) == NULL)//���Ͽ��� ���� �о���� 
			break;//�о���ΰ� ������ ���� ����   
		line2++;//�о���� �� ���� ī��Ʈ 
   } 
	fclose(fp);
    fp = fopen("book_info.txt", "w");//������ ���� ���� ���� 
	for(i=0;i < book_num;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	fp = fopen("book_info.txt", "a");
	fprintf(fp,"%s	%s	%s	%s	���Ⱑ��	-",title,authors,publisher,isbn2);
	fprintf(fp,"\n");
	fclose(fp);
	fp = fopen("book_info.txt", "a");
	for(i=book_num+1;i < line;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
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

	printf("--------- �α��� ---------\n");

	for(num=0; num<1; num++)
		{
		printf("ID : ");
		scanf("%s",&id);

		printf("pw : ");
		scanf("%s",&pw);

		}

	// + �߸��� ���� �Է����� �� ����ó��

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
				printf("\n======== �缭 ���� =========\n");
				check=1;
				strcpy(login_id,id);
				
			}
			else
			{
				printf("\n======== �л� ���� =========\n");
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
		//printf("\n======== ȸ�� ���� =========\n");

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

	printf("============ �缭 ============\n\n");
	printf("--------- �� å ��� ---------\n");

	for(num=0; num<1; num++)
		{
		printf("å ���� : ");
		gets(Book.title);

		printf("���� : ");
		gets(Book.authors);

		printf("���ǻ� : ");
		gets(Book.publisher);

		printf("ISBN : ");
		gets(Book.isbn);

		//���⿩�� ���Ⱑ��
		//�����л� -
		}

	// + �߸��� ���� �Է����� �� ����ó��
	// + ȭ�� ��� ���� ����

	printf("----------------------------\n");

	while(1)
	{
		printf("1. ������� ����\n");
		printf("0. ����ȭ��\n");

		scanf("%d",&select);
		system("cls");
		getchar();

		if(select == 1)
		{
			for(num=0;num<1;num++)
			{
			fprintf(f,"%s	%s	%s	%s	���Ⱑ��	-",Book.title,Book.authors,Book.publisher,Book.isbn,Book.availability,Book.renting);
			// �⺻���� ���Ⱑ��, -
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
void rentlist(char *id){
	int select;
	int str_ck;
	int book_num=1;
	char cmp_id[10];
	char ID[10];
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

	printf("========�л�(%s)========\n", id);
	/// ���� ������ �ڷ�
	//printf("å ����   |   ����   |   ���ǻ�   |   ISBN   |   �����Ȳ   |   �����л�\n");
	printf("��ȣ | å ����\n");

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
				strcpy(ID,id);
				if(!strcmp(cmp_id,ID))
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
	//printf("0. ����ȭ��\n");
	printf("å ��ȣ : ");
	scanf("%d",&select);

	if(select !=0)
	{

		booklist2 = strtok(booklist,"	,\n");
		while (booklist2 != NULL)
		{
			if(!strcmp(s_book,booklist2)){
			
				//�Է¹��� å ��ȣ�� ��Ī�Ǵ� å ���� ���
				// ���� �� ���� â
			printf("%s å����\n",booklist2);
			}
			booklist2 = strtok(NULL,"	,\n");
		}
	}

	// + �ٸ��� ���� ����ó��

}
void lib_menu(){
	int lib_menu;
	while(1){
					printf("========�缭========\n");
					printf("1.�˻�\n");
					printf("2.å���\n\n");
					printf("0.�α׾ƿ�\n");
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
						printf("0~2������ �޴���ȣ�� �Է����ּ���\n");
						continue;

				}

}
void stu_menu(char *id){
	int stu_menu;

	while(1){
					printf("========�л�(%s)========\n", id);
					printf("1.�˻�\n");
					printf("2.���� ������ ����\n\n");
					printf("0.�α׾ƿ�\n");
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
						rentlist(id);
						continue;
					}
					else if(stu_menu==0){
						break;
					}
					else
						printf("0~2������ �޴���ȣ�� �Է����ּ���\n");
						continue;
				}
}
void main_menu(){
	int menu;
	char *id;
	char lib_id[10]="7654321";
	

	while(1){
		printf("========��������========\n");
		printf("1.�α���\n");
		printf("2.ȸ������\n");
		printf("3.�缭�� '45423323' å���� ��ȸ\n");////////////
		printf("==>");

		scanf("%d", &menu);
		system("CLS");
		getchar();

		////////////////////////
		if(menu=3){
			system("cls");
			bookinfo_list("7654321","45423323");
			continue;
		}
		///////////////

		if(menu==1){
			id=login();
			system("cls");
			if(!strcmp(lib_id,id)==TRUE){
				lib_menu();
			}
			else{
				stu_menu(id);
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
void bookinfo_list( char *aa, char *bb){
	int str_ck;
	int book_num=0,book_num2=0;
	char cmp_ISBN[10];
	char string[MAXSTRING]; 
	char string2[MAXSTRING]; 
	FILE *f,*fp;
	char *pch;
	char booklist[100]="";
	char bookin[150]="";
	char isbn[20];
	char str[1000][180] = {0,};//õ�ٱ��� �о���ϼ� ����(������ 256�� ����) 
	char std[1000][180] = {0,};
	int line= 0, line2= 0;//�о���� �� ���� ī��Ʈ 
	int menu;
	char lib_id[10]="7654321";//�������� ����
	struct BookInfo Book;

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
		pch = strtok(string,"	,\n");// string�� ISBN�� ��

		fgets(string2,MAXSTRING - 1,fp);
		while (pch != NULL)
		{
			/*switch(str_ck){
			case 1:{
			strcpy(Book.title,pch);break;}
			case 2:{
			strcpy(Book.authors,pch);break;}
			case 3:{
			strcpy(Book.publisher,pch);break;}
			case 4:{
			strcpy(Book.isbn,bb);break;}////
			case 5:{
			strcpy(Book.availability,pch);break;}
			case 6:{
			strcpy(Book.renting,pch);break;}
			default:
			break;

			}
			book_num++;
			*/
			if(str_ck==1){
				strcpy(Book.title,pch);
			}
			else if(str_ck==2){
				strcpy(Book.authors,pch);
			}
			else if(str_ck==3){
				strcpy(Book.publisher,pch);
			}
			else if(str_ck==4)
			{
				strcpy(cmp_ISBN,pch);
				strcpy(Book.isbn,bb);
				////////////////////
				if(!strcmp(cmp_ISBN,Book.isbn))
				{
					strcpy(isbn,pch);
					str_ck++;
					pch = strtok(NULL,"	,\n");
					strcpy(Book.availability,pch);
					str_ck++;
					pch = strtok(NULL,"	,\n");
					strcpy(Book.renting,pch);
					break;
				}
				///////////////
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

	printf("\n--------------------\n");
	printf("e��������");

	printf("\nå����   : %s",Book.title);
	printf("\n����     : %s",Book.authors);
	printf("\n���ǻ�   : %s",Book.publisher);
	printf("\nISBN     : %s",Book.isbn);
	printf("\n������Ȳ : %s",Book.availability);
	printf("\n�����л� : %s",Book.renting);




	while(1){
		printf("\n--------------------\n");

		if(!strcmp(lib_id,aa)==TRUE){//�缭
			//////�Լ��� �ѱ�°� ������
			printf("1.����\n");
			printf("2.����\n");
			printf("3.����\n");
			printf("4.�ݳ�\n");
			printf("0.����ȭ��\n");
			printf("=>");
			scanf("%d",&menu);

			switch(menu){
				case 0:{//�缭�޴�
					   lib_menu();}
				case 1:{//
					   Update(bb);}
				case 2:{//
					   Delete();}/////////////////////////�ƹ����� �ȳѱ�??isbn��..?
				case 3:{//
					   rent(bb);}
				case 4:{//
					   Return(bb);}
				default:{
						break;}

			}
		}
		else{
			//////�Լ��� �ѱ�°� ������
			while(1){
				printf("0.����ȭ��\n");
				printf("=>");
				scanf("%d",&menu);

				if(menu==0)
					stu_menu(aa);
				else
					printf("! �������� �ʴ� �޴���ȣ�Դϴ�.\n");
			}
		}
	}
};
