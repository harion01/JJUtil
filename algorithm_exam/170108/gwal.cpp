#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100
using namespace std;
typedef struct data{
	int num;
	char ch;
};


class stack{
	public :
		stack(){
			index =0;
			dummy.num = -1;
			dummy.ch = 0x00;
			for(int cnt=0; cnt<MAXSIZE+1; cnt++){
				list[cnt] = dummy;
			}
		}

		struct data checktop(){
			return list[index];
		}

		int istopnum(){
			if(list[index].num >0){
				return list[index].num;
			}
			return -1;
		}

		int push(struct data arg){
			if(index == MAXSIZE){
				cout << "stack.push : stack is full! \n";
				return -1;
			}
			index++;	
			list[index] = arg;
			return 0;
		}

		struct data pop(){
			struct data ret;
			ret = list[index];
			list[index] = dummy;
			index--;
			return ret;
		}

	private :
		int index;
		struct data dummy;
		struct data list[MAXSIZE];
};

class gwal{
	public:
		gwal(){
		}

		int checkvalid(char* str){
			
			return 0;
		}
		
		int calcgwal(char* origin, int size){
			char str[100];
			memset(str,0x00,sizeof(str));
			strncpy(str, origin, size);
			int ret = 0;
			struct data finaldata;
			for(int pos = 0; pos < size; pos++){
				if(checkgwal(str[pos])<0){
					cout << "checkgwal fail\n";
					return -1;
				}
				origin++;
			}
			finaldata = strstack.pop();
			ret = finaldata.num;
			return ret;
		}

	private:
		stack strstack;
		stack imsistack;

		int checkgwal(char ch){
			cout << "checkgwal arg is [" << ch << "]\n";
			struct data checked;
			if(ch == ')'){
				checked.ch = 0x00;
				checked.num = stackcheck(ch);
				if(checked.num <0){
					return -1;
				}
			}else if (ch == ']'){
				checked.ch = 0x00;
				checked.num = stackcheck(ch);
				if(checked.num <0){
					return -1;
				}
			}else {
				checked.ch = ch;
				checked.num = -1;
			}

			strstack.push(checked);
			
			return 0;
		}

		int stackcheck(char ch){
			struct data imsi;
			char pair;
			int ret;
			pair = pairof(ch);
			imsi = strstack.pop();
			if(imsi.num < 0){ // () []
				if(imsi.ch == pair){
					cout <<"stackcheck pair case success. \n";
					ret = numof(ch);
				}else {
					cout <<"stackcheck fail. invalid pair. \n";
					return -1;
				}
			}else if(imsi.num > 0){ //(2)
				int mulnum = 0;
				mulnum = imsi.num;
				imsi = strstack.pop();
				if(imsi.ch == pair){
					cout <<"stackcheck multiply case success. \n";
					ret = numof(ch)*mulnum;
				}else {
					cout <<"stackcheck fail. invalid pair. \n";
					return -1;
				}
			}

			if(strstack.istopnum() > 0){
				cout <<"stackcheck sum case success. \n";
				imsi = strstack.pop();
				ret = ret+imsi.num;
			}
			return ret;

		}

		char pairof(char ch){
			if(ch == ')'){
				return '(';
			}else if (ch == ']'){
				return '[';
			}
		}

		int numof(char ch){
			if(ch == ')'){
				return 2;
			}else if (ch == ']'){
				return 3;
			}
		}

};


int main(){
	gwal gwalcalc;
	char* str =  "[()[]]";
	int ret;
	ret = gwalcalc.calcgwal(str, strlen(str));

	cout << "calc complelte! ret is [" << ret << "]\n";

	return 0;
}
