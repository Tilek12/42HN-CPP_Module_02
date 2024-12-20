/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:05:53 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 13:56:22 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

};

/*-------------*/
/*  Functions  */
/*-------------*/
std::ostream& operator<<( std::ostream& out, const Fixed& fixed );

#endif
