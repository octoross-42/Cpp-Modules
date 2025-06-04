#include "BitcoinExchange.hpp"

bool	BitcoinExchange::isInputHeader(const std::string &date, const std::string &valueStr)
{
	return ((date == "date") && (valueStr == "value"));
}

bool	BitcoinExchange::isDbHeader(const std::string &date, const std::string &valueStr)
{
	return ((date == "date") && (valueStr == "exchange_rate"));
}

void	BitcoinExchange::splitLine(const std::string &file_type, const std::string &file_name, const std::string &line, char spliter, const size_t line_nbr, std::string &first, std::string &second)
{
	(void)file_name;
	size_t	i = 0;
	size_t	start = 0;
	while (line[start] == ' ')
		start ++;
	i = start;
	while ((i < line.length()) && (line[i] != spliter) && (line[i] != ' '))
		i ++;
	if ((i == line.length()) || (start == i))
	{
		if (start == i)
			throw std::runtime_error(ERROR_LINE(file_type, file_name, line, line_nbr, "no date provided"));
		else
			throw std::runtime_error(ERROR_LINE(file_type, file_name, line, line_nbr, "only date supplied"));
	}

	first = line.substr(start, i - start);
	if (line[i] != spliter)
	{
		i ++;
		while (line[i] == ' ')
			i ++;
		if (line[i] != spliter)
			throw std::runtime_error(ERROR_LINE(file_type, file_name, line, line_nbr, "no " + spliter + "separator detected after first word"));
	}
	i ++;
	while (line[i] == ' ')
		i ++;
	start = i;
	while ((i < line.length()) && (line[i] != ' '))
		i ++;
	
	if (i == start)
	{
		if (file_type == file_type)
			throw std::runtime_error(ERROR_LINE(file_type, file_name, line, line_nbr, "no exchange_rate provided"));
		else
			throw std::runtime_error(ERROR_LINE(file_type, file_name, line, line_nbr, "no value provided"));
	}
	second = line.substr(start, i - start);

	if (line[i] == ' ')
	{
		i ++;
		while ((i < line.length()) && (line[i] == ' '))
			i ++;
		if (i != line.length())	
			throw std::runtime_error(ERROR_LINE(file_type, file_name, line, line_nbr, "too many values provided"));
	}
}

double	BitcoinExchange::dbValue(const std::string &valueStr, const size_t line_nbr)
{
	try
	{
		float	input = typeOfString<double>(valueStr, "double");
		return (input);
	}
	catch (std::runtime_error &e)
	{
		throw std::runtime_error(ERROR_WRONG_EXCHANGE_RATE(_db_name, valueStr, line_nbr));
	}
}

float	BitcoinExchange::inputValue(const std::string &input_name, const std::string &valueStr, const size_t line_nbr)
{
	(void)input_name;
	
	try
	{
		float input = typeOfString<float>(valueStr, "float");
		
		if ((input < 0) || (input > 1000))
			throw std::runtime_error(ERROR_WRONG_INPUT(input_name, valueStr, line_nbr));
		return (input);
	}
	catch (std::exception &e)
	{
		throw std::runtime_error(ERROR_WRONG_INPUT(input_name, valueStr, line_nbr));
	}

}

bool BitcoinExchange::isLeapYear(int year) {
    return (!(year % 4) && ((year % 100) || !(year % 400)));
}

int	BitcoinExchange::getDaysInMonth(int year, unsigned int month)
{
    if (month == 2) return (isLeapYear(year) ? 29 : 28);
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) return (30);
    return (31);
}

YMD_date_t	BitcoinExchange::YMDDate(int year, int month, int day)
{
	YMD_date_t date;
	date.year = year;
	date.month = month;
	date.day = day;
	return (date);
}

std::string BitcoinExchange::formatedDate(YMD_date_t date)
{
	std::string dateString = stringOfType<int>(date.year) + "-";
	if (date.month < 10)
		dateString += "0";
	dateString += stringOfType<int>(date.month) + "-";
	if (date.day < 10)
		dateString += "0";
	dateString += stringOfType<int>(date.day);
	return (dateString);
}

YMD_date_t	BitcoinExchange::checkYMDDate(const std::string &file_type, const std::string &file_name, const std::string &date, const size_t line_nbr)
{
	(void)file_name;
	size_t i = 0;
	while ((i < date.length()) && (date[i] != '-'))
		i ++;

	int year;
	try
	{
		year = typeOfString<int>(date.substr(0, i), "int");
	}
	catch (std::exception &e)
	{
		throw std::runtime_error(ERROR_WRONG_YMDDATE(file_type, file_name, date, line_nbr));
	}

	if (i == date.length())
		throw std::runtime_error(ERROR_YMDDATE(file_type, file_name, date, line_nbr));

	size_t start = ++i;
	while ((i < date.length()) && (date[i] != '-'))
		i ++;

	if (i == date.length())
		throw std::runtime_error(ERROR_YMDDATE(file_type, file_name, date, line_nbr));
	
	int	month;
	try
	{
		month = typeOfString<int>(date.substr(start, i - start), "int");
	}
	catch (std::exception &e)
	{
		throw std::runtime_error(ERROR_WRONG_YMDDATE(file_type, file_name, date, line_nbr));
	}
	
	if ((month < 1) || (month > 12))
		throw std::runtime_error(ERROR_IMPOSSIBLE_YMDDATE(file_type, file_name, date, line_nbr));

	int day;
	try
	{
		day = typeOfString<int>(date.substr(++ i), "int");
	}
	catch (std::exception &e)
	{
		throw std::runtime_error(ERROR_WRONG_YMDDATE(file_type, file_name, date, line_nbr));
	}

	int max_day = getDaysInMonth(year, month);

	if ((day < 1) || (day > max_day))
		throw std::runtime_error(ERROR_IMPOSSIBLE_YMDDATE(file_type, file_name, date, line_nbr));
	return (YMDDate(year, month, day));

}

void	BitcoinExchange::handleDbLine(const std::string &line, const size_t line_nbr)
{
	std::string date;
	std::string valueStr;
	YMD_date_t YMDDate;

	splitLine("database", _db_name, line, ',', line_nbr, date, valueStr);
	if ((line_nbr == 1) && isDbHeader(date, valueStr))
		return ;
	YMDDate = checkYMDDate("database", _db_name, date, line_nbr);
	double value = dbValue(valueStr, line_nbr);
	if (_db.find(YMDDate) != _db.end())
		throw std::runtime_error(ERROR_DB_ALREADY(_db_name, formatedDate(YMDDate), line_nbr));
	_db[YMDDate] = value;
}


void	BitcoinExchange::handleInputLine(const std::string &input_name, const std::string &line, const size_t line_nbr)
{
	std::string date;
	std::string valueStr;
	YMD_date_t YMDDate;

	splitLine("input", input_name, line, '|', line_nbr, date, valueStr);
	if ((line_nbr == 1) && isInputHeader(date, valueStr))
		return ;
	YMDDate = checkYMDDate("input", input_name, date, line_nbr);
	float value = inputValue(input_name, valueStr, line_nbr);
	if (_db.size() == 0)
	{
		std::cout << "\t" << BGREEN << formatedDate(YMDDate) << " | " << value << R \
				<< ": database is " << B << "empty" << R << std::endl;
		return ;
	}
	std::map<YMD_date_t, double>::iterator it = _db.find(YMDDate);
	if (it != _db.end())
	{
		std::cout << "\t" << BGREEN << SHOW_INPUT(it->second, formatedDate(YMDDate), value) << std::endl;
		return ;
	}
	if (YMDDate < _db.begin()->first)
	{
		std::cout << "\t" << BYELLOW << "Warning: " << R \
			<< I << "date provided is before first database input: " << R \
			<< B << SHOW_CLOSEST_INPUT(formatedDate(_db.begin()->first), _db.begin()->second, formatedDate(YMDDate), value) << std::endl;
		return ;
	}

	it = _db.begin();
	it ++;
	while (it != _db.end())
	{
		if (YMDDate < it->first)
		{
			it --;
			std::cout << "\t" << BGREEN << SHOW_CLOSEST_INPUT(formatedDate(it->first), it->second, formatedDate(YMDDate), value) << std::endl;
			return ;
		}
		it ++;
	}
	it --;
	std::cout << "\t" << BGREEN << SHOW_CLOSEST_INPUT(formatedDate(it->first), it->second, formatedDate(YMDDate), value) << std::endl;
}

std::string	repeat_string(const std::string &str, unsigned int n)
{
	if (n == 0)
		return ("");
	std::string s = "";
	s.reserve(str.length() * n);
	unsigned int i = 0;
	while (i < n)
	{
		s += str;
		i ++;
	}
	return (s);
}


void	BitcoinExchange::readFile(const std::string &file_type, const std::string &file_name)
{
	std::ifstream file(file_name.c_str());
	
	if (!file.is_open())
	{
		if (file_type == "database")
			throw std::runtime_error(ERROR_OPEN_DB(file_name, strerror(errno)));
		else
			std::cerr << ERROR_OPEN_INPUT(file_name, strerror(errno)) << std::endl;

		return ;
	}

	if (file_type == "database")
		std::cout << "╔══ Loading " << BBLUE << "database" << R << " ... " << repeat_string("═", 92) << "╗" << R << std::endl;
	else
		std::cout << std::endl << "╔══ " << BCYAN << file_name << R << " " + repeat_string("═", 112 - file_name.length()) + "╗" << std::endl;
	
	std::string	line;
	size_t	line_nbr = 0;
	while (std::getline(file, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); // fichier windows -> \r\n donc on enlève le \r pour comptabilité
		
		line_nbr ++;
		size_t i = 0;
		int start = -1;
		while (i < line.length())
		{
			if ((start == -1) && (line[i] != ' '))
				start = i;
			if (!std::isprint(static_cast<unsigned char>(line[i])))
			{
				if (file_type == "database")
					std::cerr << ERROR_PRINT("database", _db_name, (int)line[i], line_nbr) << std::endl;
				else
					std::cerr << ERROR_PRINT("input", file_name, (int)line[i], line_nbr) << std::endl;
				break;
			}
			i ++;
		}
		if (start > 0)
			line = line.substr(start);
		if (line.empty())
			continue;
		if ((i < line.length()) && !std::isprint(static_cast<unsigned char>(line[i])))
			continue;

		try
		{
			if (file_type == "database")
				handleDbLine(line, line_nbr);
			else
				handleInputLine(file_name, line, line_nbr);
		}
		catch (std::exception &e)
		{
			if (SHOW_ERROR)
				std::cerr << e.what() << std::endl;
		}

	}
	file.close();
	if (file_type == "database")
		std::cout << "╚══ ⤷ " << BBLUE << "database" << R << " loaded !" << repeat_string("═", 94) << "╝" << std::endl;

	else
		std::cout << "╚══ " << BCYAN << file_name << R << " over🌟 " + repeat_string("═", 105 - file_name.length()) + "╝" << std::endl;
}