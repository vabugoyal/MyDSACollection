#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main(int args, char** argv)
{
    if(args < 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string fileName = argv[1];
    const string reversedFileName = fileName + "_reversed.txt";

    int fd = open(fileName.c_str(), O_RDONLY);
    int revFd = open(reversedFileName.c_str(), O_CREAT | O_WRONLY, 0666);

    // read the line byte by byte until the newline char
    auto readLine = [&](string& line) -> bool
    {
        char b;
        size_t bytesRead;
        bool hasChar = false;
        while((bytesRead = read(fd, &b, 1)) > 0)
        {
            hasChar |= bytesRead;
            if(b == '\n')
            {
                break;
            }
            line.push_back(b);
        }

        // return true if we read something even if it is \n
        return hasChar;
    };

    string line;
    while(readLine(line))
    {
        // reverse this line and write it
        ranges::reverse(line);
        line.push_back('\n');
        write(revFd, line.c_str(), (size_t)line.size());
        line.clear();
    }

    close(fd);
    close(revFd);
}