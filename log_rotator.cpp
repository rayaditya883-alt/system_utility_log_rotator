#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

/*
 Log Rotator Utility
 Demonstrates file handling and error handling in C++

 Edge cases handled:
 - Log file does not exist
 - Log file exceeds size limit
 - Backup file already exists
*/

int main() {
    string logFile = "app.log";
    string backupFile = "app.log.bak";
    const uintmax_t MAX_SIZE = 1024; // 1 KB limit

    try {
        // If log file does not exist, create it
        if (!fs::exists(logFile)) {
            ofstream createLog(logFile);
            createLog << "Log file created.\n";
            createLog.close();
            cout << "Log file created successfully.\n";
            return 0;
        }

        // Check file size
        uintmax_t size = fs::file_size(logFile);
        cout << "Current log size: " << size << " bytes\n";

        // Rotate if size exceeds limit
        if (size >= MAX_SIZE) {
            if (fs::exists(backupFile)) {
                fs::remove(backupFile);
            }

            fs::rename(logFile, backupFile);

            ofstream newLog(logFile);
            newLog << "New log file after rotation.\n";
            newLog.close();

            cout << "Log rotated successfully.\n";
        } else {
            cout << "Log size within limit. No rotation needed.\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unexpected error occurred.\n";
    }

    return 0;
}
