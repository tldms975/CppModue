#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &c);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap &c);
		void whoAmI(void);
		void attack(std::string const& target);
};
#endif
