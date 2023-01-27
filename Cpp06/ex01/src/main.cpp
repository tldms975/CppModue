#include "Data.h"
#include <iostream>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data* data1 = new Data;
	data1->data = "sielee";

	uintptr_t raw = serialize(data1);
	Data* data2 = deserialize(raw);

	std::cout << "data1: " << data1->data << "(" << &data1 << ")" << std::endl;
	std::cout << "data2: " << data2->data << "(" << &data2 << ")" << std::endl;
	delete data1;
	// system("leaks ex01.exe");
	return (0);
}