#include <windows.h>
#include <msiquery.h>
#include <cstdio>

static UINT do_query(MSIHANDLE hdb, const char *query, MSIHANDLE *phrec)
{
    MSIHANDLE hview = 0;
    UINT r, ret;

    if (phrec)
        *phrec = 0;

    /* open a select query */
    r = MsiDatabaseOpenViewA(hdb, query, &hview);
    if (r != ERROR_SUCCESS)
        return r;
    r = MsiViewExecute(hview, 0);
    if (r != ERROR_SUCCESS)
        return r;
    ret = MsiViewFetch(hview, phrec);
    r = MsiViewClose(hview);
    if (r != ERROR_SUCCESS)
        return r;
    r = MsiCloseHandle(hview);
    if (r != ERROR_SUCCESS)
        return r;
    return ret;
}

int main(int argc, char *argv[])
{
    MSIHANDLE hdb, hrec;
    DWORD sz;
    UINT r;
    const char *msifile = "db1.msi";
    char buffer[10000];

    r = MsiOpenDatabaseA(msifile, MSIDBOPEN_READONLY, &hdb);
    if (r != ERROR_SUCCESS) printf("Couldn't open database \n");

    r = do_query(hdb, "SELECT * FROM `Control`", &hrec);
    if (r != ERROR_SUCCESS) printf("Couldn't query database \n");

    buffer[0] = 0;
    sz = sizeof(buffer);
    r = MsiRecordGetStringA( hrec, 2, buffer, &sz);
    if (r != ERROR_SUCCESS) printf("failed to get string\n");

    printf(" %s\n", buffer);

    return 0;
}


