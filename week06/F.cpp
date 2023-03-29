#include <iostream>
using namespace std;

enum Response
{
    Continue              = 100,
    OK                    = 200,
    Created               = 201,
    Accepted              = 202,
    Bad_Request           = 400,
    Unauthorized          = 401,
    Not_Found             = 404,
    Method_Not_Allowed    = 405,
    Internal_Server_Error = 500,
    Not_Implemented       = 501,
    Bad_Gateway           = 502
};

void print(int response) {
    if (response == Response::Continue) {
        cout << "Continue" << endl;
    } else if (response == Response::OK) {
        cout << "OK" << endl;
    } else if (response == Response::Created) {
        cout << "Created" << endl;
    } else if (response == Response::Accepted) {
        cout << "Accepted" << endl;
    } else if (response == Response::Bad_Request) {
        cout << "Bad Request" << endl;
    } else if (response == Response::Unauthorized) {
        cout << "Unauthorized" << endl;
    } else if (response == Response::Not_Found) {
        cout << "Not Found" << endl;
    } else if (response == Response::Method_Not_Allowed) {
        cout << "Method Not Allowed" << endl;
    } else if (response == Response::Internal_Server_Error) {
        cout << "Internal Server Error" << endl;
    } else if (response == Response::Not_Implemented) {
        cout << "Not Implemented" << endl;
    } else if (response == Response::Bad_Gateway) {
        cout << "Bad Gateway" << endl;
    }
}

int main() {
    int response;
    cin >> response;
    while (response != 0) {
        print(response);
        cin >> response;
    }
    return 0;
}