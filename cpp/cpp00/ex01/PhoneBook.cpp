#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->idx = 0;
}

static int	check_str(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (str[i] > 126 || str[i] < 32)
			return -1;
	}
	return 0;
}

void    PhoneBook::add(void)
{
	Contact		ct;
	std::string str;

	while (ct.get_firstname().empty())
	{
		std::cout << "firstname : ";
		std::getline(std::cin, str);
		if(check_str(str))
			continue;
		ct.set_firstname(str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
	}
	while (ct.get_lastname().empty())
	{
		std::cout << "lastname : ";
		std::getline(std::cin, str);
		if (check_str(str))
			continue;
		ct.set_lastname(str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
	}
	while (ct.get_nickname().empty())
	{
		std::cout << "nickname : ";
		std::getline(std::cin, str);
		if (check_str(str))
			continue;
		ct.set_nickname(str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
	}
	while (ct.get_phonenumber().empty())
	{
		std::cout << "phonenumber : ";
		std::getline(std::cin, str);
		if (check_str(str))
			continue;
		ct.set_phonenumber(str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
	}
	while (ct.get_darkestsecret().empty())
	{
		std::cout << "darkestsecret : ";
		std::getline(std::cin, str);
		if (check_str(str))
			continue;
		ct.set_darkestsecret(str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
	}
	this->contacts[idx] = ct;
	std::cout << "contact added at " << ++this->idx << std::endl;
	if(this->idx == MAX_CONTACT)
		this->idx = 0;
}

static void print_pb(Contact *contacts)
{
	std::string	temp;

	std::cout << "     index| firstname|  lastname|  nickname" << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++)
	{
		std::cout << std::setw(10) << i + 1 << std::right << "|";
		temp = contacts[i].get_firstname().length() < 11 ?\
		contacts[i].get_firstname() : contacts[i].get_firstname().substr(0, 9) + ".";
		std::cout << std::setw(10) << temp << std::right << "|";
		temp = contacts[i].get_lastname().length() < 11 ?\
		contacts[i].get_lastname() : contacts[i].get_lastname().substr(0, 9) + ".";
		std::cout << std::setw(10) << temp << std::right << "|";
		temp = contacts[i].get_nickname().length() < 11 ?\
		contacts[i].get_nickname() : contacts[i].get_nickname().substr(0, 9) + ".";
		std::cout << std::setw(10) << temp << std::right << "\n";
	}
}

static void	print_ct(Contact contact)
{
	std::cout << "firstname : " << contact.get_firstname() << std::endl;
	std::cout << "lastname : " << contact.get_lastname() << std::endl;
	std::cout << "nickname : " << contact.get_nickname() << std::endl;
	std::cout << "phonenumber : " << contact.get_phonenumber() << std::endl;
	std::cout << "darkestsecret : " << contact.get_darkestsecret() << std::endl;
}

void    PhoneBook::search(void)
{
	std::string	user_index;

	print_pb(this->contacts);
	while(user_index.empty())
	{
		std::cout << "자세히 보려면 인덱스를 입력하세요." << std::endl;
		std::getline(std::cin, user_index);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (std::stoi(user_index) < 1 || std::stoi(user_index) > 8)
		{
			std::cout << "잘못된 인덱스" << std::endl;
			user_index = "";
			continue;
		}
		else if (this->contacts[std::stoi(user_index) - 1].get_firstname().empty())
		{
			std::cout << "해당 번호는 비어있습니다." << std::endl;
			user_index = "";
			continue;
		}
		else
		{
			print_ct(this->contacts[std::stoi(user_index) - 1]);
			break;
		}
	}
}

void    PhoneBook::exit(void)
{
	std::cout << "bye" << std::endl;
}