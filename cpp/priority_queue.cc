#include <iostream>

template<typename T>

class PriorityQueue
{
	public:

	PriorityQueue();
	~PriorityQueue();


	int sort();
	int pop();
	int insert();

	private:

	struct data{
		int opcode;
		int timestamp;
		std::string value;
	};

	std::vector<data> db;
};


int main(int argc, char *argv[])
{
	return 0;
}
