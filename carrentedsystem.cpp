#include <iostream>
#include <string>
using namespace std;

const int max_cars = 100;

struct Car {
    int id;
    string brand;
    string model;
    double price_per_day;
    bool isrented;
};

void addCar(Car cars[], int& carCount) {
    if (carCount >= max_cars) {
        cout << "Over limit. Cannot add more cars.\n";
    
    }

    Car car;
    cout << "\nEnter Car ID: ";
    cin >> car.id;
    cout << "Enter Car Brand: ";
    cin >> car.brand;
    cout << "Enter Car Model: ";
    cin >> car.model;
    cout << "Enter Price per Day: ";
    cin >> car.price_per_day;
    car.isrented = false;

    cars[carCount] = car;
    carCount++;

    cout << "Car added successfully!\n";
}

void displayAvailableCars(const Car cars[], int carCount) {
    cout << "\n--- Available Cars ---\n";
    bool found = false;

    for (int i = 0; i < carCount; ++i) {
        if (!cars[i].isrented) {
            cout << "ID: " << cars[i].id
                 << ", Brand: " << cars[i].brand
                 << ", Model: " << cars[i].model
                 << ", Price/Day: $" << cars[i].price_per_day << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No cars available.\n";
    }
}

void rentCar(Car cars[], int carCount) {
    int carid;
    cout << "Enter Car ID to rent: ";
    cin >> carid;

    for (int i = 0; i < carCount; ++i) {
        if (cars[i].id == carid) {
            if (cars[i].isrented) {
                cout << "The car is already rented.\n";
            } else {
                cars[i].isrented = true;
                cout << "Car rented successfully.\n";
            }
            
        }
    }

    cout << "Car ID not found.\n";
}

void returnCar(Car cars[], int carCount) {
    int carid;
    cout << "Enter Car ID to return: ";
    cin >> carid;

    for (int i = 0; i < carCount; ++i) {
        if (cars[i].id == carid) {
            if (cars[i].isrented) {
                cars[i].isrented = false;
                cout << "Car return successful.\n";
            } else {
                cout << "This car was not rented.\n";
            }
        
        }
    }

    cout << "Car ID not found.\n";
}

int main() {
    Car cars[max_cars];
    int carCount = 0;
    int ch;

    do {
        cout << "\n--- Car Rental System ---\n";
        cout << "1. Add Car\n";
        cout << "2. Display Available Cars\n";
        cout << "3. Rent a Car\n";
        cout << "4. Return a Car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                addCar(cars, carCount);
                break;
            case 2:
                displayAvailableCars(cars, carCount);
                break;
            case 3:
                rentCar(cars, carCount);
                break;
            case 4:
                returnCar(cars, carCount);
                break;
            case 5:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 5);

    return 0;
}
