#ifndef JJCALC_H
#define JJCALC_H

#include "JJparser.h"
#include <iostream>
#include <stack>



class JJcalc : private JJparser{
	private:
		int GetPriority(string Operator);
		string InToPost(string InfixExpression);

	public:
		double Calculate(string InfixExpression);

};


#endif
