#include <iostream>
#include <fcntl.h>
#include <unistd.h>
// 0 - stdin
// 1 - stdout
// 2 - stderr

int main()
{
    close(1);   // closing stdout, and as a result number "1" became free
    int fd = open("anomaly", O_CREAT | O_WRONLY, 0666);  // open returns the minimal free number which is "1" in our case
    std::cout << "Writing to anomaly file!"  << ", FD=" << fd;    // so, now std::cout prints in opened file instead of stdout
} 

