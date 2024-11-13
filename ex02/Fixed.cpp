/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:51:23 by chorst            #+#    #+#             */
/*   Updated: 2024/10/28 12:49:14 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fpn_value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fpn_value = original._fpn_value;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->_fpn_value = original._fpn_value;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fpn_value = i << _fractionalBits;
}

Fixed::Fixed(const float nbr)
{
	// std::cout << "Float constructor called" << std::endl;
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

// Overload comparising based Operators:
bool Fixed::operator>(Fixed const &fixed)
{
	if (this->toFloat() > fixed.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<(Fixed const &fixed)
{
	if (this->toFloat() < fixed.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>=(Fixed const &fixed)
{
	if (this->toFloat() >= fixed.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator<=(Fixed const &fixed)
{
	if (this->toFloat() <= fixed.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator==(Fixed const &fixed)
{
	if (this->toFloat() == fixed.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator!=(Fixed const &fixed)
{
	if (this->toFloat() != fixed.toFloat())
		return true;
	else
		return false;
}

// Overload math based Operators:
Fixed Fixed::operator+(Fixed const &fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(Fixed const &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed const &fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed const &fixed)
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
	this->_fpn_value++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fpn_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fpn_value;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fpn_value;
	return temp;
}

Fixed &Fixed::min(Fixed &fpn_value_1, Fixed &fpn_value_2)
{
	if (fpn_value_1.toFloat() <= fpn_value_2.toFloat())
		return fpn_value_1;
	else
		return fpn_value_2;
}

const Fixed &Fixed::min(Fixed const &fpn_value_1, Fixed const &fpn_value_2)
{
	if (fpn_value_1.toFloat() <= fpn_value_2.toFloat())
		return fpn_value_1;
	else
		return fpn_value_2;
}

Fixed &Fixed::max(Fixed &fpn_value_1, Fixed &fpn_value_2)
{
	if (fpn_value_1.toFloat() > fpn_value_2.toFloat())
		return fpn_value_1;
	else
		return fpn_value_2;
}


const Fixed &Fixed::max(Fixed const &fpn_value_1, Fixed const &fpn_value_2)
{
	if (fpn_value_1.toFloat() > fpn_value_2.toFloat())
		return fpn_value_1;
	else
		return fpn_value_2;
}
