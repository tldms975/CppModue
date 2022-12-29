#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string &typeRef();
		void		setType(std::string type);
		std::string	getType() const;
};

#endif