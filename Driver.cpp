//Anthony Franklin afranklin18@cnm.edu
//PROGRAM TO DEMONSTRATE SHARED_PTR IN A VECTOR
//04/21/2022
//Driver.cpp

#include "StudentUser.h"

int main()
{
	StudentUser* user1 = new StudentUser;
	StudentUser* user2 = new StudentUser;
	StudentUser* user3 = new StudentUser;
	StudentUser* user4 = new StudentUser;
	user1->SetName("Anthony Franklin");
	user2->SetName("Ivonne Nelson");
	user3->SetName("John Doe");
	user4->SetName("Mike Hawk");
	
	user2->Delete(1);
	auto temp = user1->Front();	

	cout << user1->GetName() << " is adding the title \"War and Pizzas: The Battle for Deliciousness\"\n";
	user1->Push("War and Pizzas: The Battle for Deliciousness");
	cout << user2->GetName() << " is adding the title \"Another Test Title\"\n";
	user2->Push("Another Test Title");
	cout << user3->GetName() << " is adding the title \"What to Do When you Can't Think of a Funny Title\"\n";
	user3->Push("What to Do When you Can't Think of a Funny Title");
	cout << user4->GetName() << " is adding the title \"My Struggle (Against the World)\"\n";
	user4->Push("My Struggle (Against the World)");
	cout << user2->GetName() << " is adding the title \"The Last Title\"\n";
	user2->Push("The Last Title");

	cout << user3->ReferenceCount(2) << " pointers are currently pointed at " << user3->Title(2) << "\n";
	user3->Write(to_string(user3->ReferenceCount(2)) + " pointers are currently pointed at " + user3->Title(2) + "\n");
	cout << user3->GetName() << " is making a copy of " << user3->Title(2) << "\n";
	user3->Write(user3->GetName() + " is making a copy of " + user3->Title(2) + "\n");
	auto tempPointer = user3->GetResourceTitle(2);
	cout << user3->ReferenceCount(2) << " pointers are currently pointed at " << user3->Title(2) << "\n";
	user3->Write(to_string(user3->ReferenceCount(2)) + " pointers are currently pointed at " + user3->Title(2) + "\n");

	/*cout << user4->ReferenceCount(2) << " pointers are currently pointed at " << user4->Title(2) << "\n";
	user3->Write(to_string(user4->ReferenceCount(2)) + " pointers are currently pointed at " + user4->Title(2) + "\n");*/
	cout << user4->GetName() << " is making a copy of " << user4->Title(2) << "\n";
	user3->Write(user4->GetName() + " is making a copy of " + user4->Title(2) + "\n");
	auto tempPointer2 = user4->GetResourceTitle(2);
	cout << user4->ReferenceCount(2) << " pointers are currently pointed at " << user4->Title(2) << "\n";
	user3->Write(to_string(user4->ReferenceCount(2)) + " pointers are currently pointed at " + user4->Title(2) + "\n");;

	cout << user1->ReferenceCount(0) << " pointers are currently pointed at " << user1->Title(0) << "\n";
	user1->Write(to_string(user1->ReferenceCount(0)) + " pointers are currently pointed at " + user1->Title(0) + "\n");
	cout << user1->GetName() << " is making a copy of " << user1->Title(0) << "\n";
	user1->Write(user1->GetName() + " is making a copy of " + user1->Title(0) + "\n");
	for (int i{ 0 }; i < 1; i++)
	{
		auto tempPointer3 = user1->GetResourceTitle(0);
		cout << user1->ReferenceCount(0) << " pointers are currently pointed at " << user1->Title(0) << "\n";
		user1->Write(to_string(user1->ReferenceCount(0)) + " pointers are currently pointed at " + user1->Title(0) + "\n");
	}

	delete user1;
	cout << user2->ReferenceCount(0) << " pointers are currently pointed at " << user2->Title(0) << "\n";
	user2->Write(to_string(user2->ReferenceCount(0)) +" pointers are currently pointed at " + user2->Title(0) + "\n");


	user2->Delete(3);
	for (int i{ 0 }; i < user2->GetSize(); i++)
	{
		user2->Write(*resourceTitles.at(i) + "\t");
	}
	user2->Write("\n");
	user2->Pop();
	user2->Pop();
	for (int i{ 0 }; i < resourceTitles.size(); i++)
	{
		user2->Write(*resourceTitles.at(i) + "\t");
	}
	user2->Write("\n");
	delete user3;
	delete user4;
	delete user2;
	cout << "\n\n****Our vector is now out of scope, goodbye!****\n\n";
	return 0;
}