/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:15:58 by dmaestro          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:46 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "iterator"
#include "string"
#include <algorithm>
#include <sstream>
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
std::string LongLongToString(long long date)
{
    int years;
    int days;
    int month;
    years = date / 10000;
    
    month = (date  - years*10000)  / 100  ;
    days  = date - years * 10000 - month * 100;

    std::ostringstream result;
    result << years << "-" << ((month < 10) ? "0" : "" )<< month << "-" <<  ((days < 10) ? "0" : "") << days;
    return(result.str());
}
BitcoinExchange::BitcoinExchange() : separator("")
{
    //std::cout << BitcoinExchange default constructor << std::endl;
}
BitcoinExchange::InvalidInput::InvalidInput(const char *message) : msg(message)
{
}
 void BitcoinExchange::setError(unsigned int line, Error type)  
 {
    this->ErrorCheck.insert(std::make_pair(line, type));
    
 }
 void dateValue(std::string line, long long first_date, BitcoinExchange& Data, unsigned int actualLine);
 static void headerParser(bool type, std::string line,  BitcoinExchange& nidia);
 bool BitcoinExchange::parseFile(const std::string & Data, long long initialValue)
{
     std::ifstream file;
    file.open(Data.c_str());
    if(!file)
    {
        this->setError(0, INVALID_DATA_BASE);
        return(false) ;
    }
    std::string actualLine;
    unsigned int i = 0;
    while(std::getline(file, actualLine))
    {
        if(!actualLine.empty())
        { 
            break; 
        }   
    }
    headerParser(false, actualLine, *this);
    try 
    {
        takeError(this->ErrorCheck.at(i));
    }
    catch(std::exception &e)
    {
        std::cerr << RED << e.what() << RESET <<  std::endl;
        return(false);
    }
    
    i++;
    while(std::getline(file, actualLine))
    {
        if(actualLine.empty())
        {  
            continue;
        }
        dateValue(actualLine, initialValue, *this, i);
        i++;
    }
    return(true);
    
}
long long dateToLongLongConverter(std::string& date,  BitcoinExchange& Data,unsigned int actuaLine, long long first_date );
void BitcoinExchange::setSeparator( std::string& ref) 
{
    this->separator = ref;
}
static void headerParser(bool type, std::string line,  BitcoinExchange& nidia)
{
    
    if(line.empty())
    {
         nidia.setError(0, INVALID_HEADER);
         return ;
    }
    line.erase(std::remove(line.begin(),line.end(), ' '), line.end());
    if((line.length() != 18 && type == true )|| (line.length() != 10 && type == false))
    {
        nidia.setError(0, INVALID_HEADER);
        return ;
    }
    std::string buff1 = line.substr(0,4);
    if(buff1 != "date")
    {
        nidia.setError(0, INVALID_HEADER);
    }
    std::string buff2;
    if(type == true)
    {
         buff2 = line.substr(5, 13);
        if(buff2 != "exchange_rate")
            {
                nidia.setError(0, INVALID_HEADER);
                return ;
            }
    }
    else
    {
         buff2 = line.substr(5, 5);
    }    
    std::string separator = line.substr(4, 1);
    nidia.setSeparator(separator);
    nidia.setError(0, SEXYSMOKINSTYLE);
}
float BitcoinExchange::getValueaprox(long long date)
{
    std::map<long long , float>::iterator first = this->base.begin();
     std::map<long long , float>::iterator second = this->base.begin();
     second ++;

        while(second != this->base.end())
            {
                if(second->first > date   && first->first <= date )
                    return(first->second);
                first++;
                second++;
            }

     return(second->second);
     
}
void BitcoinExchange::setValue(long long date, float value)
{
    this->base.insert(std::make_pair(date, value));
    
}
std::string &BitcoinExchange::getSeparator()
{
    return(this->separator);
}

void dateValue(std::string line, long long first_date, BitcoinExchange& Data, unsigned int actualLine)
{
    std::string buff;
    std::string buff2;
    std::string comprobator;
    std::string separator = Data.getSeparator();
    line.erase(std::remove(line.begin(),line.end(), ' '), line.end());
     std::stringstream tempfile(line);
    std::getline(tempfile, buff, *separator.c_str());
    if(buff.empty())
        Data.setError(actualLine, BAD_DATE);
     std::getline(tempfile, buff2);
    if(buff2.empty())
        Data.setError(actualLine, BAD_VALUE);
     std::getline(tempfile, comprobator);
    if(!comprobator.empty())
        Data.setError(actualLine, BAD_VALUE);
    for(size_t i = 0; i < buff.length(); i++)
    {
        if((i == 4  || i == 7) && buff[i] != '-')
            Data.setError(actualLine, BAD_DATE);
        else if((i != 4  && i != 7) && !std::isdigit(buff[i]))
            Data.setError(actualLine, BAD_DATE);            
    }
    Data.setValue(dateToLongLongConverter(buff, Data, actualLine, first_date), std::atof(buff2.c_str()));
        Data.setError(actualLine, SEXYSMOKINSTYLE);
        
    
}
bool validDay(unsigned int days , unsigned int month, unsigned int years)
{
    if(((month % 7) % 2 != 0 || month == 7) && days > 31 )
        return(false);
    else if((month % 7) % 2 == 0 && month != 7 && days > 30 )
        return (false);
    else if(month == 2 && ((years % 4 && years % 100 != 0) || (years % 100 == 0 &&  years %400 == 0)))
        return(true);
    return true;
}

long long dateToLongLongConverter(std::string& date,  BitcoinExchange& Data,unsigned int actuaLine, long long first_date )
{
    long long years;
    long long month;
    long long days;
    std::stringstream line(date);
    std::string buff;
    std::string separator = "-";
    int result = 0;
    
    std::getline(line, buff, *separator.c_str() );
    years = std::atol(buff.c_str());
     std::getline(line, buff, *separator.c_str());
    month = std::atol(buff.c_str());
    if(month > 12)
        Data.setError(actuaLine, BAD_DATE);
    std::getline(line, buff, *separator.c_str());
    days = std::atol(buff.c_str());
    if(!validDay(days, month, years))
        Data.setError(actuaLine, BAD_DATE);
    result = years*10000 + month*100 + days;
    if(result < (long long)first_date)
    {
        Data.setError(actuaLine, BAD_DATE);
    }
    return(result);
    
}
long long BitcoinExchange::getFirstValue()
{
    return(this->base.begin()->first);    
}
bool BitcoinExchange::parseDataBase(const std::string & Data)
{
    std::ifstream file;
    if(Data.substr(Data.length() - 4, 4).compare(".csv"))
    {
         this->setError(0, INVALID_DATA_BASE);
         return false;
    }
    file.open(Data.c_str());
    if(!file)
    {
        this->setError(0, INVALID_DATA_BASE);
        return false;
    }
    std::string actualLine;
    unsigned int i = 0;
    while(std::getline(file, actualLine))
    {
        if(!actualLine.empty())
        { 
            break; 
        }   
    }
    headerParser(true, actualLine, *this);
      try 
    {
        takeError(this->ErrorCheck.at(i));
    }
    catch(std::exception &e)
    {
        std::cerr << RED << e.what() << RESET <<  std::endl;
        return(false);
    }
    i++;
    while(std::getline(file, actualLine))
    {
        if(actualLine.empty())
        {
            continue;
        }
        dateValue(actualLine, -1, *this, i);
        i++;
    }
    std::map<long long, float>::iterator a;
    a = this->base.begin();
    for (size_t j = 0; a != this->base.end(); j++, a++)
        {
             Error whicht = this->ErrorCheck.at(j);
            try
            {
                this->takeError(whicht);
            }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << " in line " << j;
            switch (int i = whicht / 100)
            {
                case 1:
                    std::cerr << RESET << std::endl;
                    return false;
                    break;
                case 2:
                    std::cerr <<"=> "<< LongLongToString(a->first) << RESET << std::endl;
                    return(false);
                    break;
                case 3:
                    std::cerr <<"=> "<< a->second << RESET << std::endl;
                    return false;
                default:
                    std::cerr << RESET << std::endl;
                    break;
            }
            
        }

        }
    return(true);
}
/*int  Value_checker(std::string &value, BitcoinExchange& other, int actualLine, bool max)
{
    for(size_t i = 0; i != value.size(); i++)
    {
        if(!isdigit(value[i]) && value[i] != '.')
            other.ErrorCheck            
    }
}*/
void BitcoinExchange::printResult(BitcoinExchange &other)
{
    std::map<long long, float>::iterator a;
    std::map<unsigned int, Error>::iterator b;
    a = this->base.begin();
   
    unsigned int i = 1;
    while(a != this->base.end())
    {
        Error whicht = this->ErrorCheck.at(i);
        try
        {
            this->takeError( this->ErrorCheck.at(i));
             std::cout << LongLongToString(a->first)  << " => " << a->second << " = " <<  other.getValueaprox(a->first)*a->second <<  std::endl;
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
                    std::cerr <<"=> "<< LongLongToString(a->first) << RESET << std::endl;
                    break;
                case 3:
                    std::cerr <<"=> "<< a->second << RESET << std::endl;
                default:
                    std::cerr << RESET << std::endl;
                    break;
            }
            
        }
        i++;
        a++;
    }
}


