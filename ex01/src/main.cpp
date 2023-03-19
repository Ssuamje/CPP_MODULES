/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:33:50 by sanan             #+#    #+#             */
/*   Updated: 2023/03/19 15:38:34 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"
#include <sstream>

void initPhoneBookContacts(PhoneBook *phoneBook) {
	for (int i = 0; i < NUM_CONTACTS; i++) {
		phoneBook->setContactByIndex(
			i, "", "", "", "", "", NOT_ADDED
		);
	}
}

int	isIndexValid(int idx) {
	return (0 <= idx && idx < NUM_CONTACTS);
}

int isInputValidCommand(std::string input) {
	return (input == "SEARCH"
		||	input == "ADD"
		||	input == "EXIT");
}

int printFieldByIndexElement(PhoneBook phoneBook, int idx, int element) {
	std::string toPut;

	if (isIndexValid(idx) == false)
		return (false);
	switch (element)
	{
		case FIRST_NAME:
			toPut = phoneBook.getFirstNameByIndex(idx);
			break;
		case LAST_NAME:
			toPut = phoneBook.getLastNameByIndex(idx);
			break;
		case NICK_NAME:
			toPut = phoneBook.getNickNameByIndex(idx);
			break;
		case PHONE_NUMBER:
			toPut = phoneBook.getPhoneNumberByIndex(idx);
			break;
		case DARKEST_SECRET:
			toPut = phoneBook.getDarkestSecretByIndex(idx);
			break;
		default:
			std::cout << "Invalid Element!!!" << std::endl;
			return (false);
	}
	if (toPut.length() < 10)
		std::cout << std::setw(10) << toPut.substr(0, toPut.length());
	else
		std::cout << std::setw(9) << toPut.substr(0, 9) << ".";
	return (true);
}

void printContactSchema(void) {
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "NickName";
	std::cout << "|" << std::setw(10) << "Contact" << "|" << std::endl;
}

void printContactDetailByIndex(PhoneBook phoneBook, int idx) {

	std::cout << "|" << std::setw(10) << idx;
	std::cout << "|";
	printFieldByIndexElement(phoneBook, idx, FIRST_NAME);
	std::cout << "|";
	printFieldByIndexElement(phoneBook, idx, LAST_NAME);
	std::cout << "|";
	printFieldByIndexElement(phoneBook, idx, NICK_NAME);
	std::cout << "|";
	printFieldByIndexElement(phoneBook, idx, PHONE_NUMBER);
	std::cout << "|" << std::endl;
}

void printContactFloor(void) {
	for (int i = 0; i < 10 * 5 + 6; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void printAllContacts(PhoneBook phoneBook) {
	printContactFloor();
	printContactSchema();
	printContactFloor();
	for (int i = 0; i < NUM_CONTACTS; i++) {
		if (phoneBook.getIsaddedByIndex(i) == ADDED)
			printContactDetailByIndex(phoneBook, i);
	}
	printContactFloor();
}

void printSpecificContactByIndex(PhoneBook phoneBook, int idx) {
	printContactFloor();
	printContactSchema();
	printContactFloor();
	printContactDetailByIndex(phoneBook, idx);
	printContactFloor();
}

int	myAtoi(std::string str) {
	std::stringstream ss(str);
	int	ret;

	ss >> ret;
	return (ret);
}

int	isSearchableNumericString(std::string str) {
	int idx = 0;
	int num;

	while (idx < (int)str.length()) {
		if ('0' <= str[idx] && str[idx] <= '9') {
			idx++;
			continue ;
		}
		else
			return (false);
	}
	num = myAtoi(str);
	return (0 <= num && num < NUM_CONTACTS);
}

int phoneBookSearch(PhoneBook phoneBook) {
	std::string idxInput;
	
	while (true){
		printAllContacts(phoneBook);
		std::cout << "Input contact index you want to see [0 ~ " << NUM_CONTACTS - 1 << "]" << std::endl;
		std::getline(std::cin, idxInput);
		system("clear");
		if (isSearchableNumericString(idxInput) == false) {
			std::cout << "Input was invalid." << std::endl;
			continue ;
		}
		else {
			printSpecificContactByIndex(phoneBook, myAtoi(idxInput));
			return (true);
		}
	}
}

int	phoneBookAdd(PhoneBook *phoneBook) {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Input first name of contact owner : " << std::endl;
	std::getline(std::cin, firstName);
	if (std::cin.eof() == true)
		return (false);
	std::cout << "Input last name of contact owner : " << std::endl;
	std::getline(std::cin, lastName);
	if (std::cin.eof() == true)
		return (false);
	std::cout << "Input nick name of contact owner : " << std::endl;
	std::getline(std::cin, nickName);
	if (std::cin.eof() == true)
		return (false);
	std::cout << "Input phoneNumber of contact owner : " << std::endl;
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof() == true)
		return (false);
	std::cout << "Input darkestSecret of contact owner : " << std::endl;
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof() == true)
		return (false);
	phoneBook->swapContacts();
	phoneBook->setContactByIndex(
		0,
		firstName,
		lastName,
		nickName,
		phoneNumber,
		darkestSecret,
		ADDED
	);
	return (true);
}

int	proceedByCommand(PhoneBook *phoneBook, std::string command) {
	system("clear");
	if (command == "ADD")
		return (phoneBookAdd(phoneBook));
	if (command == "SEARCH")
		return (phoneBookSearch(*phoneBook));
	if (command == "EXIT") {
		exit(EXIT_SUCCESS);
	}
	return (true);
}

int main() {
	std::string input;
	PhoneBook phoneBook;
	
	initPhoneBookContacts(&phoneBook);
	while (true) {
		std::cout << "Usage : [\"ADD\", \"SEARCH\", \"EXIT\"]" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			return (EXIT_SUCCESS);
		if (isInputValidCommand(input) == false) {
			system("clear");
			continue ;
		}
		if (proceedByCommand(&phoneBook, input) == true)
			continue ;
		else
			break ;
	}
}