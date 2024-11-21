/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:32:15 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/21 12:04:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

private:

	int					_value;
	static const int	_bits = 8;

public:

	Fixed();
	Fixed( const Fixed& other );
	Fixed& operator=( const Fixed& other );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

#endif
