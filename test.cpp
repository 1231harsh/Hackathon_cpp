#include<ctime>
#include<iostream>
#include<ctime>
#include<sstream>
using namespace std;

time_t parseDateTime(const char* datetimeString, const char* format)
{
    struct tm tmStruct;
    strptime(datetimeString, format, &tmStruct);
    return mktime(&tmStruct);
}

int main()
{
    time_t t1 = time(0)+1*24*60*60;
    time_t t2 = time(0);
    // int d = difftime(t1, t2)/(24*60*60);
    // cout << "Total time required = "
    //      << d << " days " << endl;;
    char * d = ctime(&t2);
    // cout<<d<<endl;
    char * format = "%a %b %d %H:%M:%S %Y";
    time_t pt = parseDateTime(d,format);
    cout<<pt<<endl;
    return 0;
}