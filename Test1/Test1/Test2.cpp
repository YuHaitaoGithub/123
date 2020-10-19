//#include "Windows.h"
//#include "stdio.h"
//void main()
//{
//	LPCWSTR section = L"1223";
//	LPCWSTR key = L"x";
//	LPCWSTR key2 = L"y";
//	LPCWSTR feilname = L"..\\..\\..\\Ini.ini";
//	int a = GetPrivateProfileInt(section, key, -1, feilname);
//	LPCWSTR buf[100] = {};
//	LPWSTR nSize = 'l';
//	GetPrivateProfileString(section, key2, buf[100], nSize, -1,feilname);
//	printf("%d\n", a);
//	system("pause");
//}
#include <cstdlib>
#include <iostream>
#include <Windows.h>


using namespace std;


char    IP_addr[128] = { '\0' };
char    IP_addr_1[128] = { '\0' };

int main(int argc, char *argv[])
{
	cout << IP_addr_1 << " here is IP_addr_1" << endl;
	int len = 0;
	len = GetPrivateProfileStringA("TESTER_SETUP", "IP_ADDRESS_1", NULL, IP_addr_1, sizeof(IP_addr), ".\\Setup.ini");
	//if(0!= len)
	cout << IP_addr_1 << endl << " here is IP_addr_1" << endl;


	system("PAUSE");
	return EXIT_SUCCESS;
}