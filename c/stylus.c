
#include <stdio.h>
#include <ctype.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

static BOOL match_token(const char *haystack, const char *needle)
{
    const char *p, *q;
    for (p = haystack; *p; )
    {
        while (*p && isspace(*p))
            p++;
        if (! *p)
            break;

        for (q = needle; *q && *p && tolower(*p) == tolower(*q); q++)
            p++;
        if (! *q && (isspace(*p) || !*p))
            return TRUE;

        while (*p && ! isspace(*p))
            p++;
    }
    return FALSE;
}

 static BOOL is_tablet_cursor(const char *name, const char *type)
 {
     int i;
      static const char *tablet_cursor_allowlist[] = {
          "wacom",
          "wizardpen",
          "acecad",
          "tablet",
          "cursor",
          "stylus",
          "eraser",
          "pad",
          NULL
      };

      for (i=0; tablet_cursor_allowlist[i] != NULL; i++) {
          if (name && match_token(name, tablet_cursor_allowlist[i]))
              return TRUE;
          if (type && match_token(type, tablet_cursor_allowlist[i]))
              return TRUE;
      }
      return FALSE;
  }

int main(void) {
	BOOL result = is_tablet_cursor( "xwayland tablet stylus:10", "xwayland-pointer" ) ;
	printf( "result is: %d\n", result); // prints 0
	return 0;
}
