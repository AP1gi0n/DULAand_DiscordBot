#include <dpp/dpp.h>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Account.h"
#include "glitter_func.h"
#include <iostream>
using namespace std;

extern vector<Account> users;
void load_user_data();
void set_up_mine(dpp::cluster& bot);
//Typically you are meant to keep your bot token secret from others
string BOT_TOKEN = "/*PLACE YOUR OWN BOT TOKEN HERE AS DESCRIBED IN README*/";
int main()
{
	//Initializes cluster
	dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);
	//Loads user data for minigame
	load_user_data();
	//Checks if the bot is connecting
	bot.on_log(dpp::utility::cout_logger());
	set_up_mine(bot);
	bot.on_ready([&bot](const dpp::ready_t& event)
	{
		//Registers commands needed to run minigame
		if(dpp::run_once<struct register_bot_commands>())
		{
			bot.global_command_create(dpp::slashcommand("mine","Mine for ores!", bot.me.id));
			bot.global_command_create(dpp::slashcommand("sell","Sell your inventory of ore, and save your progress!", bot.me.id));
			bot.global_command_create(dpp::slashcommand("balance","Check your balance!", bot.me.id));
			bot.global_command_create(dpp::slashcommand("slog","Check the last sell you have made!", bot.me.id));
		}
		cout << "Logged in as: " << bot.me.username << endl;				
	});
	//Starts the bot, basically an infinite loop	
	bot.start(dpp::st_wait);
	return 0;
}
