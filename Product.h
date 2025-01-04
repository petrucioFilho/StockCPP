#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
    Product(string productName = "Produto", double value = 0.0, string newDescription = "Novo produto", bool sale = false);
    ~Product();

    string getProductName();
    double getProductPrice();
    string getProductDescription();
    bool getProductForSale();
    void showProduct();
    void updateProduct(string productName, double value, string newDescription, bool sale);

private:
    string name;
    string description;
    double price;
    bool forSale;

    void setPrice(double price);
    void setForSale(bool forSale);
    void setDescription(string description);
    void setName(string name);
};

#endif
