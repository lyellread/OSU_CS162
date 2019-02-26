/*********************************************************************
** Program Filename:zoo.cpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Zoo Code ... Much Code ...
** Input:na
** Output:na
*********************************************************************/

#include "zoo.hpp"

/*********************************************************************
** Function:Zoo
** Description:Constructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:object created
*********************************************************************/ 


Zoo::Zoo(){
	
	this->sloths = NULL;
	this->monkeys = NULL;
	this->sea_otters = NULL;
	
	this->len_sloths = 0;
	this->len_monkeys = 0;
	this->len_sea_otters = 0;
	
	this->current_balance = 100000;
	this->food_base_cost = 100;
	this->food_percent_change = 1.0;
	
}

/*********************************************************************
** Function:~Zoo
** Description:destructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


Zoo::~Zoo(){
	
	if (this->len_sloths > 0){
		
		delete[] this->sloths;
		
	}
	
	if (this->len_monkeys > 0){
		
		delete[] this->monkeys;
		
	}
	
	if (this->len_sea_otters > 0){
		
		delete[] this->sea_otters;
		
	}
}

/*********************************************************************
** Function:add_sloth
** Description:Sloth adder
** Parameters:sloth to add
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::add_sloth (Sloth sloth_to_add){
	
	if (this->len_sloths == 0){
		
		this->sloths = new Sloth [1];
		this->sloths[0] = sloth_to_add;
		this->len_sloths++;
		
	}
	else{
		
		Sloth * temp = new Sloth [this->len_sloths + 1];
		
		for (int element = 0; element < len_sloths; ++element){
			
			temp[element] = this->sloths[element];
			
		}
		
		temp[len_sloths] = sloth_to_add;
		
		Sloth * delete_temp = sloths;
		
		this->sloths = temp;
		this->len_sloths++;
		
		delete[] delete_temp;
		
	}
}

/*********************************************************************
** Function:add_monkey
** Description:Adds a monkey to array
** Parameters:monkey to add
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::add_monkey (Monkey monkey_to_add){
	
	if (this->len_monkeys == 0){
		
		this->monkeys = new Monkey [1];
		this->monkeys[0] = monkey_to_add;
		this->len_monkeys++;
		
	}
	else{
		
		Monkey * temp = new Monkey [this->len_monkeys + 1];
		
		for (int element = 0; element < len_monkeys; ++element){
			
			temp[element] = this->monkeys[element];
			
		}
		
		temp[len_monkeys] = monkey_to_add;
		
		Monkey * delete_temp = monkeys;
		
		this->monkeys = temp;
		this->len_monkeys++;
		
		delete[] delete_temp;
		
	}	
}

/*********************************************************************
** Function:add_sea_otter
** Description:adds sea otter
** Parameters:sea otter to add
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 

			
void Zoo::add_sea_otter (SeaOtter sea_otter_to_add){
	
	if (this->len_sea_otters == 0){
		
		this->sea_otters = new SeaOtter [1];
		this->sea_otters[0] = sea_otter_to_add;
		this->len_sea_otters++;
		
	}
	else{
		
		SeaOtter * temp = new SeaOtter [this->len_sea_otters + 1];
		
		for (int element = 0; element < len_sea_otters; ++element){
			
			temp[element] = this->sea_otters[element];
			
		}
		
		temp[len_sea_otters] = sea_otter_to_add;
		
		SeaOtter * delete_temp = sea_otters;
		
		this->sea_otters = temp;
		this->len_sea_otters++;
		
		delete[] delete_temp;
		
	}	
}

/*********************************************************************
** Function:remove sloth
** Description:removes a sloth
** Parameters:index of sloth to remove
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::remove_sloth(int index){
	
	if (this->len_sloths == 1){
		
		delete[] this->sloths;
		this->len_sloths--;
		
	}
	
	if (len_sloths == 0){
		
		cout << "==ERROR : Trying to delete nonexistant sloth!" << endl;
		
	}
	
	//swap with last unit;
	Sloth temp = this->sloths[index];
	this->sloths[index] = this->sloths[this->len_sloths-1];
	sloths[this->len_sloths-1] = temp;
	
	//copy all but that last one.
	Sloth * new_array = new Sloth[this->len_sloths-1];
	
	for (int element = 0; element<(this->len_sloths-1); ++element){
		new_array[element] = this->sloths[element];
	}
	
	Sloth * array_to_delete = this->sloths;
	this->sloths = new_array;
	delete[] array_to_delete;
	
	this->len_sloths--;
	
}

/*********************************************************************
** Function:remove_monkey
** Description:remove monkey
** Parameters:index of monkey to remove
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::remove_monkey (int index){
	
	if (this->len_monkeys == 1){
		
		delete[] this->monkeys;
		this->len_monkeys--;
		
	}
	
	if (len_monkeys == 0){
		
		cout << "==ERROR : Trying to delete nonexistant monkey!" << endl;
		
	}
	
	//swap with last unit;
	Monkey temp = this->monkeys[index];
	this->monkeys[index] = this->monkeys[this->len_monkeys-1];
	monkeys[this->len_monkeys-1] = temp;
	
	//copy all but that last one.
	Monkey * new_array = new Monkey[this->len_monkeys-1];
	
	for (int element = 0; element<(this->len_monkeys-1); ++element){
		new_array[element] = this->monkeys[element];
	}
	
	Monkey * array_to_delete = this->monkeys;
	this->monkeys = new_array;
	delete[] array_to_delete;
	
	this->len_monkeys--;	
}

/*********************************************************************
** Function:remove_sea_otter
** Description:removes a sea otter
** Parameters:index of sea otter to remove
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 

			
void Zoo::remove_sea_otter (int index){
	
	if (this->len_sea_otters == 1){
		
		delete[] this->sea_otters;
		this->len_sea_otters--;
		
	}
	
	if (len_sea_otters == 0){
		
		cout << "==ERROR : Trying to delete nonexistant sea_otter!" << endl;
		
	}
	
	//swap with last unit;
	SeaOtter temp = this->sea_otters[index];
	this->sea_otters[index] = this->sea_otters[this->len_sea_otters-1];
	sea_otters[this->len_sea_otters-1] = temp;
	
	//copy all but that last one.
	SeaOtter * new_array = new SeaOtter[this->len_sea_otters-1];
	
	for (int element = 0; element<(this->len_sea_otters-1); ++element){
		new_array[element] = this->sea_otters[element];
	}
	
	SeaOtter * array_to_delete = this->sea_otters;
	this->sea_otters = new_array;
	delete[] array_to_delete;
	
	this->len_sea_otters--;	
}

/*********************************************************************
** Function:increase_all_ages
** Description:increases all ages of all creatures
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::increase_all_ages () {
	
	for (int i = 0; i<this->len_sloths; ++i){this->sloths[i].increase_age();}
	for (int i = 0; i<this->len_monkeys; ++i){this->monkeys[i].increase_age();}
	for (int i = 0; i<this->len_sea_otters; ++i){this->sea_otters[i].increase_age();}

}

/*********************************************************************
** Function:gather_all_revenue
** Description:gathers and updates daily revenue
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::gather_all_revenue () {
	
	int individual = 0;
	int total = 0;
	
	for (int i = 0; i<this->len_sloths; ++i){
		
		individual = this->sloths[i].get_revenue();
		if (this->sloths[i].get_age() >= 1094){individual *= 2;}
		
		total += individual;
	}
	for (int i = 0; i<this->len_monkeys; ++i){
		
		individual = this->monkeys[i].get_revenue();
		if (this->monkeys[i].get_age() >= 1094){individual *= 2;}
		
		total += individual;	
		
	}
	
	for (int i = 0; i<this->len_sea_otters; ++i){
		
		individual = this->sea_otters[i].get_revenue();
		if (this->sea_otters[i].get_age() >= 1094){individual *= 2;}
		
		total += individual;
	}
	
	cout << "\n\nTotal Income Gathered Today:" << total << endl;
	
	this->current_balance += total;

}

/*********************************************************************
** Function:get_user_input
** Description:gets the user input for menus
** Parameters:low end, high end of range
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Zoo::get_user_input(int low, int high){
	
	string input;
	
	cin >> input;
	
	//check string is int
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) {
			cout << "That caused an error. Re-enter:" << endl;
			return get_user_input (low, high);
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
	
	if (output<=high && output>=low){
		
		return output;
		
	}
	
	return get_user_input (low, high); 
}

/*********************************************************************
** Function:buy_animals
** Description:manges the buying animals process
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Zoo::buy_animals(){
	
	cout << "   Main Menu:\n   ----------\n + 1 Buy a Sloth\n + 2 Buy a Monkey\n + 3 Buy a Sea Otter\n   ---   \n + 4 Pass Turn\n + 5 Retire (quit) \n\nChoice:";	
	int user_choice_1 = get_user_input(1,5);
	
	if (user_choice_1 == 4) {return 1;}
	
	if (user_choice_1 == 5) {return -2;}
	
	cout << "How Many (1 or 2) :";
	
	int user_choice_2 = get_user_input(1,2);
	
	switch (user_choice_1){
		
		case 1: //we want sloth
			
			for (int i=0; i<user_choice_2; ++i){
				
				Sloth temp(1095);//with age and such...
				if (temp.get_cost() >= current_balance){return -1;}
				this->current_balance -= temp.get_cost();
				add_sloth(temp);
				
			}
			
		break;
		
		case 2:
		
			for (int i=0; i<user_choice_2; ++i){
				
				Monkey temp(1095);//with age and such...
				if (temp.get_cost() >= current_balance){return -1;}
				this->current_balance -= temp.get_cost();
				add_monkey(temp);
				
			}
		
		break;
		
		case 3:
		
			for (int i=0; i<user_choice_2; ++i){
				
				SeaOtter temp(1095);//with age and such...
				if (temp.get_cost() >= current_balance){return -1;}
				this->current_balance -= temp.get_cost();
				add_sea_otter(temp);
				
			}
		
		break;
		
	}
	return 1;
}

/*********************************************************************
** Function:generate_food_percent_change
** Description:generates the food percent change
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::generate_food_percent_change(){
	float value;
	value = rand()%50;
	value += 75;
	value = value / 100;
	
	//cout << "==DBG: foodval = " << value << endl;
	
	this->food_percent_change = value;
}

/*********************************************************************
** Function:buy_all_food
** Description:buys all required food to feed everyone
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Zoo::buy_all_food(){
	
	generate_food_percent_change();
	float current_base_cost = this->food_base_cost * this->food_percent_change;
	this->food_base_cost = current_base_cost; //update that thing
	
	cout << "\n\nFood Statistics:\nCost Base: " << this->food_base_cost << endl << "Change from Yesterday: " << this->food_percent_change << endl;;
		
	float individual = 0;
	float total = 0;
	
	for (int i = 0; i<this->len_sloths; ++i){
		individual = this->sloths[i].get_food_cost_multiplier() * current_base_cost;
		total += individual;
	}
	
	for (int i = 0; i<this->len_monkeys; ++i){
		individual = this->monkeys[i].get_food_cost_multiplier() * current_base_cost;
		total += individual;
	}
	
	for (int i = 0; i<this->len_sea_otters; ++i){
		individual = this->sea_otters[i].get_food_cost_multiplier() * current_base_cost;
		total += individual;
	}
	
	if (total > this->current_balance){
		
		return -1;
		
	}
	
	this->current_balance -= total;
	
	cout << "Total Food Costs Today: " << total << endl << endl << endl;
	
	return 1;
}

/*********************************************************************
** Function:sick_animal_event
** Description:runs the sick animal event
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Zoo::sick_animal_event(){
	
	//-1 if out of $
		
	int type = rand()%3+1;
	int animal = -1;
	int cost_to_heal;
	
	if (this->len_sloths == 0 && this->len_monkeys == 0 && this->len_sea_otters == 0){return -2;}
	
	switch (type) {
		
		case 1:
			
			//sloth will get sick...
			
			if (len_sloths == 0){return -1;}
			
			cout << "\n\nA Sick Animal Event Occurrs!" << endl;

			
			animal = rand()%this->len_sloths;
						
			cout << "--> Sloth " << animal << " is sick." << endl;
			cost_to_heal = this->sloths[animal].get_cost() / 2;
			if (this->sloths[animal].get_age() < 31){cost_to_heal *= 2;}
			cout<< "--> Required $ To Save: " << cost_to_heal << endl;
			if (cost_to_heal >= this->current_balance){
				cout << "R.I.P Sloth " << animal << endl;
				remove_sloth(animal);
			}
			else{
				cout << "You Saved It. Yeet!" << endl;
				this->current_balance -= cost_to_heal;
			}
			return 1;
			break;
			
		case 2:
			
			if (len_monkeys == 0){return -1;}
			
			cout << "\n\nA Sick Animal Event Occurrs!" << endl;

			
			//monkey will get sick...
			animal = rand()%this->len_monkeys;
						
			cout << "--> Monkey " << animal << " is sick." << endl;
			cost_to_heal = this->monkeys[animal].get_cost() / 2;
			if (this->monkeys[animal].get_age() < 31){cost_to_heal *= 2;}
			cout << "--> Required $ to save: " << cost_to_heal << endl;
			if (cost_to_heal >= this->current_balance){
				cout << "iT diEd..." << endl;
				remove_monkey(animal);
			}
			else{
				cout << "You Saved It. Yeet" << endl;
				this->current_balance -= cost_to_heal;
			}
			return 1;
			break;			
	
		case 3:
			
			if (len_sea_otters == 0){return -1;}
			
			cout << "\n\nA Sick Animal Event Occurrs!" << endl;

			
			//sea otter will get sick...
			animal = rand()%this->len_sea_otters;
						
			cout << "--> Sea Otter " << animal << " is sick." << endl;
			cost_to_heal = this->sea_otters[animal].get_cost() / 2;
			if (this->sea_otters[animal].get_age() < 31){cost_to_heal *= 2;}
			cout << "--> Required $ to save: " << cost_to_heal << endl;
			if (cost_to_heal >= this->current_balance){
				cout << "You Could not Save Your Precious Sea Otter :(" << endl;
				remove_sea_otter(animal);
			}
			else{
				cout << "You Saved It. Yeet" << endl;
				this->current_balance -= cost_to_heal;
			}
			return 1;
			break;
			
	}
}

/*********************************************************************
** Function:animal_birth_event
** Description:runs the animal birth event
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Zoo::animal_birth_event(){
	
	int type = rand()%3+1;
	int animal = -1;
	int is_adult = 0;
	
	int adult_sloths = 0;
	int adult_monkeys = 0;
	int adult_sea_otters = 0;
	
	Sloth tempsloth(0);
	Monkey tempmonkey(0);	
	SeaOtter tempseaotter(0);
	
	
	for (int i=0; i<len_sloths; ++i){if (this->sloths[i].is_adult()){ adult_sloths++;}}
	for (int i=0; i<len_monkeys; ++i){if (this->monkeys[i].is_adult()){ adult_monkeys++;}}
	for (int i=0; i<len_sea_otters; ++i){if (this->sea_otters[i].is_adult()){ adult_sea_otters++;}}
	
	if (adult_sloths == 0 && adult_monkeys == 0 && adult_sea_otters == 0){return -2;}
	
	
	switch (type) {
		
		case 1:
		
			if (adult_sloths == 0){return -1;}
			
			cout << "\n\nA Birthing Event Occurrs!" << endl;

			
			animal = rand()%this->len_sloths;
			is_adult = this->sloths[animal].is_adult();
			while (is_adult == 0){
				
				animal = rand()%this->len_sloths;
				is_adult = this->sloths[animal].is_adult();
				
			}
					
			cout << "--> Sloth " << animal << " had 3 babies!!" << endl;
			
			for (int baby = 0; baby < this->sloths[animal].get_baby_number(); ++baby){
				
				add_sloth(tempsloth);
				
			}			
			return 1;
			break;
			
		case 2:
			
			if (adult_monkeys == 0){return -1;}
			
			cout << "\n\nA Birthing Event Occurrs!" << endl;

			
			animal = rand()%this->len_monkeys;
			is_adult = this->monkeys[animal].is_adult();
			while (is_adult == 0){
				
				animal = rand()%this->len_monkeys;
				is_adult = this->monkeys[animal].is_adult();
				
			}
					
			cout << "--> Monkey " << animal << " had a baby!!" << endl;
			
			for (int baby = 0; baby < this->monkeys[animal].get_baby_number(); ++baby){
				
				add_monkey(tempmonkey);
				//cout << "Adding Temp Monkey" << endl;
				
			}			
			return 1;
			break;
	
		case 3:
			
			if (adult_sea_otters == 0){return -1;}
			
			cout << "\n\nA Birthing Event Occurrs!" << endl;

			
			animal = rand()%this->len_sea_otters;
			is_adult = this->sea_otters[animal].is_adult();
			while (is_adult == 0){
				
				animal = rand()%this->len_sea_otters;
				is_adult = this->sea_otters[animal].is_adult();
				
			}
					
			cout << "--> Sea Otter " << animal << " had two babies!!" << endl;
			
			for (int baby = 0; baby < this->sea_otters[animal].get_baby_number(); ++baby){
				
				add_sea_otter(tempseaotter);
				
			}			
			return 1;
			break;
			
	}
}	

/*********************************************************************
** Function:zoo_attendance_event
** Description:runs the zoo attendance event
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 

	
void Zoo::zoo_attendance_event(){
	
	cout << "\n\nZoo Attendance Event Occurrs!" << endl;
	int bonus = 0;
	int total = 0;
	
	for (int i = 0; i < len_monkeys; ++i){
		
		bonus = rand()%250 + 250;
		if (this->monkeys[i].get_age() < 31){bonus *= 2;}
		total += bonus;
		
	}
	
	cout << "People love seeing the monkeys. They generated an extra: " << total << " profit!" << endl;
	
	this->current_balance += total;	
}

/*********************************************************************
** Function:manage_special_events
** Description:manages all special events
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::manage_special_events(){
	
	int event_choice = rand()%4+1; //0..3+1
	int result = -1;
	
	//cout << "==DBG: Event Number Chosen: " << event_choice << endl;
	
	switch (event_choice){
		
		case 1:
			//cout << "CASE 1 CHOSEN" << endl;
			while (result == -1){
				result = sick_animal_event();
			}
			break;
			
		case 2:
			//cout << "CASE 2 CHOSEN" << endl;
			while (result == -1){
				result = animal_birth_event();
			}
			break;
			
		case 3:
			//cout << "CASE 3 CHOSEN" << endl;
			zoo_attendance_event();
			break;
			
		case 4:
			
			cout << "\n\nNo Event Takes Place This Turn!" << endl;
			break;
			
	}
}

/*********************************************************************
** Function:print_sloths
** Description:prints the sloth exhibit
** Parameters:
** Pre-Conditions:na
** Post-Conditions:prints all the sloths
*********************************************************************/ 


void Zoo::print_sloths(){
	for (int i=0; i<this->len_sloths; ++i){
		cout << "Sloth " << i << ", Age: " << this->sloths[i].get_age() <<endl;
	}
}

/*********************************************************************
** Function:print_monkeys
** Description:prints the monkey exhibit
** Parameters:
** Pre-Conditions:na
** Post-Conditions:prints the monkey exhibit
*********************************************************************/ 


void Zoo::print_monkeys(){
	for (int i=0; i<this->len_monkeys; ++i){
		cout << "Monkey " << i << "; Age: " << this->monkeys[i].get_age() <<endl;
	}
}

/*********************************************************************
** Function:print_sea_otters
** Description:prints the sea otter exhibit
** Parameters:
** Pre-Conditions:na
** Post-Conditions:prints sea otter exhibit
*********************************************************************/ 


void Zoo::print_sea_otters(){
	for (int i=0; i<this->len_sea_otters; ++i){
		cout << "Sea Otters " << i << "; Age: " << this->sea_otters[i].get_age() << endl;
	}
}

/*********************************************************************
** Function:clear_screen
** Description:uh... duh ...
** Parameters:
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Zoo::clear_screen(){
	
	for (int i = 0; i<100; ++i){
		
		cout << "\n";
		
	}
} 

/*********************************************************************
** Function:play_game
** Description:manages the gameplay
** Parameters:
** Pre-Conditions:na
** Post-Conditions:game dons
*********************************************************************/ 


void Zoo::play_game(){
	
	srand(time(NULL));
	int broke = 0;
	
	while (1){
		
		clear_screen();
		
		cout << "Sloth Exhibit\n-------------\n";
		print_sloths();
		cout << "\n";
		
		cout << "Monkey Exhibit\n--------------\n";
		print_monkeys();
		cout << "\n";
		
		cout << "Sea Otter Exhibit\n-----------------\n";
		print_sea_otters();
		cout << "\n";
		
		//cout << "==DBG: Print Statements Passed" << endl;
		
		cout << "\nCurrent Balance: " << this->current_balance;
		
		increase_all_ages();
		
		gather_all_revenue();			

		
		manage_special_events();
		//cout << "==DBG: increase all ages passed" << endl;
		
		broke = buy_all_food();
		//cout << "==DBG: buy all food passed" << endl;
				
		if (broke < 0){cout << "You ran out of money :(. Quitting!" << endl; return;}
		
		broke = buy_animals();
		if (broke == -2){return;}
		if (broke < 0){cout << "You ran out of money :(. Quitting!" << endl; return;}
		
						
	}
}



	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//yeet
	