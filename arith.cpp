#include <iostream>

using namespace std;

#string myString = new string[8];
char const *myStrings[] = {
    "Some",
    "Strings"
};

enum Token_type{
     NAME,
     NUMBER,
     END,
     PLUS='+',
     MINUS='-',
     MUL='*',
     DIV='/',
     PRINT=';',
     ASSIGN='=',
     LP='(',
     RP=')'
};


Class Token
{
	Token_type type;
	double numbervalue;
	string stringvalue
	Token get_token();
}

Class Lexer
{
	Token getToken();
}

Class Parser
{
	double prim(bool);
	double term(bool);
	double expr(bool);

	map<string, double> table;
}

int main()
{
	string text;
	cin >> text;
	cout << "text is : " << text;	

}
