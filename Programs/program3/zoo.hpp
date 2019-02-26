/*********************************************************************
** Program Filename:animal.hpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Header for Class Zoo
** Input:na
** Output:na
*********************************************************************/


#ifndef ZOO
#define ZOO

#include <iostream>
#include <cstdlib>
#include <string>

#include "animal.hpp"

#include "sloth.hpp"
#include "monkey.hpp"
#include "sea_otter.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Zoo {
	
	private:
	
		Sloth * sloths;
		Monkey * monkeys;
		SeaOtter * sea_otters;
		
		int len_sloths;
		int len_monkeys;
		int len_sea_otters;
		
		float current_balance;
		float food_base_cost;
		float food_percent_change;
		
	public:
		
		//Constructor and Destructor
		Zoo();
		~Zoo();
				
		//add and remove and manpiluate array
		void add_sloth(Sloth sloth_to_add);
		void add_monkey(Monkey monkey_to_add);
		void add_sea_otter(SeaOtter sea_otter_to_add);
		void remove_sloth(int index);
		void remove_monkey(int index);
		void remove_sea_otter(int index);
		
		//increase_all_ages
		void increase_all_ages();
		
		//buy new animals
		int get_user_input(int low, int high);
		int buy_animals();
		
		//food cost
		void generate_food_percent_change();
		int buy_all_food();
		
		void gather_all_revenue();
		
		//special events
		int sick_animal_event();
		int animal_birth_event();
		void zoo_attendance_event();
		void manage_special_events();
		
		//printout functions
		void print_sloths();
		void print_monkeys();
		void print_sea_otters();

		void clear_screen();
		
		void play_game();
		
};	

#endif