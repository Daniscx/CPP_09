/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:25:25 by dmaestro          #+#    #+#             */
/*   Updated: 2026/05/14 19:54:49 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
    RPN::RPN()
    {
        //std::cout << "default constructor called" << std::endl;
    }
    RPN::RPN(const RPN &other)
    {
        //std::cout << "assignament constructor called" << std::endl;        
    }
  RPN  RPN::operator=(const RPN &other)
    {
        //std::cout << "assignament copy  constructor called" << std::endl;    
        if(&other != this)
        {
            
            this->Numbers_stack = other.Numbers_stack;
            this->operation = other.operation;
        }
        return(*this);
    }
    RPN::~RPN()
    {
        //std::cout << "assignament constructor called" << std::endl;    
        
    }
    RPN::RPN(std::string& input)
    {
        
    }
    int resta(int a, int b)
    {
        return(a -b);
    }
    int suma(int a, int b)
    {
        return(a +b);
    }
    int multi(int a, int b)
    {
        return(a*b);
    }
    static void *funciton(int i)
    {
        switch (i)
        {
        case 42:
            return(&multi);
            break;
        case 43:
            return(&suma);
        case 45:
        return(&resta);
        default:
            break;
        }
    }
    int RPN::result(std::string& input)
    {
        int actual = 0;
        int i = 0;
        input.erase(std::remove(input.begin(),input.end(), ' '), input.end());
        
        while (input[i])
        {
            if(isdigit(input[i]))
                this->Numbers_stack.push(input[i] - '0');
            if()
            i++;
            
        }
        
        try 
        { 
            actual = this->Numbers_stack.pop()
        }
        catch(std::exception &e)
        {
            throw InvalidInputa("asdasdas");

        }
            
    }