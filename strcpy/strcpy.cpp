#include <iostream>
#include <cassert>
//º¯ÊýÔ­ÐÍ  
//char* strcpy(char* to, const char* from);

char* strcpy1(char* to, const char* from)
{
	assert(to != NULL && from != NULL);
	char* p = to;
	while ((*p++ = *from++) != '\0')
	{

	};
	return to;

}



int main(int argc, char** argv)
{
	char str[] = "123456";
	const char* strsnd = "world!";
	char* strend = strcpy1(str, strsnd);

	printf("%s", strend);

	return 0;
}