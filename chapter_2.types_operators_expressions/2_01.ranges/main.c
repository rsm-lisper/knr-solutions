
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>


void progr_d (int modu, int val);
void progr_u (unsigned int modu, unsigned int val);
void progr_ld (long int modu, long int val);
void progr_lu (unsigned long int modu, unsigned long int val);
void clear_progr ();


int main ()
{
  signed long long int c_min, c_max, sc_min, sc_max, uc_min, uc_max;
  char c, cp;
  signed char sc, scp;
  unsigned char uc, ucp;

  signed long long int s_min, s_max, ss_min, ss_max, us_min, us_max;
  short s, sp;
  signed short ss, ssp;
  unsigned short us, usp;

  signed long long int i_min, i_max, si_min, si_max, ui_min, ui_max;
  int i, ip;
  signed int si, sip;
  unsigned int ui, uip;

  signed long long int li_min, li_max, sli_min, sli_max, uli_min, uli_max;
  long int li, lip;
  signed long int sli, slip;
  unsigned long int uli, ulip;
  
  printf("[type]\t\t\t[computed]\t\t\t[defined]\n"
         "\t\t\t[min ~ max]\t\t\t[min ~ max]\n");

  // char /////
  for (cp=10, c=9; cp>c; cp=c, --c) progr_d(10, cp);
  clear_progr();
  c_min = cp;
  for (cp=0, c=1; cp<c; cp=c, ++c) progr_d(10, cp);
  clear_progr();
  c_max = cp;
  printf("char:\t\t\t%lld ~ %lld\t\t\t%d ~ %d\n",
         c_min, c_max, CHAR_MIN, CHAR_MAX);
  
  for (scp=10, sc=9; scp>sc; scp=sc, --sc) progr_d(10, scp);
  clear_progr();
  sc_min = scp;
  for (scp=0, sc=1; scp<sc; scp=sc, ++sc) progr_d(10, scp);
  clear_progr();
  sc_max = scp;
  printf("signed char:\t\t%lld ~ %lld\t\t\t%d ~ %d\n",
         sc_min, sc_max, SCHAR_MIN, SCHAR_MAX);
  
  for (ucp=10, uc=9; ucp>uc; ucp=uc, --uc) progr_d(10, ucp);
  clear_progr();
  uc_min = ucp;
  for (ucp=0, uc=1; ucp<uc; ucp=uc, ++uc) progr_d(10, ucp);
  clear_progr();
  uc_max = ucp;
  printf("unsigned char:\t\t%lld ~ %lld\t\t\t\t%d ~ %d\n",
         uc_min, uc_max, 0, UCHAR_MAX);

  // short /////
  for (sp=10, s=9; sp>s; sp=s, --s) progr_d(1000, sp);
  clear_progr();
  s_min = sp;
  for (sp=0, s=1; sp<s; sp=s, ++s) progr_d(1000, sp);
  clear_progr();
  s_max = sp;
  printf("short:\t\t\t%lld ~ %lld\t\t\t%d ~ %d\n",
         s_min, s_max, SHRT_MIN, SHRT_MAX);

  for (ssp=10, ss=9; ssp>ss; ssp=ss, --ss) progr_d(1000, ssp);
  clear_progr();
  ss_min = ssp;
  for (ssp=0, ss=1; ssp<ss; ssp=ss, ++ss) progr_d(1000, ssp);
  clear_progr();
  ss_max = ssp;
  printf("signed short:\t\t%lld ~ %lld\t\t\t%d ~ %d\n",
         ss_min, ss_max, SHRT_MIN, SHRT_MAX);

  for (usp=10, us=9; usp>us; usp=us, --us) progr_d(1000, usp);
  clear_progr();
  us_min = usp;
  for (usp=0, us=1; usp<us; usp=us, ++us) progr_d(1000, usp);
  clear_progr();
  us_max = usp;
  printf("unsigned short:\t\t%lld ~ %lld\t\t\t%d ~ %d\n",
         us_min, us_max, 0, USHRT_MAX);

  // int /////
  for (ip=10, i=9; ip>i; ip=i, --i) progr_d(1000000, ip);
  clear_progr();
  i_min = ip;
  for (ip=0, i=1; ip<i; ip=i, ++i) progr_d(1000000, ip);
  clear_progr();
  i_max = ip;
  printf("int:\t\t\t%lld ~ %lld\t%d ~ %d\n",
         i_min, i_max, INT_MIN, INT_MAX);
  
  for (sip=10, si=9; sip>si; sip=si, --si) progr_d(1000000, sip);
  clear_progr();
  si_min = sip;
  for (sip=0, si=1; sip<si; sip=si, ++si) progr_d(1000000, sip);
  clear_progr();
  si_max = sip;
  printf("signed int:\t\t%lld ~ %lld\t%d ~ %d\n",
         si_min, si_max, INT_MIN, INT_MAX);
  
  for (uip=10, ui=9; uip>ui; uip=ui, --ui) progr_u(1000000, uip);
  clear_progr();
  ui_min = uip;
  for (uip=0, ui=1; uip<ui; uip=ui, ++ui) progr_u(1000000, uip);
  clear_progr();
  ui_max = uip;
  printf("unsigned int:\t\t%lld ~ %lld\t\t\t%u ~ %u\n",
         ui_min, ui_max, 0, UINT_MAX);

  // long int /////
  for (lip=10, li=9; lip>li; lip=li, --li) progr_ld(1000000, lip);
  clear_progr();
  li_min = lip;
  for (lip=0, li=1; lip<li; lip=li, ++li) progr_ld(1000000, lip);
  clear_progr();
  li_max = lip;
  printf("long int:\t\t%lld ~ %lld\t%ld ~ %ld\n",
         li_min, li_max, LONG_MIN, LONG_MAX);

  for (slip=10, sli=9; slip>sli; slip=sli, --sli) progr_ld(1000000, slip);
  clear_progr();
  sli_min = slip;
  for (slip=0, sli=1; slip<sli; slip=sli, ++sli) progr_ld(1000000, slip);
  clear_progr();
  sli_max = slip;
  printf("signed long int:\t%lld ~ %lld\t%ld ~ %ld\n",
         sli_min, sli_max, LONG_MIN, LONG_MAX);
  
  for (ulip=10, uli=9; ulip>uli; ulip=uli, --uli) progr_lu(1000000, ulip);
  clear_progr();
  uli_min = ulip;
  for (ulip=0, uli=1; ulip<uli; ulip=uli, ++uli) progr_lu(1000000, ulip);
  clear_progr();
  uli_max = ulip;
  printf("unsigned long int:\t%lld ~ %lld\t\t%d ~ %lu\n",
         uli_min, uli_max, 0, ULONG_MAX);

  return 0;
}


void progr_d (int modu, int val)
{
  if (val % modu == 0) {
    printf("%d   \r", val);
  }
}


void progr_u (unsigned int modu, unsigned int val)
{
  if (val % modu == 0) {
    printf("%u   \r", val);
  }
}


void progr_ld (long int modu, long int val)
{
  if (val % modu == 0) {
    printf("%ld   \r", val);
  }
}


void progr_lu (unsigned long int modu, unsigned long int val)
{
  if (val % modu == 0) {
    printf("%lu   \r", val);
  }
}


void clear_progr ()
{
  printf("                              \r");
}
