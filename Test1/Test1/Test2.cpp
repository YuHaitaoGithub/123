#include "Windows.h"
#include "stdio.h"

#define MAX_LINE 100



/*	LPCWSTR section = L"1223";
	LPCWSTR key = L"x";
	LPCWSTR feilname = L"..\\..\\..\\Ini.ini";
	int a = GetPrivateProfileInt(section, key, -1, feilname);//5
	printf("%d\n", a);
*/

	


	
	TCHAR *SectionGet(LPCWSTR feilname, TCHAR section[])
	{
		GetPrivateProfileSectionNames(section, -1, feilname);//结果1223
		return section;
	/*	while (section2[j] != '\0')
		{
			printf("%c", section2[j]);
			j++;
		}*/

	}


	
	//char len = {};
	//LPCWSTR c = L"456";
	//WritePrivateProfileString(section, key2, c, feilname);
	TCHAR *Key_Get(LPCWSTR section, LPCWSTR key, TCHAR buff[], int Max_line, LPCWSTR feilname)
	{
		GetPrivateProfileString(section, key, NULL, buff, Max_line, feilname);//123
		return buff;
	}

/*	TCHAR    IP_addr[128];
	GetPrivateProfileStringW(section, key, NULL, IP_addr, sizeof(IP_addr), feilname);//结果5


	TCHAR section2[100];
	GetPrivateProfileSectionNames(section2, -1, feilname);//结果1223

	char    IP_addr_1[128] = { '\0' };
	GetPrivateProfileStringA("1223", "y", NULL, IP_addr_1, sizeof(IP_addr_1), "..\\..\\..\\Ini.ini");//结果123
	printf("%s\n", IP_addr_1);

	TCHAR buf[200];
	GetPrivateProfileSection(section, buf, 200, feilname);//x=5
	printf("%s\n", buf);

//	GetProfileString(section, key,NULL,feilname,1);
*/




void main()
{
	LPCWSTR feilname = L"..\\..\\..\\Ini.ini";

	TCHAR section[MAX_LINE] = {};
	TCHAR *p1 = SectionGet(feilname, section);
	int j = 0;

	

	while (p1[j] != '\0')
	{
		printf("%c", p1[j]);
		j++;
	}

	LPCWSTR section2 = L"1223";
	LPCWSTR key1 = L"x";
	LPCWSTR key2 = L"y";
	TCHAR buff[MAX_LINE] = {};
	TCHAR buffer[MAX_LINE] = {};
	TCHAR *p3 = Key_Get(section2, key1, buff, MAX_LINE, feilname);
	TCHAR *p2 = Key_Get(section2, key2, buffer, MAX_LINE, feilname);
	int a = atoi((const char*)p3);
	int b = atoi((const char*)p2);

	printf("\n%d %d", a,b);

	system("pause");
}