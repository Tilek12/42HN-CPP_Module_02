/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:44:02 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/21 12:11:43 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value( 0 ) {

	std::cout << "Default constructor called\n";

}

Fixed::Fixed( const Fixed& other ) {

	std::cout << "Copy constructor called\n";
	*this = other;

}

Fixed&	Fixed::operator=( const Fixed& other ) {

	std::cout << "Copy assignment operator called\n";

	if ( this != &other ) {
		this->_value = other.getRawBits();
	}

	return *this;

}

Fixed::~Fixed( void ) {

	std::cout << "Destcructor called\n";

}

int	Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called\n";
	return _value;

}

void	Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called\n";
	_value = raw;

}
