// == PLAYER.CPP - FUNCTION DEFENITIONS FOR PLAYER CLASS == //

#include "player.hpp"

//==== Constructors and Destructors ====//

Player::Player(){
	
	//cout << "Player Constructor Called" << endl;

	this->racks = new int [13];
	this->current_racks = 0;

}

Player::~Player(){
	
	delete[] racks;
	//cout << "Player Destructor Called" << endl;
	
}

//==== Getters and Setters and Member Functions ====//

void Player::print_hand(){
	
	this->hand.print_hand();
	
}

void Player::add_rack(int card_number){
	
	//cout << "==== DBG: Rack Manager : Add Rack : Started. To Note Address : " << this->racks << ", and index: " << current_racks << endl;
	
	this->racks[this->current_racks] = card_number;
	++this->current_racks;
	
	//cout << "==== DBG: Rack Manager : Add Rack : Success on Rack Add" << endl;

	this->hand.remove_all_n(card_number);
	
}
	
int Player::get_hand_size(){
	
	return this->hand.get_hand_size();
	
}

void Player::add_card_to_hand (Card card_to_add){
	
	this->hand.add_card_to_hand(card_to_add);
	
}

Card Player::pop_n_from_hand (int card_number){
	
	return this->hand.pop_n_from_hand(card_number);
	
}

int Player::check_for_racks(){
	
	return this->hand.check_for_racks();
	
}

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

int Player::get_rack_number (){
	
	return this->current_racks;
	
}

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

int Player::n_in_hand(int card_number){
	
	for (int i=0; i<this->hand.get_hand_size(); ++i){
		if (this->hand.get_number_at_element(i) == card_number){
			return 1;
		}
	}
	return 0;
}

void Player::go_fish (Card card_drawn){
	
	this->hand.add_card_to_hand(card_drawn);
	
}