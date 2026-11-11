/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 02:18:47 by byaprak           #+#    #+#             */
/*   Updated: 2026/11/11 17:06:44 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCLASS_HPP
#define MYCLASS_HPP
#include<iostream>
class	Fixed
{
	private:
		int	rawbits;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif