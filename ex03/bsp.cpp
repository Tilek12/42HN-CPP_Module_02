/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:39:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 20:37:16 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*-------------------------------------*/
/*  Formula to get the absolute value  */
/*-------------------------------------*/
static Fixed	abs( Fixed const& value ) {
	return ( value < 0 ) ? (value * -1) : value;
}

/*---------------------------------------------*/
/*  Formula to calculate the area of triangle  */
/*---------------------------------------------*/
static Fixed	area( Point const a, Point const b, Point const c ) {

	Fixed	valueA = a.getX() * ( b.getY() - c.getY() );
	Fixed	valueB = b.getX() * ( c.getY() - a.getY() );
	Fixed	valueC = c.getX() * ( a.getY() - b.getY() );

	return abs( valueA + valueB + valueC ) / 2;
}

/*-----------------------*/
/*  Define bsp function  */
/*-----------------------*/
bool	bsp( Point const a, Point const b, Point const c, Point const point ) {

	Fixed	totalArea = area( a, b, c );
	Fixed	areaPBC = area( point, b, c );
	Fixed	areaAPC = area( a, point, c );
	Fixed	areaABP = area( a, b, point );
	Fixed	newArea = areaPBC + areaAPC + areaABP;

	bool	isInside = ( totalArea == newArea );
	bool	isOnEdge = ( areaPBC == 0 || areaAPC == 0 || areaABP == 0 );

	return isInside || isOnEdge;
}
