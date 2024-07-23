#include<iostream>
#include<string>
using namespace std;

class person {
public:
	string name;
	string address;
	string CNIC;
	string cell_no;
	static int count;

	// non-parameterized               // initializer list
	person() : name(""), address(""), CNIC(""), cell_no("") {
		cout << "Inside Person non-parameterized constructor" << endl;
		count++;
	}
	// parameterized                                  // initializer list
	person(string n, string a, string C, string no) : name(n), address(a), CNIC(C), cell_no(no) {
		cout << "Inside Person parameterized constructor" << endl;
		name = n;
		address = a;
		CNIC = C;
		cell_no = no;
	}
	// destructor
	~person() {
		cout << "Inside Person destructor!" << endl;
		count--;
	}
	// getters
	string get_name() { return name; }
	string get_address() { return address; }
	string get_CNIC() { return CNIC; }
	string get_number() { return cell_no; }
	// setters
	void set_name(string n) { name = n; }
	void set_address(string a) { address = a; }
	void set_CNIC(string c) { CNIC = c; }
	void set_number(string no) { cell_no = no; }
	static int get_count() { return count; }
};
class teacher : public person {
public:
	string teacher_ID;
	teacher() : person(), teacher_ID("") {
		cout << "Inside Teacher non-parameterized constructor" << endl;
		count++;
	}
	teacher(string n, string a, string C, string no, string id) : person(n, a, C, no), teacher_ID(id) {
		cout << "Inside Teacher parameterized constructor" << endl;
		teacher_ID = id;
	}
	~teacher() {
		cout << "Inside teacher destructor!" << endl;
		count--;
	}
	string get_teacher() { return teacher_ID; }
	void set_teacherID(string id) { teacher_ID = id; }
	static int get_count() { return count; }

	void print_teacher() const {
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "Cell No: " << cell_no << endl;
		cout << "Teacher ID: " << teacher_ID << endl;
	}
};
class student : public person {
public:
	string student_ID;
	student() : person(), student_ID("") {
		cout << "Inside student non-parameterized constructor" << endl;
		count++;
	}
	student(string n, string a, string C, string no, string id) : person(n, a, C, no), student_ID(id) {
		cout << "Inside student parameterized constructor" << endl;
		student_ID = id;
	}
	~student() {
		cout << "Inside student destructor!" << endl;
		count--;
	}
	string get_student() { return student_ID; }
	void set_studentID(string id) { student_ID = id; }
	static int get_count() { return count; }

	void print_student() const {
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "Cell No: " << cell_no << endl;
		cout << "Teacher ID: " << student_ID << endl;
	}
};

int person::count = 0;

int main() {
	// initializing static data
	person::count = 0;
	teacher::count = 0;
	student::count = 0;

	// non-parameterized
	cout << "NON-PARAMETERIZED:" << endl;
	person PNP;
	cout << "Checking count of person class: " << person::get_count() << endl << endl;

	teacher TNP;
	cout << "Checking count of teacher class: " << teacher::get_count() << endl;
	cout << "Checking count of person class: " << person::get_count() << endl << endl;

	student SNP;
	cout << "Checking count of teacher class: " << teacher::get_count() << endl;
	cout << "Checking count of person class: " << person::get_count() << endl << endl;

	// parameterized
	cout << "PARAMETERIZED:" << endl;
	person PP("person 1", "ABC", "DEF", "1234");
	cout << "Checking count of person class: " << person::get_count() << endl << endl;

	teacher TP("teacher 1", "ABC", "DEF", "1234", "2222");
	cout << "Checking count of teacher class: " << teacher::get_count() << endl;
	cout << "Checking count of person class: " << person::get_count() << endl << endl;

	student SP("student 1", "ELM", "SEF", "4321", "4444");
	cout << "Checking count of teacher class: " << teacher::get_count() << endl;
	cout << "Checking count of person class: " << person::get_count() << endl << endl;
	cout << endl;
	// Updating using mutators
	cout << "USING MUTATORS:" << endl;
	PNP.set_name("person 2");
	PNP.set_address("EFG");
	PNP.set_CNIC("4567");
	PNP.set_number("7890");
	cout << "Name: " << PNP.get_name() << endl;
	cout << "address: " << PNP.get_address() << endl;
	cout << "CNIC: " << PNP.get_CNIC() << endl;
	cout << "Phone Number: " << PNP.get_number() << endl << endl;

	TNP.set_name("TEACHER 2");
	TNP.set_address("HHH");
	TNP.set_CNIC("9087");
	TNP.set_number("4520");
	TNP.set_teacherID("9999");
	cout << "Name: " << TNP.get_name() << endl;
	cout << "address: " << TNP.get_address() << endl;
	cout << "CNIC: " << TNP.get_CNIC() << endl;
	cout << "Phone Number: " << TNP.get_number() << endl;
	cout << "Teacher ID: " << TNP.get_teacher() << endl << endl;

	SNP.set_name("STUDENT 2");
	SNP.set_address("FGH");
	SNP.set_CNIC("5678");
	SNP.set_number("8901");
	SNP.set_studentID("7777");
	cout << "Name: " << SNP.get_name() << endl;
	cout << "address: " << SNP.get_address() << endl;
	cout << "CNIC: " << SNP.get_CNIC() << endl;
	cout << "Phone Number: " << SNP.get_number() << endl;
	cout << "Student ID: " << SNP.get_student() << endl << endl;

	// showing data using printperson functions
	cout << "USING FUNCTIONS:" << endl;
	cout << "Showing data using print_teacher function" << endl;
	TP.print_teacher();
	cout << endl;
	cout << "Showing data using print_student function" << endl;
	SP.print_student();
	cout << endl;

	return 0;
}
