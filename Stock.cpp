#include "Stock.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

Stock::Stock() : cmdGlobal(0) {}

void Stock::addProduct() {
    system("clear||cls");
    string productName = "";
    double value;
    string newDescription;
    int sale;
    cout << "Cadastro de Produto\n";
    cout << "----------------------------------\n";
    cout << "Digite o nome do produto:\n";
    cin >> productName;

    cout << "Digite o valor do produto:\n";
    cin >> value;

    cout << "Digite a descrição do produto:\n";
    cin.ignore();
    getline(cin, newDescription);

    cout << "O produto está a venda? (1 para sim, 0 para não)\n";
    cin >> sale;

    Product *prod = new Product(productName, value, newDescription, sale == 1 ? true : false);
    products.push_back(*prod);

    sort(products.begin(), products.end(), [](Product& a, Product& b) {
        return a.getProductPrice() < b.getProductPrice();
    });

    showProducts();
    system("clear||cls");
}

void Stock::showProducts() {
    system("clear||cls");
    cmdGlobal = 0;
    cout << "--------------------------------------------------------"<< endl;
    if (products.size() == 0) {
        cout << "Nenhum produto cadastrado" << endl;
    }
    for (auto product : products) {
        product.showProduct();
        cout << "--------------------------------------------------------"<< endl;
    }

    cout << "Digite o número do comando desejado\n";
    cout << "1.Menu  2.Cadastrar Produto\n";
    while (1) {
        cin >> cmdGlobal;
        if (cmdGlobal == 1) {
            break;
        }
        if (cmdGlobal == 2) {
            addProduct();
            break;
        }
    }
}

string Stock::toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int Stock::searchProduct(string productName) {
    for (size_t i = 0; i < products.size(); i++) {
        if (toLower(products[i].getProductName()) == toLower(productName)) {
            return i;
        }
    }
    cout << "Produto não encontrado" << endl;
    return -1;
}

void Stock::updateProduct() {
    string productName = "";
    string newName = "";
    double value = 0.0;
    string newDescription = "";
    int sale = 0;

    cout << "Atualizar o Produto\n";
    cout << "----------------------------------\n";
    cout << "Digite o nome do produto que deseja atualizar:\n";
    cin >> productName;

    cout << "Digite o novo nome do produto caso deseja atualizar:\n";
    cin >> newName;

    cout << "Digite o novo valor do produto:\n";
    cin >> value;

    cout << "Digite a nova descrição do produto:\n";
    cin.ignore();
    getline(cin, newDescription);

    cout << "O produto está a venda? (1 para sim, 0 para não)\n";
    cin >> sale;

    int index = searchProduct(productName);
    if (index != -1) {
        products[index].updateProduct(newName, value, newDescription, sale == 1 ? true : false);
    }

    sort(products.begin(), products.end(), [](Product& a, Product& b) {
        return a.getProductPrice() < b.getProductPrice();
    });
}

void Stock::menu() {
    while (true) {
        system("clear||cls");
        cout << "-------------------Estoque-------------------" << endl
             << "###########################################" << endl
             << "Escolha uma opção para fazer com seus produtos:" << endl
             << "1. Adicionar          " << endl
             << "2. Ver                " << endl
             << "3. Atualizar          " << endl
             << "4. Sair               " << endl
             << "###########################################" << endl
             << "------------------------------------------------------------" << endl;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (line == "4") {
            system("clear||cls");
            break;
        } else if (cmd == "1") {
            system("clear||cls");
            addProduct();
        } else if (cmd == "2") {
            system("clear||cls");
            showProducts();
        } else if (cmd == "3") {
            system("clear||cls");
            updateProduct();
        }
        cout << "--------------------------------------------------------" << endl;
    }
}
