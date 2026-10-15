# 🔐 Security Log Analyzer in C++

## 📌 Project Overview
Security Log Analyzer is a beginner-friendly cybersecurity mini project developed using C++. It analyzes login activity recorded in a security log file, identifies suspicious IP addresses, detects possible brute-force attacks, and generates a security report.

The project demonstrates how basic log analysis can help monitor login attempts and identify potentially risky activity.

## ✨ Features
- **Display Security Logs:** View all recorded login activities.
- **Analyze Security Logs:** Calculate total successful and failed login attempts.
- **IP Activity Tracking:** Display successful and failed login attempts for each IP address.
- **Brute-Force Detection:** Flag IP addresses with repeated failed login attempts.
- **Risk Classification:** Classify IP addresses as Normal, Medium Risk, or High Risk.
- **IP Address Search:** Search for a specific IP address and view its activity.
- **Suspicious IP Logging:** Save suspicious IP addresses to a separate file.
- **Report Generation:** Export the security analysis to a text file.
- **Sample Log Generation:** Create sample data for testing.
- **Menu-Driven Interface:** Navigate through the features using a simple console menu.

## 🛠️ Technologies Used
- **Programming Language:** C++
- **Concepts:** Structures, Functions, Arrays, Loops, Conditional Statements
- **File Handling:** `ifstream` and `ofstream`
- **Cybersecurity Concepts:** Log Analysis, Brute-Force Detection, IP Monitoring, Risk Classification

## 📂 Project Structure

```text
Security-Log-Analyzer/
│
├── security_log_analyzer.cpp
├── security_log.txt
├── security_report.txt
├── blocked_ips.txt
└── README.md
```

*Note: The text files are created when the corresponding features are used.*

## ⚙️ How to Run

### Step 1: Install a C++ Compiler
Install a compiler such as GCC/G++ or use an existing C++ setup in VS Code.

### Step 2: Compile the Program
Open the terminal in your project folder and run:

```bash
g++ security_log_analyzer.cpp -o security_log_analyzer
```

### Step 3: Run the Program

**Windows:**
```bash
.\security_log_analyzer.exe
```

**Linux:**
```bash
./security_log_analyzer
```

### Step 4: Generate Sample Data
Choose option **6 — Generate Sample Log** from the menu.

Then select the required option to display or analyze the log.

## 📄 Log File Format

Each line contains an IP address followed by a login status.

Example:

```text
192.168.1.10 LOGIN_SUCCESS
192.168.1.20 LOGIN_FAILED
192.168.1.20 LOGIN_FAILED
10.0.0.5 LOGIN_FAILED
10.0.0.5 LOGIN_FAILED
```

Supported login statuses:
- `LOGIN_SUCCESS`
- `LOGIN_FAILED`

## 🚨 Risk Classification

| Failed Login Attempts | Risk Level |
|---|---|
| 0–2 | Normal |
| 3–4 | Medium Risk |
| 5 or more | High Risk |

These are example thresholds used for this project and may be adjusted as needed.

## 📊 Output Files

| File Name | Purpose |
|---|---|
| `security_log.txt` | Stores login activity |
| `security_report.txt` | Stores the generated security report |
| `blocked_ips.txt` | Stores IP addresses flagged as suspicious |

**Note:** The program records suspicious IP addresses in a file. It does not implement actual network-level IP blocking.

## 🎯 Learning Outcomes
- Understanding security log analysis.
- Learning C++ file handling.
- Tracking login activity by IP address.
- Identifying suspicious login patterns.
- Applying basic risk classification.
- Generating reports using file operations.

## 🔮 Future Enhancements
- Add timestamps to security logs.
- Detect repeated failed logins within a time window.
- Integrate real system authentication logs.
- Add graphical reports and charts.
- Implement actual blocking through an authorized firewall.
- Add user authentication and alert notifications.

## 👩‍💻 Author
**Sanjana Mallick**

B.Tech CSIT — Cybersecurity

## ⚠️ Disclaimer
This project is intended for educational and cybersecurity learning purposes. It uses sample log data and basic detection rules. Its alerts indicate potentially suspicious activity and do not prove that an attack has occurred.
