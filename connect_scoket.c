#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<string.h> //strlen
int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message, server_reply[10000];

	//create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc == -1)
	{
		printf("Could not create socket");
	}	

//	server.sin_addr.s_addr = inet_addr("220.95.233.172"); //never
	
//	server.sin_addr.s_addr = inet_addr("114.108.157.19"); //daum
//	server.sin_addr.s_addr = inet_addr("74.125.235.20");
//	server.sin_addr.s_addr = inet_addr("54.248.60.217"); //ot
	server.sin_addr.s_addr = inet_addr("87.98.158.89"); // gephi.org
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	//connect to remote server
	if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");

	//send some data
	//약간의 데이타를 보낸다.
	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(socket_desc, message, strlen(message), 0) < 0){
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");

	//Receive a reply from the server
	if( recv(socket_desc, server_reply, 2000, 0) < 0)
	{
		puts("recv_failed");
	}
	puts("Reply received\n");
	puts(server_reply);
	return 0;
}
