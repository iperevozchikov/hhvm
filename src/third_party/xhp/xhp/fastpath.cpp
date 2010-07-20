/* Generated by re2c 0.13.5 on Thu May 27 03:14:47 2010 */
#line 1 "fastpath.re"
/*
  +----------------------------------------------------------------------+
  | XHP                                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 2009 - 2010 Facebook, Inc. (http://www.facebook.com)          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE.PHP, and is    |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
*/

#include "fastpath.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool xhp_fastpath(const char* yy, const size_t len, const xhp_flags_t &flags) {
  const char* YYMARKER = NULL;
  char* heredoc_marker = NULL;
  size_t heredoc_marker_len = NULL;
  bool result = false;
  enum {
    HTML,
    PHP,
    HEREDOC,
    HEREDOC_START,
    COMMENT_EOL,
    COMMENT_BLOCK
  } state = flags.eval ? PHP : HTML;

  #define YYCURSOR yy
  #define YYCTYPE char
  #define YYGETCONDITION() state
  #define YYFILL(ii)
  #define YYDEBUG(s, c) printf("%03d: %c [%d]\n", s, c, c)

  for (;;) {
    const char* yystart = yy;

#line 48 "fastpath.cpp"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	switch (YYGETCONDITION()) {
	case COMMENT_BLOCK: goto yyc_COMMENT_BLOCK;
	case COMMENT_EOL: goto yyc_COMMENT_EOL;
	case HEREDOC: goto yyc_HEREDOC;
	case HEREDOC_START: goto yyc_HEREDOC_START;
	case HTML: goto yyc_HTML;
	case PHP: goto yyc_PHP;
	}
/* *********************************** */
yyc_COMMENT_BLOCK:

	YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy6;
	case '*':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
#line 141 "fastpath.re"
	{ continue; }
#line 74 "fastpath.cpp"
yy4:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '/':	goto yy8;
	default:	goto yy5;
	}
yy5:
#line 55 "fastpath.re"
	{ continue; }
#line 84 "fastpath.cpp"
yy6:
	++YYCURSOR;
#line 51 "fastpath.re"
	{
      result = false;
      break;
    }
#line 92 "fastpath.cpp"
yy8:
	++YYCURSOR;
#line 142 "fastpath.re"
	{
      state = PHP;
      continue;
    }
#line 100 "fastpath.cpp"
/* *********************************** */
yyc_COMMENT_EOL:
	YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy18;
	case '\n':	goto yy14;
	case '\r':	goto yy16;
	case '?':	goto yy17;
	default:	goto yy12;
	}
yy12:
	++YYCURSOR;
yy13:
#line 55 "fastpath.re"
	{ continue; }
#line 117 "fastpath.cpp"
yy14:
	++YYCURSOR;
yy15:
#line 132 "fastpath.re"
	{
      state = PHP;
      continue;
    }
#line 126 "fastpath.cpp"
yy16:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy22;
	default:	goto yy15;
	}
yy17:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy20;
	default:	goto yy13;
	}
yy18:
	++YYCURSOR;
#line 51 "fastpath.re"
	{
      result = false;
      break;
    }
#line 146 "fastpath.cpp"
yy20:
	++YYCURSOR;
#line 136 "fastpath.re"
	{
      state = HTML;
      continue;
    }
#line 154 "fastpath.cpp"
yy22:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy15;
/* *********************************** */
yyc_HEREDOC:
	YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy29;
	case '\n':
	case '\r':	goto yy27;
	default:	goto yy25;
	}
yy25:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy34;
yy26:
#line 117 "fastpath.re"
	{
      continue;
    }
#line 178 "fastpath.cpp"
yy27:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy32;
yy28:
#line 120 "fastpath.re"
	{
      if (strncmp(yy, heredoc_marker, heredoc_marker_len) == 0 && (
            yy[heredoc_marker_len] == ';' || yy[heredoc_marker_len] == '\r' ||
            yy[heredoc_marker_len] == '\n')
      ) {
        free(heredoc_marker);
        heredoc_marker = NULL;
        state = PHP;
      }
      continue;
    }
#line 196 "fastpath.cpp"
yy29:
	++YYCURSOR;
#line 51 "fastpath.re"
	{
      result = false;
      break;
    }
#line 204 "fastpath.cpp"
yy31:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
yy32:
	switch (yych) {
	case '\n':
	case '\r':	goto yy31;
	default:	goto yy28;
	}
yy33:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
yy34:
	switch (yych) {
	case 0x00:
	case '\n':
	case '\r':	goto yy26;
	default:	goto yy33;
	}
/* *********************************** */
yyc_HEREDOC_START:
	YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy41;
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x1F:
	case ' ':
	case '!':
	case '"':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
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
	case ':':
	case ';':
	case '<':
	case '=':
	case '>':
	case '?':
	case '@':
	case '[':
	case '\\':
	case ']':
	case '^':
	case '`':
	case '{':
	case '|':
	case '}':
	case '~':	goto yy37;
	default:	goto yy39;
	}
yy37:
	++YYCURSOR;
#line 55 "fastpath.re"
	{ continue; }
#line 311 "fastpath.cpp"
yy39:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy44;
yy40:
#line 108 "fastpath.re"
	{
      heredoc_marker_len = yy - yystart;
      heredoc_marker = (char*)malloc(heredoc_marker_len + 1);
      memcpy(heredoc_marker, yystart, heredoc_marker_len);
      heredoc_marker[heredoc_marker_len] = 0;
      state = HEREDOC;
      continue;
    }
#line 326 "fastpath.cpp"
yy41:
	++YYCURSOR;
#line 51 "fastpath.re"
	{
      result = false;
      break;
    }
#line 334 "fastpath.cpp"
yy43:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
yy44:
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x1F:
	case ' ':
	case '!':
	case '"':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case ':':
	case ';':
	case '<':
	case '=':
	case '>':
	case '?':
	case '@':
	case '[':
	case '\\':
	case ']':
	case '^':
	case '`':
	case '{':
	case '|':
	case '}':
	case '~':	goto yy40;
	default:	goto yy43;
	}
/* *********************************** */
yyc_HTML:
	YYFILL(7);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy50;
	case '<':	goto yy49;
	default:	goto yy47;
	}
yy47:
	++YYCURSOR;
yy48:
#line 55 "fastpath.re"
	{ continue; }
#line 421 "fastpath.cpp"
yy49:
	yych = *++YYCURSOR;
	switch (yych) {
	case '%':	goto yy52;
	case '?':	goto yy54;
	default:	goto yy48;
	}
yy50:
	++YYCURSOR;
#line 51 "fastpath.re"
	{
      result = false;
      break;
    }
#line 436 "fastpath.cpp"
yy52:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy64;
	default:	goto yy53;
	}
yy53:
#line 67 "fastpath.re"
	{
      if (flags.asp_tags) {
        state = PHP;
      }
      continue;
    }
#line 451 "fastpath.cpp"
yy54:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '=':	goto yy58;
	case 'P':
	case 'p':	goto yy56;
	default:	goto yy55;
	}
yy55:
#line 61 "fastpath.re"
	{
      if (flags.short_tags) {
        state = PHP;
      }
      continue;
    }
#line 469 "fastpath.cpp"
yy56:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'H':
	case 'h':	goto yy59;
	default:	goto yy57;
	}
yy57:
	YYCURSOR = YYMARKER;
	goto yy55;
yy58:
	yych = *++YYCURSOR;
	goto yy55;
yy59:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy60;
	default:	goto yy57;
	}
yy60:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case ' ':	goto yy61;
	case '\r':	goto yy63;
	default:	goto yy57;
	}
yy61:
	++YYCURSOR;
yy62:
#line 57 "fastpath.re"
	{
      state = PHP;
      continue;
    }
#line 507 "fastpath.cpp"
yy63:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy61;
	default:	goto yy62;
	}
yy64:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy53;
/* *********************************** */
yyc_PHP:
	YYFILL(8);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy81;
	case '"':	goto yy69;
	case '#':	goto yy70;
	case '%':	goto yy72;
	case '&':	goto yy73;
	case '\'':	goto yy74;
	case ')':	goto yy75;
	case '/':	goto yy76;
	case ':':	goto yy77;
	case '<':	goto yy78;
	case '?':	goto yy79;
	case 'B':
	case 'b':	goto yy80;
	default:	goto yy67;
	}
yy67:
	++YYCURSOR;
yy68:
#line 55 "fastpath.re"
	{ continue; }
#line 543 "fastpath.cpp"
yy69:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x00) goto yy68;
	goto yy84;
yy70:
	++YYCURSOR;
yy71:
#line 86 "fastpath.re"
	{
      state = COMMENT_EOL;
      continue;
    }
#line 557 "fastpath.cpp"
yy72:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy115;
	default:	goto yy68;
	}
yy73:
	yych = *++YYCURSOR;
	switch (yych) {
	case '#':	goto yy107;
	default:	goto yy68;
	}
yy74:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x00) goto yy68;
	goto yy87;
yy75:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy113;
	case '[':	goto yy107;
	default:	goto yy68;
	}
yy76:
	yych = *++YYCURSOR;
	switch (yych) {
	case '*':	goto yy110;
	case '/':	goto yy112;
	case '>':	goto yy107;
	default:	goto yy68;
	}
yy77:
	yych = *++YYCURSOR;
	switch (yych) {
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
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy107;
	case ':':	goto yy108;
	default:	goto yy68;
	}
yy78:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '/':	goto yy94;
	case '<':	goto yy96;
	default:	goto yy68;
	}
yy79:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy92;
	default:	goto yy68;
	}
yy80:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '"':	goto yy83;
	case '\'':	goto yy86;
	default:	goto yy68;
	}
yy81:
	++YYCURSOR;
#line 51 "fastpath.re"
	{
      result = false;
      break;
    }
#line 691 "fastpath.cpp"
yy83:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
yy84:
	switch (yych) {
	case 0x00:	goto yy85;
	case '"':	goto yy89;
	case '\\':	goto yy91;
	default:	goto yy83;
	}
yy85:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy68;
	case 1: 	goto yy95;
	}
yy86:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
yy87:
	switch (yych) {
	case 0x00:	goto yy85;
	case '\'':	goto yy89;
	case '\\':	goto yy88;
	default:	goto yy86;
	}
yy88:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
	goto yy86;
yy89:
	++YYCURSOR;
#line 85 "fastpath.re"
	{ continue; }
#line 729 "fastpath.cpp"
yy91:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
	goto yy83;
yy92:
	++YYCURSOR;
#line 74 "fastpath.re"
	{
      state = HTML;
      continue;
    }
#line 742 "fastpath.cpp"
yy94:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'S':
	case 's':	goto yy100;
	default:	goto yy95;
	}
yy95:
#line 103 "fastpath.re"
	{
      result = true;
      break;
    }
#line 757 "fastpath.cpp"
yy96:
	yych = *++YYCURSOR;
	switch (yych) {
	case '<':	goto yy97;
	default:	goto yy85;
	}
yy97:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case ' ':
	case '"':
	case '\'':	goto yy97;
	default:	goto yy99;
	}
yy99:
#line 94 "fastpath.re"
	{
      state = HEREDOC_START;
      continue;
    }
#line 781 "fastpath.cpp"
yy100:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'C':
	case 'c':	goto yy101;
	default:	goto yy85;
	}
yy101:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'R':
	case 'r':	goto yy102;
	default:	goto yy85;
	}
yy102:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'I':
	case 'i':	goto yy103;
	default:	goto yy85;
	}
yy103:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy104;
	default:	goto yy85;
	}
yy104:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy105;
	default:	goto yy85;
	}
yy105:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy105;
	case '>':	goto yy92;
	default:	goto yy85;
	}
yy107:
	yych = *++YYCURSOR;
	goto yy95;
yy108:
	++YYCURSOR;
#line 98 "fastpath.re"
	{ continue; }
#line 836 "fastpath.cpp"
yy110:
	++YYCURSOR;
#line 90 "fastpath.re"
	{
      state = COMMENT_BLOCK;
      continue;
    }
#line 844 "fastpath.cpp"
yy112:
	yych = *++YYCURSOR;
	goto yy71;
yy113:
	++YYCURSOR;
	YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy113;
	case '[':	goto yy107;
	default:	goto yy85;
	}
yy115:
	++YYCURSOR;
#line 78 "fastpath.re"
	{
      if (flags.asp_tags) {
        state = PHP;
      }
      continue;
    }
#line 869 "fastpath.cpp"
}
#line 146 "fastpath.re"

  }
  if (heredoc_marker) {
    free(heredoc_marker);
  }
  return result;
}
