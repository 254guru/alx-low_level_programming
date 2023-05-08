# FILE DESCRIPTORS

In Unix-like operating systems, including Ubuntu 14.04LTS, file descriptors are a way of identifying and accessing open files or other input/output (I/O) resources such as network sockets, pipes, and devices. 

A file descriptor is an integer value that is associated with an open file or I/O resource. When a file is opened, the operating system assigns a unique file descriptor to that file, which is used to access the file in subsequent operations. 

The standard input, output, and error streams (stdin, stdout, and stderr) are also represented as file descriptors: 0, 1, and 2, respectively.

File descriptors are typically used in C programming to perform I/O operations on files and other resources using system calls such as `open()`, `read()`, `write()`, `close()`, and `select()`. The file descriptor is passed as an argument to these system calls to specify which file or resource to operate on.

It's important to note that file descriptors are process-specific and are not shared between processes. Each process has its own set of file descriptors, which are independent of other processes.
