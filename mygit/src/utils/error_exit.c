#include "miniRT.h"

void	error_exit(int code)
{
	if (code == -1)
		print_errorl("Error: Can't allocate memory for new element");
	exit(code);
}

