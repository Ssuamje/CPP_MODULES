/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:35:23 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 09:19:43 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

# include <fstream>
# include <iostream>

// ofs와 ifs는 기본적으로 copy되지 않는 것이기 때문에, static으로 선언해주어야 함
class FileManager {
	private:
	static std::ofstream	_ofs;
	static std::ifstream	_ifs;
	std::string 			_file;

	public:
	FileManager();
	FileManager(std::string file);
	~FileManager();
	void		setFile(std::string file);
	std::string	extractStringFromFile();
	void		putStringToFile(std::string str);
};

#endif