#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void)
{
    std::string cmd;
	PhoneBook   pb;

    while(1)
    {
        std::cout << "<PHONE BOOK> ADD, SEARCH, EXIT" << std::endl;
		std::cin.clear();
		clearerr(stdin);
		std::getline(std::cin, cmd);
		if(cmd == "ADD")
			pb.add();
		else if(cmd == "SEARCH")
			pb.search();
		else if(cmd == "EXIT" || std::cin.eof())
		{
			pb.exit();
			break;
		}
    }
    return 0;
}

