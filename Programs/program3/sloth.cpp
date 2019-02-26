/*********************************************************************
** Program Filename:sloth.cpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Sloth Class Code
** Input:na
** Output:na
*********************************************************************/


#include "sloth.hpp"

/*********************************************************************
** Function:Sloth
** Description:constructor for new birth
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:sloth with age 0 created
*********************************************************************/ 


Sloth::Sloth () : Animal (0, 2000, 3, 1, 0.05) {}

/*********************************************************************
** Function:Sloth
** Description:constructor for purchase
** Parameters:age
** Pre-Conditions:na
** Post-Conditions:creates a sloth with age 3
*********************************************************************/ 


Sloth::Sloth (int age) : Animal (age, 2000, 3, 1, 0.05) {}