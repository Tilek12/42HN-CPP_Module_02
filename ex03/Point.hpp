/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:29:48 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 14:38:18 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

private:

	Fixed	x;
	Fixed	y;

public:

	Point( void );
	Point( float x, float y );
	Point( const Point& other );
	Point& operator=( const Point& other );
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

};

#endif
