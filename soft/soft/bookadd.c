#include <stdio.h>
#include <string.h>
#include <windows.h>


int main()
{
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

	return 0;
}
