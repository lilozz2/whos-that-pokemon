/*----------------------------------------------------------------------------
POKEMON.H

Note: #define VAR_DECLS 1 before including this file to DECLARE and INITIALIZE
global variables.  Include this file without defining VAR_DECLS to extern
these variables.
----------------------------------------------------------------------------*/
#ifndef VAR_DEFS          // Make sure this file is included only once
#define VAR_DEFS 1

/*----------------------------------------------
Setup variable declaration macros.
----------------------------------------------*/
#ifndef VAR_DECLS
# define _DECL extern
# define _INIT(x)
#else
# define _DECL
# define _INIT(x)  = x
#endif

/*----------------------------------------------
Declare variables as follows:

_DECL [standard variable declaration] _INIT(x);

where x is the value with which to initialize
the variable.  If there is no initial value for
the varialbe, it may be declared as follows:

_DECL [standard variable declaration];
----------------------------------------------*/

_DECL const unsigned char Rx _INIT(96);
_DECL const unsigned char Ry _INIT(64);

typedef struct item{
  int posX;
  int posY;
  long SPRITE_XY;
  long SPRITE;
  unsigned char shadow;
  int flip;
  struct item *next;
} ITEM;
typedef ITEM *ITEM_POINTER;

#endif
/*----------------------------------------------------------------------------
----------------------------------------------------------------------------*/
