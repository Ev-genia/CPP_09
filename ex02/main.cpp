/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:50:35 by mlarra            #+#    #+#             */
/*   Updated: 2023/04/05 11:52:48 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: No input sequence provided." << std::endl;
		return (1);
	}
	std::vector<int>	vec;
	std::list<int>		lst;
	int					num;

	for (int i = 1; i < argc; i++) {
		try {
			if (std::strcmp(argv[i], "0") != 0)
			{
				num = std::atoi(argv[i]);
				if (num <= 0)
				{
					throw std::invalid_argument("Error");
				}
			}
			else
				num = 0;
			vec.push_back(num);
			lst.push_back(num);
			
		}
		catch (const std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
	}

	int count = 0;
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
		for (int k = 0; std::to_string(*it)[k] != '\0'; k++)
			count +=1;
		count +=1;
		if (count >= 15)
		{
			std::cout << "[...]";
			break; 
		}
	}
	std::cout << std::endl;

	int nVec = vec.size();
	int nLst = lst.size();

	std::clock_t start_vec = std::clock();
	sortVector(vec, 0, nVec - 1);
	std::clock_t end_vec = std::clock();
	double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

	std::clock_t start_lst = std::clock();
	sortList(lst, 0, nLst - 1);
	std::clock_t end_lst = std::clock();
	double elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC * 1000000;

	count = 0;
	std::cout << "After:  ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
		for (int k = 0; std::to_string(*it)[k] != '\0'; k++)
			count +=1;
		count +=1;
		if (count >= 15)
		{
			std::cout << "[...]";
			break; 
		}
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size();
	std::cout << " elements with vector merge-insert sort: " << elapsed_vec;
	std::cout << " us" << std::endl;

	std::cout << "Time to process a range of " << lst.size();
	std::cout << " elements with list merge-insert sort: " << elapsed_lst;
	std::cout << " us" << std::endl;
	return (0);
}
