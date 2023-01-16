#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	ICharacter* bob = new Character("bob");
	// tmp = src->createMateria("ice");
	// bob->equip(tmp);
	// tmp = src->createMateria("cure");
	// bob->equip(tmp);

	// me->use(0, *me);
	me->use(0, *bob);
	// me->use(1, *me);
	me->use(1, *bob);

	// std::cout << "----------------" << std::endl;

	// me->unequip(0);
	// me->unequip(1);
	// me->use(0, *me);
	// me->use(0, *bob);
	// me->use(1, *me);
	// me->use(1, *bob);

	// Character c1;
	// Character c2(c1);
	// c1 =c2;
	// if (&c1 == &c2)
	// 	std::cout << "Shallow Copy" << std::endl;
	// else
	// 	std::cout << "Deep Copy" << std::endl;
	// MateriaSource m1;
	// MateriaSource m2(m1);
	// m1 = m2;
	// if (&m1 == &m2)
	// 	std::cout << "Shallow Copy" << std::endl;
	// else
	// 	std::cout << "Deep Copy" << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}