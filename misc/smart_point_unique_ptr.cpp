#include <iostream>
#include <memory>  // For smart pointers

class MyClass {
public:
    MyClass(int val) : value(val) { std::cout << "Constructor: " << value << "\n"; }
    ~MyClass() { std::cout << "Destructor: " << value << "\n"; }
    void show() { std::cout << "Value: " << value << "\n"; }

private:
    int value;
};

int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(10);  // Create unique_ptr
    ptr1->show();

    // incorrect usage - only using std::move it can be assigned
    //std::unique_ptr<MyClass> ptr3 = ptr1;

    // Transfer ownership using std::move
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
    if (!ptr1) std::cout << "ptr1 is now null\n";

    ptr2->show();  // ptr2 now owns the object

    return 0;  // Object is deleted automatically
}

