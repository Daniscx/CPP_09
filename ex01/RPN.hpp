/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:06:44 by dmaestro          #+#    #+#             */
/*   Updated: 2026/05/14 19:45:16 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include "iostream"
#include "algorithm"
#include "stack"

class RPN
{
    private:
    std::stack<int> Numbers_stack;
    std::stack<int(*)(int, int)> operation; 
    public:
    RPN();
    RPN(const RPN &other);
    RPN operator=(const RPN &other);
    ~RPN();
    RPN(std::string& input);
    int result(std::string& input);
    class InvalidInputa: public std::exception
    {
        private:const char * message;
        public:
        InvalidInputa(const char *c){
            this->message = c;
        };
        const char *what() const throw(){
            return(this->message);
        };
    };
    
};
#endif