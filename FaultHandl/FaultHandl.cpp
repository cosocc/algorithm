#include <cstdio>
#include <stdexcept>

struct Cyberd {
    Cyberd() {
        printf("I'm a friend of Sarah.\n");
    }
    //�뿪������Ż������������
    ~Cyberd() {
        int x = 1;
        throw std::runtime_error{ "I'll be back." };  //2
    }
};

int main() {
    try {
        Cyberd t800;
        //�������в����쳣û�е����쳣����
        //������������쳣����  �򲻻�����ִ��  ����ֱ����ת�����������е��쳣����
        throw std::runtime_error{ "Come with me if you want to live.\n" }; //1
        int x = 2;
    }
    catch (const std::exception& e) {
        printf("Caught exception: %s\n", e.what());
    }
}
