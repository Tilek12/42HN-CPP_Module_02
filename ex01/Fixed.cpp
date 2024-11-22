/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:20:43 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/22 16:47:16 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value( 0 ) {

	std::cout << "Default constuctor called\n";

}

Fixed::Fixed( int value ) {

	std::cout << "Int constructor called\n";
	_value = value << _bits;

}

Fixed::Fixed( float value ) {

	std::cout << "Float constructor called\n";
	_value = roundf( value * ( 1 << _bits ) );

}

Fixed::Fixed( const Fixed& other ) {

	std::cout << "Copy constructor called\n";
	*this = other;

}

Fixed& Fixed::operator=( const Fixed& other ) {

	std::cout << "Copy assignment operator called\n";

	if ( this != &other ) {
		_value = other._value;
	}

	return *this;

}

Fixed::~Fixed( void ) {

	std::cout << "Desctructor called\n";

}

int	Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called\n";
	return _value;

}

void	Fixed::setRawBits( int const rawBits ) {

	std::cout << "setRawBits member function called\n";
	_value = rawBits;

}

float	Fixed::toFloat( void ) const {

	return static_cast<float>( _value ) / ( 1 << _bits );

}

int	Fixed::toInt( void ) const {

	return _value >> _bits;

}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed ) {

	out << fixed.toFloat();
	return out;

}
