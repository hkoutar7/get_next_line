# Get_Next_Line Project - 42 Cursus


## The get_next_line project is part of the 42 Cursus curriculum and is designed to introduce  to file input/output operations and dynamic memory allocation in C programming language. The main objective of this project is to create a function that reads a file line by line, regardless of the size of the file or the buffer used to read it.

# Project Overview
The get_next_line function takes three arguments:


### The get_next_line project is part of the 42 Cursus curriculum and is designed to introduce  to file input/output operations and dynamic memory allocation in C programming language. The main objective of this project is to create a function that reads a file line by line, regardless of the size of the file or the buffer used to read it.

# Project Overview
#### The get_next_line function takes three arguments:

- int get_next_line(int fd, char **line, int buffer_size);
- fd          : file descriptor of the file to be read
- line        : pointer to a character string that will be used to store the line read from the file
- buffer_size : size of the buffer to be used for reading the file

#### The function reads one line at a time from the file pointed to by fd and stores it in the line variable. The function returns 1 if a line has been successfully read, 0 if the end of the file has been reached, and -1 if an error occurs.

#### The get_next_line function must also be able to handle multiple file descriptors at the same time, allowing for simultaneous reading from multiple files.

# Project Requirements
#### In order to successfully complete the get_next_line project,we  must meet the following requirements:

+ The function must be able to read and handle multiple file descriptors at the same time
* The function must use dynamic memory allocation to ensure efficient memory usage

# Conclusion
#### The get_next_line project is an important exercise in file input/output operations and dynamic memory allocation in C programming language. By successfully completing this project, students gain valuable experience in handling file input/output operations, managing dynamic memory allocation, and improving their overall programming skills.

## Deployment

##### Create a new file that will hold outext for instance jojo.txt
##### To deploy this project run

```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.h get_next_line.c get_next_line_utils.c main.c 
```

## Get next line Ressources

 - [get_next_line tester gnlTester](https://github.com/Tripouille/gnlTester)
 - [helpful video](hhttps://www.youtube.com/watch?v=-Mt2FdJjVno&t=643s)


## Authors

- [hkoutar7](https://github.com/)

## Contributing

Contributions are always welcome!

