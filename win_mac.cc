#include <winsock2.h> // htons() htonl() and other helper functions
#pragma comment (lib,"WS2_32.lib") 
#include <windows.h> 
#include <Iphlpapi.h>// Used to find information about the device such as default gateway and hardware addresses
#pragma comment (lib,"Iphlpapi.lib") 
#include <iostream>

int main(int argc, char *argv[])
{
	ULONG   MAC[2], size = 6;
	LPBYTE  buffer;
	char data[20];

	if (SendARP(inet_addr("192.168.1.10"), 0, MAC, &size) == NO_ERROR)
	{
		buffer = (LPBYTE)MAC;

		// access the address one byte at a time
		sprintf(data, "%02X:%02X:%02X:%02X:%02X:%02X",
			buffer[0],
			buffer[1],
			buffer[2],
			buffer[3],
			buffer[4],
			buffer[5]);
	}
	cout << data << endl;
  return 0;
  }
