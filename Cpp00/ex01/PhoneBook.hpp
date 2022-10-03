#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>


class PhoneBook
{
	private:
		Contact	contact[8];
		int		numOfContact;
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
		void	displayContact(Contact &contact);
		void	exit();
};

#endif