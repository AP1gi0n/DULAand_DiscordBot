#pragma once
#include <dpp/dpp.h>
#include "LinkedList.h"
#include "ArrayList.h"

class Account
{
	private:
		dpp::snowflake m_user_id;
		int m_balance;
		LinkedList m_inventory;
		ArrayList m_slog;
	public:
		Account();
		Account(dpp::snowflake id, int initial_bal);
		dpp::snowflake get_id();
		int get_balance();
		void add_bal(const int amount);
		bool operator>(const Account& other) const;
		bool operator<(const Account& other) const;
		LinkedList& get_inven();
		ArrayList& get_slog();
};
