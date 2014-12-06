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
			break;
		}
		else
			continue;
	}

	fclose(f);
}
void Update(){
	char str[1000][180] = {0,};//õ�ٱ��� �о���ϼ� ����(������ 256�� ����) 
    int line= 0;//�о���� �� ���� ī��Ʈ 
    int i, n,m,a;//������ ���� �ӽ� ������ 
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
	/*printf("������ ����:"); 
    scanf("%d", &n); 
	getchar();
	printf("�����ϰ��� �ϴ� ����");
	scanf("%d", &m);
	getchar();
	a=n-1;
	if(m==1){
		printf("å ����: =>");
		scanf("%s",str[a][0]);
		getchar();
	}*/
    fp = fopen("book_info.txt", "w");//������ ���� ���� ���� 
	for(i=0;i < line;i++){ 
		//if(n != (i+1))//������ ������ �ƴϸ� ���Ͽ� ���� 
			fprintf(fp, "%s", str[i]);
	} 
	fclose(fp); 
	//fp = fopen("book_info.txt", "a");
	//fclose(fp);

}
void Delete(){
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
						printf("0~2������ �޴���ȣ�� �Է����ּ���\n");
						continue;

				}

}
void stu_menu(char *aa){
	int stu_menu;

	while(1){
					printf("========�л�(%s)========\n", aa);
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
	char *aa;
	char lib_id[10]="7654321";
	

	while(1){
		printf("========��������========\n");
		printf("1.�α���\n");
		printf("2.ȸ������\n");
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