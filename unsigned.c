#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define XENSTORE_RING_SIZE 1024
#define MASK_XENSTORE_IDX(idx) ((idx) & (XENSTORE_RING_SIZE-1))

bool check_indexes(uint32_t prod, uint32_t cons)
{
	return ((prod - cons) <= XENSTORE_RING_SIZE);
}

struct data{
	char data[XENSTORE_RING_SIZE];

	char test;
	uint32_t prod, cons;
};

int main()
{
    uint32_t prod = -1;
    uint32_t cons = 0;
    uint32_t len;
    struct data mydata;
    char copied[50] = { 0 };

    len = prod - cons;
    memset(&mydata, 0, sizeof(struct data));
    mydata.test = 'c';

    if (!check_indexes(prod, cons)) printf("Sorry, got caught\n");


    printf(" %u \n", len);

    printf("Masked value producer : %d \n", MASK_XENSTORE_IDX(prod));
    printf("Masked value consumer : %d \n", MASK_XENSTORE_IDX(cons));

    memset(mydata.data, 'x', XENSTORE_RING_SIZE);
    memcpy(copied, mydata.data + prod + 1, 1);

    printf(" %s \n", copied);

    return 0;
}
