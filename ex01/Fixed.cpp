/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:51:23 by chorst            #+#    #+#             */
/*   Updated: 2024/10/28 11:03:47 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fpn_value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fpn_value = original._fpn_value;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->_fpn_value = original._fpn_value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpn_value = i << _fractionalBits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpn_value = roundf(nbr * (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return _fpn_value >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)_fpn_value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &outputStream, const Fixed &fixed)
{
	outputStream << fixed.toFloat();
	return outputStream;
}
