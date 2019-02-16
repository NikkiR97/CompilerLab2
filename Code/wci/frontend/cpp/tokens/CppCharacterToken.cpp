/**
 * <h1>cppStringToken</h1>
 *
 * <p> cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "CppCharacterToken.h"

#include <string>
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

CppCharacterToken::CppCharacterToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppCharacterToken::extract() throw (string)
{
    char value_char;

    char current_ch = next_char();  // consume initial quote
    text += "'";

    // Get string characters.

	// Replace any whitespace character with a blank.
	if (isspace(current_ch)) current_ch = ' ';

	if(current_ch == '\\')
	{
		text += current_ch;
		current_ch = next_char();
		if(current_ch == 'n')
		{
			text += current_ch;
			value_char = '\n';
			current_ch = next_char();
		}
		else if(current_ch == 't')
		{
			text += current_ch;
			value_char = '\t';
			current_ch = next_char();
		}
		else if(current_ch == '\'')
		{
			text += current_ch;
			value_char = '\'';
			current_ch = next_char();
		}
		else if(current_ch == '\\')
		{
			text += current_ch;
			value_char = '\\';
			current_ch = next_char();
		}

//		text += current_ch;
//			current_ch = next_char();
//			if(current_ch == 'n')
//			{
//				text += current_ch;
//				current_ch = next_char();
//			}
//			else if(current_ch == 't')
//			{
//				text += current_ch;
//				current_ch = next_char();
//			}
//			else if(current_ch == '\'')
//			{
//				text += current_ch;
//				current_ch = next_char();
//			}
//			else if(current_ch == '\\')
//			{
//				text += current_ch;
//				current_ch = next_char();
//			}


	}
	else
	{
		text += current_ch;
		value_char = current_ch;
		current_ch = next_char();
	}

    if (current_ch == '\'')
    {
        next_char();  // consume final quote
        text += '\'';
        type = (TokenType) PT_CHAR;
        value = value_char;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }
}

}}}} // namespace wci::frontend::cpp::tokens
