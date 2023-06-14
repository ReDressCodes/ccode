#include <stdio.h>

int __attribute__((warn_unused_result)) test_function()
{
	return 0;
}

int main(int argc, char *argv[])
{
	int ( __attribute__((warn_unused_result)) *fn_ptr) (void);

	fn_ptr = test_function;

	fn_ptr();

	return 0;
}
