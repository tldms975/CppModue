#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string	_type;

	public:
	// constructor
		WrongAnimal();
		// copy
		WrongAnimal(const WrongAnimal& w);
		// copy assignment
		WrongAnimal& operator=(const WrongAnimal& w);
		// destructor
		virtual ~WrongAnimal();

		WrongAnimal(const std::string& type);
		void				makeSound(void) const;
		void				setType(const std::string& type);
		std::string	getType(void) const;
};

#endif