# Railway Queueing System

## B.Tech CSE Mini Project — C Language

---

# Project Overview

The Railway Queueing System is a console-based mini project developed using the C programming language.

This project simulates a railway reservation and passenger management system using different data structures such as Queue, Stack, Linked List, and Structures.

The system allows passengers to:

* Book train tickets
* Join waiting lists
* Access emergency/priority booking
* Cancel tickets
* View train details

The project follows modular programming concepts by dividing the system into multiple `.c` and `.h` files.

---

# Features

* Add Passenger
* Book Ticket
* View Booking Queue
* View Waiting List
* Emergency / Priority Booking
* Serve Emergency Passenger
* Cancel Ticket
* Display Train Details
* CSV File Storage
* Modular Code Structure

---

# Data Structures Used

## Queue (FIFO)

Used for normal passenger booking.

## Stack (LIFO)

Used for emergency and priority passengers.

## Linked List

Used for dynamic waiting list management.

## Structures

Used for storing passenger and train details.

---

# Technologies Used

* C Language
* GCC Compiler
* Git & GitHub
* CSV File Handling

---

# Modular File Structure

```text
RailwayQueueSystem/
│
├── main.c
├── common.h
│
├── queue.c
├── queue.h
│
├── emergency.c
├── emergency.h
│
├── waiting_list.c
├── waiting_list.h
│
├── train.c
├── train.h
│
├── file_handling.c
├── file_handling.h
│
├── passengers.csv
├── waiting.csv
├── emergency.csv
│
└── README.md
```

---

# Team Contributions

| Member   | Contribution                                                                    |
| -------- | ------------------------------------------------------------------------------- |
| Member 1 Pankaj | main.c, file_handling.c, file_handling.h, train.c, train.h, common.h, README.md |
| Member 2 Omkar | queue.c, queue.h                                                                |
| Member 3 Bhaskar| emergency.c, emergency.h                                                        |
| Member 4 Vedant | waiting_list.c, waiting_list.h                                                  |

---

# GitHub Collaboration

* All group members were added as collaborators to the GitHub repository.
* Collaboration requests were accepted by all members.
* Each member made meaningful commits to the project repository.
* The project follows modular programming practices.

---

# File Handling

Passenger booking data is stored using CSV files:

* passengers.csv
* waiting.csv
* emergency.csv

This ensures that passenger information is stored properly.

---

# Compilation Command

```bash
gcc main.c queue.c emergency.c waiting_list.c train.c file_handling.c -o railway
```

---

# Run Command

## Windows

```bash
railway.exe
```

## Linux / Mac

```bash
./railway
```

---

# Learning Outcomes

Through this project we learned:

* Queue implementation
* Stack implementation
* Linked List implementation
* Structures in C
* File Handling
* Modular Programming
* GitHub Collaboration
* Team-based software development

---

# Developed For

B.Tech CSE Mini Project

---

# License

This project is developed for educational purposes only.
