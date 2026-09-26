# Security Log Analyzer

## 📌 Description

Security Log Analyzer is a simple **C++ cybersecurity project** that analyzes security log files and detects suspicious login activity.

The program reads login records from a text file and identifies successful logins, failed login attempts, and potentially suspicious IP addresses.

## 🎯 Features

* Display security logs
* Count successful login attempts
* Count failed login attempts
* Detect suspicious IP addresses
* Identify repeated failed login attempts
* Generate a basic security report

## 🛠️ Technologies Used

* **Language:** C++
* **IDE:** Dev-C++
* **File Handling:** C++ `fstream`
* **Input File:** `security_log.txt`

## 🔍 Suspicious Activity Detection

An IP address is considered **suspicious** when it has **3 or more failed login attempts**.

Example:

```text
192.168.1.15 LOGIN_FAILED
192.168.1.15 LOGIN_FAILED
192.168.1.15 LOGIN_FAILED
```

The program will flag `192.168.1.15` as suspicious.

## 📂 Project Structure

```text
Security-Log-Analyzer/
│
├── SecurityLogAnalyzer.cpp
├── security_log.txt
└── README.md
```

## ▶️ How to Run

1. Open **Dev-C++**.
2. Open `SecurityLogAnalyzer.cpp`.
3. Make sure `security_log.txt` is in the same folder as the `.cpp` file.
4. Compile and run the program.
5. Select an option from the menu.

## 📄 Sample Log Format

```text
192.168.1.10 LOGIN_SUCCESS
192.168.1.15 LOGIN_FAILED
192.168.1.15 LOGIN_FAILED
192.168.1.15 LOGIN_FAILED
192.168.1.20 LOGIN_SUCCESS
192.168.1.25 LOGIN_FAILED
```

## 🎓 Learning Outcomes

* Understanding security logs
* Basic cybersecurity monitoring
* File handling in C++
* String processing
* Identifying suspicious login activity
* Applying conditional statements and loops

## ⚠️ Note

This is an **educational cybersecurity project** designed to demonstrate basic security log analysis using C++. It is not a replacement for a real Security Information and Event Management (SIEM) system.

## 👩‍💻 Author

**Sanjana Mallick**

B.Tech CSIT — Cybersecurity
****
