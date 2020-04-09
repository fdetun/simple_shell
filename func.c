#include "simple_shell.h"
/**
 * print_prompt - print the prompt
*/
void print_prompt ()
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
