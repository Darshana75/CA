#include <iostream>
#include <chrono>
#include <ctime>
#include<windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iterator>

using namespace std;
int square(int x){
    return x*x;
}



int main (){

    string cmd = "GETMAC /s localhost ";
    string filename = "mac_name.txt";
  
    system((cmd + ">" + filename).c_str());
    string line;
    ifstream myfile ("mac_name.txt");
    
    if(myfile.is_open()){
        while(getline(myfile,line)){
        cout<<line<<endl;
        }
        myfile.close();
    }
    else{
    cout<<"Unable to open the file";
    }
            
    for (int i = 1; i <= 20; i++){

        ofstream file("text.txt",  std::ios_base::app);

        cout<<"Count is " << i <<'\n';
        file<<"count is "<< i << endl;
        int num,squ;
        cout<<"Enter a number find to square ";
        cin>>num;
        file<< "input number is "<< num << endl;
        squ = square(num);
        cout<<"Square of " <<num << " is " << squ <<'\n';
        file<<"Square of " <<num << " is " << squ <<'\n';

        auto system_Time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        cout << "System time is " << ctime(&system_Time) << endl;
        file << "System time is " << ctime(&system_Time) << endl;
        file.close();

    }

    ofstream file("text.txt",  std::ios_base::app);

    auto system_Time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "Cuurent system time is " << ctime(&system_Time) << endl;
    file <<"Cuurent system time is " << ctime(&system_Time) << endl;

    

    return 0;
}