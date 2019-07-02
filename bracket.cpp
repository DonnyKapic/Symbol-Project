#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<char>);

int main(){
	stack<char> mystack;

	string test;
	cout << "Please enter a test string.\n";
	cin >> test;

	cout << "The test string is: " << test << endl;

	//if number of symbols is odd do not accept
	if(test.size() % 2 != 0){
		cout << "Invalid: Odd number of symbols.\n";
		return 0;
	}

	//iterate through string
	for(auto it = test.begin(); it != test.end(); it++)
		if(*it == '(' || *it == '[' || *it == '{'){	//open symbols
			mystack.push(*it);
			printStack(mystack);
		}
		else if(*it == ')' || *it == ']' || *it == '}'){	//closed symbols
			switch(*it){					//check for matching open symbol
				case ')': if(mystack.top() == '('){
						mystack.pop();
					  };
					  break;
				case ']': if(mystack.top() == '['){
						mystack.pop();
					  };
					  break;
				case '}': if(mystack.top() == '{'){
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
		
	if(mystack.empty())
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
