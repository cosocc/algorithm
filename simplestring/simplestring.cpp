#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString 
{
	SimpleString(size_t max_size) :max_size{ max_size }, length{} 
	{
		if (!max_size)
		{
			throw std::runtime_error{ "Max size must be at leasr 1." };
		}
		buffer = new char[max_size];
		buffer[0] = 0;
	}
	~SimpleString()
	{
		delete[] buffer;
	}

	void print(const char* tag) const
	{
		printf("%s:%s", tag, buffer);
	}

	bool append_line(const char * x)
	{
		const auto x_len = strlen(x);
		if (x_len+length >max_size)
			return false;
		strncpy(buffer + length, x, max_size - length);
		length += x_len;
		buffer[length++] = '\n';
		buffer[length] = 0;
		return true;
	}

private:
	size_t max_size;
	char* buffer;
	size_t length;
};

int main(int argc, char** argv)
{
	SimpleString  strtest{ 115 }, strtest1{115};
	strtest.append_line("beijing whaddya hear ?");
	strtest.append_line("the capital of china!");
	strtest.print("ritian.zhao:");//58

	//if (!strtest.append_line("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"))//70
	//	printf("String was not big enough to append another message!");


	strtest1.append_line("I live there for eight years!");
	strtest1.append_line("It's a very nice city!");
	strtest1.print("hansan.hu:");



	return 0;
}