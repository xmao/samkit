#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "ids") == 0) {
	if (argc > 3) {
	    sam_ids(argv[2], atoi(argv[3]));
	} else {
	    sam_ids(argv[2], 0);	    
	}
    } else if (strcmp(argv[1], "loc") == 0) {
	sam_loc(argv[2]);
    }
    
    return 0;
}
