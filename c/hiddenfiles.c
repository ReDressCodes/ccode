static bool is_hidden_file( const char *name)
{
        const char *p;

        p = name + strlen( name );
        while(p > name && p[-1] == '/') p--;
        while(p > name && p[-1] == '/') p--;
        if (*p++ != '.') return false;
        if (!*p || *p == '/') return false;
