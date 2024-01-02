#include <iostream>
#include <iomanip>
#include <fstream>
#include "equipment.h"
#include "branch.h"
#include "orders.h"

using namespace std;

const int row = 10;


equipment equiparr[row];

branch brancharr[row];

equipment1 equiparr1[row];

branch1 brancharr1[row];

order orderarr[row];

void storedata(equipment(*arr), string file) {
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < row; i++) {
		fout << arr[i].id << " " << arr[i].name << " " << arr[i].price << " " << arr[i].manufacturer << endl;
	}
	fout.close();
}
void loaddata(equipment(*arr), string file) {
	ifstream fin;
	fin.open(file);
	for (int i = 0; i < row; i++) {
		fin >> arr[i].id >> arr[i].name >> arr[i].price >> arr[i].manufacturer;
	}
	fin.close();
}

void storedata(branch(*arr), string file) {
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < row; i++) {
		fout << arr[i].id << " " << arr[i].name << " " << arr[i].cap << " " << arr[i].current << endl;
	}
	fout.close();
}
void loaddata(branch(*arr), string file) {
	ifstream fin;
	fin.open(file);
	for (int i = 0; i < row; i++) {
		fin >> arr[i].id >> arr[i].name >> arr[i].cap >> arr[i].current;
	}
	fin.close();
}

void storedata(order(*arr), string file) {
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < row; i++) {
		fout << arr[i].branch << " " << arr[i].equipid << " " << arr[i].quantity << " " << arr[i].total << endl;
	}
	fout.close();
}
void loaddata(order(*arr), string file) {
	ifstream fin;
	fin.open(file);
	for (int i = 0; i < row; i++) {
		fin >> arr[i].branch >> arr[i].equipid >> arr[i].quantity >> arr[i].total;
	}
	fin.close();
}

void storedata(equipment1(*arr), string file) {
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < row; i++) {
		fout << arr[i].id << " " << arr[i].name << " " << arr[i].price << " " << arr[i].manufacturer << endl;
	}
	fout.close();
}
void loaddata(equipment1(*arr), string file) {
	ifstream fin;
	fin.open(file);
	for (int i = 0; i < row; i++) {
		fin >> arr[i].id >> arr[i].name >> arr[i].price >> arr[i].manufacturer;
	}
	fin.close();
}

void storedata(branch1(*arr), string file) {
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < row; i++) {
		fout << arr[i].id << " " << arr[i].name << " " << arr[i].cap << " " << arr[i].current << endl;
	}
	fout.close();
}
void loaddata(branch1(*arr), string file) {
	ifstream fin;
	fin.open(file);
	for (int i = 0; i < row; i++) {
		fin >> arr[i].id >> arr[i].name >> arr[i].cap >> arr[i].current;
	}
	fin.close();
}

void storecount(int count){
	ofstream fout;
	fout.open("countdata.txt");
	fout << count;
	fout.close();
}

void getcount(int* arraycounter) {
	ifstream fin;
	fin.open("countdata.txt");
	fin >> *arraycounter;
}

int arraycounter;

void choicedisplay();

void landingpage();

void choicedisplay2();

int main() {
	loaddata(equiparr, "equipdata.txt");
	loaddata(brancharr, "branchdata.txt");
	loaddata(equiparr1, "equipdata.txt");
	loaddata(brancharr1, "branchdata.txt");
	loaddata(orderarr, "orderdata.txt");
	getcount(&arraycounter);
	landingpage();
}

void choicedisplay() {
	char choice;
	cout << "GYM EQUIPMENT MANAGEMENT SYSTEM! \n";
	cout << "Press 1. To add new equipment. \nPress 2. To view existing records. \nPress 3. To search. \nPress 4. To Update Price. \nPress 5. To Delete a Record. \nPress 6. To go back. \n";
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case '1':
		addequipment(equiparr, row);
		break;
	case '2':
		dispequipments(equiparr, row);
		break;
	case '3':
		search(equiparr, row);
		break;
	case '4':
		updaterecord(equiparr, row);
		break;
	case '5':
		deleterecord(equiparr, row);
		break;
	case '6':
		storedata(equiparr, "equipdata.txt");
		cout << "DATABASE CLOSED!";
		cout << endl;
		landingpage();
	default:
		cout << "Invalid Choice! \n";
		cout << endl;

	}
}
void choicedisplay2() {
	char choice;
	cout << "GYM BRANCH MANAGEMENT SYSTEM! \n";
	cout << "Press 1. To add new branch. \nPress 2. To view existing records. \nPress 3. To search. \nPress 4. To Update Current Members. \nPress 5. To delete a record. \nPress 6. To go back. \n"; //Display options
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case '1':
		addbranch(brancharr, row);
		break;
	case '2':
		viewarr(brancharr, row);
		break;
	case '3':
		checkbranch(brancharr, row);
		break;
	case '4':
		updatemembers(brancharr, row);
		break;
	case '5':
		deletebranch(brancharr, row);
		break;
	case '6':
		storedata(brancharr, "branchdata.txt");
		cout << "DATABASE CLOSED!" << endl;
		cout << endl;
		landingpage();
	default:
		cout << "Invalid Choice! \n";
		cout << endl;

	}
}

void choicedisplay3() {
	char choice;
	cout << "GYM EQUIPMENT ORDERING SYSTEM! \n";
	cout << "Press 1. To place new order. \nPress 2. To view orders placed \nPress 3.To go back.\n";
	cout << "Enter choice : ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case '1':
		addorder(orderarr, equiparr1, brancharr1, row, &arraycounter);
		break;
	case'2':
		vieworder(orderarr, equiparr1, brancharr1, row, &arraycounter);
		break;
	case '3':
		storedata(orderarr, "orderdata.txt");
		storecount(arraycounter);
		cout << "DATABASE CLOSED! \n";
		cout << endl;
		landingpage();
	default:
		cout << "Invalid Choice! \n";
		cout << endl;
	}
}

void landingpage() {
	char option;
	cout << "Press 1. To open Gym equipment mangment system. \nPress 2. To open Gym branch managment system.\nPress 3. To open Order managment system. \nPress 4. To exit.\n"; //Display options
	cout << "Enter choice : ";
	cin >> option;
	cout << endl;
	switch (option) {
	case '1':
		while (true) {
			choicedisplay();
		}
	case '2':
		while (true) {
			choicedisplay2();
		}
	case '3':
		while (true) {
			choicedisplay3();
		}
	case '4':
		cout << "PROGRAM CLOSED!";
		exit(0);
	}
}

