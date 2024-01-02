using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>

struct branch {
	int id, cap, current;
	string name;
};

void addbranch(branch arr[], int row) {
	for (int i = 0; i < row; i++) {
		if (arr[i].id == 0) {
			cout << "Enter branch # : ";
			cin >> arr[i].id;
			cout << "Enter branch reg# : ";
			cin >> arr[i].name;
			cout << "Enter branch maximum capacity : ";
			cin >> arr[i].cap;
			cout << "Enter branch current members : ";
			cin >> arr[i].current;
			break;
		}
	}
	cout << endl;
}
void viewarr(branch arr[], int row) {
	cout << left << setw(15) << "Branch#" << left << setw(15) << "BranchReg#" << left << setw(15) << "BranchCap" << left << setw(15) << "BranchMembers" << endl;
	cout << endl;
	for (int i = 0; i < row; i++) {
		if (arr[i].id != 0) {
			cout << left << setw(15) << arr[i].id << left << setw(15) << arr[i].name << left << setw(15) << arr[i].cap << left << setw(15) << arr[i].current << endl;
		}
		else {
			break;
		}
	}
	cout << endl;
}
void checkbranch(branch arr[], int row) {
	int branch;
	bool checkstatus = false;
	cout << "Enter to branch # to search : ";
	cin >> branch;
	cout << endl;
	for (int i = 0; i < row; i++) {
		if (arr[i].id == branch) {
			cout << left << setw(15) << "Branch#" << left << setw(15) << "BranchReg#" << left << setw(15) << "BranchCap" << left << setw(15) << "BranchMembers" << endl;
			cout << endl;
			cout << left << setw(15) << arr[i].id << left << setw(15) << arr[i].name << left << setw(15) << arr[i].cap << left << setw(15) << arr[i].current << endl;
			checkstatus = true;
			break;
		}
	}
	if (checkstatus == false) {
		cout << "Branch does not exist in database!" << endl;
	}
	cout << endl;
}
void updatemembers(branch arr[], int row) {
	int branch;
	bool checkexist = false;
	cout << "Enter branch# whose members to update : ";
	cin >> branch;
	for (int i = 0; i < row; i++) {
		if (arr[i].id == branch) {
			cout << "Enter new member count : ";
			cin >> arr[i].current;
			checkexist = true;
			break;
		}
	}
	if (checkexist == false) {
		cout << "Branch does not exist in database!" << endl;
	}
	cout << endl;
}

void deletebranch(branch arr[], int row) {
	int branch;
	cout << "Enter branch you want to remove : ";
	cin >> branch;
	cout << endl;
	for (int i = 0; i < row; i++) {
		if (arr[i].id == branch) {
			for (int j = i; j < row-1; j++) {
				arr[j].id = arr[j + 1].id;
				arr[j].name = arr[j + 1].name;
				arr[j].cap = arr[j + 1].cap;
				arr[j].current = arr[j + 1].current;
			}
			break;
		}
	}
}






