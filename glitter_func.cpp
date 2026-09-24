#include "glitter_func.h"
#include <dpp/dpp.h>
#include <cstdlib>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Account.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

// LinkedList and ArrayList classes present in Account class
vector<Account> users;
ores ore;

// Function that saves past data incase the bot is turned off
void save_user_data()
{
	ofstream out ("user_database.txt");
	for (auto& user : users)
	{
		out << user.get_id() << " " << user.get_balance() << " " << user.get_inven().size() << endl;
		user.get_inven().save_to(out);
		out << endl;
	}
	out.close();
}
// Function that loads past data for when the bot is turned on
void load_user_data()
{
	ifstream in ("user_database.txt");
	if (!in.is_open())
	{
		cerr << "Error loading user database file"<< endl;
		return;
	}
	dpp::snowflake id;
	int bal;
	int item_count;
	users.clear();
	while (in >> id >> bal >> item_count)
	{
		users.emplace_back(id, bal);
		Account& cur_user = users.back();
		cur_user.get_inven().load_from(in, item_count);
		cout <<"Loading user: "<<id<<"| User balance:"<<bal<<"| Item Count:"<< item_count<< flush;
	}
	in.close();
	cout <<"Loaded " << users.size() <<" from user_database"<<endl;
}

// Function that gets current users account based on id
Account* get_account(dpp::snowflake id)
{
	for (auto& u : users)
	{
		if (u.get_id() == id)
		{
			return &u;
		}
	}
	users.emplace_back(id, 0);
	return &users.back();
}
// Function that sets up minigame
void set_up_mine (dpp::cluster& bot)
{
	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event)
	{
		Account* user = get_account(event.command.usr.id);
		srandom(time(0));
		if (event.command.get_command_name() == "mine")
		{
			int max_ore_chance = 110;
			int min_ore_chance = 0;
			int mined_ore = int (double(random())/(double(RAND_MAX) +1) *110) +1;
			string found_ore_name;
			int found_ore_value;
			bool found_ore = false;
			while (!found_ore)
			{
			//Size of chance array is 7
				for ( int a = 6; a >= 0; --a )
				{
					if (mined_ore >= ore.chances[a])
					{
						int what_found = ore.chances[a];
						auto it_val = ore.value_map.find(what_found);
						auto it_name = ore.name_map.find(what_found);
						if (it_val != ore.value_map.end() && it_name != ore.name_map.end())
						{
							found_ore_value = it_val->second;
							found_ore_name = it_name->second;
							found_ore = true;
							break;
						}
					}
				}
			}
			event.reply("⛏ You found " + found_ore_name + " worth $" + to_string(found_ore_value) + "!");
			user->get_inven().add(found_ore_value);
			save_user_data();
			return;
		}

		if (event.command.get_command_name() == "sell")
		{
			int value = user->get_inven().sum();
			if (value <= 0)
			{
				event.reply("❌ Your inventory is empty!");
				return;
			}
			user->add_bal(value);
			user->get_slog().add(value);
			user->get_inven().filter(0);
			save_user_data();
			event.reply("💰 You sold your haul for $" + to_string(value) + "!"); 
		}

		if(event.command.get_command_name() == "balance")
		{
			// Currently only god knows why this code is working
			event.thinking();
			Account* user = get_account(event.command.get_issuing_user().id);
			int cur_balance = user->get_balance();
			int cur_inven = user->get_inven().sum();
			if (cur_balance == 0)
			{
				event.edit_response("🏦You don't have a money at the moment! Try '/mine' and '/sell' to earn money.");
				return;
			}
			event.edit_response("🏦 Your current balance is: $" + to_string(cur_balance) + "\nYour unsold ore is worth: $" + to_string(cur_inven));
		}

		if(event.command.get_command_name() == "slog")
		{
			if (user->get_slog().size() == 0)
			{
				event.reply("📝 Your sell log is currently empty.");
				return;	 
			}
			string history = "📝 **Recent Sales**\n";
			int max_hist = user->get_slog().size();
			int min_hist = 0;
			for (int a = min_hist; a < max_hist; ++a)
			{
				history += "🔷 Sale#" + to_string(a + 1)+": $" + to_string(user->get_slog()[a]);
			}
			event.reply(history);
		}

	});
}

