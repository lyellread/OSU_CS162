/*********************************************************************
** Program Filename:player.cpp
** Author:Lyell Read
** Date:2/3/2019
** Description:player class function definitions
** Input:na
** Output:na
*********************************************************************/


#include "player.hpp"

//==== Constructors and Destructors ====//

/*********************************************************************
** Function:Player
** Description:constructor
** Parameters:none
** Pre-Conditions:nothing
** Post-Conditions:class created
*********************************************************************/ 

Player::Player(){
	
	//cout << "Player Constructor Called" << endl;

	this->racks = new int [13];
	this->current_racks = 0;

}

/*********************************************************************
** Function:~Player
** Description:destructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:class destroyed
*********************************************************************/ 

Player::~Player(){
	
	delete[] racks;
	//cout << "Player Destructor Called" << endl;
	
}

//==== Getters and Setters and Member Functions ====//

/*********************************************************************
** Function:print_hand
** Description:prints hand
** Parameters:
** Pre-Conditions:
** Post-Conditions:hand printed
*********************************************************************/ 


void Player::print_hand(){
	
	this->hand.print_hand();
	
}

/*********************************************************************
** Function:add_rack
** Description:adds a rack to the player
** Parameters:card number
** Pre-Conditions:
** Post-Conditions:rack added
*********************************************************************/ 


void Player::add_rack(int card_number){
	
	//cout << "==== DBG: Rack Manager : Add Rack : Started. To Note Address : " << this->racks << ", and index: " << current_racks << endl;
	
	this->racks[this->current_racks] = card_number;
	++this->current_racks;
	
	//cout << "==== DBG: Rack Manager : Add Rack : Success on Rack Add" << endl;

	this->hand.remove_all_n(card_number);
	
}

/*********************************************************************
** Function:get_hand_size
** Description:returns hand size
** Parameters:
** Pre-Conditions:
** Post-Conditions:hand size returns
*********************************************************************/ 

	
int Player::get_hand_size(){
	
	return this->hand.get_hand_size();
	
}

/*********************************************************************
** Function:add_card_to_hand
** Description:adds a card to hand
** Parameters:card_to_add
** Pre-Conditions:
** Post-Conditions:card added
*********************************************************************/ 


void Player::add_card_to_hand (Card card_to_add){
	
	this->hand.add_card_to_hand(card_to_add);
	
}

/*********************************************************************
** Function:pop_n_from_hand
** Description:pops a card of number n from hand
** Parameters:number
** Pre-Conditions:
** Post-Conditions:card removed
*********************************************************************/ 


Card Player::pop_n_from_hand (int card_number){
	
	return this->hand.pop_n_from_hand(card_number);
	
}

/*********************************************************************
** Function:check_for_racks
** Description:checks for racks in a hand
** Parameters:
** Pre-Conditions:
** Post-Conditions:hand checked, return value passed on
*********************************************************************/ 


int Player::check_for_racks(){
	
	return this->hand.check_for_racks();
	
}

/*********************************************************************
** Function:print_racks
** Description:prints all racks for a player
** Parameters:
** Pre-Conditions:
** Post-Conditions:racks printed
*********************************************************************/ 


void Player::print_racks(){
	
	cout << "Current Racks:\n";
	
	if (this->current_racks == 0){
		cout << "None\n\n";
		return;
	}
	cout << this->racks[0];
	
	for (int i=1; i<this->current_racks; ++i){
		
		cout << ", " << this->racks[i];
		
	}
	
	cout << "\n";
}

/*********************************************************************
** Function:get_rack_number
** Description:gets number of racks
** Parameters:
** Pre-Conditions:
** Post-Conditions:rack count returned
*********************************************************************/ 


int Player::get_rack_number (){
	
	return this->current_racks;
	
}

/*********************************************************************
** Function:rack manager
** Description:manages function of adding a rack to hand and checking
** Parameters:
** Pre-Conditions:
** Post-Conditions:racks managed for player
*********************************************************************/ 


void Player::rack_manager(){
	
	//cout << "==== DBG: Rack Manager Started" << endl;
	int temp = this->check_for_racks();
	//cout << "==== DBG: Rack Manager : Check for Racks returned: " << temp << endl;
	while (check_for_racks() != -1){
		
		this->add_rack(temp);
		//cout << "==== DBG: Rack Manager : Rack added." << endl;

		this->hand.remove_all_n(temp);
		//cout << "==== DBG: Rack Manager : Cards Removed from hand" << endl;

		
		temp = this->check_for_racks();
		//cout << "==== DBG: Rack Manager : Check for racks called again; Value:" << temp << endl;

		
	}
	
}

/*********************************************************************
** Function:n_in_hand
** Description:check that n is in hand
** Parameters:card_number
** Pre-Conditions:
** Post-Conditions:returns value depending on presence
*********************************************************************/ 


int Player::n_in_hand(int card_number){
	
	for (int i=0; i<this->hand.get_hand_size(); ++i){
		if (this->hand.get_number_at_element(i) == card_number){
			return 1;
		}
	}
	return 0;
}

/*********************************************************************
** Function:go_fish
** Description:adds a selected card to hand
** Parameters:card_drawn
** Pre-Conditions:
** Post-Conditions:card added
*********************************************************************/ 


void Player::go_fish (Card card_drawn){
	
	this->hand.add_card_to_hand(card_drawn);
	
}