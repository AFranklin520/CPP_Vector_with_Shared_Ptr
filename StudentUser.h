//Anthony Franklin afranklin18@cnm.edu
//PROGRAM TO DEMONSTRATE SHARED_PTR IN A VECTOR
//04/21/2022
//StudentUser.h

#ifndef STUDENTUSER_H
#define STUDENTUSER_H
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

static int referenceCount;
static ofstream logger;
static vector <shared_ptr<string>> resourceTitles;
class StudentUser
{
private:
	string name;
	int size{ 0 };
	bool IsInBounds(int index) { return index >= 0 && index <= resourceTitles.size(); }
	void Initialize();

public:
	StudentUser();
	~StudentUser();
	int GetSize() { return resourceTitles.size(); }
	bool IsEmpty() { return resourceTitles.size() == 0; }
	int ReferenceCount(int index);
	void SetName(string n) { name = n; }
	string GetName() { return name; }
	shared_ptr<string> GetResourceTitle(string title);
	shared_ptr<string> GetResourceTitle(int index);
	string Title(int index);
	string Front();
	string Back();
	bool Push(string title);
	bool Delete(string title);
	bool Delete(int index);
	bool Pop();
	bool Find(string title);
	static void Write(string logMessage);
};
#endif // !STUDENTUSER_H