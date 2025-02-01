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

int main() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(30);
    std::weak_ptr<MyClass> weakPtr = sharedPtr;  // weak_ptr does not increase reference count

    std::cout << "Use count: " << sharedPtr.use_count() << "\n";

    if (auto locked = weakPtr.lock()) {  // Check if object still exists
        locked->show();
    } else {
        std::cout << "Object no longer exists\n";
    }

    sharedPtr.reset();  // Manually release ownership

    if (weakPtr.expired()) {
        std::cout << "Object deleted, weak_ptr is now expired\n";
    }

    return 0;
}

