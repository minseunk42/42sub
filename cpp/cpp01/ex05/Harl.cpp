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
            (h.*fp[DEBUG])();
            break;
        case INFO:
            (h.*fp[INFO])();
            break;
        case WARNING:
            (h.*fp[WARNING])();
            break;
        case ERROR:
            (h.*fp[ERROR])();
            break;
        default:
            std::cout << "Wrong input" << std::endl;
    }
}
