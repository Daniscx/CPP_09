/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:15:58 by dmaestro          #+#    #+#             */
/*   Updated: 2026/04/27 00:33:48 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "iterator"

void  BitcoinExchange::takeError(Error type)
{
    switch (type)
    {
        case SEXYSMOKINSTYLE:
            return ;
            break;
        case BAD_DATE:
            throw BitcoinExchange::InvalidInput("ERROR::Bad data input");
            break;
        case BAD_VALUE:
            throw BitcoinExchange::InvalidInput("ERROR::Bad value input");
            break;
        case INVALID_DATA_BASE :
            throw BitcoinExchange::InvalidInput("ERROR::Invalid data_base file");
            break;
        case NO_DATE:
            throw BitcoinExchange::InvalidInput("ERROR::No date input");
            break;
        case NO_VALUE:
            throw BitcoinExchange::InvalidInput("ERROR::Not value input");
            break;
    default:
        break;
    };
};
BitcoinExchange::BitcoinExchange()
{
    //std::cout << BitcoinExchange default constructor << std::endl;
}
BitcoinExchange::InvalidInput::InvalidInput(const char *message) : msg(message)
{
}

void BitcoinExchange::parseFile(const std::string & input)
{
    
    
}
Error BitcoinExchange::parseDataBase(const std::string & Data)
{
    std::ifstream file;
    if(Data.substr(Data.length() - 4, 4).compare(".csv"))
        this->ErrorCheck.emplace(0, INVALID_DATA_BASE);
    file.open(Data);
    if(!file)
        this->ErrorCheck.emplace()

}
void BitcoinExchange::printResult()
{
    std::map<int, float>::iterator a;
    std::map<unsigned int, Error>::iterator b;
    a = this->base.begin();
    Error whicht = this->ErrorCheck.at(1);
    unsigned int i = 1;
    while(a != this->base.end())
    {
        try
        {
            this->takeError( this->ErrorCheck.at(1));
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << " in line " << i;
            switch (int i = whicht / 100)
            {
                case 1:
                    std::cerr << RESET << std::endl;
                    break;
                case 2:
                    std::cerr <<"=> "<< a->first << RESET << std::endl;
                    break;
                case 3:
                    std::cerr <<"=> "<< a->second << RESET << std::endl;
                default:
                    break;
            }
            
        }
        i++;
        a++;
        
    }

    
}


