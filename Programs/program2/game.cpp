// == CARD.CPP - FUNCTION DEFENITIONS FOR CARD CLASS == //

#include "game.hpp"

//==== Constructors and Destructors ====//

Game::Game(){
	
	//cout << "Game Constructor Called" << endl;

	//yeet//
	
}

Game::~Game(){
	
	//cout << "Game Destructor Called" << endl;

	//yote//

}

//==== Getters and Setters and Member Functions ====//

int Game::check_for_win(){
	
	if (this->players[0].get_hand_size() == 0){
		return 0;
	}
	
	if (this->players[1].get_hand_size() == 0){
		return 1;
	}
	
	return -1;
	
}

int Game::prompt_player (int player_number){
	
	string input;
	
	cout << "Player " << player_number+1 << ", what to ask for:";
	cin >> input;
	
	//check string is int
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) {
			cout << "That caused an error. Re-enter:" << endl;
			return prompt_player (player_number);
		}	
	}
	
	//convert string to int
	int output=0;
	for (int str_index=0; str_index < input.length(); str_index++){

		int multiplier = input.length()-(str_index+1);
		int working_digit = int(input[str_index])-48;

		for (int iterator=0; iterator < multiplier; iterator++){
			working_digit*=10;
		}//this works by usign ones, tens, hundreds...

		output+=working_digit;
	}
	
	//ensure that int is in hand:
	if (this->players[player_number].n_in_hand(output)){
		return output;
	}
	cout << "\nThat's not in your hand! Re-enter" << endl;
	return prompt_player(player_number);
}

void Game::clear_screen(){
	
	for (int i=0; i<100; ++i){
		cout << "\n";
	}
}

void Game::play_turn(int player_number, int enemy_player_num){
	
	//have the user ask the other player for a card; if they get it repeat.
	this->clear_screen();
	cout << "\n= = = = = = = = = = = = = = = = = = = = = \n       It is now Player " << player_number+1 << "'s turn!\n= = = = = = = = = = = = = = = = = = = = = \n" << endl;
	
	int choice, player_ask_failed;
	Card temp;
	player_ask_failed = 0;
	
	while (player_ask_failed == 0 && ((this->players[0].get_rack_number() + this->players[1].get_rack_number()) != 13)){
		
		//print the player's current status <hand, racks>
		this->players[player_number].print_hand();
		this->players[player_number].print_racks();
		
		//ask the player to choose what to ask for
		choice = prompt_player(player_number);
		
		//add a card if the player has none, and the deck has some.
		if (this->deck.get_deck_size() != 0 && this->players[player_number].get_hand_size() == 0){
			temp = this->deck.pop_from_deck();
			this->players[player_number].add_card_to_hand(temp);
		}
		
		//steal the eny card.
		temp = this->players[enemy_player_num].pop_n_from_hand(choice);
		
		if (temp.get_number() == -1){ // if the card does not exist in the other players hand
			
			
			if (this->deck.get_deck_size() != 0){ //if theres still some cards in the deck
				cout << "\n\nThe other player does not have a card by that number. You had to Go Fish." << endl;
				Card go_fish_draw = this->deck.pop_from_deck();
				
				//if the draw is same as initial card...
				if (go_fish_draw.get_number() == choice){ //if the player drew the same card they ask for.
					this->players[player_number].go_fish(go_fish_draw);
					cout << "You got the same card you asked for." << endl;
				}
				else{//break turn
					this->players[player_number].go_fish(go_fish_draw);
					this->players[player_number].print_hand();
					player_ask_failed = 1;
					cout << "Press any key to continue . . . ";
					getchar();
					getchar();
				}	
			}
		}
		
		
		while (temp.get_number() != -1){//card(s) exist in opponents hand
			
			cout << "\n\nGreat Success! you got a " << temp.get_number() << " from the other player." << endl;
			this->players[player_number].add_card_to_hand(temp);
			temp = this->players[enemy_player_num].pop_n_from_hand(choice);
		}
		
		//do all the rack stuff.
		this->players[player_number].rack_manager();
		
		//if there are still cards in the deck and the player has just run outta cards...
		if (this->deck.get_deck_size() != 0 && this->players[player_number].get_hand_size() == 0){
			temp = this->deck.pop_from_deck();
			this->players[player_number].add_card_to_hand(temp);
		}
		

	}
	

	
	return;
	
}

void Game::play_computer_turn(int player_number, int enemy_player_num){
	
	//have the user ask the other player for a card; if they get it repeat.
	this->clear_screen();
	//cout << "\n= = = = = = = = = = = = = = = = = = = = = \n       It is now Player " << player_number+1 << "'s turn!\n= = = = = = = = = = = = = = = = = = = = = \n" << endl;
	
	srand(time(NULL));
	
	int choice, player_ask_failed;
	Card temp;
	player_ask_failed = 0;
	
	while (player_ask_failed == 0 && ((this->players[0].get_rack_number() + this->players[1].get_rack_number()) != 13)){
		
		//print the player's current status <hand, racks>
		//this->players[player_number].print_hand();
		//this->players[player_number].print_racks();
		
		//ask the player to choose what to ask for
		choice = computer_choice(player_number);
		
		//add a card if the player has none, and the deck has some.
		if (this->deck.get_deck_size() != 0 && this->players[player_number].get_hand_size() == 0){
			temp = this->deck.pop_from_deck();
			this->players[player_number].add_card_to_hand(temp);
		}
		
		//steal the eny card.
		temp = this->players[enemy_player_num].pop_n_from_hand(choice);
		
		if (temp.get_number() == -1){ // if the card does not exist in the other players hand
			
			
			if (this->deck.get_deck_size() != 0){ //if theres still some cards in the deck
				//cout << "\n\nThe other player does not have a card by that number. You had to Go Fish." << endl;
				Card go_fish_draw = this->deck.pop_from_deck();
				
				//if the draw is same as initial card...
				if (go_fish_draw.get_number() == choice){ //if the player drew the same card they ask for.
					this->players[player_number].go_fish(go_fish_draw);
					//cout << "You got the same card you asked for." << endl;
				}
				else{//break turn
					this->players[player_number].go_fish(go_fish_draw);
					this->players[player_number].print_hand();
					player_ask_failed = 1;
					//cout << "Press any key to continue . . . ";
					//getchar();
					//getchar();
				}	
			}
		}
		
		
		while (temp.get_number() != -1){//card(s) exist in opponents hand
			
			//cout << "\n\nGreat Success! you got a " << temp.get_number() << " from the other player." << endl;
			this->players[player_number].add_card_to_hand(temp);
			temp = this->players[enemy_player_num].pop_n_from_hand(choice);
		}
		
		//do all the rack stuff.
		this->players[player_number].rack_manager();
		
		//if there are still cards in the deck and the player has just run outta cards...
		if (this->deck.get_deck_size() != 0 && this->players[player_number].get_hand_size() == 0){
			temp = this->deck.pop_from_deck();
			this->players[player_number].add_card_to_hand(temp);
		}
	}	
	return;
}

int Game::computer_choice(int player_number){
	
	int temp_choice = rand()%13;
	while (! this->players[player_number].n_in_hand(temp_choice)){
		
		temp_choice = rand()%13;
		
	}
	
	return temp_choice;
	
}
	

void Game::deal_cards(){
	
	Card tempcard;
	
	for (int player = 0; player < 2; ++player){
		
	
		for (int i=0; i<7; ++i){
			
			tempcard = this->deck.pop_from_deck();
			this->players[player].add_card_to_hand(tempcard);
			
		}
	}
}
			
			
			
void Game::manage_gameplay (){
	
	int p1_racks, p2_racks, opposite_player_number, player_number;
	
	deal_cards();
	
	p1_racks = this->players[0].get_rack_number();
	p2_racks = this->players[1].get_rack_number();	
	
	while ((p1_racks + p2_racks) != 13){
		
		player_number = 0;
		opposite_player_number= 1;
		play_turn (player_number, opposite_player_number);

		player_number = 1;
		opposite_player_number = 0;
		play_computer_turn (player_number, opposite_player_number);
		
		p1_racks = this->players[0].get_rack_number();
		p2_racks = this->players[1].get_rack_number();
		
	}
	
	this->clear_screen();
	
	if (p1_racks > p2_racks){
		cout << "\n= = = = = = = = = = = = = = = = = = = = = \n       Player 1 Wins!\n= = = = = = = = = = = = = = = = = = = = = \n" << endl;
	}
	else{
		cout << "\n= = = = = = = = = = = = = = = = = = = = = \n       Player 2 Wins!\n= = = = = = = = = = = = = = = = = = = = = \n" << endl;
	}
}
	
		
		
		
		
		
		
		
		
		
		