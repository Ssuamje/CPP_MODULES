/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:31:07 by sanan             #+#    #+#             */
/*   Updated: 2023/03/21 23:16:54 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

enum contactElements {
	ADDED,
	NOT_ADDED,
	FIRST_NAME,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
};

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
		int			_isAdded;
	
	public:
		Contact();
		~Contact();
		void setContact(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret,
			int			isAdded
		);
		
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		int 		getIsAdded() const;
};

#endif