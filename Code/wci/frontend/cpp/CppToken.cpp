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
        "AUTO", "BREAK", "CASE", "CHAR", "CLASS", "CONST", "CONTINUE", "DO",
        "DOUBLE", "ELSE", "ENUM", "EXTERN", "FOR", "FLOAT", "GOTO", "STATIC",
        "INT", "LONG", "NAMESPACE", "OPERATOR", "PACKAGE", "PUBLIC", "RETURN", "IF",
        "STRUCT", "SWITCH", "TEMPLATE", "THIS", "THROW", "UNION", "VOID", "WHILE"
    };

    vector<CppTokenType> rw_keys =
    {
        CppTokenType::AUTO,
        CppTokenType::ELSE,
        CppTokenType::ENUM,
        CppTokenType::EXTERN,
        CppTokenType::FOR,
        CppTokenType::FLOAT,
        CppTokenType::BREAK,
        CppTokenType::CASE,
        CppTokenType::CHAR,
        CppTokenType::CLASS,
        CppTokenType::CONST,
        CppTokenType::CONTINUE,
        CppTokenType::DO,
        CppTokenType::DOUBLE,
        CppTokenType::GOTO,
        CppTokenType::STATIC,
        CppTokenType::INT,
        CppTokenType::LONG,
        CppTokenType::NAMESPACE,
        CppTokenType::OPERATOR,
        CppTokenType::PACKAGE,
        CppTokenType::PUBLIC,
        CppTokenType::RETURN,
        CppTokenType::IF,
        CppTokenType::STRUCT,
        CppTokenType::SWITCH,
        CppTokenType::TEMPLATE,
        CppTokenType::THIS,
        CppTokenType::THROW,
        CppTokenType::UNION,
        CppTokenType::VOID,
        CppTokenType::WHILE,
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
        "%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*", "*/","\\n","\\t"
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::VER_BAR,
        CppTokenType::SLASH,
        CppTokenType::COLON,
        CppTokenType::SEMICOLON,
        CppTokenType::QUESTION,
        CppTokenType::LESS_THAN,
        CppTokenType::GREATER_THAN,
        CppTokenType::DOT,
        CppTokenType::COMMA,
        CppTokenType::QUOTE,
        CppTokenType::DOUBLE_QUOTE,
        CppTokenType::LEFT_PAREN,
        CppTokenType::RIGHT_PAREN,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,
        CppTokenType::LEFT_BRACE,
        CppTokenType::RIGHT_BRACE,
        CppTokenType::INCREMENT,
        CppTokenType::FLAG,
        CppTokenType::NEGATE,
        CppTokenType::AT,
        CppTokenType::MOD,
        CppTokenType::UP_ARROW,
        CppTokenType::AMPERSAND,
        CppTokenType::STAR,
        CppTokenType::MINUS,
        CppTokenType::PLUS,
        CppTokenType::ASSIGN,
        CppTokenType::DECREMENT,
        CppTokenType::LEFT_SHIFT,
        CppTokenType::RIGHT_SHIFT,
        CppTokenType::LESS_EQUALS,
        CppTokenType::GREATER_EQUALS,
        CppTokenType::OR,
        CppTokenType::AND,
        CppTokenType::LINE_COMMENT,
        CppTokenType::BEGIN_COMMENT,
        CppTokenType::END_COMMENT,
        CppTokenType::NEW_LINE,
        CppTokenType::TAB,
        CppTokenType::ADD_EQUAL,
        CppTokenType::SUB_EQUAL,
        CppTokenType::MUL_EQUAL,
        CppTokenType::DIV_EQUAL,
        CppTokenType::EQUALS,
        CppTokenType::OR_EQUAL,
        CppTokenType::MOD_EQUAL,
        CppTokenType::AND_EQUAL,
        CppTokenType::UP_ARROW_EQUAL,
        CppTokenType::NOT_EQUALS,
        CppTokenType::LEFT_SHIFT_EQUAL,
        CppTokenType::RIGHT_SHIFT_EQUAL

    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
        "FLAG", "NEGATE", "AT", "MOD", "UP_ARROW", "AMPERSAND", "STAR", "MINUS", "PLUS",
        "ASSIGN", "VER_BAR", "SLASH", "COLON", "SEMICOLON", "QUESTION", "LESS_THAN",
        "GREATER_THAN", "DOT", "COMMA","QUOTE", "DOUBLE_QUOTE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET",
        "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE","INCREMENT", "DECREMENT", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_EQUALS",
        "GREATER_EQUALS", "ADD_EQUAL", "SUB_EQUAL", "MUL_EQUAL", "DIV_EQUAL",
        "LINE_COMMENT", "BEGIN_COMMENT", "END_COMMENT", "NEW_LINE", "TAB","EQUALS", "OR_EQUAL", "MOD_EQUAL", "AND_EQUAL", "UP_ARROW_EQUAL", "NOT_EQUALS",
        "LEFT_SHIFT_EQUAL", "RIGHT_SHIFT_EQUAL", "OR", "AND"
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

}}}  // namespace wci::frontend::cpp
