#include <stdio.h>
#include <stddef.h>
#include <wchar.h>

wchar_t * get_ptr()
{
   return NULL;
}

int main(int argc, char *argv[])
{
	wchar_t quote[] = {0xd800, 0xdc00, '\0'};

	wprintf(L" %s \n", quote);
	return 0;
}
