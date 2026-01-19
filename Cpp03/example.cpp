// file: example.cpp
#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base::show\n"; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived::show\n"; }
    ~Derived() {}
};

int main() {
    Base* b = new Derived();
    b->show();
    delete b;
    return 0;
}
