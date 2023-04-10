/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:59:29 by mlarra            #+#    #+#             */
/*   Updated: 2023/04/04 22:30:35 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN {
private:
	std::stack<int>	_nbrStack;
	void	clearStack();
public:
	RPN();
	RPN&	operator=(const RPN &);
	RPN(const RPN &);
	~RPN();
	int	hundlerStr(char *);
};

#endif