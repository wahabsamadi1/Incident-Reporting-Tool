# Incident Reporting Tool

### Overview
This project is designed to manage and report incidents, including resolving incidents and calculating response times. The tool supports basic functionalities such as reporting new incidents, resolving incidents, displaying all incidents, calculating response times for resolved incidents, and running unit tests for core functionalities.

### Features
+ Report New Incident: Allows users to enter a description for a new incident and records the time when the incident is reported.  
+ Resolve Incident: Lets users mark an incident as "Resolved" and records the time when the incident was resolved.  
+ Display All Incidents: Displays a list of all reported incidents along with their details.  
+ Calculate Response Times: For resolved incidents, calculates and displays the response time in minutes from when the incident was reported to when it was resolved.  
+ Unit Tests: Provides basic unit tests for core functionalities such as reporting incidents, resolving incidents, and calculating response times.   


### How to Use
1. Clone the repository:  
   git clone https://github.com/wahabsamadi1/incident-reporting-tool.git
2. Navigate to the project directory:  
   cd incident-reporting-tool  
3. Compile the C++ code:
   g++ -o IncidentReportingTool main.cpp   
4. Run the program

### Usage
Running the Application
After compiling the program, you can run the tool using the following command:  
./IncidentReportingTool  

You will be presented with a menu of options to choose from:  
1. Report a new incident.  
2. Resolve an incident.  
3. Display all incidents.  
4. Calculate response times for resolved incidents.  
5. Run unit tests.  
6. Exit the program.  
   
### Example Usage
1. Here’s an example of how to interact with the tool:
2. Report a new incident: You will be prompted to enter an incident description. The incident will be logged with a unique ID and the time it was reported.
3. Resolve an incident: You will need to input the ID of the incident you want to resolve. The incident will be marked as "Resolved", and the resolution time will be recorded.
4. Display all incidents: This will show a list of all reported incidents along with their descriptions, reported times, resolution times, and status.
5. Calculate response times: For resolved incidents, this option will calculate the time taken from reporting the incident to resolving it, and display it in minutes.
6. Run Unit Tests: This will test the core functionalities of reporting, resolving, and calculating response times.

### Code Structure
+ main.cpp: Contains the main code for the incident reporting system.
+ Incident: A struct that represents an incident with fields for ID, description, reported time, resolution time, and status.
+ reportIncident(): Function to report a new incident.
+ resolveIncident(): Function to resolve an incident.
+ displayIncidents(): Function to display all incidents.
+ calculateResponseTime(): Function to calculate response time for resolved incidents.
+ unitTests(): Function to perform basic unit testing on the core functionalities.

### Requirements
+ C++11 or later.
+ A C++ compiler (e.g., GCC, Clang, or MSVC).

### Files
+ Main.cpp: The main program file that contains the code for the incident reporting tool.
+ README.md: This file, providing an overview of the project, how it works, and how to run it.
  
### License
This project is licensed under the MIT License. Feel free to use, modify, and distribute this code.
