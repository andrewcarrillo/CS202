#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include "player.h"
#
using namespace std;



int main()
	{
		srand(time(0));
		int amount;
		cout<<"how many players are playing in this game?" << endl;
		cin>>amount;
		player* players = new player[amount];
		card* deckunshuffled = new card[52];
		card* deckshuffled = new card[52];
		card* discard = new card[52];
		card* stock = new card[52];
		ifstream fs;
		fs.open("cards.txt");
		for(int i=0; i<52; i++)
			{
				fs>>deckunshuffled[i];
				deckunshuffled[i].setlocation("unshuffled");
			}
		cout<< "HI" << endl;
		for(int i=0; i<52; i++)
			{
				deckshuffled[i] = deckunshuffled[i];
				//deckshuffled[i].setlocation("shuffled");
			}
		
		card temp;
		
		cout<< "Hi"<< endl;
		for(int j=0; j<100; j++)
			{
			for(int i=0; i<52; i++)
				{
					int shuffle = rand() %52;
					temp = deckshuffled[i] ;
					deckshuffled[i] = deckshuffled[shuffle];
					deckshuffled[shuffle] = temp;
					deckshuffled[i].setlocation("shuffled");
				}
			}
		cout<<"hi"<<endl;
/*
		for(int i=0; i<amount*5; i++)
			{
				for(int j=0; j<amount; j++)
					{
						for(int z=0; z<5; z++)
							{
								players[j].hand[z] = deckshuffled[i];
							}
					}
			}
*/
			card** tempcards= new card*[amount];
			for(int i=0; i<amount; i++)
				{
					tempcards[i] = new card[5];
				}
			
			card* tptr;
		int index=0;
//loop through each player and deal five cards to each player
		for(int i=0; i<5; i++)
			{
				//loop through players
				for(int j=0; j<amount; j++)
					{
						//give a card to temporary array of cards
						tptr = players[i].getplayerhand();						
						tptr[i] = deckshuffled[index];
						index++;
					}
				
				//discard card
				discard[i]=deckshuffled[index];
				index++;	
			}
		int stockvalue = index;
		for(int i=stockvalue; i<52; i++)
			{
				stock[i-stockvalue] = deckshuffled[i];
			}
		for(int i=0; i<52; i++)
			{
				cout<<deckshuffled[i]<<endl;
			}
		
	
		delete[]players;
		delete[]deckshuffled;
		delete[]deckunshuffled;
		delete[]tempcards;
		delete[]discard;






		return 0;
	}
