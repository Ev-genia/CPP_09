/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:05:30 by mlarra            #+#    #+#             */
/*   Updated: 2023/04/04 22:29:44 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN::clearStack()
{
	while (_nbrStack.size() > 0)
		_nbrStack.pop();
}

RPN::RPN()
{
	if (_nbrStack.size())
		clearStack();
}

RPN&	RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		_nbrStack = rhs._nbrStack;
	}
	return (*this);
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{
	if (_nbrStack.size() > 0)
		clearStack();
}

int	RPN::hundlerStr(char *str)
{
	std::istringstream	iss(str);
	std::string			token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_nbrStack.size() < 2)
			{
				std::cout << "" << std::endl;
				exit (1);
			}
			int	n1 = _nbrStack.top();
			_nbrStack.pop();
			int	n2 = _nbrStack.top();
			_nbrStack.pop();
			int	rez;
			if (token == "+")
				rez = n2 + n1;
			else if (token == "-")
				rez = n2 - n1;
			else if (token == "*")
				rez = n2 * n1;
			else if (token == "/")
			{
				if (n1 == 0)
				{
					std::cout << "Error: division by zero" << std::endl;
					return (1);
				}
				rez = n2 / n1;
			}
			_nbrStack.push(rez);
		}
		else
		{
			if (token[0] < 48 || token[0] > 57)
			{
				std::cout << "Error" << std::endl;
				exit (1);
			}
			int	num = std::atoi(token.c_str());
			_nbrStack.push(num);
		}

	}
	if (_nbrStack.size() != 1)
	{
		std::cout << "Error: invalid input" << std::endl;
		exit (1);
	}
	return (_nbrStack.top());
}
