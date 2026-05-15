/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:25:25 by dmaestro          #+#    #+#             */
/*   Updated: 2026/05/15 16:47:07 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
    RPN::RPN()
    {
        //std::cout << "default constructor called" << std::endl;
    }
    RPN::RPN(const RPN &other)
    {
        (void)other;
        //std::cout << "assignament constructor called" << std::endl;        
    }
  RPN  RPN::operator=(const RPN &other)
    {
        //std::cout << "assignament copy  constructor called" << std::endl;    
        if(&other != this)
        {
            
            this->Numbers_stack = other.Numbers_stack;

        }
        return(*this);
    }
    RPN::~RPN()
    {
        //std::cout << "assignament constructor called" << std::endl;    
        
    }
    RPN::RPN(std::string& input)
    {
        (void)input;
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
    int division(int a, int b)
    {
        if(b == 0)
           throw std::out_of_range("NO 0 bicht");
        return(a/b);
    }
     funct function(int i)
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
        case 47:
            return(&division);
        default:
            break;
        }
        return(NULL);
    }
    
    void RPN::result(std::string& input)
    {
        int actual = 0;
        int second2 = 0;
        int i = 0;
        funct operation;
        input.erase(std::remove(input.begin(),input.end(), ' '), input.end());
        try
        {
            while (input[i])
            {
                if(isdigit(input[i]))
                {
                    this->Numbers_stack.push(input[i] - '0');
                    i++;
                    continue;
                }
            
            operation = function(input[i]);
            if(operation != NULL)
            {
                if(this->Numbers_stack.size() < 2)
                    throw(InvalidInputa("tete"));
                actual = this->Numbers_stack.top();
                this->Numbers_stack.pop();
                second2 = this->Numbers_stack.top();
                this->Numbers_stack.pop();
                this->Numbers_stack.push(operation(second2, actual));
            }
            i++;
            
        }
        }
        catch(const std::exception& e)
        {
            std::cerr <<"ERROR" << '\n';
            exit(1);
        }
        if(this->Numbers_stack.size() != 1)
          {
            std::cerr <<"ERROR" << '\n';
            exit(1);
        }
        std::cout << this->Numbers_stack.top() << std::endl;
        

    }