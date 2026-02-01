# System Utility – Log Rotator (C++)

## Goal
Build a small system utility demonstrating file handling in C++.

## Description
This program checks the size of a log file.  
If the file exceeds a fixed size limit, it is renamed as a backup and a new log file is created.

## Features
- File existence check
- File size checking
- Log rotation
- Error handling using try-catch

## Edge Cases Handled
- Log file not found
- Log file already backed up
- File system errors

## How to Run
Compile:
cl /EHsc log_rotator.cpp

Run:
log_rotator.exe

## Sample Output
Log file created successfully.
OR
Current log size: 1500 bytes
Log rotated successfully.
