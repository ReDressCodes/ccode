#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <vector>

class Reader {

	public:
	Reader(size_t read_size)
	{
		this->read_size = read_size;

		this->file = new std::fstream("irclog.txt", std::fstream::in | std::fstream::out);
		this->already_read = 0;

		this->file->seekg(0, this->file->end);
		this->file_size = this->file->tellg();
		this->file->seekg(0, this->file->beg);

		for (int i = 0; i < 8; i++){
			threads.push_back(new std::thread(Reader::Read, std::ref(this->read_size)));
		}
	}

	~Reader()
	{
		for (auto &t: this->threads) { t->join(); }

		for (auto t: this->threads) { delete t; }

		this->file->close();
		delete file;

		this->Output();
	}

	static void Read(size_t read_size)
	{
		while (1) {
			mutex.lock();

			size_t to_read = file_size - already_read;

			if (to_read > read_size)
			{
				to_read = read_size;
			}

			std::string data(to_read, '\0');
			file->read(&data[0], to_read);

			file_contents.push_back(data);

			already_read += to_read;

			if (to_read < read_size) { mutex.unlock(); break; }

			mutex.unlock();
		}
	}

	void Output()
	{
		for(auto &s: this->file_contents) { std::cout << s; }
	}

private:
	inline static size_t read_size;
	inline static size_t file_size;
	inline static size_t already_read;

	std::vector<std::thread*> threads;
	/* protect the private members against concurrent access by multiple threads */
	inline static std::mutex mutex;
	inline static std::fstream *file;
	inline static std::vector<std::string> file_contents;
};

int main(int argc, char *argv[])
{

	Reader *reader = new Reader(1024);

	delete reader;

	return 0;
}
