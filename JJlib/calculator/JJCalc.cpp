#include "JJCalc.h"

/*
class JJcalc : public JJparser{
	private:
		bool IsNumber(string Cipher);
		int GetPriority(string Operator, bool InStack);
		vector<string> ParseExpression(Expression);
		bool InToPost(string InfixExpression, string PostfixExpression);

	public:
		double Calculate(string InfixExpression);

};
*/

int JJcalc::GetPriority(string Operator){
	if (Operator.compare(")") == 0){
		return 5;
	}

	if (Operator.compare("(") ==0){
		return 4;
	}

	if (Operator.compare("*") == 0 || Operator.compare("/")==0){
		return 3;
	}

	if (Operator.compare("+") == 0 || Operator.compare("-")==0){
		return 2;
	}

	return 0;
}


string JJcalc::InToPost(string InfixExpression){
	vector<string> expression = this->parseMathExpression(InfixExpression);
	string PostfixExpression;
	stack<string> st;
	for(string i : expression){
		//operand case
		//append numbers
		//cout << "i : " << i << endl;
		if(GetPriority(i) == 0){
			PostfixExpression.append(i);	
			PostfixExpression.append(" ");	
		//operaotr case
		//push to stack priority
		}else if(0< GetPriority(i) && GetPriority(i) < 5){
			if(st.empty()){
				st.push(i);
			}else {
				int instack = GetPriority(st.top());
				if(instack == 4){
					instack = 0;
				}
				int tok = GetPriority(i);
				if(instack >tok ){
					PostfixExpression.append(st.top());
					PostfixExpression.append(" ");	
					st.pop();
				}else {
					st.push(i);
				}
			}
		//operator ) case
		//pop and append until  )
		}else {
			while(!st.empty()){
				if(GetPriority(st.top()) == 4){
					st.pop();
					break;
				}else {
					PostfixExpression.append(st.top());
					PostfixExpression.append(" ");	
					st.pop();
				}
			}
		}
	}
	
	//append least
	while(!st.empty()){
		PostfixExpression.append(st.top());
		PostfixExpression.append(" ");	
		st.pop();
	}

	return PostfixExpression;
}

double JJcalc::Calculate(string InfixExpression){
	double ret;
	cout << "input : " << InfixExpression << endl;
	string post = InToPost(InfixExpression);
	cout << "convert : " << post << endl;
	
	stack<double> operand;
	vector<string> expression = this->parseMathExpression(post);
	for(string i : expression){
		//cout << "[" << i << "]" << endl;
		if(this->IsNumber(i[0])){
			operand.push(stod(i));
		}else {
			double one = operand.top();
			operand.pop();
			double two = operand.top();
			operand.pop();

			double imsi;
			if(i[0] == '+'){
				imsi = two + one;
			} else if(i[0] == '-'){
				imsi = two - one;
			} else if(i[0] == '*'){
				imsi = two * one;
			} else if(i[0] == '/'){
				imsi = two / one;
			}

			operand.push(imsi);
		}
	}

	ret = operand.top();
	operand.pop();

	return ret;
}
