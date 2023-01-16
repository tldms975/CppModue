#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define NUM_OF_ANIMAL 8

int	main()
{
	// test1
	{
		const Animal* i = new Dog();
		const Animal* j = new Cat();

		delete i;
		delete j;
	}
	std::cout << "\n\n\n";

	//test2
	{
		Animal	*animal[NUM_OF_ANIMAL];

		for (int i = 0; i < NUM_OF_ANIMAL; i++)
		{
			if (i % 2)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}
		for (int i = 0; i < NUM_OF_ANIMAL; i++)
			delete animal[i];
	}
	std::cout << "\n\n\n";
	//test3
	{
		Cat c1;
		Cat c2(c1);

		if (&c1 == &c2)
			std::cout << "same\n";
		else
			std::cout << "different\n";
	}
	//test4
	{
		Dog* dog1 = new Dog();

		for (int i = 0; i < 10; i++)
			dog1->getBrain()->setIdea(i, "meong");
		dog1->getBrain()->printIdeas();
		delete dog1;
	}
	//test5
	{
		Cat* cat1 = new Cat();
		Cat* cat2 = new Cat();


		cat1->getBrain()->printIdeas();
		cat2->getBrain()->setIdea(0, "hello");
		cat2->getBrain()->printIdeas();

		delete cat1;
		delete cat2;
	}
	//system("Leaks ex01.exe");
	return (0);
}