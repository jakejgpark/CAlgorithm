#include <iostream>

int main()
{
	int base=50;
	int num=0;
	
	while (1)
	{
		std::cout<<"�Ǹ� �ݾ��� ���� ������ �Է�:";
		std::cin>>num;
		if (num==-1)
		{
			std::cout<<"���α׷��� �����մϴ�."; 
			break;
		}
		std::cout<<"�̹� �� �޿�: "<<base+0.12*num<<std::endl; 
	}
	return 0;
}
	
