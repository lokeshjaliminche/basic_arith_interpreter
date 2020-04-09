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


class Token
{

	public:
		Token_type type;
		Token_type currToken;
		double numbervalue;
		string stringvalue;
};

class Lexer 
{
	public:
	void get_token();
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

void Lexer::get_token()
{
	char ch = 0;
	Token token;
	Token_type type;
	do
	{
		if(!cin.get(ch))
		{
			token.currToken = END;
			return;
		}
	}while(ch != '\n' && isspace(ch));

}
