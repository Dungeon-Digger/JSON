#pragma once
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
using namespace std;

class Letter {
	string sender, recipient, text, sendDate;
public:
	Letter();
	Letter(string sender, string recipient, string text, string sendDate);

	void SetSender(string sender);
	void SetRecipient(string recipient);
	void SetText(string text);
	void SetSendDate(string sendDate);

	string GetSender();
	string GetRecipient();
	string GetText();
	string GetSendDate();

	void Serialize();
	Letter Deserialize();

	void Print();

	void operator =(Letter other);
};

