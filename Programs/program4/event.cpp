

/*********************************************************************
** Program Filename:event.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:VIRTUAL Declarations for the class event
** Input:None
** Output:Text-Based
*********************************************************************/


#include <iostream>
#include "event.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Function:event
** Description:event constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:event created
*********************************************************************/ 

Event::Event(int param) : type(param) {}