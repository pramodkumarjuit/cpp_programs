#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass(int val) : value(val) { std::cout << "Constructor: " << value << "\n"; }
        ~MyClass() { std::cout << "Destructor: " << value << "\n"; }
        void show() { std::cout << "Value: " << value << "\n"; }

    private:
        int value;
};

#if 1
// No change in reference Count if passed by ref
void fun(std::shared_ptr<MyClass> myClass) {
//void fun(MyClass *myClass) {
    std::cout << "Enter fun(): " << std::endl;
    myClass->show();
    std::cout << "Reference Count: " << myClass.use_count() << "\n";
    std::cout << "Exit fun(): " << std::endl;
}
#endif
/**
 * ✅ std::make_shared<MyClass>(20) returns an object of std::shared_ptr<MyClass>, not a raw pointer.
 * ✅ std::shared_ptr<MyClass> manages memory automatically.
 * ✅ When the last shared_ptr is destroyed, MyClass is deleted automatically.
 */
int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(20);  // Create shared_ptr
    {
        std::shared_ptr<MyClass> ptr2 = ptr1;  // Shared ownership
        std::cout << "Reference Count: " << ptr1.use_count() << "\n";
        ptr2->show();
    }  // ptr2 goes out of scope, but ptr1 is still valid


    fun(ptr1);
//    fun(ptr1.get()); // Use .get() to Get the Raw Pointer for legacy API or passing to a func that doesn't accept std::shared_ptr

    std::cout << "Reference Count: " << ptr1.use_count() << "\n";
    return 0;  // Object deleted only when last reference goes out of scope
}

