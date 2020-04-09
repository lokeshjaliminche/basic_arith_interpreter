/*
 * This is an Interpreter for ARITH
 * Followed these websites to understand the concepts
 * and coding 
 * https://ruslanspivak.com/lsbasi-part7/
 * http://www.cplusplus.com/forum/general/1116/2/
 */

#include <iostream>
#include <iterator>
#include <map>

using namespace std;

/*
 * Binary Operations:
 * ==================
 * ADD
 * SUBSTRACT
 * MULTIPLICATION
 * DIVISION
 *
 * Unary operations:
 * =================
 * '-'
 *
 * Precedence:
 * ==========
 * '(',')'
 * '*','/'
 * '+','-'
 *
 * Grammer:
 * =======
 * Primary:
 * 	NUMBER
 * 	- primary
 * 	(expression)
 *
 * expression:
 * 	term + expression
 * 	term - expression
 * 	term
 *
 * term:
 * 	primary / term
 * 	primary * term
 * 	primary
 */

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
int numbervalue;
string stringvalue;

class Lexer 
{
	public:
	Token_type get_token();
};

class Parser
{
	public:
	int prim(bool);
	int term(bool);
	int expr(bool);

	map<string, int> table;
};

int Parser::expr(bool get)
{
	int left = term(get);

	while(1)
	{
		switch(currToken)
		{
			case PLUS:
				left += term(true);
				break;
			case MINUS:
				left -= term(true);
				break;
			default:
				return left;
		}
	}
}

int Parser::term(bool get)
{
    int left = prim(get);

    while(1)
    {
        switch (currToken)
        {
        case  MUL:
            left *= prim(true);
            break;
        case DIV:
            if (int d = prim(true))
            {
                left /= d;
                break;
            }
	    cout << "Divide by 0";
            return 1;
        default:
            return left;
        }
    }

}
int Parser::prim(bool get)
{
	Lexer l;
	if(get) l.get_token();

	switch(currToken)
	{
		case NUMBER:
		{
			int v = numbervalue;
			l.get_token();
			return v;	
		}

		case MINUS:
		{
			return -prim(true);
		}

		case LP:
		{
			int e = expr(true);
			if (currToken != RP)
				cout << "expected )";
			l.get_token();
			return e;
		}
		default:
			return 1;
	}
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

int main()
{
	Parser parse;
	Lexer lex;
	while(cin)
	{
		lex.get_token();

		if (currToken == END) break;
		int result = parse.expr(false);
		cout << result << endl;

	}
}


