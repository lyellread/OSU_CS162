/*********************************************************************
** Program Filename:card.hpp
** Author:Lyell Read
** Date:2/3/2019
** Description:prototypes for the card class
** Input:na
** Output:na
*********************************************************************/

#ifndef CARD
#define CARD

class Card {
	
	private:
		
		int number;
		int suit;
	
	public:
	
		Card();
		Card(int number, int suit);
		~Card();

		void set_number(int number);
		void set_suit(int suit);
		
		int get_number();
		int get_suit();
		
};


#endif