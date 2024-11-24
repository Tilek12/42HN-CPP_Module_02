/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:53:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 20:37:12 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

# define intMAX 2147483647
# define intMIN -2147483648

/*----------------------*/
/*  Define Fixed class  */
/*----------------------*/
class	Fixed {

private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:

	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );

	Fixed( const Fixed& other );

	Fixed& operator=( const Fixed& other );

	~Fixed( void );

	void	setRawBits( int const raw );
	int		getRawBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator<( const Fixed& other ) const;
	bool	operator>( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;

	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;

	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	static Fixed&		min( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static Fixed&		max( Fixed& a, Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );

};

/*-------------*/
/*  Functions  */
/*-------------*/
std::ostream& operator<<( std::ostream& out, const Fixed& fixed );

#endif
