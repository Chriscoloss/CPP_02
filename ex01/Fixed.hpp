/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:51:45 by chorst            #+#    #+#             */
/*   Updated: 2024/10/29 10:04:25 by chorst           ###   ########.fr       */
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
				// Default constructor
				Fixed();
				// Copy constructor
				Fixed(const Fixed& original);
				// Assignment constructor
				Fixed& operator=(const Fixed& original);
				// Deconstructor
				~Fixed();
				// Int constructor
				Fixed(const int i);
				// Float constructor
				Fixed(const float nbr);

				// Methods
				float toFloat(void) const;
				int toInt(void) const;
};

std::ostream& operator<<(std::ostream &o, Fixed const &fixed);

#endif
