/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 02:27:00 by byaprak           #+#    #+#             */
/*   Updated: 2026/11/11 18:31:57 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawbits = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	rawbits = value << 8;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	rawbits = roundf(value * (1 << 8));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->rawbits = rhs.rawbits;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Fixed& object)
{
	o << object.toFloat();
	return (o);
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (rawbits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	rawbits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(rawbits) / (1 << bits));
}

int		Fixed::toInt(void) const
{
		return (rawbits >> bits);
}