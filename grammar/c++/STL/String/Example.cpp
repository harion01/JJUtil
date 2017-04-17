// comparing apples with apples
#include <iostream>
#include <string>

int main ()
{
	

	std::string str1 ("green apple");
	std::string str2 ("red apple");

	if (str1.compare(str2) != 0)
		std::cout << str1 << " is not " << str2 << '\n';

	if (str1.compare(6,5,"apple") == 0)
		std::cout << "still, " << str1 << " is an apple\n";

	if (str2.compare(str2.size()-5,5,"apple") == 0)
		std::cout << "and " << str2 << " is also an apple\n";

	if (str1.compare(6,5,str2,4,5) == 0)
		std::cout << "therefore, both are apples\n";


	for(int i=0; i<str1.length(); i++){
		std::cout << str1[i] << std::endl;
	}

	return 0;
}

/* compare output 

green apple is not red apple
still, green apple is an apple
and red apple is also an apple
therefore, both are apples

*/
