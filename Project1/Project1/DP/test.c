#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#define p1 (0xf002000)

struct Person {    // ����ü ����
    char name[20];        // ����ü ��� 1
    int age;              // ����ü ��� 2
    char address[100];    // ����ü ��� 3
};

int main()
{
    (struct Person *) p1;    // ����ü ������ ����, �޸� �Ҵ�
	
    return 0;
}
