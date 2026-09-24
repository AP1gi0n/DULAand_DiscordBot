#include "Account.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include <dpp/dpp.h>

Account::Account() : m_user_id(0), m_balance(0) {}

Account::Account (dpp::snowflake id, int initial_bal)
{
	m_user_id = id;
	m_balance = initial_bal;
}

dpp::snowflake Account::get_id()
{
	return m_user_id;
}

int Account::get_balance()
{
	return m_balance;
}

void Account::add_bal(const int amount)
{
	if (amount > 0)
	{
		m_balance += amount;
	}
}

bool Account::operator>(const Account& other) const
{
	return this->m_balance > other.m_balance;
}

bool Account::operator<(const Account& other) const
{
	return this->m_balance < other.m_balance;
}

LinkedList& Account::get_inven()
{
	return m_inventory;
}

ArrayList& Account::get_slog()
{
	return m_slog;
}

