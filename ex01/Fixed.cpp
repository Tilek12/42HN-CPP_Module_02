/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:20:43 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 14:06:29 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*---------------------------------------------*/
/*  Fixed Class constructor with no parameter  */
/*---------------------------------------------*/
Fixed::Fixed( void ) : _fixedPointValue( 0 ) {

	std::cout << "Default constuctor called\n";

}

/*----------------------------------------------*/
/*  Fixed Class constructor with int parameter  */
/*----------------------------------------------*/
Fixed::Fixed( const int value ) {

	std::cout << "Int constructor called\n";

	if ( value > ( intMAX >> _fractionalBits ) ||
		value < ( intMIN >> _fractionalBits ) ) {
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


	std::cout << "Float constructor called\n";

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
Fixed::Fixed( const Fixed& other ) {

	std::cout << "Copy constructor called\n";
	*this = other;

}

/*----------------------------------------*/
/*  Fixed Class copy assignment operator  */
/*----------------------------------------*/
Fixed& Fixed::operator=( const Fixed& other ) {

	std::cout << "Copy assignment operator called\n";

	if ( this != &other ) {
		_fixedPointValue = other._fixedPointValue;
	}

	return *this;

}

/*--------------------------*/
/*  Fixed Class destructor  */
/*--------------------------*/
Fixed::~Fixed( void ) {

	std::cout << "Desctructor called\n";

}

/*------------------------------*/
/*  Define setRawBits function  */
/*------------------------------*/
void	Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called\n";
	_fixedPointValue = raw;

}

/*------------------------------*/
/*  Define getRawBits function  */
/*------------------------------*/
int	Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called\n";
	return _fixedPointValue;

}

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

/*---------------------------------------*/
/*  Overload the insertion («) operator  */
/*---------------------------------------*/
std::ostream& operator<<( std::ostream& out, const Fixed& fixed ) {

	out << fixed.toFloat();
	return out;

}
