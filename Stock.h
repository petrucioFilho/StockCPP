#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include "Product.h"

class Stock {
private:
    vector<Product> products;
    int cmdGlobal;
    
    void addProduct();
    void showProducts();
    string toLower(const string& str);
    int searchProduct(string productName);
    void updateProduct();

public:
    string line;
    Stock();
    void menu();
};

#endif
