/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "CppToken.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;

map<string, CppTokenType> CppToken::RESERVED_WORDS;
map<string, CppTokenType> CppToken::SPECIAL_SYMBOLS;
map<CppTokenType, string> CppToken::SPECIAL_SYMBOL_NAMES;

bool CppToken::INITIALIZED = false;

void CppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
		"AUTO", "DOUBLE", "INT", "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH",
		"CASE", "ENUM", "NAMESPACE", "TEMPLATE", "CHAR", "EXTERN", "OPERATOR", "THIS",
		"CLASS", "FLOAT", "PROTECTED", "THROW", "CONST", "FOR", "PUBLIC", "UNION",
		"CONTINUE", "GOTO", "RETURN", "VOID", "DO", "IF", "STATIC", "WHILE"
    };

    vector<CppTokenType> rw_keys =
    {
    		CppTokenType::AUTO,
    		CppTokenType::DOUBLE,
    		CppTokenType::INT,
    		CppTokenType::STRUCT,
    		CppTokenType::BREAK,
    		CppTokenType::ELSE,
    		CppTokenType::LONG,
    		CppTokenType::SWITCH,
    		CppTokenType::CASE,
    		CppTokenType::ENUM,
    		CppTokenType::NAMESPACE,
    		CppTokenType::TEMPLATE,
    		CppTokenType::CHAR,
    		CppTokenType::EXTERN,
    		CppTokenType::OPERATOR,
    		CppTokenType::THIS,
    	    CppTokenType::CLASS,
    		CppTokenType::FLOAT,
    		CppTokenType::PROTECTED,
    		CppTokenType::THROW,
    		CppTokenType::CONST,
    		CppTokenType::FOR,
    		CppTokenType::PUBLIC,
    		CppTokenType::UNION,
    		CppTokenType::CONTINUE,
    		CppTokenType::GOTO,
    		CppTokenType::RETURN,
    		CppTokenType::VOID,
    		CppTokenType::DO,
    		CppTokenType::IF,
    		CppTokenType::STATIC,
    		CppTokenType::WHILE

    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
	"~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|", "/", ":",
	";", "?", "<", ">", "." ,"," ,"'" ," " ,"(" ,"(" ,"[" ,"]" ,"{" ,"}", 
	"++", "--", "<<", ">>" ,"<=", ">=", "+=", "-=", "*=", "/=", "==", "|=",
	"%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*", "*/"
	//"+", "-", "*", "/", ":=", ".", ",", ";", ":", "'", "=", "<>",
        //"<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", ".."
    };

    vector<CppTokenType> ss_keys =
    {
    		CppTokenType::NEG,
    		CppTokenType::NOT,
    		CppTokenType::AT,
    		CppTokenType::MOD,
    		CppTokenType::XOR,
    		CppTokenType::AND,
    		CppTokenType::MUL,
    		CppTokenType::MINUS,
    		CppTokenType::PLUS,
    		CppTokenType::EQUAL,
    		CppTokenType::OR,
    		CppTokenType::DIV,
    	    CppTokenType::COLON,
    		CppTokenType::SEMICOLON,
    		CppTokenType::QUESTIONMARK,
    		CppTokenType::LESS,
    		CppTokenType::GREATER,
    		CppTokenType::DOT,
    		CppTokenType::COMMA,
    		CppTokenType::SQUOTE,
    		CppTokenType::QUOTE,
    		CppTokenType::LEFT_PAREN,
    		CppTokenType::RIGHT_PAREN,
    		CppTokenType::LEFT_BRACKET,
    		CppTokenType::RIGHT_BRACKET,
			CppTokenType::LEFT_BRACE,
    		CppTokenType::RIGHT_BRACE,
    		CppTokenType::INCRE,
    		CppTokenType::DECRE,
    		CppTokenType::COUT,
    		CppTokenType::CIN,
    		CppTokenType::LESS,
    		CppTokenType::GREATER_EQ,
    		CppTokenType::PLUS_EQ,
    		CppTokenType::MINUS_EQ,
    		CppTokenType::MUL_EQ,
    		CppTokenType::DIV_EQ,
    		CppTokenType::EQ_EQ,
    		CppTokenType::OR_EQ,
    		CppTokenType::MOD_EQ,
    		CppTokenType::AND_EQ,
    		CppTokenType::XOR_EQ,
    		CppTokenType::NOT_EQ,
    		CppTokenType::COUT_EQ,
    		CppTokenType::CIN_EQ,
    	    CppTokenType::OR_OR,
    		CppTokenType::AND_AND,
    		CppTokenType::DIV_DIV,
    		CppTokenType::OPEN_BLOCK,
    		CppTokenType::CLOSE_BLOCK
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
		"NEG","NOT","AT","MOD","XOR","AND","MUL","MINUS","PLUS",
		"EQUAL","OR","DIV", "COLON","SEMICOLON", "QUESTIONMARK",
		"LESS","GREATER","DOT","COMMA","SQUOTE","QUOTE","LEFT_PAREN",
		"RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE",
		"RIGHT_BRACE", "INCRE", "DECRE", "COUT", "CIN", "LESS_EQ", "GREATER_EQ",
		"PLUS_EQ", "MINUS_EQ", "MUL_EQ", "DIV_EQ", "EQ_EQ", "OR_EQ",
		"MOD_EQ", "AND_EQ", "XOR_EQ", "NOT_EQ", "COUT_EQ", "CIN_EQ", "OR_OR",
		"AND_AND", "DIV_DIV", "OPEN_BLOCK", "CLOSE_BLOCK"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CppToken::CppToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cpp
