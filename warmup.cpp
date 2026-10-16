// =====================================================================
//  C++ WARM-UP  ·  African Olympiad Academy
//
//  The question descriptions are in README.md. Read them there.
//  This file holds the data, one worked example, and your answers.
//
//  BUILD AND RUN:   g++ -std=c++17 -Wall -o run warmup.cpp && ./run
//            or:    ./run.sh
//
//  Work on ONE question at a time. Write it, run it, check the output
//  against the README, commit it, move on.
// =====================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/**
 * THE RECORD
 * One delivery: who brought it, how much, and what grade it was given.
 */
struct Delivery {
    string farmer;
    double kg;
    char   grade;
};


/**
 * THE DATA
 * Do not change these. Every expected answer in the README comes from exactly this data.
 */

// Q1 — one morning's weights, in the order they were weighed
vector<double> morningWeights = {
    45.5, 80.0, 12.0, -3.0, 66.5, 20.0, 31.0, 95.0, 50.0, 18.5, 0.0, 72.0
};

// Q2, Q3, Q4, Q7, Q8 — the day's logbook
vector<Delivery> logbook = {
    {"Keza",    45.5, 'A'},
    {"Bonu",    80.0, 'B'},
    {"Isanda",  20.0, 'A'},
    {"Keza",    12.0, 'C'},
    {"Onyinye", 66.5, 'B'},
    {"Karimi",  31.0, 'A'},
    {"Karimi",  31.0, 'A'},
    {"Keza",    18.5, 'B'},
    {"Bonu",    50.0, 'C'},
    {"Isanda",  20.0, 'A'},
    {"Onyinye", 72.0, 'A'}
};   // yes, one of these rows is in here twice. Q8 is about that.

// Q5 — records as the volunteers typed them, before any checking. Several of these are wrong. That is the point.
struct RawRecord {
    string id;
    string kg;        // text, because a volunteer can type anything
    char   grade;
};

vector<RawRecord> rawRecords = {
    {"F012", "45.5",  'A'},
    {"F7",   "20",    'A'},
    {"F033", "heavy", 'B'},
    {"F021", "0",     'C'},
    {"F044", "80",    'b'},
    {"F055", "",      'A'},
    {"F066", "31.5",  'D'},
    {"F077", "92",    'B'}
};

// Q6 — an Igisoro board. 16 pits, in sowing order.
//      Position 0 is unused so that board[1] really is pit 1.
vector<int> board = {0, 0, 0, 1, 0, 0, 4, 1, 0, 0, 2, 2, 0, 1, 5, 0, 0};


// ---------------------------------------------------------------------
//  A HELPER YOU MAY FIND USEFUL
// ---------------------------------------------------------------------
void printBoard(const vector<int> &b) {
    for (int i = 1; i <= 16; i++) cout << b[i] << " ";
    cout << "\n";
}


int main() {

    // =================================================================
    //  WORKED EXAMPLE  ·  not a question
    //
    //  This is the house style: walk the data once, keep what you need
    //  as you go, print at the end. Read it before you start Q1.
    //
    //  It answers: how many deliveries were grade A, and what was the
    //  heaviest single delivery in the whole logbook?
    // =================================================================

    int gradeACount = 0;
    Delivery heaviest = logbook[0];        // start from a REAL entry,
                                           // never from a made-up 0
    for (Delivery d : logbook) {
        if (d.grade == 'A') {
            gradeACount++;
        }
        if (d.kg > heaviest.kg) {
            heaviest = d;                  // keep the WHOLE record,
        }                                  // not just the number
    }

    cout << "=== Worked example ===\n";
    cout << "Grade A deliveries: " << gradeACount << "\n";
    cout << "Heaviest: " << heaviest.farmer << " with "
         << heaviest.kg << " kg\n\n";


    // =================================================================
    //  Q1  ·  THE WEIGHING SESSION          (see README)
    //  Uses: morningWeights
    // =================================================================

    cout << "=== Q1 ===\n";    
    
    for (int i = 0; i < int(morningWeights.size()); i++) {
    vector<double> morningWeights = {
    45.5, 80.0, 12.0, -3.0, 66.5, 20.0, 31.0, 95.0, 50.0, 18.5, 0.0, 72.0
    };
    double sum = accumulate(morningWeights.begin(), morningWeights.end(), 0.0);
    cout << "The total is : " << sum << "\n";
}
    int a = 0;
    for (int i = 0; i < int(morningWeights.size()); i+= 1) {
        if (morningWeights[i] > 0 && morningWeights[i] <= 80) {
            a += 1;
        }
    }
    cout << "The number of valid weights is: " << a << " of 12" <<"\n";

    int b = 0;
    int pos = 0;
    for (int i = 0; i < int(morningWeights.size()); i++) {
        if (morningWeights[i] > b ) {
            b = morningWeights[i];
            pos = i;
        }
    }
    cout << "The heaviest weight is: " << b << " kg at position " << pos << "\n";

    
    int longest_valid_run = 0;
    int current_valid_run = 0;

    for (int i = 0; i < morningWeights.size(); i++) {
        if (morningWeights[i] > 0.0 && morningWeights[i] <= 80) {
            current_valid_run++;
            if (current_valid_run > longest_valid_run) {
                longest_valid_run = current_valid_run;
            }
        } else {
            current_valid_run = 0;
        }
    }
    cout << "Longest valid run: " << longest_valid_run << "\n";



    cout << "\n";


    // =================================================================
    //  Q2  ·  GRADE SUMMARY                 (see README)
    //  Uses: logbook
    // =================================================================

    cout << "=== Q2 ===\n";

    struct Delivery {
         string farmer;
         double kg;
         char   grade;
    };

 vector<Delivery> logbook = {
    {"Keza",    45.5, 'A'},
    {"Bonu",    80.0, 'B'},
    {"Isanda",  20.0, 'A'},
    {"Keza",    12.0, 'C'},
    {"Onyinye", 66.5, 'B'},
    {"Karimi",  31.0, 'A'},
    {"Karimi",  31.0, 'A'},
    {"Keza",    18.5, 'B'},
    {"Bonu",    50.0, 'C'},
    {"Isanda",  20.0, 'A'},
    {"Onyinye", 72.0, 'A'}
 };

   double a_total = 0, b_total = 0, c_total = 0;
   int a_count = 0, b_count = 0, c_count = 0;
   for (int i; i <= logbook.size(); i++) {
       if (logbook[i].grade == 'A') {
           a_count += 1;
           a_total += logbook[i].kg;
       } else if (logbook[i].grade == 'B') {
           b_count += 1;
           b_total += logbook[i].kg;
       } else if (logbook[i].grade == 'C') {
           c_count += 1;
           c_total += logbook[i].kg;
     }
    }
    double aa = (a_count > 0) ? (a_total / a_count) : 0;
    double ab = (b_count > 0) ? (b_total / b_count) : 0;
    double ac = (c_count > 0) ? (c_total / c_count) : 0;  
 if (aa > ab && aa > ac) {
       cout << "Best average: grade A"<<"\n";
   } else if (ab > aa && ab > ac) {
       cout << "Best average: grade B"<<"\n";
   } else if (ac > aa && ac > ab) {
       cout << "Best average: grade C"<<"\n";
   }
   
   cout << "Grade A: " << a_count << " deliveries, " << a_total << " kg total, " << aa << " kg average"<<"\n";
   cout << "Grade B: " << b_count << " deliveries, " << b_total << " kg total, " << ab << " kg average"<<"\n";
   cout << "Grade C: " << c_count << " deliveries, " << c_total << " kg total, " << ac << " kg average"<<"\n";
   
    cout << "\n";

    // =================================================================
    //  Q3  ·  WHO IS WHO                    (see README)
    //  Uses: logbook, and the findFarmer function you write below main
    // =================================================================

    cout << "=== Q3 ===\n";


    cout << "\n";


    // =================================================================
    //  Q3  ·  WHO IS WHO                    (see README)
    //  Uses: logbook, and the findFarmer function you write below main
    // =================================================================

    cout << "=== Q3 ===\n";





    cout << "\n";


    // =================================================================
    //  Q4  ·  PAYMENT RUN WITH A DAILY CAP  (see README)
    //  Uses: logbook, and the payment function you write below main
    // =================================================================

    cout << "=== Q4 ===\n";





    cout << "\n";


    // =================================================================
    //  Q5  ·  THE VALIDATION REPORT         (see README)
    //  Uses: rawRecords
    // =================================================================

    cout << "=== Q5 ===\n";





    cout << "\n";

    // =================================================================
    //  Q6  ·  IGISORO: A FULL TURN          (see README)
    //  Uses: board
    // =================================================================

    cout << "=== Q6 ===\n";



    
    // =================================================================
    //  STRETCH  ·  optional
    // =================================================================

    // =================================================================
    //  Q7  ·  SORT THE LOGBOOK              (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q7 ===\n";





    // =================================================================
    //  Q8  ·  SPOTTING DOUBLE-ENTRIES       (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q8 ===\n";





    return 0;
}
   
 // =====================================================================
   //  FUNCTIONS YOU WRITE
//  C++ reads a file top to bottom, so a function must be DECLARED above

   //  the place that calls it. These two are declared here at the bottom,
//  which main() cannot see — so move them ABOVE main(), or leave a
//  one-line declaration up there. Working that out is part of Q3.
// =====================================================================

// Q3:  return the position of the first delivery by this farmer,
//      or -1 if the farmer is not in the log at all.
//
// int findFarmer(const vector<Delivery> &log, string name) {
//
// }


// Q4:  what one delivery earns, before any cap is applied.
//      Grade A pays 10% above the rate, B pays the rate,
//      anything else pays 20% below it. The rate is 450.
//
// double payment(double kg, char grade) {
//
// }
