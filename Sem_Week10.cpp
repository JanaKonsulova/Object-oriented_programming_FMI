// Sem_Week10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#pragma warning (disable : 4996)

class ComponentBase
{
protected:
	float x;
	float y;

public:
	virtual void ShowDialog() = 0;
	void move(float dx, float dy);
	virtual ~ComponentBase() = default;
};

class Label:public ComponentBase
{
	char arr[16];
	void ShowDialog() override
	{
		std::cout << "Enter coordinates: " << std::endl;
		std::cin >> x >> y;
		std::cout << "Enter label: " << std::endl;
		std::cin.getline(arr, 16);
	}
};

class RadioButton :public ComponentBase
{
	char text[16];
	bool chosen;
	void ShowDialog() override
	{
		std::cout << "Enter name: " << std::endl;
		std::cin.getline(text, 16);
		std::cout << "On or Off: ";
		char choice[3];
		std::cin.getline(choice, 3);
		if (choice == "On")
			chosen = true;
		else
			chosen = false;
	}
	void flip()
	{
		chosen = !chosen;
	}
	bool isOn() const
	{
		return chosen;
	}

};


class TextBox :public ComponentBase
{
	std::string text;

	void ShowDialog() override
	{
		std::cout << "Enter text or file path:" << std::endl;
		char choice[10];
		std::cin.getline(choice, 10);
		if (choice == "text")
		{
			std::cin >> text;
		}
		else
		{
			char fileName[1024];
			std::cin.getline(fileName, 1024);
			std::fstream ifs(fileName, std::ios::in);
			std::stringstream buffer;
			buffer << ifs.rdbuf();
			text = buffer.str();
		}

	}
};

class Collection
{
	std::vector <ComponentBase*> col;
public:
	void addLabel(Label* l)
	{
		col.push_back(l);
	}
	void addRadioButton(RadioButton* rb)
	{
		col.push_back(rb);
	}
	void addTextBox(TextBox* tb)
	{
		col.push_back(tb);
	}
};



