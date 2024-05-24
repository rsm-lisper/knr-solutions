# ifndef SWAP_H
# define SWAP_H

# define swap(T, X, Y) \
  {                    \
    T c = X;           \
    X = Y;             \
    Y = c;             \
  };                   \

# endif
