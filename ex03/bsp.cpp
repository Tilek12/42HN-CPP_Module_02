/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:39:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 18:20:36 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	area( Point const a, Point const b, Point const c ) {

	return ( ( a.getX() * ( b.getY() - c.getY() ) ) +
			( b.getX() * ( c.getY() - a.getY() ) ) +
			( c.getX() * ( a.getY() - b.getY() ) ) ) / 2;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {

	Fixed	totalArea = area( a, b, c );
	Fixed	area1 = area( point, b, c );
	Fixed	area2 = area( a, point, c );
	Fixed	area3 = area( a, b, point );
	Fixed	newArea = area1 + area2 + area3;

	return ( totalArea == newArea ) && !( area1 == 0 || area2 == 0 || area3 == 0 );
}
