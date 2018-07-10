#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void Ciphering(string& _msg, int _key);
void CipherWithKey(string& _msg);
void DecipherWithoutKey(string _msg);

int main()
{

	int temp;
	string msg;
	char userCmd[100];
	while (true) {

		cout << "What do you want?" << endl;
		cout << "1 - Code (with key)" << endl;
		cout << "2 - Decode" << endl;
		cout << "3 - Exit" << endl;

		cin.getline(userCmd, sizeof(userCmd));
		temp = atoi(userCmd);

		switch (temp)
		{
		case 1: CipherWithKey(msg);
		break;
		case 2:  DecipherWithoutKey(msg);
		break;
		case 3:
		return 0;
		break;
		default: cout << "Invalid command" << endl;
		break;

		}
		cout << " " << endl;
	}


	return 0;
}

void CipherWithKey(string& _msg) {
	char userKey[100];
	int _key;


	cout << "Input message for coding: " << endl;
	getline(cin, _msg);
	cout << "Input key: " << endl;

	cin.getline(userKey, sizeof(userKey));
	_key = atoi(userKey);

	if (_key > 26)
	cout << "Invalid key!" << endl;
	else if (!isdigit(_key))
	cout << "Invalid key!" << endl;
	else
	cout << "Encrypted text: " << endl;
	Ciphering(_msg, _key);
	cout << _msg << endl;

}

void DecipherWithoutKey(string _msg) {
	cout << "Input message for decoding:" << endl;
	getline(cin, _msg);
	for (int j = 0; j < 26; ++j)
	{
		for (int i = 0; _msg[i] != NULL; ++i)
		{
			if (_msg[i] == 'A')
				_msg[i] = 'Z';
			else if (_msg[i] == 'a')
				_msg[i] = 'z';
			else if (_msg[i] == '0')
				_msg[i] = '9';
			else if (_msg[i] == ' ')
				_msg[i] = ' ';
			else if (_msg[i] == ',')
				_msg[i] = ',';
			else if (_msg[i] == '.')
				_msg[i] = '.';
			else if (_msg[i] == '!')
				_msg[i] = '!';
			else if (_msg[i] == '?')
				_msg[i] = '?';
			else
				--_msg[i];
		}
		cout << "Version of key " << j + 1 << " = " << _msg << endl;
	}
}

void Ciphering(string& _msg, int _key) {
	for (int i = 0; _msg[i] != NULL; ++i)
	{
		for (int j = 0; j < _key; ++j)
		{
			if (_msg[i] == 'Z')
				_msg[i] = 'A';
			else if (_msg[i] == 'z')
				_msg[i] = 'a';
			else if (_msg[i] == '9')
				_msg[i] = '0';
			else if (_msg[i] == ' ')
				_msg[i] = ' ';
			else if (_msg[i] == ',')
				_msg[i] = ',';
			else if (_msg[i] == '.')
				_msg[i] = '.';
			else if (_msg[i] == '!')
				_msg[i] = '!';
			else if (_msg[i] == '?')
				_msg[i] = '?';
			else
				++_msg[i];
		}
	}
}