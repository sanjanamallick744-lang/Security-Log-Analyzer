
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct IPData
{
    string ip;
    int failed;
    int success;
};

int loadData(IPData data[], int &totalFailed, int &totalSuccess)
{
    ifstream file("security_log.txt");

    if (!file)
        return -1;

    int count = 0;
    string ip, status;

    totalFailed = 0;
    totalSuccess = 0;

    while (file >> ip >> status)
    {
        int index = -1;

        for (int i = 0; i < count; i++)
        {
            if (data[i].ip == ip)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            if (count >= 100)
                break;

            index = count;
            data[count].ip = ip;
            data[count].failed = 0;
            data[count].success = 0;
            count++;
        }

        if (status == "LOGIN_FAILED")
        {
            data[index].failed++;
            totalFailed++;
        }
        else if (status == "LOGIN_SUCCESS")
        {
            data[index].success++;
            totalSuccess++;
        }
    }

    file.close();
    return count;
}

string getRisk(int failed)
{
    if (failed >= 5)
        return "HIGH RISK";
    else if (failed >= 3)
        return "MEDIUM RISK";
    else
        return "NORMAL";
}

void generateSampleLog()
{
    ofstream file("security_log.txt");

    if (!file)
    {
        cout << "\nUnable to create log file!\n";
        return;
    }

    file << "192.168.1.10 LOGIN_SUCCESS\n";
    file << "192.168.1.10 LOGIN_FAILED\n";
    file << "192.168.1.20 LOGIN_FAILED\n";
    file << "192.168.1.20 LOGIN_FAILED\n";
    file << "192.168.1.20 LOGIN_FAILED\n";
    file << "10.0.0.5 LOGIN_FAILED\n";
    file << "10.0.0.5 LOGIN_FAILED\n";
    file << "10.0.0.5 LOGIN_FAILED\n";
    file << "10.0.0.5 LOGIN_FAILED\n";
    file << "10.0.0.5 LOGIN_FAILED\n";
    file << "172.16.0.2 LOGIN_SUCCESS\n";

    file.close();

    cout << "\nSample security log created successfully!\n";
}

void displayLog()
{
    ifstream file("security_log.txt");
    string line;

    if (!file)
    {
        cout << "\nLog file not found. Generate a sample log first.\n";
        return;
    }

    cout << "\n========== SECURITY LOG ==========\n";

    while (getline(file, line))
        cout << line << endl;

    file.close();
}

void analyzeLog(bool exportReport)
{
    IPData data[100];
    int totalFailed = 0, totalSuccess = 0;

    int count = loadData(data, totalFailed, totalSuccess);

    if (count == -1)
    {
        cout << "\nLog file not found!\n";
        return;
    }

    ofstream report;

    if (exportReport)
    {
        report.open("security_report.txt");

        if (!report)
        {
            cout << "\nUnable to create report file!\n";
            return;
        }
    }

    cout << "\n========== SECURITY REPORT ==========\n";
    cout << "Successful Logins: " << totalSuccess << endl;
    cout << "Failed Logins    : " << totalFailed << endl;

    if (exportReport)
    {
        report << "========== SECURITY REPORT ==========\n";
        report << "Successful Logins: " << totalSuccess << endl;
        report << "Failed Logins: " << totalFailed << endl;
    }

    cout << "\n---------- IP ACTIVITY ----------\n";

    if (exportReport)
        report << "\n---------- IP ACTIVITY ----------\n";

    for (int i = 0; i < count; i++)
    {
        string risk = getRisk(data[i].failed);

        cout << "\nIP Address: " << data[i].ip;
        cout << "\nSuccessful Attempts: " << data[i].success;
        cout << "\nFailed Attempts: " << data[i].failed;
        cout << "\nRisk Level: " << risk << endl;

        if (risk != "NORMAL")
            cout << "Alert: Possible brute-force activity!\n";

        if (exportReport)
        {
            report << "\nIP Address: " << data[i].ip;
            report << "\nSuccessful Attempts: " << data[i].success;
            report << "\nFailed Attempts: " << data[i].failed;
            report << "\nRisk Level: " << risk << endl;

            if (risk != "NORMAL")
                report << "Alert: Possible brute-force activity!\n";
        }
    }

    if (exportReport)
    {
        report.close();
        cout << "\nReport saved to security_report.txt\n";
    }
}

void searchIP()
{
    string search;
    cout << "\nEnter IP address to search: ";
    cin >> search;

    IPData data[100];
    int failed = 0, success = 0;
    int count = loadData(data, failed, success);

    if (count == -1)
    {
        cout << "\nLog file not found!\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (data[i].ip == search)
        {
            cout << "\nIP Address: " << data[i].ip;
            cout << "\nSuccessful Logins: " << data[i].success;
            cout << "\nFailed Logins: " << data[i].failed;
            cout << "\nRisk Level: " << getRisk(data[i].failed) << endl;
            return;
        }
    }

    cout << "\nIP address not found in the log.\n";
}

void blockSuspiciousIP()
{
    IPData data[100];
    int failed = 0, success = 0;
    int count = loadData(data, failed, success);

    if (count == -1)
    {
        cout << "\nLog file not found!\n";
        return;
    }

    bool found = false;

    ofstream blocked("blocked_ips.txt", ios::app);

    if (!blocked)
    {
        cout << "\nUnable to open blocked_ips.txt!\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (data[i].failed >= 3)
        {
            cout << "\nSuspicious IP: " << data[i].ip;
            cout << " - " << getRisk(data[i].failed);

            blocked << data[i].ip << endl;
            found = true;
        }
    }

    blocked.close();

    if (found)
        cout << "\n\nSuspicious IPs saved to blocked_ips.txt\n";
    else
        cout << "\nNo suspicious IPs found.\n";

    cout << "\nNote: This simulates blocking; it does not block network traffic.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n================================";
        cout << "\n       SECURITY LOG ANALYZER";
        cout << "\n================================";
        cout << "\n1. Display Security Log";
        cout << "\n2. Analyze Security Log";
        cout << "\n3. Search IP Address";
        cout << "\n4. Save Suspicious IPs";
        cout << "\n5. Export Security Report";
        cout << "\n6. Generate Sample Log";
        cout << "\n7. Exit";
        cout << "\n\nEnter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input! Enter a number.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                displayLog();
                break;

            case 2:
                analyzeLog(false);
                break;

            case 3:
                searchIP();
                break;

            case 4:
                blockSuspiciousIP();
                break;

            case 5:
                analyzeLog(true);
                break;

            case 6:
                generateSampleLog();
                break;

            case 7:
                cout << "\nExiting Security Log Analyzer...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
