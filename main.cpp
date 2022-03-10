#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct tweet_struct
{
    int ID;
    string msg;
    string author;
    unsigned long int timestamp;
    float lng;
    float lat;
};
void display_tweet_by_value(tweet_struct twt);
void display_tweet_by_reference(const tweet_struct &twt);
void display_tweet_by_pointer(const tweet_struct *twt);
void display_tweet_array_notation(const tweet_struct arr[], int size);
void display_tweet_pointer_notation(const tweet_struct *arr, int size);
int main() {
    tweet_struct tweet1;
    tweet1.ID = 1;
    tweet1.msg = "Just setting up my twtr";
    tweet1.author= "Jack";
    tweet1.timestamp = (unsigned long int)12356789L;
    tweet1.lng = 25.69896;
    tweet1.lat = 26.3336;
    display_tweet_by_reference(tweet1);
    display_tweet_by_pointer(&tweet1);
    tweet_struct *twt1 = new tweet_struct;
    twt1->ID=2;
    twt1->msg="twtr all set up";
    twt1->author="jack";
    twt1->timestamp=12358974;
    twt1->lat=25.669;
    twt1->lat = 26.3336;
    display_tweet_by_pointer(twt1);
    display_tweet_by_reference(*twt1);
    display_tweet_by_value(*twt1);

    tweet_struct tweet_arr[3];
    tweet_arr[0].ID=3;
    tweet_arr[0].msg="tweet 3";
    tweet_arr[0].author="Jill";
    tweet_arr[0].timestamp=123456789;
    tweet_arr[0].lng=35.333;
    tweet_arr[0].lat=39.6687;
    tweet_arr[1].ID=4;
    tweet_arr[1].msg="tweet 4 ";
    tweet_arr[1].author="June";
    tweet_arr[1].timestamp=126543219;
    tweet_arr[1].lng=38.333;
    tweet_arr[1].lat=39.6689;
    tweet_arr[2].ID=5;
    tweet_arr[2].msg="tweet 5 ";
    tweet_arr[2].author="Delboy8080";
    tweet_arr[2].timestamp=126543288;
    tweet_arr[2].lng=38.333;
    tweet_arr[2].lat=39.6689;
    display_tweet_array_notation(tweet_arr, 3);
    display_tweet_pointer_notation(tweet_arr, 3);

    int size = 3;
    tweet_struct *arr_start = new tweet_struct[3];
    for(int i = 0; i < size;i++)
    {
        arr_start[i] = tweet_arr[i];
        arr_start[i].msg += " - pointer";
    }
    display_tweet_array_notation(arr_start, size);
    display_tweet_pointer_notation(arr_start, size);
    delete [] arr_start;
    arr_start = nullptr;
    return 0;
}
void display_tweet_by_value(tweet_struct twt)
{
    string header(40, '=');
    string::size_type size = 40 - twt.author.length();
    cout << header << endl;
    cout << twt.ID <<endl;
    cout << twt.msg <<endl;
    cout << twt.author <<setw(size)<<twt.timestamp<<endl;
    cout << "Location: (" << twt.lat <<", " << twt.lng<<")"<<endl;
    cout << header << endl;
}

void display_tweet_by_reference(const tweet_struct &twt)
{
    string header(40, '=');
    string::size_type size = 40 - twt.author.length();
    cout << header << endl;
    cout << twt.ID <<endl;
    cout << twt.msg <<endl;
    cout << twt.author <<setw(size)<<twt.timestamp<<endl;
    cout << "Location: (" << twt.lat <<", " << twt.lng<<")"<<endl;
    cout << header << endl;
}

void display_tweet_by_pointer(const tweet_struct *twt)
{
    string header(40, '=');
    string::size_type size = 40 - twt->author.length();
    cout << header << endl;
    cout << twt->ID <<endl;
    cout << twt->msg <<endl;
    cout << twt->author <<setw(size)<<twt->timestamp<<endl;
    cout << "Location: (" << twt->lat <<", " << twt->lng<<")"<<endl;
    cout << header << endl;
}

void display_tweet_array_notation(const tweet_struct arr[], int size)
{
    cout << "Array Notation: " <<endl;
    for(int i = 0; i <size;i++)
    {
        display_tweet_by_reference(arr[i]);
    }
}
void display_tweet_pointer_notation(const tweet_struct *arr, int size)
{
    cout << "Pointer Notation: " <<endl;
    for(int i = 1; i <=size;i++)
    {
        display_tweet_by_pointer(arr);
        arr++;
    }
}