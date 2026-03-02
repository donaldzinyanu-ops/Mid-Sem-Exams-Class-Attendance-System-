#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <limits>
#include <ctime>
#include <sstream>
#include <cstddef> //Required for size_t in c++98//
#include <cctype> //Required for toupper()//

Using namespace std;

// --- Student Class  Definition (functional requirement 5.1)...//
class Student {
private:
    string indexNumber;
    string name;
    
    public:
       Student() {} //C++98 default constructor//

    Student(string idx, string n ) : indexNumber(idx),name(n) {}
    
    string getindex() const{return indexNumber;}
    string getname() const{return name;}
    
    void saveToFile(ofstream outFile) const{
    	outFile <<indexNumber<<""<<name<<endl;
    }
    
    //Helper function for formatted display//
    void displayFormatted() const{
    	cout<< left << setw(15) << indexNumber << setw(30) << name << endl;
	}
};
//--- Attendance Record Structure---//
struct AttendanceRecord {
	string studentIndex;
	string status;
};
	
//AttendanceSession Class Definition (Functional Requirement 5.2)---//
	class AttendanceSession {
		private:
			string courseCode;
			string date;
    		string startTime;
    		string duration;
    		vector<AttendanceRecord> records;
    		
    	public:
			AttendanceSession(string code,string dt,string st,string dur)
				:coursecode(code), date(dt), startTime(st), duration(dur) {}
			
			void addRecord(string index, string status) {
				AttendanceRecord newRecord;
				newRecord.studentIndex=index;
				newRecord.status=status;
				records.push_back(newRecord);
			}
			
			void saveToFile() const {
				ofstream outFile(generateFilename().c_str());
				
				if (outFile.is_open()) {
					outFile <<"Course:" <<courseCode <<", Date: " <<
							<<", Start Time: "<<", Duration: " << endl;
					for (size_t i=0; < records.size(); ++i) {
						outFile << records[i].studentIndex <<""<< records[i].status << endl;
					}
				    outFile.close();
					cout<< "Success! Student data has been saved to " <<generateFilename() << endl;
				} else {
					cerr <<"Error creating session file." << endl;
				}
			}
				
	};
			
    void registerStudent(vector<Student>& students) {
    string index, name;
    cout << "Enter student index: "; cin >> index;
    cout << "Enter student name: "; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    students.push_back(Student(index, name));
    ofstream outFile("students.csv", ios::app); 
    if (outFile.is_open()) {
        // If file is empty, write header first
        outFile.seekp(0, ios::end);
        if (outFile.tellp() == 0) outFile << "Index Number, Student Name\n";
        students.back().saveToFile(outFile);
        outFile.close();
    }
}


	//...Function Prototypes (Declarations)...//
	//...These tell the main function about the existence and structure of the functions below//		
	void loadStudentsFromFile(vector<Students>& students);
    void registerStudent(vector<Student>& students);
    void markAttendance(vector<Students>& students);
    void displayReports(vector<Students>& students);
    string getCurrentDate();

    //...Main Function (Menu.Driven Program Flow)...//
    int main() {
        vector<student> students;
        loadStudentsFromFile(students); //Now the compiler knows what this function is

        int choice = 0;
        do {
            cout << "\n--------------------------------------------------" << endl;
            cout << "            Digital Attendance System Menu" << endl;
            cout << "  --------------------------------------------------" << endl;
            cout << "1. Register a new student." << endl;
            cout << "2. View all registered students." << endl;
            cout << "3. Create/Mark a lecture session." << endl;
            cout << "4. View Reports & Summaries." << endl;
            cout << "5. Exit." << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Enter Your Selection: " << endl;

            if (!(cin >> choice)) {
                cout << "\nInvalid input. Please enter one of the numbers above." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    registerStudent(students);
                    break;
                case 2:
                    loadStudentsFromFile(students);
                    break;
                case 3:
                    markAttendance(students);
                    break;
                case 4:
                    displayReports(students);
                    break;
                case 5:
                    Exit
            }
        }
    }
