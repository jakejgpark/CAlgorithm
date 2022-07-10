#include <iostream>

namespace A
{
	int _printf()
	{
		std::cout<<"Hi";
	}
}
namespace B
{
	int _printf()
	{
		std::cout<<"Hi2";
	}
}

int main()
{
	A::_printf();
	B::_printf();
	
	return 0;
}
	
