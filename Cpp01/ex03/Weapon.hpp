#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private:
		const std::string	type;
	public:
		Weapon();
		~Weapon();
		std::string &typeRef();
		void		setType(std::string type);
		std::string	getType();
};

#endif