#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const std::string type);
		virtual ~Animal();
		Animal(const Animal& c);
		Animal&				operator=(const Animal& c);
		std::string			getType() const;

		virtual void		makeSound() const = 0;
};

#endif
