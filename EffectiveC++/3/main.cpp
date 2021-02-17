
#include "../common.hpp"
#include "customer.h"

class Widget {
public:
    Widget() : x(0), y(0) {print("Widget constructor");}
    Widget(int x, int y) : x(x), y(y) {print("Widget constructor");}
    ~Widget() {print("Widget destructor", x, y);};

    int x, y;
};

int get_priority(){
    print("get_priority");
    return 100;
}

void processWidget(shared_ptr<Widget> pw, int priority){
    print("process", pw->x, pw->y);
}

void print_int(int a, int b){
    print(a, b);
}

void test(){
    print("");
    processWidget(shared_ptr<Widget>(new Widget(1, 2)), get_priority());


    print("");
    auto pw = shared_ptr<Widget>(new Widget(3, 4));
    processWidget(pw, get_priority());
    print("");

    processWidget(make_shared<Widget>(5, 6), get_priority());

    print("");
    auto pw2 = make_shared<Widget>(7, 8);
    processWidget(pw2, get_priority());

    auto pw3 = allocate_shared<Widget>(allocator<int>(), 9, 10);
    processWidget(pw3, get_priority());

    print("main end");

    int x = 10;
    print_int(x++, x++);
}

int main() {
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());


    PriorityCustomer pc;

    print(pc)


    return 0;
}
