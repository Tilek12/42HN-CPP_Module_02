/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:29:48 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 18:18:44 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

private:

	Fixed	_x;
	Fixed	_y;

public:

	Point( void );
	Point( float x, float y );
	Point( const Point& other );
	Point& operator=( const Point& other );
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
