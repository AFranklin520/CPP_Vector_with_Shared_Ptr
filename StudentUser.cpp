//Anthony Franklin afranklin18@cnm.edu
//PROGRAM TO DEMONSTRATE SHARED_PTR IN A VECTOR
//04/21/2022
//StudentUser.cpp

#include "StudentUser.h"
bool IsInitialized = false;
void StudentUser::Initialize()
{
	referenceCount = 0;
	IsInitialized = true;
	resourceTitles.push_back(make_shared<string>("Title Number One"));
	resourceTitles.push_back(make_shared<string>("A Second Title"));
	resourceTitles.push_back(make_shared<string>("Third Title"));
	resourceTitles.push_back(make_shared<string>("What, Another Title?!"));
	logger.open("FranklinP9_log.txt");
	if (logger.is_open())
	{
		cout << "FranklinP9_log.txt has been successfully created!\n";
		logger << "Anthony Franklin afranklin18@cnm.edu\n04/21/2022\nFranklinP9\n";
		logger << "***** PROGRAM TO DEMONSTRATE SHARED_PTR IN A VECTOR *****\n\n";
	}
}
StudentUser::StudentUser()
{
	if (IsInitialized == false) Initialize();
	referenceCount++;
	if (logger.is_open())
	{
		logger << "New StudentUser has been created.\n";
		logger << "Reference count is now: " << referenceCount << "\n";
		cout << "Reference count is now: " << referenceCount << "\n";
	}

}

StudentUser::~StudentUser()
{
	cout << name << " is now going out of scope and is being deleted.\n";
	logger << name << " is now going out of scope and is being deleted.\n";
	referenceCount--;
	if (logger.is_open())
	{
		logger << "Reference count is now: " << referenceCount << "\n";
		cout << "Reference count is now: " << referenceCount << "\n";
	}
	if (referenceCount == 0) logger.close();
}

int StudentUser::ReferenceCount(int index)
{
	if (IsInBounds(index)) return resourceTitles.at(index).use_count();
	else return -1;
}

shared_ptr<string> StudentUser::GetResourceTitle(string title)
{
	for (auto temp : resourceTitles)
	{
		if (*temp == title)
		{
			return temp;
			break;
		}
		else return nullptr;
	}
}

shared_ptr<string> StudentUser::GetResourceTitle(int index)
{
	if (IsInBounds(index))
	{
		if (resourceTitles.at(index))
		{
			auto temp = resourceTitles.at(index);
			return temp;
		}
	}
	else return nullptr;
}

string StudentUser::Title(int index)
{
	if (resourceTitles.at(index)) return *resourceTitles.at(index);
}

string StudentUser::Front()
{
	if (resourceTitles.front()) return *resourceTitles.front();
	else return "[ERROR] The vector is empty!";
}

string StudentUser::Back()
{
	if (resourceTitles.front()) return *resourceTitles.front();
	else return "[ERROR] The vector is empty!";
}

bool StudentUser::Push(string title)
{
	auto temp = make_shared<string>(title);
	resourceTitles.push_back(temp);
	if (find(resourceTitles.begin(), resourceTitles.end(), temp) != resourceTitles.end())
	{
		logger << name << " has added " << title << " to the vector.\nVector size is now " << to_string(resourceTitles.size()) << "\n";
		return true;
	}
	return false;
}

bool StudentUser::Delete(string title)
{
	for (int i{0}; i < resourceTitles.size(); i++)
	{
		if (*resourceTitles.at(i) == title)
		{
			resourceTitles.erase(resourceTitles.begin() + (i-1));
			logger << name << " has deleted " << title << " from the vector.\nVector size is now " << to_string(resourceTitles.size()) << "\n";
			cout << name << " has deleted " << title << " from the vector.\nVector size is now " << resourceTitles.size() << "\n";
			return true;
		}
	}
	return false;
}

bool StudentUser::Delete(int index)
{
	if (IsInBounds(index))
	{
		resourceTitles.erase(resourceTitles.begin() + index - 1);
		return true;
	}
	else return false;
}

bool StudentUser::Pop()
{
	if (resourceTitles.size() == 0) return false;
	else
	{
		resourceTitles.pop_back();
		logger << name << " has popped a vector item.\nVector size is now " << to_string(resourceTitles.size()) << "\n";
		cout << name << " has popped a vector item.\nVector size is now " << resourceTitles.size() << "\n";
		return true;
	}
}

bool StudentUser::Find(string title)
{
	for_each(resourceTitles.begin(), resourceTitles.end(), [title](shared_ptr<string> p) {
		if (*p == title)
		{
			return true;
		}
		});
	return false;
}

void StudentUser::Write(string logMessage)
{
	string message = logMessage;
	logger << message;
}
