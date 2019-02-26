/*********************************************************************
** Program Filename:animal.hpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Header for Class Animal
** Input:na
** Output:na
*********************************************************************/


#ifndef ANIMAL
#define ANIMAL

#include <iostream>

using std::cout;
using std::endl;

class Animal {
	
	private:
		
		int age;
		float cost;
		int babies;
		float food_cost_multiplier;
		float revenue_percentage;
		
	public:
	
		Animal();
		Animal(int age, int cost, int babies, int food_cost_multiplier, float revenue_percentage);
		~Animal();
		
		int get_age ();
		int get_cost ();
		int get_baby_number ();
		float get_food_cost_multiplier();
		int get_revenue();
		int is_adult();
		
		void set_age(int age);
		int increase_age();
};

#endif