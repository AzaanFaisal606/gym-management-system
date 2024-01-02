using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>

struct order {
	int branch, equipid, quantity;
	double total;
};

struct equipment1 {
	int id;
	string name, manufacturer;
	double price;
};

struct branch1 {
	int id, cap, current;
	string name;
};

void addorder(order(*orderarr),equipment1(*equiparr),branch1(*brancharr), int row,int* arraycounter) {
	int branch, equip;
	bool checkbranch = false;
	bool checkequip = false;
	cout << "Enter Branch# to Order for : ";
	cin >> branch;
	cout << endl;
	while (checkbranch == false) {	
		for (int i = 0; i < row; i++) {
			if (brancharr[i].id == branch) {
				cout << left << setw(15) << "Branch#" << left << setw(15) << "BranchReg#" << left << setw(15) << "BranchCap" << left << setw(15) << "BranchMembers" << endl;
				cout << endl;
				cout << left << setw(15) << brancharr[i].id << left << setw(15) << brancharr[i].name << left << setw(15) << brancharr[i].cap << left << setw(15) << brancharr[i].current << endl;
				cout << endl;
				cout << "Branch selected" << endl;
				cout << endl;
				orderarr[*arraycounter].branch = i;
				checkbranch = true;
				break;
			}
		}
		if (checkbranch == false) {
			cout << "Sorry Branch does not exist try again : ";
			cin >> branch;
		}
	}
	cout << "Enter ID of equipment to order : ";
	cin >> equip;
	cout << endl;
	while (checkequip == false) {
		for (int i = 0; i < row; i++) {
			if (equiparr[i].id == equip) {
				cout << left << setw(15) << "ID" << left << setw(15) << "Name" << left << setw(15) << "Price" << left << setw(15) << "Manufacturer" << endl;
				cout << endl;
				cout << left << setw(15) << equiparr[i].id << left << setw(15) << equiparr[i].name << left << setw(15) << equiparr[i].price << left << setw(15) << equiparr[i].manufacturer << endl;
				cout << endl;
				cout << "Equipment selected" << endl;
				cout << endl;
				orderarr[*arraycounter].equipid = i;
				checkequip = true;
				break;
			}
		}
		if (checkequip == false) {
			cout << "Sorry Equipment does not exist try again : ";
			cin >> equip;
		}
	}
	cout << "Enter quantity to order : ";
	cin >> orderarr[*arraycounter].quantity;
	cout << endl;
	orderarr[*arraycounter].total = orderarr[*arraycounter].quantity * equiparr[orderarr[*arraycounter].equipid].price;
	cout << "Order Details : " << endl;
	cout << endl;
	cout << left << setw(15) << "Branch#" << left << setw(15) << "Branch Name" << left << setw(15) << "Equipment ID" << left << setw(15) << "Equipment Name" << left << setw(15) << "Quantity" << left << setw(15) << "Total" << endl;
	cout << endl;
	cout << left << setw(15) << brancharr[orderarr[*arraycounter].branch].id << left << setw(15) << brancharr[orderarr[*arraycounter].branch].name << left << setw(15) << equiparr[orderarr[*arraycounter].equipid].id << left << setw(15) << equiparr[orderarr[*arraycounter].equipid].name << left << setw(15) << orderarr[*arraycounter].quantity << left << setw(15) << orderarr[*arraycounter].total << endl;
	cout << endl;
	*arraycounter = *arraycounter + 1;
}
void vieworder(order(*orderarr), equipment1(*equiparr), branch1(*brancharr), int row,int* arraycounter) {
	cout << left << setw(15) << "Branch#" << left << setw(15) << "Branch Name" << left << setw(15) << "Equipment ID" << left << setw(15) << "Equipment Name" << left << setw(15) << "Quantity" << left << setw(15) << "Total" << endl;
	for (int i = 0; i < *arraycounter; i++) {
		cout << left << setw(15) << brancharr[orderarr[i].branch].id << left << setw(15) << brancharr[orderarr[i].branch].name << left << setw(15) << equiparr[orderarr[i].equipid].id << left << setw(15) << equiparr[orderarr[i].equipid].name << left << setw(15) << orderarr[i].quantity << left << setw(15) << orderarr[i].total << endl;
	}
	cout << endl;
}
