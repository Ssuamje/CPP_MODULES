/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:43:37 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 12:46:03 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        static int const COUNT = 100;
        std::string ideas[COUNT];

    public:
        Brain();
        Brain(const Brain& ref);
        ~Brain();

        Brain&	operator=(const Brain& ref);
};

#endif
