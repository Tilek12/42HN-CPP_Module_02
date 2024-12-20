/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:32:15 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 13:49:38 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*----------------------*/
/*  Define Fixed class  */
/*----------------------*/
class Fixed {

private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:

	Fixed();
	Fixed( const Fixed& other );
	Fixed& operator=( const Fixed& other );
	~Fixed();

	void	setRawBits( int const raw );
	int		getRawBits( void ) const;

};

#endif
