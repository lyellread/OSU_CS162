/*********************************************************************
** Program Filename:animal.cpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Animal (parent) class code
** Input:na
** Output:na
*********************************************************************/


#include "animal.hpp"


/*********************************************************************
** Function:Animal
** Description:Constructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 

Animal::Animal(){
	
	//cout << "Animal Constructor Called. Nothing will happen." << endl;
	
}

/*********************************************************************
** Function:Animal
** Description:Overloaded Constructor
** Parameters:int age, int cost, int babies, int food_cost_multiplier, float revenue_percentage
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


Animal::Animal(int age, int cost, int babies, int food_cost_multiplier, float revenue_percentage) : age(age), cost(cost), babies(babies), food_cost_multiplier(food_cost_multiplier), revenue_percentage(revenue_percentage){
	
	//cout << "Animal Overloaded Constructor Called" << " BEPIS: " << babies << endl;
	
}

/*********************************************************************
** Function:~Animal
** Description:Destructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


Animal::~Animal(){
	
	//cout << "Animal Destructor Called" << endl;
	
}

/*********************************************************************
** Function:get_age
** Description:get age
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Animal::get_age (){return this->age;}

/*********************************************************************
** Function:get_cost
** Description:get cost
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Animal::get_cost (){return this->cost;}

/*********************************************************************
** Function:get_baby_number
** Description:get baby count per birth
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Animal::get_baby_number (){return this->babies;}

/*********************************************************************
** Function:get_food_cost_multiplier
** Description:^
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


float Animal::get_food_cost_multiplier () {return this->food_cost_multiplier;}

/*********************************************************************
** Function:get_revenue
** Description:gets revenue
** Parameters:na
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Animal::get_revenue() {return this->revenue_percentage * this->cost;}	

/*********************************************************************
** Function:set_age
** Description:set the age
** Parameters:ing age
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void Animal::set_age(int age) {this->age = age;}

/*********************************************************************
** Function:is_adult
** Description:^
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Animal::is_adult(){
	
	if (this->age >=1094) {
		return 1;
	}
	return 0;
}

/*********************************************************************
** Function:increase_age
** Description:^
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int Animal::increase_age() {
	
	++this->age;
	return this->age;
	
}