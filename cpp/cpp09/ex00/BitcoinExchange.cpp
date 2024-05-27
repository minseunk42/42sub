#include "BitcoinExchange.hpp"

std::string getYesterday(std::string date)
{
    int endday[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y, m, d;
    char sep1, sep2;
    std::stringstream ss(date);
    ss >> y >> sep1 >> m >> sep2 >> d;
    if (ss.fail() || sep1 != '-' || sep2 != '-')
        throw std::exception();
    if (--d == 0)
    {
        m -= 1;
        d = endday[m];
    }
    if (m == 0)
    {
        y -= 1;
        m = 12;
        d = 31;
    }
    std::stringstream ss1;
    ss1 << y;
    ss1 << "-";
    if (1 <= m && m <= 9)
        ss1 << "0";
    ss1 << m;
    ss1 << "-";
    if (1 <= d && d <= 9)
        ss1 << "0";
    ss1 << d;
    return ss1.str();
}

BitcoinExchange::BitcoinExchange(char *datafile)
{
    std::ifstream fin(datafile, std::ios_base::in);
    if (!fin)
    {
        std::cout << "Error: could not open datafile." << std::endl;
        fin.close();
        throw std::exception();
    }
    std::string buf;
    std::string key;
    float val;
    while (std::getline(fin, buf))
    {
        std::stringstream ss;
        ss << buf.substr(buf.find(",") + 1);
        ss >> val;
        key = buf.substr(0, buf.find(","));
        data[key] = val;
    }
}

static bool isValDate(std::string date)
{
    int year, month, day;
    char sep1, sep2;
    std::stringstream ss(date);
    ss >> year >> sep1 >> month >> sep2 >> day;
    if (ss.fail() || sep1 != '-' || sep2 != '-')
        return false;
    std::string str = ss.str();
    if (str.size() > 10)
        return false;
    int i = -1;
    int cnt = 0;
    while (++i < 10 && str[i])
    {
        if (str[i] == '-')
            cnt++;
    }
    if (cnt > 2)
        return false;
    if (str[--i] > '9' || str[i] < '0')
        return false;
    if ((str[--i] > '9' || str[i] < '0') && str[i] != '-')
        return false;
    if (month < 1 || month > 12)
        return false;
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            // 윤년 계산
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            return false;
    }
    if (day < 1 || day > daysInMonth)
        return false;
    if (year > 2022 || year < 2009)
        return false;
    if (year == 2009 && month == 1 && day == 1)
        return false;
    return true;
}

static void printResult(std::string day, float amount, std::map<std::string, float> data)
{
    if (!isValDate(day))
    {
        std::cout << "Error: bad input => " << day << std::endl;
        return ;
    }
    if (amount <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    if (amount > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }
    std::string tday = day;
    std::map<std::string, float>::iterator it = data.find(tday);
    if (it == data.end())
    {
        while (it == data.end())
        {
            tday = getYesterday(tday);
            it = data.find(tday);
        }
    }
    std::cout << day << " => " << it->second * amount << std::endl;
}

void BitcoinExchange::exchange(char *filename)
{
    std::ifstream fin(filename, std::ios_base::in);
    if (!fin)
    {
        std::cout << "Error: could not open file." << std::endl;
        fin.close();
        return;
    }
    std::string buf;
    std::string date;
    char sep;
    float amount;
    while (std::getline(fin, buf))
    {
        std::stringstream ss(buf);
        ss >> date >> sep >> amount;
        if (date == "date")
            continue;
        printResult(date, amount, data);
    }
}