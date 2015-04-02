#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class card
{
	public:
		card();
		card(const card&);
		~card();
		void setlocation(string location);
		card operator=(const card&);
		friend ostream& operator<<(ostream&, card&);
		friend ifstream& operator>>(ifstream&, card&);
		bool operator>(const card&) const;
		bool operator<(const card&) const;
		bool operator==(const card&) const;
	private:
		string suit;
		string rank;
		string location;
		int value;
};
