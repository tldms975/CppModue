/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:12:43 by jasong            #+#    #+#             */
/*   Updated: 2022/09/03 03:39:29 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACT_NUM 8

# include "Contact.hpp"
# include <iomanip>

class  PhoneBook {
  private:
    int       old_idx;
    int       size;
    Contact   contacts[MAX_CONTACT_NUM];

  public:
    PhoneBook();
    void  add(void);
    void  search(void);
    void  displayList(void);
    void  printDefaultmsg(void);
    void  output(std::string s);
};

#endif
