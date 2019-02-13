/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_Cpp_CppTOKEN_H_
#define WCI_FRONTEND_Cpp_CppTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;

/**
 * Cpp token types.
 */
enum class CppTokenType
{
    // Reserved words.
	AUTO, DOUBLE, INT, STRUCT, BREAK, ELSE, LONG, SWITCH,
	CASE, ENUM, NAMESPACE, TEMPLATE, CHAR, EXTERN, OPERATOR, THIS,
	CLASS, FLOAT, PROTECTED, THROW, CONST, FOR, PUBLIC, UNION,
	CONTINUE, GOTO, RETURN, VOID, DO, IF, STATIC, WHILE,

    // Special symbols.
    NOT,AT,MOD,XOR,AND,MUL,MINUS,PLUS,
	EQUAL,OR,DIV, COLON,SEMICOLON, QUESTIONMARK,
	LESS,GREATER,DOT,COMMA,SQUOTE,QUOTE,LEFT_PAREN,
	RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE,
	RIGHT_BRACE, INCRE, DECRE, COUT, CIN, LESS_EQ, GREATER_EQ,
	PLUS_EQ, MINUS_EQ, MUL_EQ, DIV_EQ, EQ_EQ, OR_EQ,
	MOD_EQ, AND_EQ, XOR_EQ, NOT_EQ, COUT_EQ, CIN_EQ, OR_OR,
	AND_AND, DIV_DIV, OPEN_BLOCK, CLOSE_BLOCK,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr CppTokenType PT_AUTO = CppTokenType::AUTO;
constexpr CppTokenType PT_DOUBLE = CppTokenType::DOUBLE;
constexpr CppTokenType PT_INT = CppTokenType::INT;
constexpr CppTokenType PT_STRUCT = CppTokenType::STRUCT;
constexpr CppTokenType PT_BREAK = CppTokenType::BREAK;
constexpr CppTokenType PT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType PT_LONG = CppTokenType::LONG;
constexpr CppTokenType PT_SWITCH = CppTokenType::SWITCH;
constexpr CppTokenType PT_CASE = CppTokenType::CASE;
constexpr CppTokenType PT_ENUM = CppTokenType::ENUM;
constexpr CppTokenType PT_NAMESPACE = CppTokenType::NAMESPACE;
constexpr CppTokenType PT_TEMPLATE = CppTokenType::TEMPLATE;
constexpr CppTokenType PT_CHAR = CppTokenType::CHAR;
constexpr CppTokenType PT_EXTERN = CppTokenType::EXTERN;
constexpr CppTokenType PT_OPERATOR = CppTokenType::OPERATOR;
constexpr CppTokenType PT_THIS = CppTokenType::THIS;
constexpr CppTokenType PT_CLASS = CppTokenType::CLASS;
constexpr CppTokenType PT_FLOAT = CppTokenType::FLOAT;
constexpr CppTokenType PT_PROTECTED = CppTokenType::PROTECTED;
constexpr CppTokenType PT_THROW = CppTokenType::THROW;
constexpr CppTokenType PT_CONST = CppTokenType::CONST;
constexpr CppTokenType PT_FOR = CppTokenType::FOR;
constexpr CppTokenType PT_PUBLIC = CppTokenType::PUBLIC;
constexpr CppTokenType PT_UNION = CppTokenType::UNION;
constexpr CppTokenType pt_CONTINUE = CppTokenType::CONTINUE;
constexpr CppTokenType PT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType PT_RETURN = CppTokenType::RETURN;
constexpr CppTokenType PT_VOID = CppTokenType::VOID;
constexpr CppTokenType PT_DO = CppTokenType::DO;
constexpr CppTokenType PT_IF = CppTokenType::IF;
constexpr CppTokenType PT_STATIC = CppTokenType::STATIC;
constexpr CppTokenType PT_WHILE = CppTokenType::WHILE;

constexpr CppTokenType PT_Not = CppTokenType::NOT;
constexpr CppTokenType PT_At = CppTokenType::AT;
constexpr CppTokenType PT_Mod = CppTokenType::MOD;
constexpr CppTokenType PT_Xor = CppTokenType::XOR;
constexpr CppTokenType PT_And = CppTokenType::AND;
constexpr CppTokenType PT_Mul = CppTokenType::MUL;
constexpr CppTokenType PT_Minus = CppTokenType::MINUS;
constexpr CppTokenType PT_Plus = CppTokenType::PLUS;
constexpr CppTokenType PT_Equal = CppTokenType::EQUAL;
constexpr CppTokenType PT_Or = CppTokenType::OR;
constexpr CppTokenType PT_Div = CppTokenType::DIV;
constexpr CppTokenType PT_Colon = CppTokenType::COLON;
constexpr CppTokenType PT_Semicolon = CppTokenType::SEMICOLON;
constexpr CppTokenType PT_Questionmark = CppTokenType::QUESTIONMARK;
constexpr CppTokenType PT_Less = CppTokenType::LESS;
constexpr CppTokenType PT_Greater = CppTokenType::GREATER;
constexpr CppTokenType PT_Dot = CppTokenType::DOT;
constexpr CppTokenType PT_Comma = CppTokenType::COMMA;
constexpr CppTokenType PT_Squot = CppTokenType::SQUOTE;
constexpr CppTokenType PT_Quot = CppTokenType::QUOTE;
constexpr CppTokenType PT_Left_paran = CppTokenType::LEFT_PAREN;
constexpr CppTokenType PT_Right_paran = CppTokenType::RIGHT_PAREN;
constexpr CppTokenType PT_Left_bracket = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType PT_Right_bracket = CppTokenType::RIGHT_BRACKET;
constexpr CppTokenType PT_Left_brace = CppTokenType::LEFT_BRACE;
constexpr CppTokenType PT_Right_brace = CppTokenType::RIGHT_BRACE;
constexpr CppTokenType PT_Incre = CppTokenType::INCRE;
constexpr CppTokenType PT_Decre = CppTokenType::DECRE;
constexpr CppTokenType PT_Cout = CppTokenType::COUT;
constexpr CppTokenType PT_Cin = CppTokenType::CIN;
constexpr CppTokenType PT_Less_Equa = CppTokenType::LESS_EQ;
constexpr CppTokenType PT_Greater_Equa = CppTokenType::GREATER_EQ;
constexpr CppTokenType PT_Plus_equal = CppTokenType::PLUS_EQ;
constexpr CppTokenType PT_Minus_equal = CppTokenType::MINUS_EQ;
constexpr CppTokenType PT_Mul_equal = CppTokenType::MUL_EQ;
constexpr CppTokenType PT_Div_equal = CppTokenType::DIV_EQ;
constexpr CppTokenType PT_Equal_equal = CppTokenType::EQ_EQ;
constexpr CppTokenType PT_Or_equal = CppTokenType::OR_EQ;
constexpr CppTokenType PT_Mod_equal = CppTokenType::MOD_EQ;
constexpr CppTokenType PT_And_equal = CppTokenType::AND_EQ;
constexpr CppTokenType PT_Xor_equal = CppTokenType::XOR_EQ;
constexpr CppTokenType PT_Not_equal = CppTokenType::NOT_EQ;
constexpr CppTokenType PT_Cout_equal = CppTokenType::COUT_EQ;
constexpr CppTokenType PT_Cin_equal = CppTokenType::CIN_EQ;
constexpr CppTokenType PT_Or_or = CppTokenType::OR_OR;
constexpr CppTokenType PT_And_and = CppTokenType::AND_AND;
constexpr CppTokenType PT_Div_div = CppTokenType::DIV_DIV;
constexpr CppTokenType PT_Div_star = CppTokenType::OPEN_BLOCK;
constexpr CppTokenType PT_Star_div = CppTokenType::CLOSE_BLOCK;

class CppToken : public Token
{
public:
    static map<string, CppTokenType> RESERVED_WORDS;
    static map<string, CppTokenType> SPECIAL_SYMBOLS;
    static map<CppTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_Cpp_CppTOKEN_H_ */
