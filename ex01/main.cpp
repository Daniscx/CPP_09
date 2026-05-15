/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:09:54 by dmaestro          #+#    #+#             */
/*   Updated: 2026/05/15 16:47:36 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool parse(std::string &input)
{
    funct tester;
    input.erase(std::remove(input.begin(),input.end(), ' '), input.end());
    for(size_t i = 0; i < input.length(); i++)
    {
    
        tester = function(input[i]);
        if(!isdigit(input[i]) && tester == NULL)
            return(false);
    }
    return(true);
}
int main(int args, char const *argv[])
{
    RPN calcu;
    if(args != 2)
    {
        std::cerr << "ERROR" << std::endl;
        return(1);
        
    }
 
        
    std::string input = argv[1];
       if(!parse(input))
       {
            std::cerr << "ERROR" << std::endl;
            return(1);
       }
        
    calcu.result(input) ;
    return 0;
}
