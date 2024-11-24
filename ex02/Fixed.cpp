/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:34:25 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 10:44:56 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue( 0 ) {}

Fixed::Fixed( int value ) {

	if ( value > ( intMAX >> _fractionalBits )
		|| value < ( intMIN >> _fractionalBits ) ) {
		std::cerr << "ERROR: Int value overflow detected!\n";
		_fixedPointValue = 0;
		std::exit( 1 );
	} else {
		_fixedPointValue = value << _fractionalBits;
	}
}

Fixed::Fixed( float value ) {

	float newValue = value * ( 1 << _fractionalBits );

	if ( newValue > intMAX || newValue < intMIN ) {
		std::cerr << "ERROR: Float value overflow detected!\n";
		_fixedPointValue = 0;
		std::exit( 1 );
	} else {
		_fixedPointValue = static_cast<int>( roundf( newValue ) );
	}
}

Fixed::Fixed( const Fixed& other ) : _fixedPointValue( other._fixedPointValue ) {}

Fixed&	Fixed::operator=( const Fixed& other ) {

	if ( this != &other ) {
		this->_fixedPointValue = other._fixedPointValue;
	}

	return *this;
}

Fixed::~Fixed( void ) {}

void	Fixed::setRawBits( int const raw ) { _fixedPointValue = raw; }

int		Fixed::getRawBits( void ) const { return _fixedPointValue; }

float	Fixed::toFloat( void ) const {
	return static_cast<float>( _fixedPointValue ) / ( 1 << _fractionalBits );
}

int	Fixed::toInt( void ) const {
	return _fixedPointValue >> _fractionalBits;
}

bool	Fixed::operator<( const Fixed& other ) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

bool	Fixed::operator>( const Fixed& other ) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool	Fixed::operator==( const Fixed& other ) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

bool	Fixed::operator!=( const Fixed& other ) const {
	return this->_fixedPointValue != other._fixedPointValue;
}

Fixed	Fixed::operator-( const Fixed& other ) const {
	return Fixed( this->toFloat() - other.toFloat() );
}

Fixed	Fixed::operator+( const Fixed& other ) const {
	return Fixed( this->toFloat() + other.toFloat() );
}

Fixed	Fixed::operator*( const Fixed& other ) const {
	return Fixed( this->toFloat() * other.toFloat() );
}

Fixed	Fixed::operator/( const Fixed& other ) const {

	if ( other._fixedPointValue == 0 ) {
		std::cerr << "ERROR: Division by zero!\n";
		std::exit( 1 );
	}

	return Fixed( this->toFloat() / other.toFloat() );
}

Fixed&	Fixed::operator++( void ) {

	++_fixedPointValue;
	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed	temp = *this;
	_fixedPointValue++;
	return temp;
}

Fixed&	Fixed::operator--( void ) {

	--_fixedPointValue;
	return *this;
}

Fixed	Fixed::operator--( int ) {

	Fixed	temp = *this;
	_fixedPointValue--;
	return temp;
}

Fixed&	Fixed::min( Fixed& a, Fixed& b ) {
	return ( a < b ) ? a : b;
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ) {
	return ( a < b ) ? a : b;
}

Fixed&	Fixed::max( Fixed& a, Fixed& b ) {
	return ( a > b ) ? a : b;
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ) {
	return ( a > b ) ? a : b;
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed ) {

	out << fixed.toFloat();
	return out;
}
