#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main()
{
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	meta->makeSound();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();	
	std::cout << cat->getType() << std::endl;
	cat->makeSound();

	delete meta;
	delete dog;
	delete cat;
//	system("Leaks ex00.exe");
	return (0);
}