/*********************************************************************
** Program Filename:program1.hpp
** Author:Lyell Read
** Date:1/17/2018
** Description:This is one part of a program that interactively displays economic data to the user. This part contains all function defenitions and the libraries. This is the header file for the project.
** Input:User input, File input
** Output:Text based output about economic data.
*********************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

//==========================================================================================
//STRUCTURES DEFINED (PER ASSIGNMENT DESCRIPTION)
//==========================================================================================

/*********************************************************************
** Structure:county
** Description:County struct contains the data for one county. It is part of an array of counties.
*********************************************************************/ 

struct county {
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
};

/*********************************************************************
** Structure:state
** Description:contains the data for a state, as well as the number of counties and a pointer to an array of counties for that state.
*********************************************************************/ 

struct state {
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  struct county* county_array;
  int county_count;
};

//==========================================================================================
//FILE READ, MEM (CREATE|DESTROY) FUNCTIONS
//==========================================================================================

struct state * allocate_states(int state_count);
struct county * allocate_county(int county_count);
void read_county_data(struct county * county_array, int county_count, ifstream &is);
void read_state_data(struct state * state_array, int state_count, ifstream &is);
void free_state_county_data (struct state * state_array, int state_count);

//==========================================================================================
//USER IO FUNCTION (PRINTOUT, DEBUG, INPUT CHECKING ...)
//==========================================================================================

void print_all(struct state * state_array, int state_count);
void parameter_check (int argc, char ** argv);
int s_to_i (string input);
int input_on_range (int acceptable_min, int acceptable_max);

//==========================================================================================
//DATA CALC FUNCTIONS AND PRINTOUT FUNCTIONS
//==========================================================================================

void household_income_state (struct state * state_array, int state_count);
void household_income_county (struct county * county_array, int county_count);
void unemployment_state (struct state * state_array, int state_count);
void unemployment_county (struct county * county_array, int county_count);
void print_unemployment_deltas_state (struct state * state_array, int state_count);
bool compare_unemployment_deltas_state (state s1, state s2);
void unemployment_deltas_state (struct state * state_array, int state_count);
void print_unemployment_deltas_county (struct county * county_array, int county_count);
bool compare_unemployment_deltas_county (county c1, county c2);
void unemployment_deltas_county (struct county * county_array, int county_count);
void print_median_income_state (struct state * state_array, int state_count);
bool compare_median_income_state (state s1, state s2);
void median_income_state (struct state * state_array, int state_count);
void print_median_income_county (struct county * county_array, int county_count);
bool compare_median_income_county (county c1, county c2);
void median_income_county (struct county * county_array, int county_count);

//==========================================================================================
//PARENT FUNCTINS AND MENUS FOR DATA PRINTOUT
//==========================================================================================

void print_data_state (struct state * state_array, int state_count);
void print_data_county (struct state * state_array, int state_count, int choice);
void menu_2 (struct state * state_array, int state_count);
void menu_1 (struct state * state_array, int state_count);