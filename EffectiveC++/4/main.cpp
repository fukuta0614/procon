
#include "../common.hpp"

enum class Month;

class Date {
public:
    Date(Month month, int day, int year){
        print(static_cast<int>(month), day, year);
    }

    int x, y;
};

enum class Month {
    Jan = 1,
    Feb = 2,
    Dec = 12
};

class Window {
public:
    string name;

    explicit Window(string& name): name(name){}

    virtual void display() const{
        print("window display");
    }
};

class WindowWithScrollBars: public Window{
public:
    explicit WindowWithScrollBars(string& name) : Window(name) {}

    void display() const override{
        print("Window with scroll bars");
    }
};


void printNameAndDisplay(Window w){

    print(w.name);
    w.display();
}

void print_int(int&& x){
    print(x);
}

void print_int(int& x){
    print(x);
}


class IntGenerator {

public:

    int v = 0;

    explicit IntGenerator(int v) : v(v) {}

    int& get_int() const {
        int x;
        x = v;
        return x;
    };

    int* get_int_heap() const{
        int* x = new int(v);
        return x;
    }

    int& get_int_static() const{
        static int x;
        x = v;
        return x;
    }
};

int main() {
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());

//    Date d(Month::Jan, 10, 10);
//
//    auto m2 = static_cast<Month>(12);
//    Date d2(m2, 10, 10);
//
//    auto m3 = static_cast<Month>(3);
//    Date d3(m3, 10, 10);
//
//    auto m4 = static_cast<Month>(13);
//    Date d4(m4, 10, 10);

    string s = "w2";
    WindowWithScrollBars w(s);

    printNameAndDisplay(w);

//    int x = 1;
//    print_int(x);
//    print_int(x+1);


    IntGenerator g(10);

    int* p = g.get_int_heap();
    print(*p);

    int& a = g.get_int_static();
    print(a);
    g.v = 20;
    int& b = g.get_int_static();
    print(a, b);

    return 0;
}
