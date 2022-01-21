//#include <stdio.h>
//#include <limits.h>
//#pragma warning(disable:4996)
//#define NUMBER 5
//
//
//
//int main(void)
//{
//	int i, max, min, index;
//	int array[NUMBER];
//	max = -10;
//	min = 10;
//
//	// array[0] ~ array[4] : 총 5개가 들어갈 수 있는 배열
//	for (i = 0; i < NUMBER; i++) {
//		scanf("%d", &array[i]);
//		if (max < array[i]) {
//			max = array[i];
//			index = i;
//
//		}
//	}
//	printf("%d %d", max, index + 1);
//
//	// array[0] ~ array[4] : 총 5개가 들어갈 수 있는 배열
//	for (i = 0; i < NUMBER; i++) {
//		scanf("%d", &array[i]);
//		if (min > array[i]) {
//			min = array[i];
//			index = i;
//		}
//	}
//
//	printf("%d %d", min,index + 1);
//
//	return 0;
//}