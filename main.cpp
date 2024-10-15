#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Maximum number of incidents
const int MAX_INCIDENTS = 100;

// Structure to represent an incident
struct Incident {
    int id;
    string description;
    string reportedTime;
    string resolutionTime;
    string status; // "Open" or "Resolved"
};

// Incident database (array of incidents)
Incident incidents[MAX_INCIDENTS];
int incidentCount = 0; // To track how many incidents have been reported

// Function declarations
void reportIncident();
void resolveIncident();
void displayIncidents();
void calculateResponseTime();
void unitTests();

// Function to report a new incident
void reportIncident() {
    if (incidentCount >= MAX_INCIDENTS) {
        cout << "Incident database is full!" << endl;
        return;
    }

    Incident newIncident;
    newIncident.id = incidentCount + 1; // Assign a new ID to the incident
    cout << "Enter Incident Description: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newIncident.description);

    // Capture current time as the reported time
    time_t now = time(0);
    char* dt = ctime(&now);
    newIncident.reportedTime = string(dt);

    newIncident.status = "Open"; // Initially, the incident is open
    newIncident.resolutionTime = ""; // No resolution time initially

    incidents[incidentCount] = newIncident; // Store the new incident
    incidentCount++;

    cout << "Incident reported successfully!" << endl;
}

// Function to resolve an incident
void resolveIncident() {
    int id;
    cout << "Enter the Incident ID to resolve: ";
    cin >> id;

    if (id < 1 || id > incidentCount) {
        cout << "Invalid Incident ID!" << endl;
        return;
    }

    // Mark the incident as resolved
    incidents[id - 1].status = "Resolved";

    // Capture resolution time
    time_t now = time(0);
    char* dt = ctime(&now);
    incidents[id - 1].resolutionTime = string(dt);

    cout << "Incident resolved successfully!" << endl;
}

// Function to display all incidents
void displayIncidents() {
    if (incidentCount == 0) {
        cout << "No incidents reported." << endl;
        return;
    }

    cout << "\nList of Incidents:\n";
    for (int i = 0; i < incidentCount; i++) {
        cout << "ID: " << incidents[i].id
             << ", Description: " << incidents[i].description
             << ", Reported Time: " << incidents[i].reportedTime
             << ", Resolution Time: " << incidents[i].resolutionTime
             << ", Status: " << incidents[i].status << endl;
    }
}

// Function to calculate response time for resolved incidents
void calculateResponseTime() {
    if (incidentCount == 0) {
        cout << "No incidents to calculate response time." << endl;
        return;
    }

    for (int i = 0; i < incidentCount; i++) {
        if (incidents[i].status == "Resolved") {
            struct tm reportedTime, resolutionTime;
            strptime(incidents[i].reportedTime.c_str(), "%a %b %d %H:%M:%S %Y", &reportedTime);
            strptime(incidents[i].resolutionTime.c_str(), "%a %b %d %H:%M:%S %Y", &resolutionTime);

            time_t reported = mktime(&reportedTime);
            time_t resolved = mktime(&resolutionTime);

            double responseTime = difftime(resolved, reported); // Time difference in seconds
            cout << "Incident ID: " << incidents[i].id
                 << ", Response Time: " << responseTime / 60 << " minutes" << endl; // Convert seconds to minutes
        }
    }
}

// Function for unit testing (for core functionality)
void unitTests() {
    // Test Report Incident
    reportIncident();
    if (incidentCount == 1) {
        cout << "Unit Test 1 Passed: Incident reported successfully." << endl;
    } else {
        cout << "Unit Test 1 Failed: Incident not reported correctly." << endl;
    }

    // Test Resolve Incident
    resolveIncident();
    if (incidents[0].status == "Resolved") {
        cout << "Unit Test 2 Passed: Incident resolved successfully." << endl;
    } else {
        cout << "Unit Test 2 Failed: Incident not resolved correctly." << endl;
    }

    // Test Response Time Calculation
    calculateResponseTime();
}

int main() {
    int choice;

    do {
        cout << "\nIncident Reporting Tool\n";
        cout << "1. Report New Incident\n";
        cout << "2. Resolve Incident\n";
        cout << "3. Display All Incidents\n";
        cout << "4. Calculate Response Times for Resolved Incidents\n";
        cout << "5. Run Unit Tests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reportIncident();
                break;
            case 2:
                resolveIncident();
                break;
            case 3:
                displayIncidents();
                break;
            case 4:
                calculateResponseTime();
                break;
            case 5:
                unitTests();
                break;
            case 6:
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
