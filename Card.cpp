#include <iostream>
#include <string>

//using Name = std::string;

struct Date_Of_Birth
{
	int year;
	int month;
	int day;
	Date_Of_Birth() = default;
	explicit Date_Of_Birth(const int year_, const int month_, const int day_) :
		year(year_), month(month_), day(day_) {};
	~Date_Of_Birth() = default;
};

class Passport
{
private:
	std::string first_name;
	std::string last_name;
	std::string address;
	Date_Of_Birth date;
public:
	Passport() = default;
	explicit Passport(const std::string first_name_, const std::string last_name_, const std::string address_,
		const int year_birth_, const int month_birth_, const int day_birth_) :
		first_name(first_name_), last_name(last_name_), address(address_),
		date(year_birth_, month_birth_, day_birth_){};
	~Passport() = default;
	std::string get_first_name() const
	{
		return first_name;
	}
	std::string get_last_name() const
	{
		return last_name;
	}
	std::string get_address() const
	{
		return address;
	}
	Date_Of_Birth get_date_of_birth() const
	{
		return date;
	}
};

enum Types_Of_Bank_Card
{
	credit, salary, individual
};

struct Date_Of_Finish_Card
{
	int year;
	int month;
	int day;
	Date_Of_Finish_Card() = default;
	explicit Date_Of_Finish_Card(const int year_, const int month_, const int day_) :
		year(year_), month(month_), day(day_) {};
	~Date_Of_Finish_Card() = default;
};

class Bank_Card
{
private:
	Date_Of_Finish_Card date;
	Types_Of_Bank_Card type;
	int money;
public:
	Bank_Card() = default;
	explicit Bank_Card(const int year_finish_, const int month_finish_, const int day_finish_, const Types_Of_Bank_Card type_):
		date(year_finish_, month_finish_, day_finish_){}
	~Bank_Card() = default;
	Date_Of_Finish_Card get_date_finish() const
	{
		return date;
	}
	Types_Of_Bank_Card get_type_card() const
	{
		return type;
	}
	int get_money() const
	{
		return money;
	}
};

class Card
{
private:
	int card_id;
	Bank_Card* bank_card;
	Passport* passport;
public:
	Card() = default;
	explicit Card(int card_id_, Bank_Card* bank_card_, Passport* passport_):
		card_id(card_id_), bank_card(bank_card_), passport(passport_){}
	~Card() = default;
    int get_card_id() const
	{
		return card_id;
	}
	std::string get_card_first_name() const
	{
		return passport->get_first_name();
	}
	std::string get_card_last_name() const
	{
		return passport->get_last_name();
	}
	int get_info_about_money() const
	{
		return bank_card->get_money();
	}
};

class Terminal
{
private:
	Card* card;
public:
	Terminal() = default;
	explicit Terminal(Card* card_): card(card_){}
	~Terminal() = default;
	void set_card(Card* card_)
	{
		card = card_;
	}
	void delete_card()
	{
		card = nullptr;
	}
};

class I_Bank_Service
{
};

class Bank_Service: public I_Bank_Service
{

};

/*class Passport_Service 
{
private:
	Passport passport;
public:
	Passport_Service() = default;
	explicit Passport_Service(const Passport passport_) :
		passport(passport_){}
	virtual Passport get()
	{

	}
	virtual void set(const Passport p)
	{

	}
};
*/