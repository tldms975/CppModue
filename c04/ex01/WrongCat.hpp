#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		// constructor
		WrongCat();
		// copy
		WrongCat(const WrongCat& wc);
		// copy assign
		WrongCat& operator=(const WrongCat& wc);
		// destructor
		virtual ~WrongCat();

		WrongCat(const std::string& type);
		std::string		getType(void) const;
		void					setType(const std::string& type);
		void makeSound(void) const;
};

#endif