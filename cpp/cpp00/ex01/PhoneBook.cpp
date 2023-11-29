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

static bool set_elem(std::string prompt, std::string (Contact::*getter)(void) const \
, void (Contact::*setter)(const std::string &firstname), Contact *ct)
{
	std::string str;

	while ((ct->*getter)().empty())
	{
		std::cout << prompt;
		std::getline(std::cin, str);
		if(check_str(str))
			continue;
		(ct->*setter)(str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return 1;
		}
	}
	return 0;
}

void    PhoneBook::add(void)
{
	Contact		ct;

	if (set_elem("firstname : ", &Contact::get_firstname, &Contact::set_firstname,  &ct))return;
	if (set_elem("lastname : ", &Contact::get_lastname, &Contact::set_lastname, &ct))return;
	if (set_elem("nickname : ", &Contact::get_nickname, &Contact::set_nickname, &ct))return;
	if (set_elem("phonenumber : ", &Contact::get_phonenumber, &Contact::set_phonenumber, &ct))return;
	if (set_elem("darkestsecret : ", &Contact::get_darkestsecret, &Contact::set_darkestsecret, &ct))return;
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
	std::string	str;
	int			idx;

	print_pb(this->contacts);
	while(str.empty())
	{
		std::cout << "자세히 보려면 인덱스를 입력하세요." << std::endl;
		std::getline(std::cin, str);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		std::istringstream(str) >> idx;
		if (idx < 1 || idx > 8)
		{
			std::cout << "잘못된 인덱스" << std::endl;
			str = "";
			continue;
		}
		else if (this->contacts[idx - 1].get_firstname().empty())
		{
			std::cout << "해당 번호는 비어있습니다." << std::endl;
			str = "";
			continue;
		}
		else
		{
			print_ct(this->contacts[idx - 1]);
			break;
		}
	}
}

void    PhoneBook::exit(void)
{
	std::cout << "bye" << std::endl;
}