
# Student Record Management System

A command-line student registration and grade-management application written in C. The project stores students, courses, enrollments, and semester marks using C structures and provides file-based persistence between sessions.

## Features

- Register, list, search, and delete students
- Register, list, and delete courses
- Enroll students while preventing duplicate enrollment
- Add and update semester marks
- Calculate semester GPA and cumulative GPA
- Search records using multiple filters
- Save and load data from text files

## Build

With GCC and Make installed:

```bash
make
./student_records
```

On Windows, run `student_records.exe` after compilation.

## Repository structure

- `include/system.h` - data structures and function declarations
- `src/system.c` - record-management implementation
- `src/main.c` - interactive menu and program entry point
- `Makefile` - GCC build configuration

## Note

The original course document accidentally repeated the header under the `main.c` label. The menu and entry-point file in this repository were reconstructed from the submitted program interface so that the recovered project can be built and run.

## Author

Andrew Chong
