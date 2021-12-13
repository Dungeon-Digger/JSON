#include "Letter.h"

Letter::Letter() : Letter("Default", "Default", "Default", "Default"){}

Letter::Letter(string sender, string recipient, string text, string sendDate) : sender(sender), recipient(recipient), text(text), sendDate(sendDate) {}

void Letter::SetSender(string sender) {
	this->sender = sender;
}

void Letter::SetRecipient(string recipient) {
	this->recipient = recipient;
}

void Letter::SetText(string text) {
	this->text = text;
}

void Letter::SetSendDate(string sendDate) {
	this->sendDate = sendDate;
}

string Letter::GetSender() {
	return sender;
}

string Letter::GetRecipient() {
	return recipient;
}

string Letter::GetText() {
	return text;
}

string Letter::GetSendDate() {
	return sendDate;
}

void Letter::Serialize() {
	nlohmann::json j;
	j["sender"] = this->sender;
	j["recipient"] = this->recipient;
	j["text"] = this->text;
	j["sendDate"] = this->sendDate;

	ofstream fout("dump.json");
	fout << j.dump() << endl;
	fout.close();
}

Letter Letter::Deserialize() {
	Letter tmp;
	string jsonString;
	ifstream fin("dump.json");
	getline(fin, jsonString);
	nlohmann::json j = nlohmann::json::parse(jsonString);
		tmp.SetSender(j["sender"].get<string>());
		tmp.SetRecipient(j["recipient"].get<string>());
		tmp.SetText(j["text"].get<string>());
		tmp.SetSendDate(j["sendDate"].get<string>());
	fin.close();
	return tmp;
}

void Letter::Print() {
	cout << "Sender: " << GetSender() << " Recipient: " << GetRecipient() << " Text: " << GetText() << " Send Date: " << GetSendDate() << endl;
}

void Letter::operator =(Letter other) {
	this->sender = other.sender;
	this->recipient = other.recipient;
	this->text = other.text;
	this->sendDate = other.sendDate;
}
