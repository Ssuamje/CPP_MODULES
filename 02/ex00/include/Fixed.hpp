/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:44:55 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 21:11:26 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
	int					_fpValue;
	static const int	_frBits;

	public:
		Fixed();
		Fixed(Fixed const& ref);
		~Fixed();

		Fixed&	operator=(Fixed const& ref);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif

