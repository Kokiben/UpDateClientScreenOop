#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsUpdateClientScreen: protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nCard Info : ";
		cout << "\n______________________";
		cout << "\nFirst Name   : " << Client.FirstName;
		cout << "\nLast  Name   : " << Client.LastName;
		cout << "\nFullName     : " << Client.FullName();
		cout << "\n Email       : " << Client.Email;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAcc.Number   : " << Client.AccountNumber();
		cout << "\nPassword     : " << Client.PinCode;
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n______________________";
	}
	static void ReadClientInfo(clsBankClient& Client)
	{
		
		cout << "\n enter first name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter last name  : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nenter Email      : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone      : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode    : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nAccount balance  : ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}

public:
	static void ShowUpDateClientScreen()
	{
		_DrawScreenHeader("\tUpDate Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(client1);
		cout << "Are you sure want Update this client ? y/n?";

		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpDate client Info : ";
			cout << "\n___________________________\n";

			ReadClientInfo(client1);

			clsBankClient::enSaveResults SaveResult;
			SaveResult = client1.Save();


			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClient(client1);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError Account was not saved because it's Empty";
				break;
			}
			}

		}
		


	}
};

