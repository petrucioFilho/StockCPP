#include "Product.h"
#include <iostream>
#include <string>

Product::Product(string productName, double value, string newDescription, bool sale) {
    name = productName;
    price = value;
    description = newDescription;
    forSale = sale;
}

Product::~Product() {}

string Product::getProductName() {
    return name;
}

double Product::getProductPrice() {
    return price;
}

string Product::getProductDescription() {
    return description;
}

bool Product::getProductForSale() {
    return forSale;
}

void Product::showProduct() {
    cout << "Nome: " << name << endl;
    cout << "Preço: " << price << endl;
    // cout << "Descrição: " << description << endl;
    // cout << "Para venda: " << (forSale ? "Sim" : "Não") << endl;
}

void Product::updateProduct(string productName, double value, string newDescription, bool sale) {
    if (productName != "") { setName(productName); }
    if (value > 0) { setPrice(value); }
    if (newDescription != "") { setDescription(newDescription); }
    if (sale != forSale) { setForSale(sale); }
}

void Product::setPrice(double price) {
    if (price < 0) {
        cout << "Preço inválido" << endl;
        return;
    }
    this->price = price;
}

void Product::setForSale(bool forSale) {
    this->forSale = forSale;
}

void Product::setDescription(string description) {
    this->description = description;
}

void Product::setName(string name) {
    this->name = name;
}
