# 🌪 Checksum generator 
This is a command-line tool written in C that generates checksums for files using either the MD5 or SHA-256 hashing algorithms. It's useful for verifying the integrity of files by comparing their generated checksums to expected values.

## 🌱 Installation
1. Clone the repository:
```
git clone https://github.com/giovanni-iannaccone/Checksum-generator
```
2. Compile the tool:
```
gcc main.c include/* src/* -o main
```
## 🕹 Usage
1. Check options:
```
main --help
```
2. Run the tool:
```
main -f FILE -a MD5
```

## 📚 Learn
Look at <a href="https://datatracker.ietf.org/doc/html/rfc1321">this</a> paper to know more about hashing with C

## ⚖ License
This project is licensed under the GPL-3.0 License. See the LICENSE file for details.
