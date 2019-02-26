/*********************************************************************
** Program Filename:monkey.cpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Monkey Class Code
** Input:na
** Output:na
*********************************************************************/

#include "monkey.hpp"

/*********************************************************************
** Function:Monkey
** Description:makes a baby monkey
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:baby monkey created
*********************************************************************/ 


Monkey::Monkey () : Animal (0, 15000, 1, 4, 0.1) {}

/*********************************************************************
** Function:Monkey
** Description:creates monkey with age age
** Parameters:age
** Pre-Conditions:na
** Post-Conditions:creates a monkey with age age
*********************************************************************/ 


Monkey::Monkey (int age) : Animal (age, 15000, 1, 4, 0.1) {}
