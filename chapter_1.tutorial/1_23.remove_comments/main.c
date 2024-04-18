
# include <stdio.h>

# define STATE_CODE 0
# define STATE_STRING 1
# define STATE_STRING_ESC 2
# define STATE_CHAR 3
# define STATE_CHAR_ESC 4
# define STATE_SLASH 5
# define STATE_LINECOMMENT 6
# define STATE_BLOCKCOMMENT 7
# define STATE_BLOCKCOMMENT_ASTER 8

# define NOC 0

# define ERR_STATE -1

void pcode ();
void pstring ();
void pstringesc ();
void pchar ();
void pcharesc ();
void pslash ();
void plinecomm ();
void pblockcomm ();
void pblockcommaster ();

void princ ();

int state;
int c, prevc;


int main ()
{
  prevc = NOC;
  state = STATE_CODE;
  while ((c = getchar()) != EOF) {
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
      return ERR_STATE;
    }
  }
  return 0;
}


void pcode ()
{
  switch (c) {
  case '"':
    state = STATE_STRING;
    princ();
    break;
  case '\'':
    state = STATE_CHAR;
    princ();
    break;
  case '/':
    state = STATE_SLASH;
    prevc = c;
    break;
  default:
    princ();
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
  princ();
}


void pstringesc ()
{
  state = STATE_STRING;
  princ();
}


void pchar ()
{
  switch (c) {
  case '\'':
    state = STATE_CODE; break;
  case '\\':
    state = STATE_CHAR_ESC; break;
  }
  princ();
}


void pcharesc ()
{
  state = STATE_CHAR;
  princ();
}


void pslash ()
{
  switch (c) {
  case '/':
    state = STATE_LINECOMMENT;
    prevc = NOC;
    break;
  case '*':
    state = STATE_BLOCKCOMMENT;
    prevc = NOC;
    break;
  default:
    state = STATE_CODE;
    princ();
  }
}


void plinecomm ()
{
  if (c == '\n') {
    state = STATE_CODE;
    princ();
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


void princ ()
{
  if (prevc != NOC) {
    printf("%c", prevc);
    prevc = NOC;
  }
  printf("%c", c);
}
