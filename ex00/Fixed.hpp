/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:51:45 by chorst            #+#    #+#             */
/*   Updated: 2024/10/28 12:58:48 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
				int _fpn_value;
				static const int _fractionalBits = 8;
	public:
				// Default constructor
				Fixed();
				// Copy constructor
				Fixed(const Fixed& original);
				// Assignment constructor
				Fixed& operator=(const Fixed& original);
				// Deconstructor
				~Fixed();

				// Methods
				int getRawBits(void) const;
				void setRawBits(int const raw);
};

#endif
