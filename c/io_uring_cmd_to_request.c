#include <stdio.h>

#define _GNU_SOURCE
#include <sys/types.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct object {
	int id;
	int status;
	int data;
	int last_modified;
};

struct data {
	struct object *obj;
	int reserved[4];
};

struct req {
	union {
		struct object *obj;
		struct data cmd;
	};

	uint8_t opcode;
	uint8_t flags;
	uint8_t fd;
	uint8_t fd_out;
	
	uint16_t buf_index;
	uint16_t iopoll_completed;

	uint64_t values;
};

struct specific_op {
	struct object *obj_out;
	loff_t off_out;
	loff_t off_in;
};

int main(int argc, char *argv[])
{
	struct req *request = malloc(sizeof(struct req));

	request->obj = malloc(sizeof(struct object));

	memset(request->obj, 3, sizeof(struct object));

	request->cmd.reserved[0] = 50;
	request->cmd.reserved[1] = 10;
	request->cmd.reserved[3] = 30;
	request->cmd.reserved[2] = 40;

	printf(" %d \n", request->obj->id);
	printf(" Reserved %d \n", request->cmd.reserved[0]);
	printf(" Reserved %d \n", request->cmd.reserved[1]);
	printf(" Reserved %d \n", request->cmd.reserved[2]);
	printf(" Reserved %d \n", request->cmd.reserved[3]);

	return 0;
}
