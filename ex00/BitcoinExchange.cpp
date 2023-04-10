/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:18:07 by mlarra            #+#    #+#             */
/*   Updated: 2023/04/04 20:19:46 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::fillDateInBtcStructure(std::string &str, BtcData &date)
{
	char sep1, sep2;
	std::stringstream stream(str);
	stream >> date.year >> sep1 >> date.month >> sep2 >> date.day;
}

void BitcoinExchange::readCsvFile(std::string fileName)
{
	std::ifstream work_file(fileName);
	std::string line;
	char delimiter = ',';
	getline(work_file, line);
	while (getline(work_file, line))
	{
		t_btcData btcData = {};
		std::stringstream stream(line);
		std::string date, price;
		getline(stream, date, delimiter);
		fillDateInBtcStructure(date, btcData);
		getline(stream, price, delimiter);
		btcData.value = std::stod(price);
		_exchangeSet.insert(btcData);
	}
	work_file.close();
}

void BitcoinExchange::checkAndCalculateInputFile(char *fileName)
{
	std::ifstream work_file(fileName);
	if (!work_file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::string firstLine;
	getline(work_file, firstLine);
	if (firstLine.compare("date | value") != 0)
	{
		std::cerr << "Error: first line doesn't match \"date | value\"" << std::endl;
		exit(1);
	}
	std::string line;
	while (getline(work_file, line))
	{
		t_btcData btcInput = {};
		std::stringstream stream(line);
		std::string date = "";
		std::string value = "";
		char separator;
		stream >> date >> separator >> value;
		if (date == "" || value == "" || separator != '|')
			std::cerr << "Error: bad input => " << date << std::endl;
		else
		{
			fillDateInBtcStructure(date, btcInput);
			if (isValidValue(value, btcInput) != true || isValidInputDate(btcInput) != true)
				std::cerr << "Error: bad input => " << date << std::endl; 
			else if (btcInput.value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (btcInput.value < 0 || btcInput.value > 1000)
				std::cerr << "Error: too large a number" << std::endl;
			else if (btcInput.value > 0 && btcInput.value < 1000) //for example: 2011-01-09 => 1 = 0.32
			{
				double rate;
				if ((rate = findRate(btcInput)) != -1) 
				{
					double res = btcInput.value * rate;
					std::cout << date  << " => " << btcInput.value
						<< " = " << res << std::endl;
				}
			}
		}	
	}
	work_file.close();
}

double BitcoinExchange::findRate(t_btcData &bData)
{
	std::set<t_btcData> :: iterator it = _exchangeSet.find(bData);
	while (it == _exchangeSet.end())
	{
		bData.day -= 1;
		if (bData.day == 0)
		{
			bData.month -= 1;
			if (bData.month == 0)
			{
				bData.month = 12;
				bData.day = 31;
				bData.year -= 1;
				if (bData.year < 2009)
				{	
					std::cerr << "Error: no valid date" << std::endl;
					return (-1);
				}
			}
			else if (bData.month == 2)
			{
				bool leapYear = bData.year % 4 == 0 && (bData.year % 100 != 0 || bData.year % 400 == 0);
				bData.day = leapYear ? 29 : 28;
			}
			else if (bData.month == 4 || bData.month == 6 || bData.month == 9 || bData.month == 11)
				bData.day = 30;
			else 
				bData.day = 31;
		}
		it = _exchangeSet.find(bData);
	}
	return it->value;
}

bool	BitcoinExchange::isValidInputDate(const t_btcData &bData)
{
	if(bData.year < 0 || bData.month < 1 || bData.month > 12 || bData.day < 1 || bData.day > 31)
			return false;
	// проверка на високосный год
	bool leapYear = bData.year % 4 == 0 && (bData.year % 100 != 0 || bData.year % 400 == 0);
	//месяцы. в которых по 30 дней
	bool littleDaysMonth =  bData.month == 4 || bData.month == 6 
		|| bData.month == 9 || bData.month == 11;
	if ((bData.month == 2 && (leapYear ? bData.day > 29 : bData.day > 28)) 
		|| (littleDaysMonth && bData.day > 30))
		return false;
	return true;

}

bool BitcoinExchange::isValidValue(const std::string& value, t_btcData &bData) {
	try
	{
		bData.value = std::stod(value);
	}
	catch (const std::invalid_argument& e)
	{
		return false;
	}
	return true;
}