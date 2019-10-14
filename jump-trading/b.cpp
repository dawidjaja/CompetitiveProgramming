// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int Y, string &A, string &B, string &W) {
    // write your code in C++14 (g++ 6.2.0)
    int months[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0) {
        months[1] = 29;
    }
    int d = 0;
    int m = 0;
    int day = 0;
    if (W == "Monday") {
        day = 0;
    } else if (W == "Tuesday") {
        day = 1;
    } else if (W == "Wednesday") {
        day = 2;
    } else if (W == "Thursday") {
        day = 3;
    } else if (W == "Friday") {
        day = 4;
    } else if (W == "Saturday") {
        day = 5;
    } else if (W == "Sunday") {
        day = 6;
    }

    int s_mon, e_mon;
    if (A == "January") {
        s_mon = 0;
    } else if (A == "February") {
        s_mon = 1;
    } else if (A == "March") {
        s_mon = 2;
    } else if (A == "April") {
        s_mon = 3;
    } else if (A == "May") {
        s_mon = 4;
    } else if (A == "June") {
        s_mon = 5;
    } else if (A == "July") {
        s_mon = 6;
    } else if (A == "August") {
        s_mon = 7;
    } else if (A == "September") {
        s_mon = 8;
    } else if (A == "October") {
        s_mon = 9;
    } else if (A == "November") {
        s_mon = 10;
    } else if (A == "December") {
        s_mon = 11;
    } 

    if (B == "January") {
        e_mon = 0;
    } else if (B == "February") {
        e_mon = 1;
    } else if (B == "March") {
        e_mon = 2;
    } else if (B == "April") {
        e_mon = 3;
    } else if (B == "May") {
        e_mon = 4;
    } else if (B == "June") {
        e_mon = 5;
    } else if (B == "July") {
        e_mon = 6;
    } else if (B == "August") {
        e_mon = 7;
    } else if (B == "September") {
        e_mon = 8;
    } else if (B == "October") {
        e_mon = 9;
    } else if (B == "November") {
        e_mon = 10;
    } else if (B == "December") {
        e_mon = 11;
    } 

    while (day != 0) {
        day++;
        day = day % 7;
        d++;
    }

    while (m != s_mon) {
        d += 7;
        if (d >= months[m]) {
            d = d % months[m++];
        }
    }

    int week = 0;
    d += 6;

    while (m <= e_mon) {
        week++;
        d += 7;
        if (d >= months[m]) {
            d = d % months[m++];
        }
    }
    return week;
}

