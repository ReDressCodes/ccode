#include <stdio.h>
#include <stdlib.h>

/* This is an attempt at solving the problem of memory overcommitment
 * in Linux kernel io-uring.
 *
 * This is something that will often happens when requests are being made into the queue and responses are not being processed. This issues forces io-uring to commit more memory than should be allowed by the size of the queue as propositioned at the point of creation of the queue.
 * This issue affect multiple endspoints. For instance;
 *
 *         - user makes poll requests which are subsequently not completed but instead they end up sleeping in the ring. The user then continued to make more similar requests and makes so many of such requests that, for instance, if they had requested that the ring is 500 requests deep, we end up with 2000 or even much more request sleeping in the ring.
 *         - user instruct the ring not to process more requests before the current request is completed. At the same time, the user continues to make more requests into the queue. io-uring has no choice but to process the requests but keep them waiting in the queue. If the user makes too many requests than was indicated originally, then the queue eventually contains too many requests than originally requested. This leads to memory overcommitment.
 *
 *         - user fails to responds to CQEs and this leads to an overflow queue being created. The ring is then forced to allocate memory because the CQE queue is full. Adding too many items into the overflow queue leads to memory overcommitment.
 *
 *         
 *
 * The above could be termed as memory ballooning, which is great until is goes beyond certain limits and could lead to security issues.
 *
 * At the same time, this is a complicated issue that is probably not easy to solve.
 *
 */


#define MAX_COUNT  500;

struct request {

	int opcode;
	time_t timestamp;
	struct request *prev;
	struct request *next;
};

typedef struct list
{
	struct request *req;
	int count;
	int max_count;
}list;

static void init_req(struct request *req)
{
	req = malloc(sizeof(struct request));

	req->request = 0;
	time(&request->timestamp);

	req->next = NULL;
	req->prev = NULL;
}

static void init_list(struct list *list)
{
	list->req = NULL;
	list->count = 0;
	list->max_count = MAX_COUNT;
}

static bool list_empty(struct list *list)
{
	if (!list->req) return true;
	else return false;
}

static int add_head(struct list *list, struct request *req)
{
	if (list_empty(list))
	{
		list->req = req;
		list->req->prev = req;
		list->req->next = req;
		return 0;
	}

	struct request *tmp = req;

	list->req  = req;
	list->req->next = tmp;
	list->req->prev = tmp->prev;
	tmp->prev = list->req->next;
}

static struct req * remove_object(struct list *list, struct req *req)
{
	req->prev->next = req->next;
	req->next->prev = 
}

int main(int argc, char *argv[])
{

	return 0;
}
