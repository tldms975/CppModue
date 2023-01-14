#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& c);
		WrongAnimal&		operator=(const WrongAnimal& c);
		std::string			getType() const;

		void		makeSound() const;
};

#endif
