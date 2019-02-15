/**
 * <h1>CppSpecialSymbolToken</h1>
 *
 * <p> Cpp special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "CppSpecialSymbolToken.h"
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

CppSpecialSymbolToken::CppSpecialSymbolToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppSpecialSymbolToken::extract() throw (string)
{
    char current_ch = current_char();
    bool good_symbol = true;

    text = current_ch;

    switch (current_ch)
    {
        // Single-character special symbols.
        case ',':  case ';':  case '(':  case ')':
        case '[':  case ']':  case '{':  case '}':
        case '~':  case '@':  case ':':
        case '?':  case '.':  case '\'': case '"':
        {
            next_char();  // consume character
            break;
        }
        //'+', '++' or '+='
        case '+':
        {
        	current_ch = next_char();  // consume ':';

        	if (current_ch == '=' || current_ch =='+')
        	{
            	text += current_ch;
                next_char();  // consume '='
            }


            break;
        }

        //'-', '--' or '-='
        case '-':
        {
           current_ch = next_char();  // consume ':';

           if (current_ch == '=' || current_ch =='-')
           {
             text += current_ch;
             next_char();  // consume '='
           }


           break;
        }


        //'&', '&=' or '&&'
        case '&':
        {
            current_ch = next_char();  // consume '&';

            if (current_ch == '=' || current_ch =='&')
            {
               text += current_ch;
               next_char();  // consume '='
            }

            break;
         }

        //'|', '|=' or '||'
        case '|':
        {
            current_ch = next_char();  // consume '&';

            if (current_ch == '=' || current_ch =='|')
            {
               text += current_ch;
               next_char();  // consume '='
            }

            break;
         }

        // 'char' or 'char'=
        case '=': case'!': case '^': case '%':
        {
            current_ch = next_char();  // consume ':';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // '/', '/=', '//' or '/*
        case '/':
        {
            current_ch = next_char();  // consume '&';

            if (current_ch == '/' || current_ch =='=' || current_ch=='*')
            {
               text += current_ch;
               next_char();  // consume '='
            }

            break;
         }

        // '<', '<<', '<=', '<<='
        case '<':
        {
            current_ch = next_char();  // consume '&';

            if (current_ch == '=')
            {
               text += current_ch;
               next_char();  // consume '='
            }

            if (current_ch=='<'){
               text += current_ch;
               next_char();  // consume '='
               if (current_ch=='='){
                  text += current_ch;
                  next_char();  // consume '='
               }
            }

            break;
         }

        // '>', '>>', '>=', '>>='
        case '>':
        {
            current_ch = next_char();  // consume '&';

            if (current_ch == '=')
            {
               text += current_ch;
               next_char();  // consume '='
            }

            if (current_ch=='>'){
               text += current_ch;
               next_char();  // consume '='
               if (current_ch=='='){
                  text += current_ch;
                  next_char();  // consume '='
               }
            }
            break;
        }
        
        default:
        {
            next_char();  // consume bad character
            type = (TokenType) (PT_ERROR);
            value = (int) INVALID_CHARACTER;
            good_symbol = false;
        }
    }

    // Set the type if it wasn't an error.
    if (good_symbol) {
        type = (TokenType) (CppToken::SPECIAL_SYMBOLS[text]);
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
