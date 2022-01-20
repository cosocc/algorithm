#include <cstdio>


struct Element{
	Element* next{};
	void insert_after(Element* new_element) {
		new_element->next = next;
		next = new_element;
	}
	char prefix[2]{};
	short operating_number{};
};

int main(int argc, char** argv) {
	Element tr1, tr2, tr3;
	tr1.prefix[0] = 'o';
	tr1.prefix[1] = 'p';
	tr1.operating_number = 1;
	tr1.insert_after(&tr2);

	tr2.prefix[0] = 'q';
	tr2.prefix[1] = 'r';
	tr2.operating_number = 2;
	tr2.insert_after(&tr3);


	tr3.prefix[0] = 's';
	tr3.prefix[1] = 't';
	tr3.operating_number = 3;

	for (Element*  cursor = &tr1 ; cursor ; cursor=cursor->next){
		printf("tr %c,%c = %d \n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
	}

}