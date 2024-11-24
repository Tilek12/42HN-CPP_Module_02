/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:06:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 18:14:51 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 ) {}

Point::Point( float x, float y ) : _x( x ), _y( y ) {}

Point::Point( const Point& other ) : _x( other._x ), _y( other._y ) {}

Point&	Point::operator=( const Point& other ) {

	std::cerr << "ERROR: Assignment operator is not allowed for Point since x and y are const.\n";
	return *this;
}

Point::~Point( void ) {}

Fixed	Point::getX( void ) const { return _x; }

Fixed	Point::getY( void ) const { return _y; }
