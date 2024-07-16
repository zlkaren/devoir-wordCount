#include <stdio.h>
#include <stdlib.h>
#include "wc.h"
#include "wc.c"

int  main (int argc,  char * argv[] )
{
		if (argc == 3)
		{
				options(argv[2] , argv[1]);
		}
		else 
		{
			   wc( argv[1]);
		}
		return (0);
}
