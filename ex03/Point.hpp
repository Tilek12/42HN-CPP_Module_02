/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:29:48 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 20:37:14 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/*----------------------*/
/*  Define Point class  */
/*----------------------*/
class	Point {

private:

	Fixed const	_x;
	Fixed const	_y;

public:

	Point( void );
	Point( const float x, const float y );
	Point( const Point& other );
	Point& operator=( const Point& other );
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

};

/*-------------*/
/*  Functions  */
/*-------------*/
bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
