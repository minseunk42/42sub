#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << DEBUG_MSG << std::endl;
}
void Harl::info( void )
{
    std::cout << INFO_MSG << std::endl;
}
void Harl::warning( void )
{
    std::cout << WARNING_MSG << std::endl;
}
void Harl::error( void )
{
    std::cout << ERROR_MSG << std::endl;
}

static int check_lv(std::string level)
{
    std::string arr[STATECNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < STATECNT && arr[i] != level)
        i++;
    return i;
}

Harl::Harl()
{
    fp[DEBUG] = &Harl::debug;
    fp[INFO] = &Harl::info;
    fp[WARNING] = &Harl::warning;
    fp[ERROR] = &Harl::error;
}

void Harl::complain( std::string level )
{
    Harl h;
    switch (check_lv(level))
    {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            (h.*fp[DEBUG])();
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            (h.*fp[INFO])();
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            (h.*fp[WARNING])();
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            (h.*fp[ERROR])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
