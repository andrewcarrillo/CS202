#include <iostream>
#include <fstream>
#include <string.h>
#include "card.h"
using namespace std;

class player
{
	public:
		player();
		player(const player&);
		~player();
		card* getplayerhand();
		void setplayername(string source);
		void setplayerbet(int value);
		friend ostream& operator<<(ostream&, player&);
		friend ifstream& operator>>(ifstream&, player&);
	
	private:
		float bet;
		string name;
		card* hand;
};

