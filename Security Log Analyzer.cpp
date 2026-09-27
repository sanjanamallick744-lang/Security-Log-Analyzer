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

void displayLog()
{
    ifstream file("security_log.txt");
    string line;

    if (!file)
    {
        cout << "\nError: security_log.txt not found!\n";
        return;
    }

    cout << "\n========== SECURITY LOG ==========\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void analyzeLog()
{
    ifstream file("security_log.txt");

    if (!file)
    {
        cout << "\nError: security_log.txt not found!\n";
        return;
    }

    IPData data[100];
    int count = 0;
    int totalFailed = 0;
    int totalSuccess = 0;

    string ip, status;
    bool found;

    while (file >> ip >> status)
    {
        int index = -1;
        found = false;

        for (int i = 0; i < count; i++)
        {
            if (data[i].ip == ip)
            {
                index = i;
                found = true;
                break;
            }
        }

        if (!found)
        {
            data[count].ip = ip;
            data[count].failed = 0;
            data[count].success = 0;
            index = count;
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

    cout << "\n========== SECURITY REPORT ==========\n";

    cout << "\nSuccessful Logins : " << totalSuccess << endl;
    cout << "Failed Logins     : " << totalFailed << endl;

    cout << "\n---------- IP ACTIVITY ----------\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nIP Address: " << data[i].ip;
        cout << "\nSuccessful Attempts: " << data[i].success;
        cout << "\nFailed Attempts: " << data[i].failed;

        if (data[i].failed >= 3)
        {
            cout << "\nSTATUS: SUSPICIOUS";
        }
        else
        {
            cout << "\nSTATUS: NORMAL";
        }

        cout << "\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n================================";
        cout << "\n       SECURITY LOG ANALYZER";
        cout << "\n================================";
        cout << "\n1. Display Log";
        cout << "\n2. Analyze Log";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayLog();
                break;

            case 2:
                analyzeLog();
                break;

            case 3:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 3);

    return 0;
}
