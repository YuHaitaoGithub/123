//#include "Windows.h"
#define _AFXDLL
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "afx.h"

#pragma once
#define MAX_LINE 100

int Key_Int(LPCWSTR section, LPCWSTR key, LPCWSTR feilname)
{
	return GetPrivateProfileInt(section, key, -1, feilname);//5
}

	
//LPCWSTR--unicode编码字符串的32位指针
//TCHAR--双字节字符wchar

	
TCHAR *SectionGet(LPCWSTR feilname, TCHAR section[])//获取节名
{
	GetPrivateProfileSectionNames(section, MAX_LINE, feilname);//结果1223
	if (section == NULL)return NULL;
	else return section;

}


	
	//char len = {};
	//LPCWSTR c = L"456";
	//WritePrivateProfileString(section, key2, c, feilname);
TCHAR *Key_Get(LPCWSTR section, LPCWSTR key, TCHAR buff[], int Max_line, LPCWSTR feilname)//获取键值
{
	GetPrivateProfileString(section, key, NULL, buff, Max_line, feilname);//123
	if (buff == NULL)return NULL;
	else return buff;
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
	LPCWSTR feilname = L"..\\..\\..\\Ini.ini";  //文件目录

	TCHAR section[MAX_LINE] = {};
	TCHAR *p1 = SectionGet(feilname, section);//找到节名
	//printf("%ws", p1);
	for (int i = 0; ((p1[i] != '\0') || (p1[i + 1] != '\0')); i++)
	{
		printf("%wc", p1[i]);
	}
	


	LPCWSTR section1 = L"TESTER_SETUP";//节名
	LPCWSTR section2 = L"1223";
	LPCWSTR key1 = L"x";//键名
	LPCWSTR key2 = L"IP_ADDRESS_1";
	TCHAR buff[MAX_LINE] = {};
	TCHAR buffer[MAX_LINE] = {};
	TCHAR *p3 = Key_Get(section2, key1, buff, MAX_LINE, feilname);
	TCHAR *p2 = Key_Get(section1, key2, buffer, MAX_LINE, feilname);
	printf("\n%ws\n", p3);
	printf("%ws", p2);
	
	printf("\n%d", Key_Int(section2, key1, feilname));

	system("pause");
}




void main1()
{
	char *feilname = "..\\..\\..\\Ini.ini";
	char *section = "1223";
	char *key = "y";
	char    IP_addr_1[128] = { '\0' };
	GetPrivateProfileStringA(section, key, NULL, IP_addr_1, sizeof(IP_addr_1), feilname);//结果123
	printf("%s\n", IP_addr_1);


	char buf[200];
	GetPrivateProfileSectionA(section, buf, 200, feilname);//x=5
	
	int a = strlen(buf);


	for (int i = 0; ((buf[i] != '\0') || (buf[i+1] != '\0')); i++)
	{
		printf("%c", buf[i]);
	}

	system("pause");
}


 
//int _tmain()
//{
//	TCHAR buffer[256];
//	TCHAR path[] = _T("..\\..\\..\\Ini.ini");
//	int len = GetPrivateProfileSectionNames
//		(buffer, sizeof(buffer), path);
//
//	TCHAR *names = buffer;
//	TCHAR *end = names + len;
//
//	//返回的sectionNames以null分隔  
//
//	while (names < end)
//	{
//		CString name = names;
//		_tprintf(_T("======%s======\r\n"), name);
//		names += name.GetLength();
//		names++;
//
//		//获取该Section下面所有的属性  
//		TCHAR buffer2[1024];
//		len = GetPrivateProfileSection(name,
//			buffer2, sizeof(buffer2), path);
//		//遍历所有行  
//		TCHAR *lines = buffer2;
//		while (*lines)
//		{
//			CString line = lines;
//			_tprintf(_T("\t%s\r\n"), line);
//
//			lines += line.GetLength();
//			lines++;
//		}
//	}
//
//	return 0;
//}