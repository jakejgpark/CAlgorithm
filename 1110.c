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
//		num10 = num / 10;        //10의 자리수의 값 추출
//		num1 = num % 10;         //1의 자리수의 값 추출
//		num_cal = (num1 + num10)%10;  //각 자릿수의 합에서 1의 자리 수
//		num = num1 * 10 + num_cal;  // 오른쪽 더한 수 이어 붙이기
//		if (num==num_buf) // 초기값과 같아지면 break
//		{
//			break;
//		}
//
//		i++;
//	}
//	printf("%d", i);
//	return 0;
//}