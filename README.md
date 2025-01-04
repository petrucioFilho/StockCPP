# StockCPP

This is a C++ project that simulates the management of a product stock. The system allows you to register, update, and view products, as well as search the stock and sort products by price.

## Features

- **Product Registration**: Allows adding a new product to the stock, including name, price, description, and whether the product is for sale.
- **Product Update**: Allows updating the details of an existing product in the stock.
- **Product Viewing**: Displays the products registered in the stock, showing their name, price, and description.
- **Product Search**: Searches for a product by name, ignoring case differences.
- **Price Sorting**: Products are automatically sorted by price, from lowest to highest.

## Project Structure

The code is modularized into different files to improve organization and facilitate code maintenance. Below is an explanation of the structure:

### Files:

1. **`Product.h`**: Header file that defines the `Product` class. This class contains the attributes and methods necessary to represent a product in the stock, such as name, price, description, and sale status.

2. **`Product.cpp`**: Implementation of the `Product` class methods, including getters, setters, and the constructor.

3. **`Stock.h`**: Header file that defines the `Stock` class. This class manages the stock, allowing products to be added, displayed, and updated. It also includes helper methods for product search and sorting.

4. **`Stock.cpp`**: Implementation of the `Stock` class methods, including logic for adding, displaying, updating, and sorting products.

5. **`main.cpp`**: Main file that starts the program and interacts with te user, displaying the menu and calling the functions of the `Stock` class.

### Modularization Details:

- **Product Class**: Encapsulates all the information about a product, such as name, price, description, and whether it is for sale. All methods related to a product (such as displaying and updating information) are within this class.
- **Stock Class**: Manages the stock, storing products in a vector and providing methods to add, display, update, and sort the products. User interaction is also handled here, allowing navigation through the system.

## How to Run

To run this project, you need a C++ compiler installed on your system (e.g., **g++**).

### Steps to Compile and Run:

1. **Run the following command in the terminal to compile**:
   ```bash
    g++ main.cpp Stock.cpp Product.cpp -o stock
   ```
2. **Then, execute the following command**:
   ```bash
    ./stock
   ```
