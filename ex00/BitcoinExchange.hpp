/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:34:11 by dmaestro          #+#    #+#             */
/*   Updated: 2026/04/30 18:12:55 by dmaestro         ###   ########.fr       */
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
    FILE_ERROR = 100,
    INVALID_INPUT_FILE,
    INVALID_DATA_BASE,
    DATE_FAIL = 200,
    BAD_DATE,
    NO_DATE,
    TOO_EARLY_DATE, 
    VALUE = 300,
    BAD_VALUE,
    NEGATIVE_VALUE,
    OVERFLOW,
    NO_VALUE,
};

class BitcoinExchange
{
    private:
    std::map<long long, float> base; 
    std::map<unsigned int, Error> ErrorCheck; 
    std::string separator;
      
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
    long long getFirstValue();
    void setValue(long long  date, float value);
    void setError(unsigned int line, Error type);
    void setSeparator(  std::string &ref);
    void takeError(Error type);
    bool parseFile(const std::string & input, long long initialValue);
    bool parseDataBase(const std::string & Data);
    void printResult(BitcoinExchange &other);
    float getValueaprox(long long date);
    
    std::string &getSeparator();
    
};