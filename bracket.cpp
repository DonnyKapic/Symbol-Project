#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<char>);

int main(){
	stack<char> mystack;
	string test = "([{}])";		//Will add user input feature in future update
	cout << "The test string is: " << test << endl;

	//If odd, invalid
	if(test.size() % 2 != 0){
		cout << "Invalid: Odd number of symbols.\n";
		return 0;
	}

	int open = 0;
	int closed = 0;

	//iterate through string
	for(auto it = test.begin(); it != test.end(); it++)
		if(*it == '(' || *it == '[' || *it == '{'){	//open symbols
			open++;
			mystack.push(*it);
			printStack(mystack);
		}
		else if(*it == ')' || *it == ']' || *it == '}'){	//closed symbols
			switch(*it){					//check for matching open symbol
				case ')': if(mystack.top() == '('){
						closed++;
						mystack.pop();
					  };
					  break;
				case ']': if(mystack.top() == '['){
					  	closed++;
						mystack.pop();
					  };
					  break;
				case '}': if(mystack.top() == '{'){
						closed++;
						mystack.pop();
					  };
					  break;
				default: cout << "No matching cases.\n";
			}
		}
		else{
			cout << "Invalid\n";
			return 0;
		}
		


	cout << "\nOpen: " << open << endl;
	cout << "Closed: " << closed << endl;

	if(open == closed)
		cout << "SUCCESS. This input is legal.\n";
	else
		cout << "This input is ILLEGAL.\n";

	return 0;
}

void printStack(stack<char> mystack){
	while(!mystack.empty()){
		cout << mystack.top() << ' ';
		mystack.pop();
	}
	cout << endl;
}
