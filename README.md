# Log Archive Tool

## Description

The Log Archive Tool is a simple command-line utility to help manage log files efficiently. It compresses logs from a specified directory into a `.tar.gz` file, stores the archive in a new directory, and logs the details of the operation. This is particularly useful for maintaining a clean system by archiving and removing old logs while preserving them for future reference.

The tool also provides opportunities to extend functionality, such as emailing archive updates or uploading archives to remote servers or cloud storage.

[Project Description Link](https://roadmap.sh/projects/log-archive-tool)
---

## Features

- **Command-line operation**: Accepts the log directory as an argument.
- **Compression**: Archives logs into a `.tar.gz` file using the `tar` command.
- **Organized storage**: Saves the archive in a dedicated directory (`archive`).
- **Logging**: Records the date, time, and archive details in a log file (`archive_log.txt`).
- **Platform compatibility**: Works on Unix-based systems where logs are typically stored in `/var/log`.

---

## Requirements

1. **C++ Compiler**: Ensure a compiler with C++17 support (e.g., GCC 8.1+, Clang 7+).
2. **`tar` Command**: The tool relies on the `tar` command for compression.

---

## How to Compile

Use the following command to compile the program:

```bash
g++ -std=c++17 -o log-archive main.cpp

