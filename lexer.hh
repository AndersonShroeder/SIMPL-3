#ifndef LEXER_H
#define LEXER_H

#include "common.hh"
#include "token.hh"

class Lexer
{
public:
  int line;
  const char *start;
  const char *current;
  std::vector<Token> tokens = {};

  Lexer(){}

  Lexer(const char *source);

  void skipWhitespace();

  bool isEnd();

  bool match(char expected);

  Token scanToken();

  Token string();

  Token number();

  Token identifier();

  TokenType identifierType();

  TokenType checkKeyword(int start, int length, const char *remain, TokenType type);

  char advance();

  char peek();

  char peekNext();
};

#endif