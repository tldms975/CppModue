#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  private:
    bool  _guard_flag;
  public:
    ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(const std::string& name,
              const int& health,
              const int& energy,
              const int& damage
            );
    ScavTrap(const ScavTrap& s);
    ScavTrap& operator=(const ScavTrap& s);
    ~ScavTrap(void);

    void  attack(const std::string& target);
    void  takeDamage(unsigned int amount);
    void  beRepaired(unsigned int amount);
    void  guardGate(void);
};

#endif