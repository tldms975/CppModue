#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
  private:
    std::string _name;
    long long   _health;
    long long   _energy;
    long long   _damage;

  public:
    ClapTrap(void);
    ClapTrap(const ClapTrap& c);
    ClapTrap& operator=(const ClapTrap& c);
    ~ClapTrap(void);

    ClapTrap(const std::string &name);

    std::string   getName(void) const;
    long long     getHealth(void) const;
    long long     getEnergy(void) const;
    long long     getDamage(void) const;
    void          getArmed(void);

    void          attack(const std::string& target);
    void          takeDamage(unsigned int amount);
    void          beRepaired(unsigned int amount);
};

#endif