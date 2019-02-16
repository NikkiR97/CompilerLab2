/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "CppCharacterToken.h"
#include "../CppError.h"

namespace wci { namespace frontend {namespace Cpp {namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

CppCharacterToken::CppCharacterToken(Source *source) throw (string) :
		CppToken(source) {
	extract();
}

void CppCharacterToken::extract() throw (string) {
	string value_str = "";
	char current_ch = next_char();  // consume initial
	text += '\'';

	do {
		
		if (isspace(current_ch))
			current_ch = ' ';

		if (current_ch == '\\') 
		{
			current_ch = next_char();

			if (current_ch == 't') 
			{
				text += "\\t";
				value_str += "	";
				current_ch = next_char();
			}
			else if (current_ch == 'n') 
			{
				text += "\\n";
				value_str += "\n";
				current_ch = next_char();
			}
			else if (current_ch == '\'') 
			{
				text += "\'";
				value_str += "\'";
				current_ch = next_char();
			}
			else if (current_ch == '\\') 
			{
				text += "\\";
				value_str += "\\";
				current_ch = next_char();
			}
		}
		else if ((current_ch != '\'') && (current_ch != EOF)) 
		{
			text += current_ch;
			value_str += current_ch;
			current_ch = next_char();  
		}
	} 
	while ((current_ch != '\'') && (current_ch != Source::END_OF_FILE));


	if (current_ch == '\'') 
	{
		next_char();  
		text += '\'';
		type = (TokenType) PT_CHARACTER;
		value = value_str;
	} 
	else 
	{
		type = (TokenType) PT_ERROR;
		value = (int) UNEXPECTED_EOF;
	}
	
}

}
}
}
}  // namespace wci::frontend::cpp::tokens
