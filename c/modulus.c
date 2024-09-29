#include <stdio.h>
#include <stdint.h>

#define DICT_HASH_MOD 1201

static uint32_t get_num_hash(float num)
{
    uint32_t x = (*((uint32_t*)&num)) % DICT_HASH_MOD;
    printf("get_num_hash: num=%f, hash=%u\n", num, x);
    return (*((uint32_t*)&num)) % DICT_HASH_MOD;
}

int main(int argc, char* argv[])
{
    float num = 2175;

    get_num_hash(num);

    num = 6259;

    get_num_hash(num);

    num = 6200;

    get_num_hash(num);

    return 0;
}
