/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:51:45 by chorst            #+#    #+#             */
/*   Updated: 2024/10/29 10:05:13 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
				int _fpn_value;
				static const int _fractionalBits;
	public:
				// Overloaded Constructors (orthodox canonical form)
				Fixed();
				Fixed(const Fixed& original);
				Fixed& operator=(const Fixed& original);
				Fixed(const int i);
				Fixed(const float nbr);

				// Deconstructor
				~Fixed();

				// Overload comparising based Operators
				bool operator>(Fixed const &fixed);
				bool operator<(Fixed const &fixed);
				bool operator>=(Fixed const &fixed);
				bool operator<=(Fixed const &fixed);
				bool operator==(Fixed const &fixed);
				bool operator!=(Fixed const &fixed);

				// Overload math based Operators:
				Fixed operator+(Fixed const &fixed);
				Fixed operator-(Fixed const &fixed);
				Fixed operator*(Fixed const &fixed);
				Fixed operator/(Fixed const &fixed);

				// pre-increment and decrement Operators
				Fixed operator++();
				Fixed operator--();

				// post-increment and decrement Operators
				Fixed operator++(int);
				Fixed operator--(int);

				// Methods
				float toFloat(void) const;
				int toInt(void) const;
				static Fixed &min(Fixed &fpn_value_1, Fixed &fpn_value_2);
				static const Fixed &min(Fixed const &fpn_value_1, Fixed const &fpn_value_2);
				static Fixed &max(Fixed &fpn_value_1, Fixed &fpn_value_2);
				static const Fixed &max(Fixed const &fpn_value_1, Fixed const &fpn_value_2);
};

std::ostream& operator<<(std::ostream &o, Fixed const &fixed);

#endif
