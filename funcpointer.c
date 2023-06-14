#define MAKE_FUNC(f) static typeof(f) *p ## f

struct data {
	int data;
	int value;
};

MAKE_FUNC( data );
