/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:17:09 by dmaestro          #+#    #+#             */
/*   Updated: 2026/04/27 00:28:59 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int agrs, char **argv)
{
    BitcoinExchange pepe;

    pepe.parseDataBase(argv[1]);
    pepe.printResult();
    
    
}