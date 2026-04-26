/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:34:11 by dmaestro          #+#    #+#             */
/*   Updated: 2026/04/27 00:26:48 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "stdlib.h"
#include "exception"
#include "map"
#include "list"
#include "fstream"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

enum Error{
 
    SEXYSMOKINSTYLE,
    UNKNOW_ERROR,
    INVALID_HEADER,
    FILE_error = 100,
    INVALID_INPUT_FILE,
    INVALID_DATA_BASE,
    DATE_FAIL = 200,
    BAD_DATE,
    NO_DATE,
    TOO_EARLY_DATE, 
    VALUE = 300,
    BAD_VALUE,
    OVERFLOW,
    NO_VALUE,
};

class BitcoinExchange
{
    private:
    std::map<int, float> base; 
    std::map<unsigned int, Error> ErrorCheck; 
      
    public:
    class InvalidInput : public std::exception
    {
        private:
        const char *msg;
        public:    
        InvalidInput(const char *message);    
        const char *what() const throw(){
            return msg;
        };
    };
    
    BitcoinExchange();
    void takeError(Error type);
    void parseFile(const std::string & input);
    void parseDataBase(const std::string & Data);
    void printResult();
    
};