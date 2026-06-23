#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
// 0 - stdin
// 1 - stdout
// 2 - stderr

int main()
{
    // open() or creat()
    int fd = open("./test_file", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        std::cerr << open("./test_file", O_CREAT, 0644);
        perror(strerror(errno));
        return errno;
    }
    std::cerr << "FD: " << fd << std::endl;

    if(write(fd, "Hello, World!", 13) == -1)
    {
        std::cerr << "Error writing to file: ";
        perror(strerror(errno));
        return errno;
    }

    close(fd);

    fd = open("./test_file", O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "Error opening file for reading: ";
        perror(strerror(errno));
        return errno;
    }
    std::cerr << "FD while reading: " << fd << std::endl;

    char buf [100];
    uint bytes = -1;
    if((bytes = read(fd, buf, 100)) == -1)
    {
        std::cerr << "Error reading from file: ";
        perror(strerror(errno));
        return errno;
    }
    buf[bytes] = 0;
    std::cout << "Bytes read: " << bytes << "\nFile contents: " << buf << std::endl;
    close(fd);

    return 0;
}