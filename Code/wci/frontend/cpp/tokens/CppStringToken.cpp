/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "CppStringToken.h"
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

CppStringToken::CppStringToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppStringToken::extract() throw (string)
{
    /*string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "'";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';

        if ((current_ch != '\'') && (current_ch != EOF))
        {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();  // consume character
        }

        // Quote?  Each pair of adjacent quotes represents a single-quote.
        if (current_ch == '\'')
        {
            while ((current_ch == '\'') && (peek_char() == '\''))
            {
                text += "''";
                value_str  += current_ch;  // append single-quote
                current_ch = next_char();  // consume pair of quotes
                current_ch = next_char();
            }
        }
    } while ((current_ch != '\'') && (current_ch != Source::END_OF_FILE));

    if (current_ch == '\'')
    {
        next_char();  // consume final quote
        text += '\'';
        type = (TokenType) PT_STRING;
        value = value_str;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }*/

    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\"";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';

        while (current_ch == '\\')
		{

        	text += current_ch;
			//value_str += current_ch;
			current_ch = next_char();

			if(current_ch =='"')
			{

				text += current_ch;
				value_str += '"';
				current_ch = next_char();
			}
			else if(current_ch == 'n')
			{
				text += current_ch;
				value_str += '\n';
				current_ch = next_char();
			}
			else if(current_ch == 't')
			{
				text += current_ch;
				value_str += '\t';
				current_ch = next_char();
			}
			else if(current_ch == '\\')
			{
				text += current_ch;
				value_str += '\\';
				current_ch = next_char();
			}
		}

        if ((current_ch != '"') && (current_ch != EOF))
        {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();  // consume character
        }

        // Quote?  Each pair of adjacent quotes represents a single-quote.

    } while ((current_ch != '"') && (current_ch != Source::END_OF_FILE));

    if (current_ch == '"')
    {
        next_char();  // consume final quote
        text += '"';
        type = (TokenType) PT_STRING;
        value = value_str;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
