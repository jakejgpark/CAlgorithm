#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int A, B, C;
	int sum;
	int arr[10] = { 0, }; // �� ���ڿ� ���� �迭 �����. �� 10��.
	int num;

	scanf("%d %d %d", &A, &B, &C);
	sum = A * B * C;

	while (sum > 0)
	{
		num = sum % 10; // 10���� �������� �� ������, ���� 1�� �ڸ� ����
		arr[num]++;
		sum /= 10;      // 10���� ������ ���� ������ ���� �ڸ��� ����.
	}

	for (int i = 0; i <= 9; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}