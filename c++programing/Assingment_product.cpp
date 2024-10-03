#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

struct Product {
    int id;
    std::string name;
    std::string category;
    int quantity;
    
    Product(int pid, std::string pname, std::string pcategory, int pquantity)
        : id(pid), name(pname), category(pcategory), quantity(pquantity) {}
};

class Inventory {
private:
    std::unordered_map<int, Product> products;  
    std::multimap<std::string, int> categoryMap; 

public:
    
    void addProduct(int id, std::string name, std::string category, int quantity) {
        if (products.find(id) != products.end()) {
            std::cout << "Product ID " << id << " already exists.\n";
            return;
        }

        Product newProduct(id, name, category, quantity);
        products[id] = newProduct;
        categoryMap.insert({category, id});
        std::cout << "Product added: " << name << " in category: " << category << "\n";
    }

    
    void updateStockQuantity(int id, int newQuantity) {
        auto it = products.find(id);
        if (it != products.end()) {
            it->second.quantity = newQuantity;
            std::cout << "Updated product ID " << id << " to quantity: " << newQuantity << "\n";
        } else {
            std::cout << "Product with ID " << id << " not found.\n";
        }
    }

    
    std::vector<Product> searchByCategory(const std::string& category) {
        std::vector<Product> results;
        auto range = categoryMap.equal_range(category);
        
        for (auto it = range.first; it != range.second; ++it) {
            int productId = it->second;
            results.push_back(products[productId]);
        }

        if (results.empty()) {
            std::cout << "No products found in category: " << category << "\n";
        }
        
        return results;
    }

    
    void printProductDetails(const Product& product) {
        std::cout << "ID: " << product.id 
                  << " | Name: " << product.name 
                  << " | Category: " << product.category 
                  << " | Quantity: " << product.quantity << "\n";
    }
};
int main() {
    Inventory inventory;
    
    
    inventory.addProduct(101, "Laptop", "Electronics", 50);
    inventory.addProduct(102, "Smartphone", "Electronics", 100);
    inventory.addProduct(103, "Shirt", "Clothing", 200);
    inventory.addProduct(104, "Pants", "Clothing", 150);

    
    inventory.updateStockQuantity(102, 80);  

    
    std::vector<Product> electronics = inventory.searchByCategory("Electronics");
    std::cout << "Products in Electronics category:\n";
    for (const auto& product : electronics) {
        inventory.printProductDetails(product);
    }

    std::vector<Product> clothing = inventory.searchByCategory("Clothing");
    std::cout << "Products in Clothing category:\n";
    for (const auto& product : clothing) {
        inventory.printProductDetails(product);
    }

    return 0;
}
