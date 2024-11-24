/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:44:02 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 13:46:07 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*---------------------------*/
/*  Fixed Class constructor  */
/*---------------------------*/
Fixed::Fixed( void ) : _fixedPointValue( 0 ) {

	std::cout << "Default constructor called\n";

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
Fixed&	Fixed::operator=( const Fixed& other ) {

	std::cout << "Copy assignment operator called\n";

	if ( this != &other ) {
		this->_fixedPointValue = other.getRawBits();
	}

	return *this;

}

/*--------------------------*/
/*  Fixed Class destructor  */
/*--------------------------*/
Fixed::~Fixed( void ) {

	std::cout << "Destcructor called\n";

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
