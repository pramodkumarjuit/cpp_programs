#include <iostream>
#include <memory>  // For std::unique_ptr
#include <string>

// Product Abstract Class
class Product {
    public:
        virtual void use() = 0;  // Pure virtual function
        virtual ~Product() = default;
};

// Concrete Product A
class ProductA : public Product {
    public:
        void use() override {
            std::cout << "Using Product A" << std::endl;
        }
};

// Concrete Product B
class ProductB : public Product {
    public:
        void use() override {
            std::cout << "Using Product B" << std::endl;
        }
};

// Simple Factory Class (Singleton)
class ProductFactory {
    private:
        // Private constructor to prevent instantiation
        ProductFactory() {}

    public:
        // Delete copy constructor and assignment operator to ensure singleton property
        ProductFactory(const ProductFactory&) = delete;
        ProductFactory& operator=(const ProductFactory&) = delete;

        // Static method to get the instance of the singleton
        static ProductFactory& getInstance() {
            static ProductFactory instance;
            return instance;
        }

        // Factory method to create products
        std::unique_ptr<Product> createProduct(const std::string& type) {
            if (type == "A") {
                return std::make_unique<ProductA>();
            } else if (type == "B") {
                return std::make_unique<ProductB>();
            } else {
                return nullptr;
            }
        }
};

int main() {
    // Access the singleton factory instance and create products
    ProductFactory& factory = ProductFactory::getInstance();

    // Create Product A
    std::unique_ptr<Product> productA = factory.createProduct("A");
    if (productA) {
        productA->use();  // Output: Using Product A
    }

    // Create Product B
    std::unique_ptr<Product> productB = factory.createProduct("B");
    if (productB) {
        productB->use();  // Output: Using Product B
    }

    // Trying to create a product that doesn't exist
    std::unique_ptr<Product> productInvalid = factory.createProduct("C");
    if (!productInvalid) {
        std::cout << "Invalid product type" << std::endl;  // Output: Invalid product type
    }

    return 0;
}

