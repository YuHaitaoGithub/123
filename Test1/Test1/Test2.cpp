#include "Windows.h"
//#define _AFXDLL
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//#include "afx.h"

#pragma once
#define MAX_LINE 100

int Key_Int(LPCWSTR section, LPCWSTR key, LPCWSTR feilname)
{
	return GetPrivateProfileInt(section, key, -1, feilname);//5
}


	
TCHAR *SectionGet(LPCWSTR feilname, TCHAR section[])//��ȡ����
{
	GetPrivateProfileSectionNames(section, MAX_LINE, feilname);//���1223
	if (section == NULL)return NULL;
	else return section;

}




void main()
{
	LPCWSTR feilname = L"E:\\Algorithm_Questions\\Practice\\Algorithm\\Algorithm\\config\\01_ContainsNearbyDuplicate.ini";
	LPCWSTR section = L"123";
	LPCWSTR key = L"Array";
	TCHAR    IP_addr_1[128] = { '\0' };
	GetPrivateProfileString(section, key, NULL, IP_addr_1, sizeof(IP_addr_1), feilname);//���123
	printf("%s\n", IP_addr_1);

}


 
