#include "Calculator.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.'};

int IsNumber(char Cipher){
	int i = 0;
	int ArrayLength = sizeof(NUMBER);

	for(i=0; i<ArrayLength; i++){
		if(Cipher == NUMBER[i])
			return 1;
	}
	return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE){
	unsigned int i = 0;

	for(i = 0; 0!= Expression[i] ; i++){
		Token[i] = Expression[i];
		
		if(IsNumber(Expression[i]) == 1){
			*TYPE = OPERAND;
			if(IsNumber(Expression[i+1]) != 1){
				break;
			}
		}else{
			*TYPE = Expression[i];
			break;
		}
	}

	Token[++i] = '\0';
	return i;
}

int GetPriority(char Operator, int InStack){
	int Priority = -1;

	switch(Operator){
		case LEFT_PARENTHESIS:
			if (InStack){
				Priority = 3;
			}else{
				Priority = 0;
			}
			break;

		case MULTIPLY:
		case DIVIDE:
			Priority = 1;
			break;

		case PLUS:
		case MINUS:
			Priority = 2;
			break;
	}
	return Priority;
}


int IsPrior(char OperatorInStack, char OperatorInToken){
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression){
	LinkedListStack* Stack;

	char Token[32];
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	LLS_CreateStack(&Stack);

	while(Position < Length){
		//splice next token
		Position+= GetNextToken(&InfixExpression[Position], Token, &Type);
		
		//copy operand token in infixexpression
		if(Type == OPERAND){
			strcat(PostfixExpression, Token);
			strcat(PostfixExpression, " ");

		//handle () 
		}else if (Type == RIGHT_PARENTHESIS){
			//find left_parenthesis in stack
			while( !LLS_IsEmpty(Stack)){
				Node* Popped = LLS_Pop(Stack);
				
				//stop searching 
				if(Popped ->Data[0] == LEFT_PARENTHESIS){
					LLS_DestroyNode(Popped);
					break;
				}else{
					//move toekn to postfix expression 
					strcat(PostfixExpression, Popped->Data);
					LLS_DestroyNode(Popped);
				}
			}

		//handle +-*/ 
		}else {
			//if operator at top is prior than token, copy it to post expression
			Node* Top = LLS_Top(Stack);
			if(Top != NULL){
				while(!IsPrior(Top->Data[0],Token[0]) ){
					Node* Popped = LLS_Pop(Stack);

					if(Popped->Data[0] != LEFT_PARENTHESIS){
						strcat(PostfixExpression, Popped->Data);
					}

					LLS_DestroyNode(Popped);
					if(LLS_IsEmpty(Stack)){
						break;
					}
				}
			}
			//push operator to stack for ordering priority
			LLS_Push(Stack, LLS_CreateNode(Token));
		}
	}
	
	//add remaining operator to post expression
	while(!LLS_IsEmpty(Stack)){
		Node* Popped = LLS_Pop(Stack);
		
		if(Popped->Data[0] != LEFT_PARENTHESIS){
			strcat(PostfixExpression, Popped->Data);
		}
		LLS_DestroyNode(Popped);
	}
	LLS_DestroyStack(Stack);
}


double Calculate(char* PostfixExpression){
	LinkedListStack* Stack;
	Node* ResultNode;

	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	LLS_CreateStack(&Stack);
	
	while(Read<Length){
		//check next token
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

		if(Type == SPACE){
			continue;
		}
		
		//if token is number ,push it to stack
		if(Type == OPERAND){
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode);

		//if token is operator, pop numbers(operand1,2) from stack and operate
		}else{
			char ResultString[32];
			double Operator1, Operator2, TempResult;
			Node* OperatorNode;
			
			OperatorNode = LLS_Pop(Stack);
			Operator2 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			OperatorNode = LLS_Pop(Stack);
			Operator1 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);
			
			switch(Type){
				case PLUS:
					TempResult = Operator1 + Operator2;
					break;
				case MINUS:
					TempResult = Operator1 - Operator2;
					break;
				case MULTIPLY:
					TempResult = Operator1 * Operator2;
					break;
				case DIVIDE:
					if(Operator2 == 0){
						printf("devide by 0 error\n");
						LLS_DestroyStack(Stack);
						return -1;
					}
					TempResult = Operator1 / Operator2;
					break;
			}

			gcvt(TempResult, 10, ResultString);
			printf("Result string: %s\n", ResultString);
			LLS_Push(Stack, LLS_CreateNode(ResultString));
		}
	}
	printf("current stack count : %d \n",LLS_GetSize(Stack));

	ResultNode = LLS_Pop(Stack);
	printf("current stack count : %d \n",LLS_GetSize(Stack));
	Result = atof(ResultNode->Data);
	LLS_DestroyNode(ResultNode);
	LLS_DestroyStack(Stack);

	return Result;

}

