
#include "../common.hpp"

template <class T>
class NamedObject {
public:
    NamedObject(string& name, const T& value) : name(name), value(value){}

    ~NamedObject() {
        try{
//            print("destruct", 3 / value);
            throw 100;
        }catch (...){
            print("error");
        }
    };

    string& name;
    const T value = 0;

};

class A { public: int a; };
class B : public A { public: int b; };

class C : public B
{
public:
    int c;
};

class A2 { public: virtual void HogeA(); virtual void HogeB(); virtual void HogeC(); };
class B2 : public A2 { public: void HogeB(); void HogeA(); int a; int b; };
class C2 : public A2 { public: void HogeC(); void HogeA(); };


int main() {
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());

    string x = "test";
    NamedObject<double> s(x, 3.5);

    auto t = s;
    print(t.name, t.value);

    NamedObject<int> s2(x, 0);

//    s = t; // エラーになる

//    print(GamePlayer::eps);

    print(sizeof(C));
    int a = 0;
    print(sizeof(&a));
    C c;
    print(sizeof(&c));

    C2 c2;
    print(sizeof(C2));

    return 0;
}
