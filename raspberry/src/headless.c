/*
The MIT License (MIT)

Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"headless.h"

/************************************************************
Function:	server

Type:		int

Return:		0 for 'q' keypress

Description:	Starts a socket to get keypresses from client.
		Passes these inputs to the headlessinput function
		in the headlessinput header.
*************************************************************/

int server(void)
{
	int server_input;
	char server_read[2];
	int listen_fd, comm_fd;
	struct sockaddr_in servaddr;
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);
	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listen_fd, 10);
	comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
	while(1)
	{
		server_input = 0;
		memset(server_read, '\0', 2);
		if(read(comm_fd, server_read, 2) == -1)
		{
			return 1;
		}
		server_input = server_read[0];
		if(server_input == 'q')
		{
			headlessinput('q');
			init(0);
			return 0;
		}
		headlessinput(server_input);
	}
}
