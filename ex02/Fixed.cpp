/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 02:27:00 by byaprak           #+#    #+#             */
/*   Updated: 2026/11/12 00:32:57 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << 8;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << 8));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs._rawBits;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Fixed& object)
{
	o << object.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed& obj) const
{
	if (this->_rawBits > obj._rawBits)
		return (1);
	return (0);
}

bool	Fixed::operator<(const Fixed& obj) const
{
	if (this->_rawBits < obj._rawBits)
		return (1);
	return (0);
}
bool	Fixed::operator>=(const Fixed& obj) const
{
	if (this->_rawBits >= obj._rawBits)
		return (1);
	return (0);
}
bool	Fixed::operator<=(const Fixed& obj) const
{
	if (this->_rawBits <= obj._rawBits)
		return (1);
	return (0);
}
bool	Fixed::operator==(const Fixed& obj) const
{
	if (this->_rawBits == obj._rawBits)
		return (1);
	return (0);
}
bool	Fixed::operator!=(const Fixed& obj) const
{
	if (this->_rawBits != obj._rawBits)
		return (1);
	return (0);
}

Fixed	Fixed::operator+(const Fixed& obj) const
{
	Fixed	newObj;

	newObj._rawBits = this->_rawBits + obj._rawBits;
	return (newObj);
}
Fixed	Fixed::operator-(const Fixed& obj) const
{
	Fixed	newObj;

	newObj._rawBits = this->_rawBits - obj._rawBits;
	return (newObj);
}
Fixed	Fixed::operator*(const Fixed& obj) const
{
	Fixed	newObj;

	newObj._rawBits = (this->_rawBits * obj._rawBits) / (1 << _bits);
	return (newObj);
}
Fixed	Fixed::operator/(const Fixed& obj) const
{
	Fixed	newObj;

	newObj._rawBits = (this->_rawBits / obj._rawBits) * (1 << _bits);
	return (newObj);
}

Fixed&			Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}
Fixed&			Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}
Fixed			Fixed::operator++(int)
{
	Fixed temp = *this;
	
	this->_rawBits++;
	return (temp);
}
Fixed			Fixed::operator--(int)
{
	Fixed temp = *this;
	
	this->_rawBits--;
	return (temp);
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _bits));
}

int		Fixed::toInt(void) const
{
		return (_rawBits >> _bits);
}

Fixed&	Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj2);
	return (obj1);
}
const Fixed&	Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj2);
	return (obj1);
}
Fixed&	Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj2);
	return (obj1);
}
const Fixed&	Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj2);
	return (obj1);
}