MutEx School — C++ Masterclass : HPC

### `File Operation System Calls: file_demo.cpp`

POSIX file-related system calls: `read` and `write`
The names can be confusing at first, but they are actually intuitive.
These functions are **POSIX system calls** used for low-level file I/O in Unix/Linux systems.

* `write` does not read — it writes data.
* `read` does not write — it reads data.

More precisely:

* `write()` reads data from the program’s memory and writes it into a file.
* `read()` reads data from a file and writes it into the program’s memory (buffer).

So the names `read` and `write` describe the direction of data transfer relative to the process.

To use these functions, you need to include:

```c
#include <unistd.h>
```

---

### `write` system call (POSIX)

```text
NAME
       write - write to a file descriptor

SYNOPSIS
       #include <unistd.h>

       ssize_t write(int fd, const void *buf, size_t count);
```

* `fd` – file descriptor
* `buf` – pointer to the data in memory
* `count` – number of bytes to write
* Returns number of bytes written or `-1` on error

Note the `const` keyword:
`write()` does not modify the buffer; it only reads from it.

---

### `read` system call (POSIX)

```text
NAME
       read - read from a file descriptor

SYNOPSIS
       #include <unistd.h>

       ssize_t read(int fd, void *buf, size_t count);
```

* `fd` – file descriptor
* `buf` – memory buffer where data will be stored
* `count` – number of bytes to read
* Returns number of bytes read, `0` for EOF, or `-1` on error

Note the absence of `const`:
`read()` writes data into the buffer.

---

### Key idea

These are **POSIX-standard system calls**, and the difference is clearly reflected in their prototypes:

* `write()` → reads from memory (`const void *buf`)
* `read()` → writes into memory (`void *buf`)

---

If you want, I can also add a short section like **“POSIX vs System call vs C library (`fwrite/fread`)”** for your README — that usually makes it very strong for interviews.




### `File anomaly example: file_anomaly.cpp`
