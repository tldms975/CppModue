#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_materia[4];
		int _cnt;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &o);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &o);

		virtual void learnMateria(AMateria *);
		virtual AMateria* createMateria(std::string const & type);
};


#endif