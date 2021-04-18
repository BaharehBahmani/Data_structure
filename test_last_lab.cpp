#include <iostream>
#include <string>
using std::string;
//Group Members: Behjat Bahmani, Danilo Gatchalian, Rian Ng, Joseph Behroz, Zachary Liang, Mohammed Deeb
 
int hash_code(const string& str) {
	int h = 0; 
	for (int i=0;i<str.length();i++)
	{
	//The value 31 was chosen because it is an odd prime. If it were even and the multiplication overflowed,
	// information would be lost, as multiplication by 2 is equivalent to shifting. The advantage of using 
	// a prime is less clear, but it is traditional.
		h = 31 * h + str[i];
	}
	//We used an array size 10 to compress the size of the hash values to range from index 0-9 because of the data size, we felt
	//that 10 is still a valid size for our current problem. Because we are using 31  as the base, that inherently decreases
	//the variety in numbers after doing modulus 10. Which allows us to use a smaller sized array since we expect the 
	//diversity to be smaller compared to if we were to use a different number, and have a larger range of H values.
	h = h % 10;
	if (h < 0) {
		h = -h;
	}
	return h;
}
 
 
int main() {
	std::string name;
	string s[10];
	while (name != "stop") {
 
		std::cout << "Please enter names to be processed: ";
		std::cin >> name;
		if (name == "stop") {
			break;
		}
		int h =  hash_code(name);
		s[h] = name;
	}
 
 
	for (int i=0;i<10;i++) {
		std::cout << s[i] << std::endl;
	}
 
	return 0;
}
 
//To solve the collision, we can use seperate chaining and create a list of Buckets such that when the same hash code gets
//called, it will create a new Node that is attached to  the first entry.