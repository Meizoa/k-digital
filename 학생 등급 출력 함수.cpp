#include <stdio.h>

int studentinput()
{
	int student_cnt;
	printf("학생 수를 입력하세요 : ");
	scanf_s("%d", &student_cnt);

	return student_cnt;
}

int scoreinput(int write, int word, int xecel, int ppt, int current_student)
{
	int sum;

	printf("%d번 학생 필기 점수(400) : ", current_student);
	scanf_s("%d", &write);
	while (!(write <= 400 && write >= 0))
	{
		printf("%d번 학생 필기 점수(400) : ", current_student);
		scanf_s("%d", &write);
	}

	printf("%d번 학생 워드 점수(200) : ", current_student);
	scanf_s("%d", &word);
	while (!(word <= 200 && word >= 0))
	{
		printf("%d번 학생 워드 점수(200) : ", current_student);
		scanf_s("%d", &word);
	}

	printf("%d번 학생 엑셀 점수(200) : ", current_student);
	scanf_s("%d", &xecel);
	while (!(xecel <= 200 && xecel >= 0))
	{
		printf("%d번 학생 엑셀 점수(200) : ", current_student);
		scanf_s("%d", &xecel);
	}

	printf("%d번 학생 ppt 점수(200) : ", current_student);
	scanf_s("%d", &ppt);
	while (!(ppt <= 200 && ppt >= 0))
	{
		printf("%d번 학생 ppt 점수(200) : ", current_student);
		scanf_s("%d", &ppt);
	}
	current_student++;

	sum = write + word + xecel + ppt;
	//printf("%d\n", sum);

	return sum;
}

void scorecheck(int sum, int* a, int* b, int* c, int* d)
{
	if (sum < 400)
		(*d)++;
	else if (sum < 600)
		(*c)++;
	else if (sum < 800)
		(*b)++;
	else
		(*a)++;
}
void scoreoutput(int* a, int* b, int* c, int* d)
{
	printf("A등급 : %d\n", *a);
	printf("B등급 : %d\n", *b);
	printf("C등급 : %d\n", *c);
	printf("D등급 : %d\n", *d);
}

int main()
{
	int write = 0, word = 0, xecel = 0, ppt = 0;
	//int current_student = 1;
	int score_sum;
	int a = 0, b = 0, c = 0, d = 0;

	int student_cnt = studentinput();

	for (int i = 1; i <= student_cnt; i++)
	{
		score_sum = scoreinput(write, word, xecel, ppt, i);
		scorecheck(score_sum, &a, &b, &c, &d);
	}

	scoreoutput(&a, &b, &c, &d);

	return 0;
}
