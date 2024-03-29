#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{
	{
		const Animal*	meta = new Animal();
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();
		const WrongAnimal* wrong = new WrongCat();


		meta->makeSound();
		std::cout << dog->getType() << std::endl;
		dog->makeSound();	
		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		wrong->makeSound();
		delete meta;
		delete dog;
		delete cat;
		delete wrong;
	}
	{
		Animal a;
		Cat c1;
		Cat c2(c1);
		if (&c1 == &c2)
			std::cout << "same\n";
		else
			std::cout << "different\n";
	}


	//system("Leaks ex00.exe");
	return (0);
}