#include <cstdio>
#include <stdexcept>

struct Cyberd {
    Cyberd() {
        printf("I'm a friend of Sarah.\n");
    }
    //离开作用域才会调用析构函数
    ~Cyberd() {
        int x = 1;
        throw std::runtime_error{ "I'll be back." };  //2
    }
};

int main() {
    try {
        Cyberd t800;
        //主程序中捕获异常没有弹窗异常警报
        //主程序如果有异常捕获  则不会往下执行  而是直接跳转到析构函数中的异常捕获
        throw std::runtime_error{ "Come with me if you want to live.\n" }; //1
        int x = 2;
    }
    catch (const std::exception& e) {
        printf("Caught exception: %s\n", e.what());
    }
}
