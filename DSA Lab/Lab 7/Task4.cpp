#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;
};

void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int n = 3;
    Product products[n];

    cout << "Enter details for 3 products:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> products[i].name;
        cout << "Enter price: ";
        cin >> products[i].price;
        cin.ignore();
        cout << "Enter description: ";
        getline(cin, products[i].description);
        cout << "Available (1 for Yes, 0 for No): ";
        cin >> products[i].available;
    }

    quickSort(products, 0, n - 1);

    cout << "\nProducts sorted by price (ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << "\nName: " << products[i].name
             << "\nPrice: $" << products[i].price
             << "\nDescription: " << products[i].description
             << "\nAvailable: " << (products[i].available ? "Yes" : "No") << "\n";
    }

    return 0;
}