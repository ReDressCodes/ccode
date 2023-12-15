#include <stdio.h>

static unsigned int hash_from_key_fn(const void *k)
{
        const char *str = k;
        unsigned int hash = 5381;
        char c;

        while ((c = *str++))
                hash = ((hash << 5) + hash) + (unsigned int)c;

        return hash;
}

static unsigned int hash(const void *k)
{
    unsigned int i = hash_from_key_fn(k);
    i += ~(i << 9);
    i ^=  ((i >> 14) | (i << 18)); /* >>> */
    i +=  (i << 4);
    i ^=  ((i >> 10) | (i << 22)); /* >>> */
    return i;
}

int main(int argc, char *argv[])
{
	const char *db_name = "19//local/domain/0";
	const char *db_name1 = "/local/domain/0";

	printf("Hash value %d \n", hash(db_name));
	printf("Hash value %d \n", hash(db_name1));

	return 0;
}
