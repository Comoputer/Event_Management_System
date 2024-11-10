#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Event {
public:
    string title;
    string description;
    string date;
    string time;
    string location;
    vector<string> attendees;

    Event(string t, string d, string dt, string tm, string loc)
        : title(t), description(d), date(dt), time(tm), location(loc) {}

    void addAttendee(string attendee) {
        attendees.push_back(attendee);
    }

    void displayEvent() {
        cout << "\nTitle: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Location: " << location << endl;
        cout << "Attendees: ";
        for (const string& attendee : attendees) {
            cout << attendee << " ";
        }
        cout << endl;
    }
};

class EventManager {
private:
    vector<Event> events;

public:
    void createEvent() {
        string title, description, date, time, location;

        cout << "Enter event title: ";
        cin.ignore(); // to clear the newline buffer
        getline(cin, title);

        cout << "Enter event description: ";
        getline(cin, description);

        cout << "Enter event date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << "Enter event time (HH:MM): ";
        getline(cin, time);

        cout << "Enter event location: ";
        getline(cin, location);

        Event newEvent(title, description, date, time, location);
        events.push_back(newEvent);
        cout << "\nEvent created successfully!\n";
    }

    void viewEvents() {
        if (events.empty()) {
            cout << "\nNo events available.\n";
            return;
        }

        for (int i = 0; i < events.size(); ++i) {
            cout << "\nEvent #" << (i + 1) << ":";
            events[i].displayEvent();
        }
    }

    void rsvpEvent() {
        int eventId;
        string attendee;

        cout << "Enter event number to RSVP: ";
        cin >> eventId;

        if (eventId < 1 || eventId > events.size()) {
            cout << "Invalid event number.\n";
            return;
        }

        cout << "Enter your name to RSVP: ";
        cin.ignore();
        getline(cin, attendee);

        events[eventId - 1].addAttendee(attendee);
        cout << "\nYou have successfully RSVP'd to the event!\n";
    }

    void viewEventDetails() {
        int eventId;

        cout << "Enter event number to view details: ";
        cin >> eventId;

        if (eventId < 1 || eventId > events.size()) {
            cout << "Invalid event number.\n";
            return;
        }

        events[eventId - 1].displayEvent();
    }
};

int main() {
    EventManager manager;
    int choice;

    while (true) {
        cout << "\nEvent Management System\n";
        cout << "1. Create Event\n";
        cout << "2. View Events\n";
        cout << "3. RSVP for an Event\n";
        cout << "4. View Event Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.createEvent();
                break;
            case 2:
                manager.viewEvents();
                break;
            case 3:
                manager.rsvpEvent();
                break;
            case 4:
                manager.viewEventDetails();
                break;
            case 5:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
