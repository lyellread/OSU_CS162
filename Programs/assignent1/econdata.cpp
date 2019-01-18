/*********************************************************************
** Program Filename:program1.cpp
** Author:Lyell Read
** Date:1/17/2018
** Description:This is one part of a program that interactively displays economic data to the user. This part contains all functions called except main.
** Input:User input, File input
** Output:Text based output about economic data.
*********************************************************************/

#include "econdata.hpp"

//==========================================================================================
//FILE READ, MEM (CREATE|DESTROY) FUNCTIONS
//==========================================================================================

/*********************************************************************
** Function:allocate_states
** Description:Allocate a dynamic array of type struct state, of size state_count
** Parameters:int state_count
** Pre-Conditions:args provided
** Post-Conditions:dynamic array created
*********************************************************************/ 

struct state * allocate_states(int state_count){
	
		state * state_array = new state[state_count];
		
		return state_array;
}

/*********************************************************************
** Function:allocate_county
** Description:Allocate a dynamic array of type struct county, of size county_count
** Parameters:int county_count
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

struct county * allocate_county(int county_count){
	
		county * county_array = new county[county_count];
		
		return county_array;
}

/*********************************************************************
** Function:read_county_data
** Description:read data from the counties in the input file and move them into the struct array createsd above
** Parameters:struct county * county_array, int county_count, ifstream &is
** Pre-Conditions:unpopulated array
** Post-Conditions:array of structs for counties is now populated with values!
*********************************************************************/ 

void read_county_data(struct county * county_array, int county_count, ifstream &is){
	
	for (int county_number=0; county_number < county_count; ++county_number){
		is >> county_array[county_number].name;
		is >> county_array[county_number].unemployed_2007;
		is >> county_array[county_number].unemployed_2015;
		is >> county_array[county_number].med_income;
	}
		
}

/*********************************************************************
** Function:read_state_data
** Description:reads state data from file into the struct array
** Parameters:struct state * state_array, int state_count, ifstream &is
** Pre-Conditions:empty struct array
** Post-Conditions:state struct array has been populated with information from the file
*********************************************************************/ 

void read_state_data(struct state * state_array, int state_count, ifstream &is){
	
	for (int state_number=0; state_number < state_count; ++state_number){
		is >> state_array[state_number].name;
		is >> state_array[state_number].unemployed_2007;
		is >> state_array[state_number].unemployed_2015;
		is >> state_array[state_number].med_income;
		is >> state_array[state_number].county_count;
		
		state_array[state_number].county_array = allocate_county(state_array[state_number].county_count);
		read_county_data(state_array[state_number].county_array, state_array[state_number].county_count, is);
		
	}
}

/*********************************************************************
** Function:free_state_county_data
** Description:free dat memory boi
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:memory is occupied by nested arrays of counties in an array of state structs. 
** Post-Conditions:no memory is taken up (dyn)
*********************************************************************/ 

void free_state_county_data (struct state * state_array, int state_count){
	for (int state_number=0; state_number < state_count; ++state_number){
		//Iterate for each state
		delete[] state_array[state_number].county_array;
	}
	
	//now all that is left is an array of state structs...
	delete[] state_array;
	
}

//==========================================================================================
//USER IO FUNCTION (PRINTOUT, DEBUG, INPUT CHECKING ...)
//==========================================================================================

/*********************************************************************
** Function:print_all
** Description:DEBUG FXN - print everything that is in the states and counties struct arrays
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:nothing printed
** Post-Conditions:full printout
*********************************************************************/ 

void print_all(struct state * state_array, int state_count){

	for (int state_number=0; state_number < state_count; ++state_number){
			cout << "Name: " << state_array[state_number].name << "\n";
			cout << "Unemployed in 2007: " << state_array[state_number].unemployed_2007 << "\n";
			cout << "Unemployed in 2015: " << state_array[state_number].unemployed_2015 << "\n";
			cout << "Median Income: " << state_array[state_number].med_income << "\n";
			cout << "Counties: " << state_array[state_number].county_count << "\n";
						
			for (int county_number=0; county_number < state_array[state_number].county_count; ++county_number){
				cout << "Name: " << state_array[state_number].county_array[county_number].name << "\n";
				cout << "Unemployed in 2007: " << state_array[state_number].county_array[county_number].unemployed_2007 << "\n";
				cout << "Unemployed in 2015: " << state_array[state_number].county_array[county_number].unemployed_2015 << "\n";
				cout << "Median Income: " << state_array[state_number].county_array[county_number].med_income << "\n";
			}
		}		
}

/*********************************************************************
** Function:parameter_check
** Description:check params are as of expected length
** Parameters:int argc, char ** argv
** Pre-Conditions:unsure about what is being passed as arguments.
** Post-Conditions:sure about length being correct.
*********************************************************************/ 

void parameter_check (int argc, char ** argv){
	if (argc != 2){
		cout << "ARGUMENT NUMBER NOT MET. QUITTING!" << endl;
		exit(EXIT_FAILURE);
	}
}

/*********************************************************************
** Function:s_to_i
** Description:string to int, self made :)
** Parameters:string input
** Pre-Conditions:string inputted
** Post-Conditions:int outputted
*********************************************************************/ 

int s_to_i (string input){
	int output=0;
	for (int str_index=0; str_index < input.length(); str_index++){

		int multiplier = input.length()-(str_index+1);
		int working_digit = int(input[str_index])-48;

		for (int iterator=0; iterator < multiplier; iterator++){
			working_digit*=10;
		}//this works by usign ones, tens, hundreds...

		output+=working_digit;
	}
	return output;
}

/*********************************************************************
** Function:input_on_range
** Description:forces input to be on range min..max
** Parameters:int acceptable_min, int acceptable_max
** Pre-Conditions:called
** Post-Conditions:input is returned
*********************************************************************/ 

int input_on_range (int acceptable_min, int acceptable_max){

	string input;
    int return_value;
	bool negative=false;

	getline(cin, input);
	int len = input.length();

	//check for length 0 (blank)
	if (len == 0){
		//for loop would not trigger as len = 0, and stoi would dump core :(
		cout << "Length was 0. Please re-enter!:";
		return input_on_range(acceptable_min, acceptable_max);
	}

	//check that each character is an int
	for (int i=0; i< len;i++){
    if (int(input[i]) < 48 || int(input[i]) > 57){
    	cout << "Invalid Character Found, Re-Enter:";
			return input_on_range(acceptable_min, acceptable_max);
		}
  }

	return_value = s_to_i(input);

	if (return_value <= acceptable_max && return_value >= acceptable_min){
		return return_value;
	}
	//its not in range :(
	else{
		cout << "Invalid. Again:";
		return input_on_range(acceptable_min, acceptable_max);
		//recursively call this again on and on...
	}
}

//==========================================================================================
//DATA CALC FUNCTIONS AND PRINTOUT FUNCTIONS
//==========================================================================================

/*********************************************************************
** Function:household_income_state
** Description:hi&lo state income, with personal min/max alg
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:nothing printed
** Post-Conditions:max and min state incomes printed
*********************************************************************/ 

void household_income_state (struct state * state_array, int state_count){
	int min = state_array[0].med_income;
	int min_index = 0;
	
	int max = state_array[0].med_income;
	int max_index = 0;
	
	for (int i=1; i<state_count; ++i){
		if (state_array[i].med_income > max){
			max=state_array[i].med_income;
			max_index = i;
		}
	}
	cout << "Max and min median income is as follows:" << endl;
	cout << " + The Highest Median Income is from " << state_array[max_index].name << ", at $" << max << endl;

	for (int i=1; i<state_count; ++i){
		if (state_array[i].med_income < min){
			min=state_array[i].med_income;
			min_index = i;
		}
	}

	cout << " + The Smallest Median Income is from " << state_array[min_index].name << ", at $" << min << "\n\n" << endl;
}

/*********************************************************************
** Function:household_income_county
** Description:hi&lo county incomes printout
** Parameters:struct county * county_array, int county_count
** Pre-Conditions:nothing printed
** Post-Conditions:hi&lo data is printed out
*********************************************************************/ 

void household_income_county (struct county * county_array, int county_count){
	int min = county_array[0].med_income;
	int min_index = 0;
	
	int max = county_array[0].med_income;
	int max_index = 0;
	
	for (int i=1; i<county_count; ++i){
		if (county_array[i].med_income > max){
			max=county_array[i].med_income;
			max_index = i;
		}
	}
	cout << "Max and min median income is as follows:" << endl;

	cout << " + The Highest Median Income is from " << county_array[max_index].name << ", at $" << max << endl;

	for (int i=1; i<county_count; ++i){
		if (county_array[i].med_income < min){
			min=county_array[i].med_income;
			min_index = i;
		}
	}
	cout << " + The Smallest Median Income is from " << county_array[min_index].name << ", at $" << min << "\n\n" << endl;
}

/*********************************************************************
** Function:unemployment_state
** Description:print hi&lo unemployment for the states array
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:nothing printed
** Post-Conditions:printout of high and low unemployment across all states.
*********************************************************************/ 

void unemployment_state (struct state * state_array, int state_count){
	float min = state_array[0].unemployed_2015;
	int min_index = 0;
	
	float max = state_array[0].unemployed_2015;
	int max_index = 0;
	
	for (int i=1; i<state_count; ++i){
		if (state_array[i].unemployed_2015 > max){
			max=state_array[i].unemployed_2015;
			max_index = i;
		}
	}
	cout << "Max and min unemployment rates are as follows:" << endl;

	cout << " + The Highest Unemployment Rate is from " << state_array[max_index].name << ", at " << max << "%" << endl;

	for (int i=1; i<state_count; ++i){
		if (state_array[i].unemployed_2015 < min){
			min=state_array[i].unemployed_2015;
			min_index = i;
		}
	}

	cout << " + The Lowest Unemployment Rate is from " << state_array[min_index].name << ", at " << min << "%\n\n" << endl;
}

/*********************************************************************
** Function:unemployment_county
** Description:hi and lo unemployment found from all counties in a state
** Parameters:struct county * county_array, int county_count
** Pre-Conditions:nothing printed
** Post-Conditions:hi and lo printed.
*********************************************************************/ 

void unemployment_county (struct county * county_array, int county_count){
	float min = county_array[0].unemployed_2015;
	int min_index = 0;
	
	float max = county_array[0].unemployed_2015;
	int max_index = 0;
	
	for (int i=1; i<county_count; ++i){
		if (county_array[i].unemployed_2015 > max){
			max=county_array[i].unemployed_2015;
			max_index = i;
		}
	}
	cout << "Max and min unemployment rates are as follows:" << endl;

	cout << " + The Highest Unemployment Rate is from " << county_array[max_index].name << ", at " << max << "%" << endl;

	for (int i=1; i<county_count; ++i){
		if (county_array[i].unemployed_2015 < min){
			min=county_array[i].unemployed_2015;
			min_index = i;
		}
	}
	cout << " + The Lowest Unemployment Rate is from " << county_array[min_index].name << ", at " << min << "%\n\nPress any key to continue . . ." << endl;
	getchar();
}

/*********************************************************************
** Function:print_unemployment_deltas_state
** Description:prints the text for the unemployment deltas of all states.
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:sorted array of states by delta unemployment
** Post-Conditions:printed data to screen
*********************************************************************/ 

void print_unemployment_deltas_state (struct state * state_array, int state_count){
	cout << "Deltas between 2007 and 2015 unemployment, sorted, are as follows:" << endl;
	for (int i=0; i<state_count; ++i){
		cout << " + " << state_array[i].name 
		<< " state went from " << state_array[i].unemployed_2007 
		<< "% in 2007 to " << state_array[i].unemployed_2015 
		<< "% in 2015. That is a change of " << (state_array[i].unemployed_2015-state_array[i].unemployed_2007) 
		<< "%." << endl;
	}
}

/*********************************************************************
** Function:compare_unemployment_deltas_state
** Description:compare function to facilitate the work of the sort fxn
** Parameters:state s1, state s2
** Pre-Conditions:two elements entered
** Post-Conditions:bool returned if a<b.
*********************************************************************/ 

bool compare_unemployment_deltas_state (state s1, state s2){
	return ( (s1.unemployed_2015 - s1.unemployed_2007) < (s2.unemployed_2015 - s2.unemployed_2007) );
}

/*********************************************************************
** Function:unemployment_deltas_state
** Description:sort then print the unemp. deltas, of all states
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:called
** Post-Conditions:unemployment deltas are printed to screen
*********************************************************************/ 

void unemployment_deltas_state (struct state * state_array, int state_count) {
	sort(state_array, state_array + state_count, compare_unemployment_deltas_state);
	print_unemployment_deltas_state (state_array, state_count);
}

/*********************************************************************
** Function:print_unemployment_deltas_county
** Description:prints the unemployment deltas for all counties
** Parameters:struct county * county_array, int county_count
** Pre-Conditions:sorted array of counties
** Post-Conditions:printout on screen
*********************************************************************/ 

void print_unemployment_deltas_county (struct county * county_array, int county_count){
	cout << "Deltas between 2007 and 2015 unemployment, sorted, are as follows:" << endl;
	for (int i=0; i<county_count; ++i){
		cout << " + " << county_array[i].name 
		<< " county went from " << county_array[i].unemployed_2007 
		<< "% in 2007 to " << county_array[i].unemployed_2015 
		<< "% in 2015. That is a change of " << (county_array[i].unemployed_2015-county_array[i].unemployed_2007) 
		<< "%." << endl;
	}
	
	cout << "\nPress any key to continue . . ." << endl;
	getchar();
}

/*********************************************************************
** Function:compare_unemployment_deltas_county
** Description:compare for sort
** Parameters:county c1, county c2
** Pre-Conditions:two elements provided
** Post-Conditions:bool if a<b
*********************************************************************/ 

bool compare_unemployment_deltas_county (county c1, county c2){
	return ( (c1.unemployed_2015 - c1.unemployed_2007) < (c2.unemployed_2015 - c2.unemployed_2007) );
}

/*********************************************************************
** Function:unemployment_deltas_county
** Description:manage the process of printing unem. deltas for all counties.
** Parameters:struct county * county_array, int county_count
** Pre-Conditions:called
** Post-Conditions:printout of deltas printed
*********************************************************************/ 

void unemployment_deltas_county (struct county * county_array, int county_count) {
	sort(county_array, county_array + county_count, compare_unemployment_deltas_county);
	print_unemployment_deltas_county (county_array, county_count);
}

/*********************************************************************
** Function:print_median_income_state
** Description:print median income values for all states
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:sorted list of states by income
** Post-Conditions:printout
*********************************************************************/ 

void print_median_income_state (struct state * state_array, int state_count){
	cout << "\n\nStates sorted by median income below:" << endl;
	for (int i=0; i<state_count; ++i){
		cout << " + " << state_array[i].name 
		<< " state has median income $" << state_array[i].med_income
		<< "." << endl;
	}
}

/*********************************************************************
** Function:compare_median_income_state
** Description:assist fxn to sort
** Parameters:state s1, state s2
** Pre-Conditions:two elements passed
** Post-Conditions:bool if a>b
*********************************************************************/ 

bool compare_median_income_state (state s1, state s2){
	return (s1.med_income > s2.med_income);
}

/*********************************************************************
** Function:median_income_state
** Description:manage the process of printing sorted income data to screen
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:called
** Post-Conditions:printout appears lol
*********************************************************************/ 

void median_income_state (struct state * state_array, int state_count) {
	sort(state_array, state_array + state_count, compare_median_income_state);
	print_median_income_state (state_array, state_count);
}

/*********************************************************************
** Function:print_median_income_county
** Description:print all counties by median income
** Parameters:struct county * county_array, int county_count
** Pre-Conditions:sorted array of counties by med income
** Post-Conditions:printout
*********************************************************************/ 

void print_median_income_county (struct county * county_array, int county_count){
	cout << "\n\nCounties sorted by median income below:" << endl;
	for (int i=0; i<county_count; ++i){
		cout << " + " << county_array[i].name 
		<< " county has median income $" << county_array[i].med_income
		<< "." << endl;
	}
}

/*********************************************************************
** Function:compare_median_income_county
** Description:compare is an assist to the sort function
** Parameters:county c1, county c2
** Pre-Conditions:two elements passed
** Post-Conditions:bool if a>b
*********************************************************************/ 

bool compare_median_income_county (county c1, county c2){
	return (c1.med_income > c2.med_income);
}

/*********************************************************************
** Function:median_income_county
** Description:manage the process of printing all counties by med income
** Parameters:struct county * county_array, int county_count
** Pre-Conditions:called
** Post-Conditions:printout
*********************************************************************/ 

void median_income_county (struct county * county_array, int county_count) {
	sort(county_array, county_array + county_count, compare_median_income_county);
	print_median_income_county (county_array, county_count);
}

//==========================================================================================
//PARENT FUNCTINS AND MENUS FOR DATA PRINTOUT
//==========================================================================================

/*********************************************************************
** Function:print_data_state
** Description:manage the printout of all state data
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:called
** Post-Conditions:all state fxns are called in order
*********************************************************************/ 

void print_data_state (struct state * state_array, int state_count){
	household_income_state (state_array, state_count);
	unemployment_state (state_array, state_count);
	unemployment_deltas_state (state_array, state_count);
	median_income_state (state_array, state_count);
	
	//menu_1(state_array, state_count);
}

/*********************************************************************
** Function:print_data_county
** Description:manage the printout of county data
** Parameters:struct state * state_array, int state_count, int choice
** Pre-Conditions:called
** Post-Conditions:all county functions are called in order
*********************************************************************/ 

void print_data_county (struct state * state_array, int state_count, int choice){
	household_income_county (state_array[choice].county_array, state_array[choice].county_count);
	unemployment_county (state_array[choice].county_array, state_array[choice].county_count);
	unemployment_deltas_county (state_array[choice].county_array, state_array[choice].county_count);
	median_income_county (state_array[choice].county_array, state_array[choice].county_count);
	
	//menu_1(state_array, state_count);
}

/*********************************************************************
** Function:menu_2
** Description:pick a state menu
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:called
** Post-Conditions:state chosen.
*********************************************************************/ 

void menu_2 (struct state * state_array, int state_count){
	
	cout << "\nStates Available:" << "\n=================\n";
	
	for (int i=0; i<state_count; ++i){
		
		cout << i+1 << ") " << state_array[i].name << endl;
	
	}
	int choice;
	cout << "\n\nChoice :";

	choice=input_on_range(1, state_count)-1;
	print_data_county (state_array, state_count, choice);
}

/*********************************************************************
** Function:menu_1
** Description:main menu - pick what to do
** Parameters:struct state * state_array, int state_count
** Pre-Conditions:unsure what to do
** Post-Conditions:directs the program, either to quit or display some data
*********************************************************************/ 

void menu_1 (struct state * state_array, int state_count){
	
		
		cout << "\n\n\nData Explorer 1.0: Please pick from options below:"
			<< "\n=================================================="
			<< "\n1) Display General State Data"
			<< "\n2) Display Data For Counties of a Specific State"
			<< "\n3) Exit\n\nChoice :";
		int choice;
		
		choice = input_on_range (1,3);
		
		cout << "\n\n\n";
		
		if (choice == 1){
			print_data_state (state_array, state_count);
			menu_1(state_array, state_count);
		}
		if (choice == 2){
			menu_2(state_array, state_count);
			menu_1(state_array, state_count);
		}
		else {
			/*
			free_state_county_data(state_array, state_count);
			cout << "====DBG: Past free" << endl;
			exit(EXIT_SUCCESS);
			*/
			return;
		}

}


