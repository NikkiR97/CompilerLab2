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
    AUTO, BREAK, CASE, CHAR, CLASS, CONST, CONTINUE, DO,
    DOUBLE, ELSE, ENUM, EXTERN, FOR, FLOAT, GOTO, STATIC,
    INT, LONG, NAMESPACE, OPERATOR, PACKAGE, PUBLIC, RETURN, IF,
    STRUCT, SWITCH, TEMPLATE, THIS, THROW, UNION, VOID, WHILE,

    // Special symbols.
    PLUS, MINUS, STAR, SLASH, FLAG, NEGATE, AT, MOD, AMPERSAND, ASSIGN,
    COMMA, SEMICOLON, COLON, QUOTE, VER_BAR, QUESTION, DOT,
    EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS, DOUBLE_QUOTE,
    GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    UP_ARROW, INCREMENT, DECREMENT, LEFT_SHIFT, RIGHT_SHIFT,
    ADD_EQUAL, SUB_EQUAL, MUL_EQUAL, DIV_EQUAL, OR_EQUAL, MOD_EQUAL,
    AND_EQUAL, UP_ARROW_EQUAL, LEFT_SHIFT_EQUAL, RIGHT_SHIFT_EQUAL,
    AND, OR, LINE_COMMENT, BEGIN_COMMENT, END_COMMENT, NEW_LINE, TAB,

    IDENTIFIER, INTEGER, REAL, STRING, CHARACTER,
    ERROR, END_OF_FILE
};

constexpr CppTokenType PT_AUTO = CppTokenType::AUTO;
constexpr CppTokenType PT_BREAK = CppTokenType::BREAK;
constexpr CppTokenType PT_CASE = CppTokenType::CASE;
constexpr CppTokenType PT_CHAR = CppTokenType::CHAR;
constexpr CppTokenType PT_CLASS = CppTokenType::CLASS;
constexpr CppTokenType PT_CONST = CppTokenType::CONST;
constexpr CppTokenType PT_CONTINUE = CppTokenType::CONTINUE;
constexpr CppTokenType PT_DO = CppTokenType::DO;

constexpr CppTokenType PT_DOUBLE = CppTokenType::DOUBLE;
constexpr CppTokenType PT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType PT_ENUM = CppTokenType::ENUM;
constexpr CppTokenType PT_EXTERN = CppTokenType::EXTERN;
constexpr CppTokenType PT_FOR = CppTokenType::FOR;
constexpr CppTokenType PT_FLOAT = CppTokenType::FLOAT;
constexpr CppTokenType PT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType PT_STATIC = CppTokenType::STATIC;


constexpr CppTokenType PT_INT = CppTokenType::INT;
constexpr CppTokenType PT_LONG = CppTokenType::LONG;
constexpr CppTokenType PT_NAMESPACE = CppTokenType::NAMESPACE;
constexpr CppTokenType PT_OPERATOR = CppTokenType::OPERATOR;
constexpr CppTokenType PT_PACKAGE = CppTokenType::PACKAGE;
constexpr CppTokenType PT_PUBLIC = CppTokenType::PUBLIC;
constexpr CppTokenType PT_RETURN = CppTokenType::RETURN;
constexpr CppTokenType PT_IF = CppTokenType::IF;

constexpr CppTokenType PT_PROGRAM = CppTokenType::STRUCT;
constexpr CppTokenType PT_RECORD = CppTokenType::SWITCH;
constexpr CppTokenType PT_REPEAT = CppTokenType::TEMPLATE;
constexpr CppTokenType PT_SET = CppTokenType::THIS;
constexpr CppTokenType PT_THEN = CppTokenType::THROW;
constexpr CppTokenType PT_TO = CppTokenType::UNION;
constexpr CppTokenType PT_TYPE = CppTokenType::VOID;
constexpr CppTokenType PT_WHILE = CppTokenType::WHILE;

constexpr CppTokenType PT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType PT_MINUS = CppTokenType::MINUS;
constexpr CppTokenType PT_STAR = CppTokenType::STAR;
constexpr CppTokenType PT_SLASH = CppTokenType::SLASH;
constexpr CppTokenType PT_FLAG = CppTokenType::FLAG;
constexpr CppTokenType PT_NEGATE = CppTokenType::NEGATE;
constexpr CppTokenType PT_AT = CppTokenType::AT;
constexpr CppTokenType PT_MOD = CppTokenType::MOD;
constexpr CppTokenType PT_AMPERSAND = CppTokenType::AMPERSAND;
constexpr CppTokenType PT_ASSIGN = CppTokenType::ASSIGN;

constexpr CppTokenType PT_COMMA = CppTokenType::COMMA;
constexpr CppTokenType PT_SEMICOLON = CppTokenType::SEMICOLON;
constexpr CppTokenType PT_COLON = CppTokenType::COLON;
constexpr CppTokenType PT_QUOTE = CppTokenType::QUOTE;
constexpr CppTokenType PT_VER_BAR = CppTokenType::VER_BAR;
constexpr CppTokenType PT_QUESTION = CppTokenType::QUESTION;
constexpr CppTokenType PT_DOT = CppTokenType::DOT;

constexpr CppTokenType PT_EQUALS = CppTokenType::EQUALS;
constexpr CppTokenType PT_NOT_EQUALS = CppTokenType::NOT_EQUALS;
constexpr CppTokenType PT_LESS_THAN = CppTokenType::LESS_THAN;
constexpr CppTokenType PT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
constexpr CppTokenType PT_DOUBLE_QUOTE = CppTokenType::DOUBLE_QUOTE;

constexpr CppTokenType PT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
constexpr CppTokenType PT_GREATER_THAN = CppTokenType::GREATER_THAN;
constexpr CppTokenType PT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
constexpr CppTokenType PT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;

constexpr CppTokenType PT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType PT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
constexpr CppTokenType PT_LEFT_BRACE = CppTokenType::LEFT_BRACE;
constexpr CppTokenType PT_RIGHT_BRACE = CppTokenType::RIGHT_BRACE;

constexpr CppTokenType PT_UP_ARROW = CppTokenType::UP_ARROW;
constexpr CppTokenType PT_INCREMENT = CppTokenType::INCREMENT;
constexpr CppTokenType PT_DECREMENT = CppTokenType::DECREMENT;
constexpr CppTokenType PT_LEFT_SHIFT = CppTokenType::LEFT_SHIFT;
constexpr CppTokenType PT_RIGHT_SHIFT = CppTokenType::RIGHT_SHIFT;

constexpr CppTokenType PT_ADD_EQUAL = CppTokenType::ADD_EQUAL;
constexpr CppTokenType PT_SUB_EQUAL = CppTokenType::SUB_EQUAL;
constexpr CppTokenType PT_MUL_EQUAL = CppTokenType::MUL_EQUAL;
constexpr CppTokenType PT_DIV_EQUAL = CppTokenType::DIV_EQUAL;
constexpr CppTokenType PT_OR_EQUAL = CppTokenType::OR_EQUAL;
constexpr CppTokenType PT_MOD_EQUAL = CppTokenType::MOD_EQUAL;

constexpr CppTokenType PT_AND_EQUAL = CppTokenType::AND_EQUAL;
constexpr CppTokenType PT_UP_ARROW_EQUAL = CppTokenType::UP_ARROW_EQUAL;
constexpr CppTokenType PT_LEFT_SHIFT_EQUAL = CppTokenType::LEFT_SHIFT_EQUAL;
constexpr CppTokenType PT_RIGHT_SHIFT_EQUAL = CppTokenType::RIGHT_SHIFT_EQUAL;

constexpr CppTokenType PT_AND = CppTokenType::AND;
constexpr CppTokenType PT_OR = CppTokenType::OR;
constexpr CppTokenType PT_LINE_COMMENT = CppTokenType::LINE_COMMENT;
constexpr CppTokenType PT_BEGIN_COMMENT = CppTokenType::BEGIN_COMMENT;
constexpr CppTokenType PT_END_COMMENT = CppTokenType::END_COMMENT;
constexpr CppTokenType PT_NEW_LINE = CppTokenType::NEW_LINE;
constexpr CppTokenType PT_TAB = CppTokenType::TAB;

constexpr CppTokenType PT_IDENTIFIER = CppTokenType::IDENTIFIER;
constexpr CppTokenType PT_INTEGER = CppTokenType::INTEGER;
constexpr CppTokenType PT_REAL = CppTokenType::REAL;
constexpr CppTokenType PT_STRING = CppTokenType::STRING;
constexpr CppTokenType PT_CHARACTER = CppTokenType::CHARACTER;
constexpr CppTokenType PT_ERROR = CppTokenType::ERROR;
constexpr CppTokenType PT_END_OF_FILE = CppTokenType::END_OF_FILE;

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
