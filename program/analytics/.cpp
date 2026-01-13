$include <iostream>
using namespace std;

int main() {
    int reviews[100];
    int count = 0;
    int choice;

    // counters
    int excellent = 0, good = 0, average = 0, poor = 0, veryPoor = 0;

    do {
        cout << "\n===== REVIEW ANALYTICS MENU =====\n";
        cout << "1. Add Review\n";
        cout << "2. Show All Reviews\n";
        cout << "3. Count Categories (Analytics)\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            if (count >= 100) {
                cout << "Review storage full!\n";
            } else {
                int r;
                cout << "Enter review (1-5): ";
                cin >> r;

                if (r < 1 || r > 5) {
                    cout << "Invalid review!\n";
                } else {
                    reviews[count++] = r;

                    if (r == 5) excellent++;
                    else if (r == 4) good++;
                    else if (r == 3) average++;
                    else if (r == 2) poor++;
                    else if (r == 1) veryPoor++;

                    cout << "Review saved.\n";
                }
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No reviews stored.\n";
            } else {
                cout << "Reviews: ";
                for (int i = 0; i < count; i++) {
                    cout << reviews[i] << " ";
                }
                cout << endl;
            }
        }

        else if (choice == 3) {
            cout << "\n--- Review Analytics ---\n";
            cout << "Total reviews : " << count << endl;
            cout << "Excellent (5) : " << excellent << endl;
            cout << "Good (4) : " << good << endl;
            cout << "Average (3) : " << average << endl;
            cout << "Poor (2) : " << poor << endl;
            cout << "Very Poor (1) : " << veryPoor << endl;

            if (count > 0) {
                float avgScore =
                    (5*excellent + 4*good + 3*average + 2*poor + 1*veryPoor)
                    / (float)count;
                cout << "Average Score : " << avgScore << endl;
            }
        }

        else if (choice == 0) {
            cout << "Exit program.\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}