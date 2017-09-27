#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <arpa/inet.h>
using namespace std;

void scan(int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, "122.4.115.227", &addr.sin_addr);

    int ret = connect(fd, (struct sockaddr *)&addr, sizeof(addr));

    string result;
    if (ret == 0)
    {
        result = "connect succeed : ";
    }
    else
    {
        result = "connect fault   : ";
    }
    cout << result << " : " << port << "  " << strerror(errno) << endl;
    close(fd);
}

int main()
{
    for (int i = 1; i <= 50010; i++)
    {
        scan(i);
    }
}