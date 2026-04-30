/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:17:09 by dmaestro          #+#    #+#             */
/*   Updated: 2026/04/30 18:38:59 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int agrs, char **argv)
{
    BitcoinExchange Data;
    BitcoinExchange input;
    

    if(!Data.parseDataBase(argv[1]))
        exit(1);
   if(!input.parseFile(argv[2], Data.getFirstValue()))
        exit(1);
    input.printResult(Data);

    
    
}