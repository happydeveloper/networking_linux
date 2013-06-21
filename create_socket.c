#include<stdio.h>
#include<sys/socket.h>
/*
http://www.binarytides.com/socket-programming-c-linux-tutorial/
This first thing to do is create a socket.

The 'socket()' function does this.

*/
int main(int argc, char *argv[])
{
	int socket_desc;
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
/*
	Function socket() creates a socket
	and return a socket descriptor 
	which can be use in other network commands.

	The above code will create a scoket of :
	Address Family : AF_INET(this is IP version 4)
	Type : SOCK_STREAM (this means connection oriented TCP protocol)
	Protocol : 0 [or IPPROTO_IP this is IP protocol]

	create a socket successfully.

*/
	if( socket_desc == -1)
	{
		printf("Could not crate socket");
	}
	
	return 0;
}
