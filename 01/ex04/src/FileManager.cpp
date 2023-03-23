/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:36:16 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 15:44:48 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FileManager.hpp"

std::ifstream FileManager::_ifs;
std::ofstream FileManager::_ofs;

FileManager::FileManager() {

}

FileManager::FileManager(std::string file) {
	this->_file = file;
}

FileManager::~FileManager() {

}

void		FileManager::setFile(std::string file) {
	this->_file = file;
}

int			FileManager::isFileValid(std::string file) {
	_ifs.open(file);
	if (_ifs.is_open() == false) {
		_ifs.clear();
		_ifs.close();
		return (false);
	}
	_ifs.clear();
	_ifs.close();
	return (true);
}

std::string FileManager::extractStringFromFile() {
	std::string	ret;
	std::string	line;

	_ifs.open(this->_file);
	if (_ifs.is_open() == false)
		exit(EXIT_FAILURE); // 추가적인 정보 제공 필요
	while (std::getline(_ifs, line)) {
		ret += line;
		if (_ifs.eof() == false || line.back() == '\n')
			ret += std::string("\n");
	}
	if (_ifs.bad()) { // _ifs.fail()은 위 루프문에서 failbit이 설정될때까지 읽기를 시도하기 때문.
		std::cout <<
		"ifstream is broken!" << std::endl;
		exit(EXIT_FAILURE);
	}
	_ifs.close();
	return (ret);
}

void		FileManager::putStringToFile(std::string str) {
	_ofs.open(this->_file + ".replace");
	if (_ofs.is_open() == false)
		exit(EXIT_FAILURE);
	_ofs << str;
	_ofs.close();
}