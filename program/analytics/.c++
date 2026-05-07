#include <iostream>
#include <string>
#include <person.pb.h>  // សម្រាប់ setw() ធ្វើតារាងស្អាត
using namespace std;

int main() {
    int n; // ចំនួនអតិថិជន
    cout << "ចូលចំនួនអតិថិជននៅផ្សារ: ";
    cin >> n;

    // ប្រកាស array សម្រាប់រាប់ (gender: 0 = Female, 1 = Male)
    int female[5] = {0}; // ក្រុមអាយុ 0..4
    int male[5] = {0};
    int total[5] = {0};

    string gender;
    int age;

    for(int i = 1; i <= n; i++) {
        cout << "\nអតិថិជនទី " << i << ":\n";
        
        // បញ្ចូលភេទ
        cout << " ភេទ (F = ស្ត្រី / M = បុរស): ";
        cin >> gender;
        
        // បញ្ចូលអាយុ
        cout << " អាយុ: ";
        cin >> age;

        // កំណត់ក្រុមអាយុ (index 0..4)
        int group;
        if(age >= 18 && age <= 25) group = 0;
        else if(age <= 35) group = 1;
        else if(age <= 45) group = 2;
        else if(age <= 55) group = 3;
        else if(age > 55) group = 4;
        else {
            cout << "អាយុមិនសមរម្យ (ត្រូវ >=18)!\n";
            i--; // បញ្ចូលឡើងវិញ
            continue;
        }

        // រាប់
        total[group]++;
        if(gender == "F" || gender == "f") {
            female[group]++;
        } else if(gender == "M" || gender == "m") {
            male[group]++;
        } else {
            cout << "ភេទមិនត្រឹមត្រូវ! បញ្ចូលឡើងវិញ...\n";
            i--;
            continue;
        }
    }

    // បង្ហាញលទ្ធផលជា analytics តារាងស្អាត
    cout << "\n=================== ANALYTICS អតិថិជនផ្សារ ===================\n";
    cout << setw(15) << "ក្រុមអាយុ" 
         << setw(12) << "ស្ត្រី(F)" 
         << setw(12) << "បុរស(M)" 
         << setw(12) << "សរុប" << endl;
    cout << "----------------------------------------------------------------\n";

    string groups[5] = {"18-25", "26-35", "36-45", "46-55", "56+"};

    int grand_f = 0, grand_m = 0, grand_total = 0;

    for(int g = 0; g < 5; g++) {
        cout << setw(15) << groups[g]
             << setw(12) << female[g]
             << setw(12) << male[g]
             << setw(12) << total[g] << endl;

        grand_f += female[g];
        grand_m += male[g];
        grand_total += total[g];
    }

    cout << "----------------------------------------------------------------\n";
    cout << setw(15) << "សរុបទាំងអស់"
         << setw(12) << grand_f
         << setw(12) << grand_m
         << setw(12) << grand_total << endl;

    cout << "\nសមាមាត្រ ស្ត្រី: " << (grand_total > 0 ? (float)grand_f / grand_total * 100 : 0) << "%" 
         << " | បុរស: " << (grand_total > 0 ? (float)grand_m / grand_total * 100 : 0) << "%\n";

    return 0;
