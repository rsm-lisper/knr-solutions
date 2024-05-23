# ifndef VARS_H
# define VARS_H

/* set_var: set variable */
void set_var (char var_name, double value);

/* get_var: get variable value */
double get_var (char var_name);

/* set_last: set last returned value */
double set_last (double value);

/* get_last: get last returned value */
double get_last (void);

#endif
