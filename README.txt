Aaron Lewis
2/18/26

Glitter Bot uses the D++ discord api library in order to interact with discords api.
In order to compile you must install the library. Instructions for how to do so can
be found here:

dpp.dev/index/.html
__________________________________________________________________________________
When making a discord bot you typically set it up through the Discord Dev Portal.
In there you can make your own bot, and recieve a bot token for it. In order to change
the bot simply change the variable in glitter.cpp called BOT_TOKEN to your bot
token. You can then invite it to your server.

NOTE:!IF YOU DO WISH TO RUN THE BOT UNDERSTAND IT USES A SIZABLE AMOUNT OF MEMORY!
28% on 64gig computer
___________________________________________________________________________________
To compile type: 
g++ -std=c++17 $(ls *.cpp | grep -v main.cpp) -o glitter -ldpp
___________________________________________________________________________________
To run type:
./glitter
___________________________________________________________________________________

Functions and Classes:
Glitter Bot uses 3 classes to store the majority of its logic. The Account class which stores user information,
The LinkedList class which stores a users inventory, and the ArrayList class which temporarily stores the 
sell log of the user until the bot is turned off. The LinkedList and ArrayList classes are stored within the
Account class as not to make them a global for all users. In order to keep the balances of users after
the bot is turned on a load function and save function stores data in user_database.txt.
___________________________________________________________________________________

Main Modifications:
In order for Glitter Bot 2 functions were added to LinkedList.cpp/.h and 1 function
to ArrayList.cpp/ArrayList.h . For ArrayList the function int& ArrayList::operator[](int index)
was added so I could easily pull data from the Array. For LinkedLists the functions
save_to and load_from were implemented to convert the live nodes into text
that could be sent to user_database.txt, and to reconstruct the text into
the nodes.
___________________________________________________________________________________

Functionality:
Glitter Bot allows you to play a minigame where you can mine ore that has some value
sell that ore, and check how much you have sold as well as how much the current 
ore you have is worth. It also allows for checking a log of each sell you have made during
the current running of the bot. There are multiple different ores that can be mined 
each with a different value.
