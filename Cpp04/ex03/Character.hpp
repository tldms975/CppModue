#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character& o);
		virtual ~Character();
		Character& operator=(const Character& o);
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		std::string const &getName() const;
};


#endif 

