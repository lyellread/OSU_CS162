/*********************************************************************
** Program Filename:sea_otter.cpp
** Author:Lyell Read
** Date:2/18/2018
** Description:Sea Otter Class Code
** Input:na
** Output:na
*********************************************************************/


#include "sea_otter.hpp"

/*********************************************************************
** Function:SeaOtter
** Description:creates a newborn SeaOtter
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:created s.o. with age 0
*********************************************************************/ 


SeaOtter::SeaOtter () : Animal (0, 5000, 2, 2, 0.05) {}

/*********************************************************************
** Function:SeaOtter
** Description:creates s.o. with age age
** Parameters:age
** Pre-Conditions:na
** Post-Conditions:creates s.o. with age age
*********************************************************************/ 


SeaOtter::SeaOtter (int age) : Animal (age, 5000, 2, 2, 0.05) {}