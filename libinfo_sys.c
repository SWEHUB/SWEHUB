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
		if(strstr( string, id) && strstr( string, pw))
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

	if(check==0)
		printf("\n======== ȸ�� ���� =========\n");

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

	printf("============ �缭 ============\n\n");
	printf("--------- �� å ��� ---------\n");

	for(num=0; num<1; num++)
		{
		printf("å ���� : ");
		gets(title);

		printf("���� : ");
		gets(authors);

		printf("���ǻ� : ");
		gets(publisher);

		printf("ISBN : ");
		gets(isbn);

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

		if(select == 1)
		{
			for(num=0;num<1;num++)
			{
			fprintf(f,"%s	%s	%s	%s	���Ⱑ��	-",title,authors,publisher,isbn,availability,renting);
			// �⺻���� ���Ⱑ��, -
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
}

void main(){
	int menu;
	int menu_librarian;
	int menu_student;
	char *aa;
	

	while(1){
		printf("========��������========\n");
		printf("1.�α���\n");
		printf("2.ȸ������\n");
		printf("==>");

		scanf("%d", &menu);
		system("CLS");
		getchar();
		if(menu==1){
			//printf("ASDFA");
			//�α��γ���
			aa=login();
			printf("%s", aa);

			continue;
		}
		else if(menu=2){
			//ȸ������
			system("cls");
			join();
			continue;
		}
		else
			continue;

		


	}
}