#include <stdio.h>
#include <string.h>
#include <time.h>
#include <liburing.h>
#include <unistd.h>

#define RING_DEPTH 4

int main() {
    struct io_uring ring;
    struct io_uring_sqe *sqe;
    struct io_uring_cqe *cqe;
    struct __kernel_timespec ts;
    int shared_data = 0;

    // 1. Initialize the io_uring instance
    if (io_uring_queue_init(RING_DEPTH, &ring, 0) < 0) {
        fprintf(stderr, "Error initializing io_uring\n");
        return 1;
    }

    printf("Setting up a 2-second timeout...\n");

    ts.tv_sec = 1; // make this as fast as possible :-)
    ts.tv_nsec = 0;

    sqe = io_uring_get_sqe(&ring);
    if (!sqe) {
	    fprintf(stderr, "Could not get SQE\n");
	    return 1;
    }
    
    io_uring_prep_timeout(sqe, &ts, 0, 0);
    
    io_uring_sqe_set_data64(sqe, 42);
    
    io_uring_submit(&ring);

    pid_t pid = fork();

    if (pid == 0) {

	    for (int i = 0; i < 10; i++) {
		    
		    printf("Waiting for timeout to fire...\n");
		    int ret = io_uring_wait_cqe(&ring, &cqe);

		    /* don't update value, just continue :-) */
		    if (cqe->user_data != 42) { i--; continue;}
		    
		    if (ret < 0) {
			    fprintf(stderr, "Error waiting for CQE\n");
			    return 1;
		    }
		    
		    printf("Timeout triggered! CQE User Data: %llu\n", (unsigned long long)cqe->user_data);

		    printf("CQE Result (Expected -ETIME/-62): %d\n", cqe->res);
		    if (cqe->res == -ETIME) {
			    printf("Success: The timer expired normally.\n");
		    }
		    
		    io_uring_cqe_seen(&ring, cqe);
		    
		    shared_data++;

		    printf("thread :%d, updated shared_data to : %d \n", getpid(), shared_data);
		    
		    sqe = io_uring_get_sqe(&ring);
		    
		    if (!sqe) {
			    fprintf(stderr, "Could not get SQE\n");
			    return 1;
		    }
		    
		    io_uring_prep_timeout(sqe, &ts, 0, 0);
		    
		    io_uring_sqe_set_data64(sqe, 10);
		    
		    io_uring_submit(&ring);
	    }
	    
    }
    else
    {
	    for (int i = 0; i < 10; i++) {
		    printf("Waiting for timeout to fire...\n");
		    int ret = io_uring_wait_cqe(&ring, &cqe);

		    if (cqe->user_data != 10) {i--; continue; }
		    
		    if (ret < 0) {
			    fprintf(stderr, "Error waiting for CQE\n");
			    return 1;
		    }
		    
		    printf("Timeout triggered! CQE User Data: %llu\n", (unsigned long long)cqe->user_data);
		    
		    printf("CQE Result (Expected -ETIME/-62): %d\n", cqe->res);
		    if (cqe->res == -ETIME) {
			    printf("Success: The timer expired normally.\n");
		    }
		    
		    io_uring_cqe_seen(&ring, cqe);
		    
		    shared_data++;

		    printf("thread :%d, updated shared_data to : %d \n", getpid(), shared_data);
		    
		    sqe = io_uring_get_sqe(&ring);
		    
		    if (!sqe) {
			    fprintf(stderr, "Could not get SQE\n");
			    return 1;
		    }
		    
		    io_uring_prep_timeout(sqe, &ts, 0, 0);
		    
		    io_uring_sqe_set_data64(sqe, 42);
		    
		    io_uring_submit(&ring);
	    }
    }
    
    io_uring_queue_exit(&ring);

    return 0;
}

