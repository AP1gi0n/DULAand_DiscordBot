#pragma once
#include <dpp/dpp.h>
#include <iostream>
#include <vector>
#include "Account.h"
using namespace std;

extern vector<Account> users;

void save_users();

void load_users();

constexpr int possible_ores = 7;
struct ores
{
	const int chances[possible_ores] = {110, 105, 95, 80, 60, 35, 1};
	const map <int, int> value_map
	{
	//       Chance Value	
		{110, 1000},
		{105, 500},
		{95, 250},
		{80, 150},
		{60, 100},
		{35, 50},
		{1, 5}
	};	

	const map <int, string> name_map
	{
		{110,"💎 Diamond"},	
		{105,"🟡 Gold"},
		{95,"🔵 Cobalt"},
		{80,"🔳 Titanium"},
		{60,"⚪ Nickel"},
		{35,"🔲 Iron"},
		{1,"🪨 Junk"}
	};
};

void set_up_mine (dpp::cluster& bot);
