#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

struct Student
{
	char name[10];
	int age;
	int fn;
};


int main()
{
	{
		std::ofstream ofs("file.dat", std::ios::out | std::ios::binary);

		Student st{ "Ivan", 10, 1234 };

		ofs.write((const char*)&st, sizeof(st));
	}
	{
		Student st;
		
		std::ifstream ifs("file.dat", std::ios::in | std::ios::binary);

		ifs.read( (char*)&st, sizeof(Student));

		std::cout << st.name << " " << st.age << " " << st.fn;
	}

}
