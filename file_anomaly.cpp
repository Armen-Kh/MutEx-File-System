#include <iostream>
#include <fcntl.h>
#include <unistd.h>
// 0 - stdin
// 1 - stdout
// 2 - stderr

int main()
{
    close(1);   
    // Closes stdout (file descriptor 1). 
    // FD 1 becomes available for reuse by the kernel.
    
    int fd = open("anomaly", O_CREAT | O_WRONLY, 0666);
    // open() returns the lowest available file descriptor.
    // Since 1 was just freed, it is reused and assigned to this file.
    
    std::cout << "Writing to anomaly file!"  << ", FD=" << fd;
    // However, since FD 1 (stdout) is now associated with "anomaly",
    // low-level writes to stdout (write(1, ...)) will go to the file.
    // std::cout itself may still be buffered/untied unless explicitly synced.
} 

