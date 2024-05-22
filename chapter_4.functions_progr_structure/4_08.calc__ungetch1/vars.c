
double vars['Z'-'A'];
double last_val;


/* set_var: set variable */
void set_var (char var_name, double value)
{
  vars[var_name-'A'] = value;
}


/* get_var: get variable value */
double get_var (char var_name)
{
  return vars[var_name-'A'];
}


/* set_last: set last returned value */
double set_last (double value)
{
  return last_val = value;
}


/* get_last: get last returned value */
double get_last (void)
{
  return last_val;
}
