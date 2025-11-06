# Hospital Management Console

A lightweight, console-driven hospital management system written in C by first-year students to learn core programming and file-handling concepts.

## Authors
- Krishna Saraswat  
- Yashraj Siwal  

## Overview
This project simulates day-to-day hospital operations—adding, updating, searching and discharging patients—entirely through a terminal interface. All records are stored in plain-text files for simplicity and portability.

## Features
- Add new patient details (ID, name, age, gender, contact, ailment, admission date)  
- Update existing records  
- Search by patient ID or name  
- Discharge patient & move record to history file  
- View complete patient list  
- Simple, menu-driven UI with input validation  

## Tech Stack
- Language: C (ISO C99)  
- Storage: text files (CSV-like format)  
- Build: GCC / MinGW, no external dependencies  

## Quick Start
1. Clone: `git clone https://github.com/iiitvkrishna/Hospital-Management-Console.git`  
2. Compile: `gcc src/*.c -o hospital.exe` (Windows) or `gcc src/*.c -o hospital` (Linux/Mac)  
3. Run: `./hospital` (or `hospital.exe`)  
4. Follow on-screen menus to manage records.


## Future Improvements
- Password-protected admin login  
- Binary file storage for faster access  
- Appointment & billing modules  
- Cross-platform GUI using GTK or Qt  

## License
MIT License – feel free to fork and improve.

> Built with ❤️ in the first year of college to solidify C fundamentals.
