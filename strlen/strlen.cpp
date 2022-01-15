#include <stdio.h>

size_t strlenx(const char* str) {
	const char* s;
	for (s = str; *s; ++s) {}
	return(s - str);
}



int main(int argc, char** argv)
{
	const char* str = "hellojds";

	size_t a = strlenx(str);
	printf("%zd", a);

	return 0;
}

