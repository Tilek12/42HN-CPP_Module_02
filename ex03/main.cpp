/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:21:23 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/24 20:37:13 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main( void ) {

	Point	a( 0, 0 ), b( 10, 0 ), c( 0, -10 );
	Point	inside( 1, -4 );
	Point	outside( 10, 10 );
	Point	onEdge( 5, -5 );

	std::cout << "Inside  : " << bsp( a, b, c, inside ) << std::endl;
	std::cout << "Outside : " << bsp( a, b, c, outside ) << std::endl;
	std::cout << "On Edge : " << bsp( a, b, c, onEdge ) << std::endl;

	return 0;
}
