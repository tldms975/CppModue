/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:13:14 by jasong            #+#    #+#             */
/*   Updated: 2022/07/25 21:31:03 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>

class Contact {
  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phonenumber;
    std::string darkest_secret;

	public:
    void setFirstname(void);
    void setLastname(void);
    void setNickname(void);
    void setPhonenumber(void);
    void setSecret(void);
    std::string	getFirstname(void);
    std::string	getLastname(void);
    std::string	getNickname(void);
    std::string	getPhonenumber(void);
    std::string	getSecret(void);
};

#endif