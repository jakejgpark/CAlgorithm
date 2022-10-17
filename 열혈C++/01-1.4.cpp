#include <iostream>

int main()
{
	int base=50;
	int num=0;
	
	while (1)
	{
		std::cout<<"판매 금액을 만원 단위로 입력:";
		std::cin>>num;
		if (num==-1)
		{
			std::cout<<"프로그램을 종료합니다."; 
			break;
		}
		std::cout<<"이번 달 급여: "<<base+0.12*num<<std::endl; 
	}
	return 0;
}
	
