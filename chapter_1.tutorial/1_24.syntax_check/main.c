
# include <stdio.h>
# include <stdlib.h>

# define STATE_CODE 0
# define STATE_STRING 1
# define STATE_STRING_ESC 2
# define STATE_CHAR 3
# define STATE_CHAR_ESC 4
# define STATE_SLASH 5
# define STATE_LINECOMMENT 6
# define STATE_BLOCKCOMMENT 7
# define STATE_BLOCKCOMMENT_ASTER 8

# define ERROR_BRACKETS_LIMIT_REACHED 1
# define ERROR_UNKNOWN_STATE 2
# define ERROR_UNKNOWN_SYNTAX_ERROR 3

# define BRACKETS_LIMIT 1000

# define SYNERR_BRACKETS_DONT_MATCH 1
# define SYNERR_OPEN_BRACKETS 2
# define SYNERR_NO_BRACKETS 3
# define SYNERR_EOF_IN_STRING 4
# define SYNERR_EOF_IN_CHAR 5
# define SYNERR_EOF_IN_BLOCKCOMMENT 6

void pcode ();
void pstring ();
void pstringesc ();
void pchar ();
void pcharesc ();
void pslash ();
void plinecomm ();
void pblockcomm ();
void pblockcommaster ();

void brackets_push ();
void brackets_pop ();
void display_brackets ();
void syntax_message ();
void internal_error ();

int error, syntax_error, c,
  state = STATE_CODE,
  bindex = 0,
  file_line = 1,
  file_pos = 0;
char brackets[BRACKETS_LIMIT];


int main ()
{
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      file_line++;
      file_pos = 0;
    } else {
      file_pos++;
    }
    switch (state) {
    case STATE_CODE:
      pcode(); break;
    case STATE_STRING:
      pstring(); break;
    case STATE_STRING_ESC:
      pstringesc(); break;
    case STATE_CHAR:
      pchar(); break;
    case STATE_CHAR_ESC:
      pcharesc(); break;
    case STATE_SLASH:
      pslash(); break;
    case STATE_LINECOMMENT:
      plinecomm(); break;
    case STATE_BLOCKCOMMENT:
      pblockcomm(); break;
    case STATE_BLOCKCOMMENT_ASTER:
      pblockcommaster(); break;
    default:
      error = ERROR_UNKNOWN_STATE;
      internal_error();
    }
  }
  if (bindex > 0) {
    syntax_error = SYNERR_OPEN_BRACKETS;
    syntax_message();
  }
  switch (state) {
  case STATE_STRING: case STATE_STRING_ESC:
    syntax_error = SYNERR_EOF_IN_STRING;
    syntax_message(); break;
  case STATE_CHAR: case STATE_CHAR_ESC:
    syntax_error = SYNERR_EOF_IN_CHAR;
    syntax_message(); break;
  case STATE_BLOCKCOMMENT: case STATE_BLOCKCOMMENT_ASTER:
    syntax_error = SYNERR_EOF_IN_BLOCKCOMMENT;
    syntax_message(); break;
  }
  return 0;
}


void pcode ()
{
  switch (c) {
  case '{': case '(': case '[':
    brackets_push(); break;
  case '}': case ')': case ']':
    brackets_pop(); break;
  case '"':
    state = STATE_STRING; break;
  case '\'':
    state = STATE_CHAR; break;
  case '/':
    state = STATE_SLASH; break;
  }
}


void pstring ()
{
  switch (c) {
  case '"':
    state = STATE_CODE; break;
  case '\\':
    state = STATE_STRING_ESC; break;
  }
}


void pstringesc ()
{
  state = STATE_STRING;
}


void pchar ()
{
  switch (c) {
  case '\'':
    state = STATE_CODE; break;
  case '\\':
    state = STATE_CHAR_ESC; break;
  }
}


void pcharesc ()
{
  state = STATE_CHAR;
}


void pslash ()
{
  switch (c) {
  case '/':
    state = STATE_LINECOMMENT; break;
  case '*':
    state = STATE_BLOCKCOMMENT; break;
  default:
    state = STATE_CODE;
  }
}


void plinecomm ()
{
  if (c == '\n') {
    state = STATE_CODE;
  }
}


void pblockcomm ()
{
  if (c == '*') {
    state = STATE_BLOCKCOMMENT_ASTER;
  }
}


void pblockcommaster ()
{
  switch (c) {
  case '/':
    state = STATE_CODE; break;
  case '*':
    break;
  default:
    state = STATE_BLOCKCOMMENT;
  }
}


void brackets_push ()
{
  if (bindex < BRACKETS_LIMIT) {
    brackets[bindex++] = c;
  } else {
    error = ERROR_BRACKETS_LIMIT_REACHED;
    internal_error();
  }
}


void brackets_pop ()
{
  char b;

  if (bindex > 0) {
    b = brackets[--bindex];
    if ((b == '(' && c != ')') || (b == '{' && c != '}')
        || (b == '[' && c != ']')) {
      syntax_error = SYNERR_BRACKETS_DONT_MATCH;
      syntax_message();
    }
  } else {
    syntax_error = SYNERR_NO_BRACKETS;
    syntax_message();
  }
}


void display_brackets ()
{
  for (int q = 0; q < bindex; q++) {
    if (q > 0) printf(" ");
    printf("%c", brackets[q]);
  }
}


void syntax_message ()
{
  printf("* Syntax Error, line %d, position %d: ", file_line, file_pos);
  switch (syntax_error) {
  case SYNERR_BRACKETS_DONT_MATCH:
    printf("brackets don't match '%c' =/= '%c'.\n", brackets[bindex+1], c);
    printf("  Brackets[] = ");
    display_brackets();
    printf("\n");
    break;
  case SYNERR_OPEN_BRACKETS:
    printf("brackets still not closed at the end of file ");
    display_brackets();
    printf(".\n"); break;
  case SYNERR_NO_BRACKETS:
    printf("there is no bracket to be closed by '%c'.\n", c); break;
  case SYNERR_EOF_IN_STRING:
    printf("string still not closed at the end of file.\n"); break;
  case SYNERR_EOF_IN_CHAR:
    printf("character still not closed at the end of file.\n"); break;
  case SYNERR_EOF_IN_BLOCKCOMMENT:
    printf("block comment still not closed at the end of file.\n"); break;
  default:
    error = ERROR_UNKNOWN_SYNTAX_ERROR;
    internal_error();
  }
}


void internal_error ()
{
  printf("[INTERNAL ERROR]\n");
  switch (error) {
  case ERROR_BRACKETS_LIMIT_REACHED:
    printf("brackets[] limit (%d) reached.\n", BRACKETS_LIMIT); break;
  case ERROR_UNKNOWN_STATE:
    printf("Unknown state (%d).\n", state); break;
  default:
    printf("Unknown error (%d).\n", error);
  }
  exit(EXIT_FAILURE);
}
