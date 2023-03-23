/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:44:55 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 19:51:53 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
	int					_fpNumber;
	static const int	_frBits;

	public:
		Fixed();
		Fixed(const Fixed& ref);
		~Fixed();

		Fixed&	operator=(const Fixed& ref);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif

