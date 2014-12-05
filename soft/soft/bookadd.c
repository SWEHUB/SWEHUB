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

	return 0;
}
