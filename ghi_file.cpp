#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct bang_diem
{
	float daiso = 0, cpp = 0, mac = 0;
}bd;
typedef struct sinhvien
{ 
	string masv;
	string ho_ten;
	string nam_sinh;
	string gioitinh;
	bd bang_diem;
}sv;
ostream& operator <<(ostream& os, bd ds_diem);
ostream& operator <<(ostream& os, sv a);
void load_file(sv ds[], int& n);

void main()
{
	sv mang[20];
	int n = 0;
	load_file(mang, n);

	for (int i = 0; i < n; i++)
	{
		cout << mang[i];
		cout << mang[i].bang_diem;
		cout << "\n\n";
	}
}
ostream& operator <<(ostream& os, sv a)
{
	os << "Ma sv: " << a.masv << endl;
	os << "Ho ten: " << a.ho_ten << endl;
	os << "Nam sinh: " << a.nam_sinh << endl;
	os << "Gioi tinh: " << a.gioitinh << endl;
	return os;
}
ostream& operator <<(ostream& os, bd ds_diem)
{
	cout << "---- DS diem ----" << endl;
	os << "Diem Mac-Lenin: " << ds_diem.mac << endl;
	os << "Diem dai so: " << ds_diem.daiso << endl;
	os << "Diem c++: " << ds_diem.cpp << endl;
	return os;
}
void load_file(sv ds[], int &n)
{
	ifstream file;
	file.open("D:\\input.txt", ios::in);
	if (file.fail() == true)
	{
		cout << "Error" << endl;
	}
	while (file.eof() == false)
	{
		sv a;
		getline(file, a.masv, ',');
		getline(file, a.ho_ten, ',');
		getline(file, a.gioitinh, ',');
		getline(file, a.nam_sinh, ',');
		file >> a.bang_diem.mac; file.ignore();
		file >> a.bang_diem.daiso; file.ignore();
		file >> a.bang_diem.cpp; file.ignore();
		ds[n++] = a;
	}
	file.close();
}
