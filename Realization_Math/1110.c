//#include <stdio.h>
//#pragma warning(disable:4996)
//
//int main(void)
//{
//	int num, num1, num10, num_buf,num_cal;
//	int i = 1;
//	scanf("%d", &num);
//	num_buf = num;
//	while (1)
//	{
//		num10 = num / 10;        //10�� �ڸ����� �� ����
//		num1 = num % 10;         //1�� �ڸ����� �� ����
//		num_cal = (num1 + num10)%10;  //�� �ڸ����� �տ��� 1�� �ڸ� ��
//		num = num1 * 10 + num_cal;  // ������ ���� �� �̾� ���̱�
//		if (num==num_buf) // �ʱⰪ�� �������� break
//		{
//			break;
//		}
//
//		i++;
//	}
//	printf("%d", i);
//	return 0;
//}