#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Node {
	string fullname;
	string name;
	int age;
	float diem;
	Node* next;
};

struct Linked_list {
	Node* head;
	int length;
};

void clear() {
	cout << "\n\n(#) Nhan vao phim bat ki de tro ve menu.";
	int x = _getch();
	system("cls");
}

void print(Linked_list* list) {
	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!";
		return;
	}
	cout << "\t(*) In thanh cong!\n\n";
	cout << "\t" << "+" << setfill('-') << setw(10) << "+"
		<< setw(30) << "+" << setw(10) << "+"
		<< setw(10) << "+" << "\n";
	cout << "\t" << "|" << left << setfill(' ')
		<< setw(9) << " STT"
		<< setw(30) << "| Ho Ten"
		<< setw(10) << "| Tuoi"
		<< setw(10) << "| Diem" << "|\n";
	cout << "\t" << "+" << right << setfill('-')
		<< setw(10) << "+" << setw(30) << "+"
		<< setw(10) << "+" << setw(10) << "+" << "\n";
	int i = 1;
	Node* p = list->head;
	while (p != NULL) {
		cout << "\t" << "|" << left << setfill(' ')
			<< " " << setw(8) << i
			<< "| " << setw(28) << p->fullname
			<< "| " << setw(8) << p->age
			<< "| " << setw(8) << p->diem << "|\n";
		p = p->next;
		i++;
	}
	cout << "\t" << "+" << right << setfill('-')
		<< setw(10) << "+" << setw(30) << "+"
		<< setw(10) << "+" << setw(10) << "+" << "\n";
}

void push_back(Linked_list* list, string s) {
	int i = s.find(';');
	Node* node = new Node();

	while (i != string::npos) {
		node->fullname = s.substr(0, i);
		s = s.substr(i + 1);
		i = s.find(';');
		node->age = stoi(s.substr(0, i));
		s = s.substr(i + 1);
		node->diem = stof(s);
		i = s.find(';');
	}

	string s1 = node->fullname;
	int j = s1.find(' ');
	while (j != string::npos) {
		s1 = s1.substr(j + 1);
		j = s1.find(' ');
	}
	node->name = s1;

	node->next = NULL;
	list->length++;

	if (list->head == NULL) {
		list->head = node;
		return;
	}
	Node* p = list->head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}

void pushback(Linked_list* list) {
	string fn;
	int age;
	float diem;
	cin.ignore();
	cout << "\t(?) Nhap ten: "; getline(cin, fn);
	cout << "\t(?) Nhap tuoi: "; cin >> age;
	cout << "\t(?) Nhap diem: "; cin >> diem;

	Node* node = new Node();
	node->fullname = fn;
	node->age = age;
	node->diem = diem;
	node->next = NULL;

	int  i = fn.find(' ');
	while (i != string::npos) {
		fn = fn.substr(i + 1);
		i = fn.find(' ');
	}
	node->name = fn;

	list->length++;

	if (list->head == NULL) {
		list->head = node;
		return;
	}

	Node* p = list->head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
	cout << "\n(*) Them thanh cong!";
}

void fix(Linked_list* list) {
	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!\n";
		clear();
		return;
	}

	int index; cout << "\t(?) Nhap so thu tu: "; cin >> index;

	if (index < 1 || index > list->length) {
		cout << "\n\t(!) Ngoai pham vi danh sach!\n";
		clear();
		return;
	}
	string command;
	string fn;
	int age;
	float diem;
	cout << "\t 1 - Sua ten!\n";
	cout << "\t 2 - Sua tuoi!\n";
	cout << "\t 3 - Sua diem!\n";
	cout << "\t(*) Moi nhap lua chon: "; cin >> command;
	cin.ignore();
	if (command == "1") {
		cout << "\t(?)Nhap ten moi: "; getline(cin, fn);
		cout << "\n(*) Sua thanh cong!";
		clear();
	}
	else if (command == "2") {
		cout << "\t(?)Nhap tuoi moi: "; cin >> age;
		cout << "\n(*) Sua thanh cong!";
		clear();
	}

	else if (command == "3") {
		cout << "\t(?)Nhap diem moi: "; cin >> diem;
		cout << "\n(*) Sua thanh cong!";
		clear();
	}
	else if (command != "1" || command != "2" || command != "3") {
		cout << "\t\t(!) Sai cu phap!";
		clear();
		return;
	}

	int i = 1;
	Node* p = list->head;
	while (p != NULL) {
		if (i == index) {
			if (command == "1") p->fullname = fn;
			else if (command == "2") p->age = age;
			else if (command == "3") p->diem = diem;
		}
		p = p->next;
		i++;
	}
	//if (command >= 1 && command <= 3) cout << "\n(*) Sua thanh cong!";
}

void erase(Linked_list* list, int index) {

	list->length--;
	if (index == 1) {
		Node* p = list->head;
		list->head = list->head->next;
		delete(p);
	}

	Node* p = list->head->next;
	Node* p_back = list->head;
	int i = 2;
	while (p != NULL) {
		if (i == index) {
			p_back->next = p->next;
			break;
		}
		p_back = p;
		p = p->next;
		i++;
	}
	if (index >= 1 && index <= list->length + 1) cout << "\n(*) Xoa thanh cong!";
	else cout << "\t(!) Ngoai pham vi danh sach!";
}

void find_name(Linked_list* list) {
	string index; cout << "\t(?) Nhap ki tu can tim: "; cin >> index;

	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!";
		return;
	}

	Node* p = list->head;
	int j = 1;
	int i = p->fullname.find(index);
	int count = 0;

	while (p != NULL) {
		if (i != string::npos) {
			cout << "\t(*) Thong tin hoc sinh can tim:\n\n";
			cout << "\t" << "+" << setfill('-') << setw(10) << "+"
				<< setw(30) << "+" << setw(10) << "+"
				<< setw(10) << "+" << "\n";
			cout << "\t" << "|" << left << setfill(' ')
				<< setw(9) << " STT"
				<< setw(30) << "| Ho Ten"
				<< setw(10) << "| Tuoi"
				<< setw(10) << "| Diem" << "|\n";
			cout << right << "\t" << "+" << setfill('-') << setw(10) << "+"
				<< setw(30) << "+" << setw(10) << "+"
				<< setw(10) << "+" << "\n";
			count++;
			break;
		}
		p = p->next;
		i = p->fullname.find(index);
		if (j == list->length - 1) break;
		j++;
	}
	if (count == 0) {
		cout << "\n\t(!) Khong tim thay thong tin!";
		return;
	}

	if (count == 1) {
		p = list->head;
		i = p->fullname.find(index);
		j = 1;
		while (p != NULL) {
			if (i != string::npos) {
				cout << "\t" << "|" << left << setfill(' ')
					<< " " << setw(8) << j
					<< "| " << setw(28) << p->fullname
					<< "| " << setw(8) << p->age
					<< "| " << setw(8) << p->diem << "|\n";
			}
			if (j == list->length) break;
			p = p->next;
			i = p->fullname.find(index);
			j++;
		}

		p = list->head;
		i = p->fullname.find(index);
		j = 1;
		while (p != NULL) {
			if (i != string::npos) {
				cout << "\t" << "+" << right << setfill('-')
					<< setw(10) << "+" << setw(30) << "+"
					<< setw(10) << "+" << setw(10) << "+" << "\n";
				count++;
				break;
			}
			if (j == list->length) break;
			p = p->next;
			i = p->fullname.find(index);
			j++;
		}
	}
}

void find_tuoi(Linked_list* list) {
	int index; cout << "\t(?) Nhap tuoi can tim: "; cin >> index;

	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!";
		return;
	}

	Node* p = list->head;
	int i = 1;
	int count = 0;

	while (p != NULL) {
		if (p->age == index) {
			cout << "\t(*) Thong tin hoc sinh can tim:\n\n";
			cout << "\t(*) Thong tin hoc sinh can tim:\n\n";
			cout << "\t" << "+" << setfill('-') << setw(10) << "+"
				<< setw(30) << "+" << setw(10) << "+"
				<< setw(10) << "+" << "\n";
			cout << "\t" << "|" << left << setfill(' ')
				<< setw(9) << " STT"
				<< setw(30) << "| Ho Ten"
				<< setw(10) << "| Tuoi"
				<< setw(10) << "| Diem" << "|\n";
			cout << right << "\t" << "+" << setfill('-') << setw(10) << "+"
				<< setw(30) << "+" << setw(10) << "+"
				<< setw(10) << "+" << "\n";
			count++;
			break;
		}
		p = p->next;
		i++;
		if (i == list->length - 1) break;
	}
	if (count == 0) {
		cout << "\n\t(!) Khong tim thay thong tin!";
		return;
	}

	if (count == 1) {
		p = list->head;
		i = 1;
		while (p != NULL) {
			if (p->age == index) {
				cout << "\t" << "|" << left << setfill(' ')
					<< " " << setw(8) << i
					<< "| " << setw(28) << p->fullname
					<< "| " << setw(8) << p->age
					<< "| " << setw(8) << p->diem << "|\n";
			}
			if (i == list->length) break;
			p = p->next;
			i++;
		}

		p = list->head;
		i = 1;
		while (p != NULL) {
			if (p->age == index) {
				cout << "\t" << "+" << right << setfill('-')
					<< setw(10) << "+" << setw(30) << "+"
					<< setw(10) << "+" << setw(10) << "+" << "\n";
				count++;
				break;
			}
			if (i == list->length) break;
			p = p->next;
			i++;
		}
	}
}

void find_diem(Linked_list* list) {
	float index; cout << "\t(?) Nhap diem can tim: "; cin >> index;

	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!";
		return;
	}

	Node* p = list->head;
	int i = 1;
	int count = 0;

	while (p != NULL) {
		if (p->diem == index) {
			cout << "\t(*) Thong tin hoc sinh can tim:\n\n";
			cout << "\t(*) Thong tin hoc sinh can tim:\n\n";
			cout << "\t" << "+" << setfill('-') << setw(10) << "+"
				<< setw(30) << "+" << setw(10) << "+"
				<< setw(10) << "+" << "\n";
			cout << "\t" << "|" << left << setfill(' ')
				<< setw(9) << " STT"
				<< setw(30) << "| Ho Ten"
				<< setw(10) << "| Tuoi"
				<< setw(10) << "| Diem" << "|\n";
			cout << right << "\t" << "+" << setfill('-') << setw(10) << "+"
				<< setw(30) << "+" << setw(10) << "+"
				<< setw(10) << "+" << "\n";
			count++;
			break;
		}
		p = p->next;
		i++;
		if (i == list->length) break;
	}
	if (count == 0) {
		cout << "\n\t(!) Khong tim thay thong tin!";
		return;
	}

	if (count == 1) {
		p = list->head;
		i = 1;
		while (p != NULL) {
			if (p->diem == index) {
				cout << "\t" << "|" << left << setfill(' ')
					<< " " << setw(8) << i
					<< "| " << setw(28) << p->fullname
					<< "| " << setw(8) << p->age
					<< "| " << setw(8) << p->diem << "|\n";
			}
			if (i == list->length) break;
			p = p->next;
			i++;
		}

		p = list->head;
		i = 1;
		while (p != NULL) {
			if (p->diem == index) {
				cout << "\t" << "+" << right << setfill('-')
					<< setw(10) << "+" << setw(30) << "+"
					<< setw(10) << "+" << setw(10) << "+" << "\n";
				count++;
				break;
			}
			if (i == list->length) break;
			p = p->next;
			i++;
		}
	}
}

void sort(Linked_list* list) {
	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!";
		return;
	}
	string n;
	cout << "\t(1) Sap xep theo ten.\n";
	cout << "\t(2) Sap xep theo tuoi.\n";
	cout << "\t(3) Sap xep theo diem.\n";
	cout << "\t(?) Nhap lua chon: "; cin >> n;

	if (n == "1") {
		for (Node* p = list->head; p != NULL; p = p->next) {
			Node* p_min = p;
			for (Node* q = p->next; q != NULL; q = q->next) {
				if (p_min->name > q->name) {
					p_min = q;
				}
			}
			swap(p->fullname, p_min->fullname);
			swap(p->name, p_min->name);
			swap(p->age, p_min->age);
			swap(p->diem, p_min->diem);
		}
	}
	else if (n == "2") {
		for (Node* p = list->head; p != NULL; p = p->next) {
			Node* p_min = p;
			for (Node* q = p->next; q != NULL; q = q->next) {
				if (p_min->age > q->age) {
					p_min = q;
				}
			}
			swap(p->fullname, p_min->fullname);
			swap(p->name, p_min->name);
			swap(p->age, p_min->age);
			swap(p->diem, p_min->diem);
		}
	}
	else if (n == "3") {
		for (Node* p = list->head; p != NULL; p = p->next) {
			Node* p_min = p;
			for (Node* q = p->next; q != NULL; q = q->next) {
				if (p_min->diem < q->diem) {
					p_min = q;
				}
			}
			swap(p->fullname, p_min->fullname);
			swap(p->name, p_min->name);
			swap(p->age, p_min->age);
			swap(p->diem, p_min->diem);
		}
	}
	else {
		cout << "\n\t(!) Sai cu phap!\n";
		return;
	}
	cout << "\n\t(*) Thanh cong!\n";
}

void thong_ke(Linked_list* list) {
	if (list->head == NULL) {
		cout << "\t(!) Chua co thong tin sinh vien!";
		return;
	}
	float s = 0;
	float diem_gioi = 0;
	float diem_kha = 0;
	float diem_tb = 0;
	Node* p = list->head;
	float diem_max = p->diem;

	while (p != NULL) {
		s += p->diem;
		if (p->diem >= 8) diem_gioi++;
		else if (p->diem >= 6.5 && p->diem < 8) diem_kha++;
		else diem_tb++;
		if (diem_max < p->diem) diem_max = p->diem;
		p = p->next;
	}
	int j = 1;
	p = list->head;
	cout << "\t(!) Diem trung binh ca lop: " << (float)(s / (list->length));
	cout << "\n\t(!) Ti le sinh vien gioi la: " << (float)(diem_gioi / (list->length)) * 100 << "%";
	cout << "\n\t(!) Ti le sinh vien kha la: " << (float)(diem_kha / (list->length)) * 100 << "%";
	cout << "\n\t(!) Ti le sinh vien tb la: " << (float)(diem_tb / (list->length)) * 100 << "%";
	cout << "\n\t(!) Sinh vien diem cao nhat la (" << diem_max << "):\n\n";
	cout << "\t" << "+" << setfill('-') << setw(10) << "+"
		<< setw(30) << "+" << setw(10) << "+"
		<< setw(10) << "+" << "\n";
	cout << "\t" << "|" << left << setfill(' ')
		<< setw(9) << " STT"
		<< setw(30) << "| Ho Ten"
		<< setw(10) << "| Tuoi"
		<< setw(10) << "| Diem" << "|\n";
	cout << right << "\t" << "+" << setfill('-') << setw(10) << "+"
		<< setw(30) << "+" << setw(10) << "+"
		<< setw(10) << "+" << "\n";
	while (p != NULL) {
		if ((p->diem) == diem_max) {
			cout << "\t" << "|" << left << setfill(' ')
				<< " " << setw(8) << j
				<< "| " << setw(28) << p->fullname
				<< "| " << setw(8) << p->age
				<< "| " << setw(8) << p->diem << "|\n";
		}
		p = p->next;
		j++;
	}
	cout << "\t" << "+" << right << setfill('-')
		<< setw(10) << "+" << setw(30) << "+"
		<< setw(10) << "+" << setw(10) << "+" << "\n";
}

void save(Linked_list* list) {
	if (list->head == NULL) {
		cout << "(!) Chua co thong tin sinh vien!";
		return;
	}
	ofstream output("data.txt");
	Node* p = list->head;
	while (p != NULL) {
		output << p->fullname << ";"
			<< p->age << ";"
			<< p->diem << "\n";
		p = p->next;
	}
	cout << "\t\t(*) Luu thanh cong!";
}

int main()
{
	string s;
	ifstream input("data.txt");
	Linked_list list = { NULL, 0 };
	while (getline(input, s)) {
		push_back(&list, s);
		s = "";
	}

	int i = 1;
	while (i > 0) {
		cout << "============== MENU ================\n"
			<< "|| 1 - In Danh Sach Sinh Vien     ||\n"
			<< "|| 2 - Them                       ||\n"
			<< "|| 3 - Sua                        ||\n"
			<< "|| 4 - Xoa                        ||\n"
			<< "|| 5 - Tim Kiem                   ||\n"
			<< "|| 6 - Sap Xep                    ||\n"
			<< "|| 7 - Thong Ke                   ||\n"
			<< "|| 8 - Sao Luu                    ||\n"
			<< "|| 9 - Thoat                      ||\n"
			<< "====================================\n";
		{
			string x; cout << "\n(-) Moi nhap lenh: "; cin >> x;
			cout << "\n";

			if (x == "1") {
				print(&list);
				clear();
			}
			else if (x == "2") {
				pushback(&list);
				clear();

			}
			else if (x == "3") {
				fix(&list);
			}
			else if (x == "4") {
				int index; cout << "\t(?) Nhap so thu tu can xoa: "; cin >> index;
				erase(&list, index);
				clear();
			}
			else if (x == "5") {
				string command;
				cout << "\t1 - Tim theo ki tu\n\t2 - Tim theo tuoi\n\t3 - Tim theo diem\n";
				cout << "\t(*) Nhap lua chon: "; cin >> command;
				if (command == "1") {
					find_name(&list);
					clear();
				}
				else if (command == "2") {
					find_tuoi(&list);
					clear();
				}
				else if (command == "3") {
					find_diem(&list);
					clear();
				}
				else {
					cout << "\n\t(!) Sai cu phap!";
					clear();
				}

			}
			else if (x == "6") {
				sort(&list);
				clear();
			}
			else if (x == "7") {
				thong_ke(&list);
				clear();
			}
			else if (x == "8") {
				string command;
				cout << "\t(!) Xac nhan luu:\n\t1 - Yes\n\t2 - No\n";
				cout << "\t(*) Nhap lua chon: "; cin >> command;
				if (command == "1") {
					save(&list);
					clear();
				}
				else if (command == "2") {
					cout << "\n\t(?) File chua duoc luu!";
					clear();
				}
				else {
					cout << "\n\t(?) Sai cu phap!";
					clear();
				}

			}
			else if (x == "9") {
				string command;
				cout << "\t(!) Xac nhan thoat:\n\t1 - Yes\n\t2 - No\n";
				cout << "\t(*) Nhap lua chon: "; cin >> command;
				if (command == "1") {
					break;
				}
				if (command == "2") {
					clear();
				}
				else {
					cout << "\n\t(!) Sai cu phap!";
					clear();
				}
			}
			else {
				cout << "(!) Sai cu phap!";
				clear();
			}

		}
	}
}