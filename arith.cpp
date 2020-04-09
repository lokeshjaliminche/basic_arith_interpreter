#include <iostream>
#include <iterator>
#include <map>

using namespace std;
enum Token_type
{
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


Token_type currToken;
double numbervalue;
string stringvalue;

class Lexer 
{
	Token_type get_token();
};

class Parser
{
	double prim(bool);
	double term(bool);
	double expr(bool);

	map<string, double> table;
};

int main()
{
	string text;
	cin >> text;
	cout << "text is : " << text;	
}

Token_type Lexer::get_token()
{
	char ch = 0;
	do
	{
		if(!cin.get(ch))
		{
			currToken = END;
			return END;
		}
	}while(ch != '\n' && isspace(ch));

        switch(ch)
	{
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
			currToken = Token_type(ch);
			return currToken;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
			cin.putback(ch);
			cin >> numbervalue;
			currToken = NUMBER;
			return currToken;
		default:
			currToken = END;
			return currToken;
	}

}
