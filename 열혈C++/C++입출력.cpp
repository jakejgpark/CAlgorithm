#include <iostream>

int main()
{
	int sum=0;
	int num=0;
	for (int i=0; i<5; i++)
	{	
		std::cout<<i<<"��° ���� �Է�: ";
		std::cin>>num;
		sum+=num;
	}
	std::cout<<sum;
	return 0;
}
	
