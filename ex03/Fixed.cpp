/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:34:25 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 14:15:03 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*---------------------------------------------*/
/*  Fixed Class constructor with no parameter  */
/*---------------------------------------------*/
Fixed::Fixed( void ) : _fixedPointValue( 0 ) {}

/*----------------------------------------------*/
/*  Fixed Class constructor with int parameter  */
/*----------------------------------------------*/
Fixed::Fixed( const int value ) {

	if ( value > ( intMAX >> _fractionalBits )
		|| value < ( intMIN >> _fractionalBits ) ) {
		std::cerr << "ERROR: Int value overflow detected!\n";
		_fixedPointValue = 0;
		std::exit( 1 );
	} else {
		_fixedPointValue = value << _fractionalBits;
	}
}

/*------------------------------------------------*/
/*  Fixed Class constructor with float parameter  */
/*------------------------------------------------*/
Fixed::Fixed( const float value ) {

	float newValue = value * ( 1 << _fractionalBits );

	if ( newValue > intMAX || newValue < intMIN ) {
		std::cerr << "ERROR: Float value overflow detected!\n";
		_fixedPointValue = 0;
		std::exit( 1 );
	} else {
		_fixedPointValue = static_cast<int>( roundf( newValue ) );
	}
}

/*--------------------------------*/
/*  Fixed Class copy constructor  */
/*--------------------------------*/
Fixed::Fixed( const Fixed& other ) : _fixedPointValue( other._fixedPointValue ) {}

/*----------------------------------------*/
/*  Fixed Class copy assignment operator  */
/*----------------------------------------*/
Fixed&	Fixed::operator=( const Fixed& other ) {

	if ( this != &other ) {
		this->_fixedPointValue = other._fixedPointValue;
	}

	return *this;
}

/*--------------------------*/
/*  Fixed Class destructor  */
/*--------------------------*/
Fixed::~Fixed( void ) {}

/*------------------------------*/
/*  Define setRawBits function  */
/*------------------------------*/
void	Fixed::setRawBits( int const raw ) { _fixedPointValue = raw; }

/*------------------------------*/
/*  Define getRawBits function  */
/*------------------------------*/
int		Fixed::getRawBits( void ) const { return _fixedPointValue; }

/*---------------------------*/
/*  Define toFloat function  */
/*---------------------------*/
float	Fixed::toFloat( void ) const {
	return static_cast<float>( _fixedPointValue ) / ( 1 << _fractionalBits );
}

/*-------------------------*/
/*  Define toInt function  */
/*-------------------------*/
int	Fixed::toInt( void ) const {
	return _fixedPointValue >> _fractionalBits;
}

/*-----------------------------*/
/*  Overload the (<) operator  */
/*-----------------------------*/
bool	Fixed::operator<( const Fixed& other ) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

/*-----------------------------*/
/*  Overload the (>) operator  */
/*-----------------------------*/
bool	Fixed::operator>( const Fixed& other ) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

/*------------------------------*/
/*  Overload the (<=) operator  */
/*------------------------------*/
bool	Fixed::operator<=( const Fixed& other ) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

/*------------------------------*/
/*  Overload the (>=) operator  */
/*------------------------------*/
bool	Fixed::operator>=( const Fixed& other ) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

/*------------------------------*/
/*  Overload the (==) operator  */
/*------------------------------*/
bool	Fixed::operator==( const Fixed& other ) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

/*------------------------------*/
/*  Overload the (!=) operator  */
/*------------------------------*/
bool	Fixed::operator!=( const Fixed& other ) const {
	return this->_fixedPointValue != other._fixedPointValue;
}

/*-----------------------------*/
/*  Overload the (-) operator  */
/*-----------------------------*/
Fixed	Fixed::operator-( const Fixed& other ) const {
	return Fixed( this->toFloat() - other.toFloat() );
}

/*-----------------------------*/
/*  Overload the (+) operator  */
/*-----------------------------*/
Fixed	Fixed::operator+( const Fixed& other ) const {
	return Fixed( this->toFloat() + other.toFloat() );
}

/*-----------------------------*/
/*  Overload the (*) operator  */
/*-----------------------------*/
Fixed	Fixed::operator*( const Fixed& other ) const {
	return Fixed( this->toFloat() * other.toFloat() );
}

/*-----------------------------*/
/*  Overload the (/) operator  */
/*-----------------------------*/
Fixed	Fixed::operator/( const Fixed& other ) const {

	if ( other._fixedPointValue == 0 ) {
		std::cerr << "ERROR: Division by zero!\n";
		std::exit( 1 );
	}

	return Fixed( this->toFloat() / other.toFloat() );
}

/*--------------------------------------------*/
/*  Overload the pre-increment (++) operator  */
/*--------------------------------------------*/
Fixed&	Fixed::operator++( void ) {

	++_fixedPointValue;
	return *this;
}

/*---------------------------------------------*/
/*  Overload the post-increment (++) operator  */
/*---------------------------------------------*/
Fixed	Fixed::operator++( int ) {

	Fixed	temp = *this;
	_fixedPointValue++;
	return temp;
}

/*--------------------------------------------*/
/*  Overload the pre-decrement (--) operator  */
/*--------------------------------------------*/
Fixed&	Fixed::operator--( void ) {

	--_fixedPointValue;
	return *this;
}

/*---------------------------------------------*/
/*  Overload the post-decrement (--) operator  */
/*---------------------------------------------*/
Fixed	Fixed::operator--( int ) {

	Fixed	temp = *this;
	_fixedPointValue--;
	return temp;
}

/*------------------------------------------------*/
/*  Define min function with non-const parameters */
/*------------------------------------------------*/
Fixed&	Fixed::min( Fixed& a, Fixed& b ) {
	return ( a < b ) ? a : b;
}

/*---------------------------------------------*/
/*  Define min function with const parameters  */
/*---------------------------------------------*/
const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ) {
	return ( a < b ) ? a : b;
}

/*------------------------------------------------*/
/*  Define max function with non-const parameters */
/*------------------------------------------------*/
Fixed&	Fixed::max( Fixed& a, Fixed& b ) {
	return ( a > b ) ? a : b;
}

/*---------------------------------------------*/
/*  Define max function with const parameters  */
/*---------------------------------------------*/
const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ) {
	return ( a > b ) ? a : b;
}

/*---------------------------------------*/
/*  Overload the insertion («) operator  */
/*---------------------------------------*/
std::ostream& operator<<( std::ostream& out, const Fixed& fixed ) {

	out << fixed.toFloat();
	return out;
}
