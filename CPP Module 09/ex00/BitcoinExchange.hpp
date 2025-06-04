#ifndef BITCOIN_EXCHANGE_HPP

# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <iostream>
# include <sstream>
# include <fstream>
# include <ctime>
# include <cerrno>
# include <cstring>
# include <cerrno>
# include <cctype>
# include <algorithm>

# define B "\033[1m"
# define I "\033[3m"
# define U "\033[4m"
# define R "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BLACK "\033[30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BMAGENTA "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"
# define BBLACK "\033[1;30m"
# define BU "\033[1;4m"
# define BR "\033[1;0m"

# ifndef DB_NAME
#  define DB_NAME "dataError.csv"
# endif

# ifndef SHOW_ERROR
#  define SHOW_ERROR true
# endif

typedef struct YMD_date_s
{
	int year;
	int month;
	int day;
	
	bool operator<(const struct YMD_date_s& other) const
	{
        if (year != other.year) return (year < other.year);
        if (month != other.month) return (month < other.month);
        return (day < other.day);
    }
}	YMD_date_t;

# define ERROR_OPEN_DB(file_name, reason) std::string(BRED) + "Error: " + R + "could not open database file: " + B + file_name + R + ": " + I + reason + R
# define ERROR_OPEN_INPUT(input_name, reason) std::string(BRED) + "Error: " + R + "could not open input file: " + B + input_name + R + ": " + I + reason + R

# define ERROR_LINE(file_type, file_name, line, line_nbr, reason) std::string(BRED) + "\tError " + file_type + " format: " + R + B + file_name + R + ": \"" + I + line + R + '"' + " (line " + stringOfType(line_nbr) + "): " + B + reason + R
# define ERROR_YMDDATE(file_type, file_name, date, line_nbr) ERROR_LINE(file_type, file_name, date, line_nbr, "has wrong Year-Month-Day date format")
# define ERROR_IMPOSSIBLE_YMDDATE(file_type, file_name, date, line_nbr) ERROR_LINE(file_type, file_name, date, line_nbr, "has impossible date")
# define ERROR_WRONG_YMDDATE(file_type, file_name, date, line_nbr) ERROR_LINE(file_type, file_name, date, line_nbr, "has incorrect date")
# define ERROR_WRONG_EXCHANGE_RATE(file_name, input, line_nbr) ERROR_LINE("database", file_name, input, line_nbr, "has incorrect exchange_rate value")
# define ERROR_WRONG_INPUT(input_file, input, line_nbr) ERROR_LINE("input", input_file, input, line_nbr, "has incorrect value")
# define ERROR_DB_ALREADY(file_name, date, line_nbr) ERROR_LINE("database", file_name, date, line_nbr, "date is a duplicate")
# define ERROR_PRINT(file_type, file_name, ascii_nbr, line_nbr) std::string(BRED) + "\tError " + file_type + ": " + R + B + file_name + R + ": line " + stringOfType(line_nbr) + ": contains unprintable characters (ascii: " + stringOfType(ascii_nbr) +  ") and can't be handled"

# define SHOW_INPUT(db_value, date, value) date + " | " + stringOfType<float>(value) + R + " x " + stringOfType<double>(db_value) + " = " + B + stringOfType<double>(value * db_value) + R
# define SHOW_DB_DATE(db_date) I + "\t(" + db_date + ")" + R 
# define SHOW_CLOSEST_INPUT(db_date, db_value, date, value) SHOW_INPUT(db_value, date, value) + SHOW_DB_DATE(db_date)

template <typename T>
T	typeOfString(const std::string &str, const std::string &type)
{
	std::istringstream iss(str);
    T	value;
    
    if (!(iss >> value))
		throw std::runtime_error(str + " can't be converted to " + type);


	char remaining;
	if (iss.get(remaining))
		throw std::runtime_error(str + " can't be converted to " + type);
    return (value);
}

template <typename T>
std::string	stringOfType(const T &value)
{
	std::ostringstream oss;
    oss << value;
    return (oss.str());
}

class BitcoinExchange
{
	private:
		std::map<YMD_date_t, double>	_db;
		std::string	_db_name;

		void		loadDatabase(const std::string &db_name) { readFile("database", db_name); };

		bool 		isLeapYear(int year);
		int			getDaysInMonth(int year, unsigned int month);
		
		YMD_date_t	YMDDate(int year, int month, int day);
		std::string formatedDate(YMD_date_t date);
		YMD_date_t	checkYMDDate(const std::string &file_type, const std::string &file_name, const std::string &date, size_t line_nbr);
		double		dbValue(const std::string &valueStr, const size_t line_nbr);
		float		inputValue(const std::string &input_name, const std::string &valueStr, const size_t line_nbr);
		bool		isDbHeader(const std::string &date, const std::string &valueStr);
		bool		isInputHeader(const std::string &date, const std::string &valueStr);
		
		void		splitLine(const std::string &file_type, const std::string &file_name, const std::string &line, char spliter, const size_t line_nbr, std::string &first, std::string &second);
		void		handleDbLine(const std::string &line, const size_t line_nbr);
		void		handleInputLine(const std::string &input_name, const std::string &line, const size_t line_nbr);

		void		readFile(const std::string &file_type, const std::string &file_name);

	public:
		BitcoinExchange(void): _db_name(DB_NAME) { loadDatabase(DB_NAME); }
		BitcoinExchange(const std::string &db_name): _db_name(db_name) { loadDatabase(db_name); }
		BitcoinExchange(const BitcoinExchange &to_copy): _db(to_copy._db) {}
		BitcoinExchange &operator=(const BitcoinExchange &to_copy)
		{
			if (this == &to_copy)
				return (*this);
			_db = to_copy._db;
			return (*this);
		}
		~BitcoinExchange(void) {}
		
		void	input(const std::string &input_name) { readFile("input", input_name); }
};

#endif