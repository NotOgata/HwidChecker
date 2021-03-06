#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>

int main()
{
	//First part gets the HDD informations
	std::cout << "HWID information" << std::endl;
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
		//std::cout << "Volume Name: " << volumeName << std::endl;
		std::cout << "Send me this number: " << serialNumber << std::endl; 
		//std::cout << "File System Type: " << fileSystemName << std::endl;
		//std::cout << "Max Component Length: " << maxComponentLen << std::endl;
	}
	//Second part gets the computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	if (GetComputerName(
		computerName,
		&size))
	{
		//std::cout << "Computer Name: " << computerName << std::endl;
	}
	//Third part gets the CPU Hash
	int cpuinfo[4] = { 0, 0, 0, 0 }; //EAX, EBX, ECX, EDX
	__cpuid(cpuinfo, 0);
	char16_t hash = 0;
	char16_t* ptr = (char16_t*)(&cpuinfo[0]);
	for (char32_t i = 0; i < 8; i++)
		hash += ptr[i];
	//std::cout << "Send me this number: " << hash << std::endl;
	system("pause");
	return(0);
}

