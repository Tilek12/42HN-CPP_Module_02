/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:06:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 20:37:15 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*---------------------------------------------*/
/*  Point Class constructor with no parameter  */
/*---------------------------------------------*/
Point::Point( void ) : _x( 0 ), _y( 0 ) {}

/*-------------------------------------------------*/
/*  Point Class constructor with float parameters  */
/*-------------------------------------------------*/
Point::Point( const float x, const float y ) : _x( x ), _y( y ) {}

/*--------------------------------*/
/*  Point Class copy constructor  */
/*--------------------------------*/
Point::Point( const Point& other ) : _x( other._x ), _y( other._y ) {}

/*----------------------------------------*/
/*  Point Class copy assignment operator  */
/*----------------------------------------*/
Point&	Point::operator=( const Point& other ) {

	( void )other;
	std::cerr << "ERROR: Assignment operator is not allowed for Point since x and y are const.\n";
	return *this;
}

/*--------------------------*/
/*  Point Class destructor  */
/*--------------------------*/
Point::~Point( void ) {}

/*------------------------*/
/*  Define getX function  */
/*------------------------*/
Fixed	Point::getX( void ) const { return _x; }

/*------------------------*/
/*  Define getY function  */
/*------------------------*/
Fixed	Point::getY( void ) const { return _y; }
