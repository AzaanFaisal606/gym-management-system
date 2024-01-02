using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>


struct equipment {
	int id;
	string name, manufacturer;
	double price;
};

void addequipment(equipment(*arr), int row) {
	for (int i = 0; i < row; i++) {
		if (arr[i].id == 0) {
			cout << "Enter equipment ID : ";
			cin >> arr[i].id;
			cout << "Enter equipment Name : ";
			cin >> arr[i].name;
			cout << "Enter equipment Price : ";
			cin >> arr[i].price;
			cout << "Enter equipment Manufacturer : ";
			cin >> arr[i].manufacturer;
			break;
		}
	}
	cout << endl;
}
void dispequipments(equipment(*arr), int row) {
	cout << left << setw(15) << "ID" << left << setw(15) << "Name" << left << setw(15) << "Price" << left << setw(15) << "Manufacturer" << endl;
	cout << endl;
	for (int i = 0; i < row; i++) {
		if (arr[i].id != 0) {
			cout << left << setw(15) << arr[i].id << left << setw(15) << arr[i].name << left << setw(15) << arr[i].price << left << setw(15) << arr[i].manufacturer << endl;
		}
		else {
			break;
		}
	}
	cout << endl;
}
void search(equipment(*arr), int row) {
	int equipment;
	bool checkstatus = false;
	cout << "Enter to equipment id to search : ";
	cin >> equipment;
	cout << endl;
	for (int i = 0; i < row; i++) {
		if (arr[i].id == equipment) {
			cout << left << setw(15) << "ID" << left << setw(15) << "Name" << left << setw(15) << "Price" << left << setw(15) << "Manufacturer" << endl;
			cout << endl;
			cout << left << setw(15) << arr[i].id << left << setw(15) << arr[i].name << left << setw(15) << arr[i].price << left << setw(15) << arr[i].manufacturer << endl;
			checkstatus = true;
			break;
		}
	}
	if (checkstatus == false) {
		cout << "Equipment does not exist in database!" << endl;
	}
	cout << endl;
}
void updaterecord(equipment(*arr), int row) {
	int equipment;
	bool checkexist = false;
	cout << "Enter equipment id for price update : ";
	cin >> equipment;
	for (int i = 0; i < row; i++) {
		if (arr[i].id == equipment) {
			cout << "Enter new price : ";
			cin >> arr[i].price;
			checkexist = true;
			break;
		}
	}
	if (checkexist == false) {
		cout << "Equipment does not exist in database!" << endl;
	}
	cout << endl;
}

void deleterecord(equipment(*arr), int row) {
	int equipment;
	cout << "Enter equipment id you want to remove : ";
	cin >> equipment;
	cout << endl;
	for (int i = 0; i < row; i++) {
		if (arr[i].id == equipment) {
			for (int j = i; j < row-1; j++) {
				arr[j].id = arr[j + 1].id;
				arr[j].name = arr[j + 1].name;
				arr[j].price = arr[j + 1].price;
				arr[j].manufacturer = arr[j + 1].manufacturer;
			}
			break;
		}
	}
}