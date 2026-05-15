/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:06:44 by dmaestro          #+#    #+#             */
/*   Updated: 2026/05/15 16:39:39 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include "iostream"
#include "algorithm"
#include "stack"

typedef  int(*funct)(int ,int);
  funct function(int i);
class RPN
{
    private:
    std::stack<int> Numbers_stack;
    public:
    RPN();
    RPN(const RPN &other);
    RPN operator=(const RPN &other);
    ~RPN();
    RPN(std::string& input);
    void result(std::string& input);
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