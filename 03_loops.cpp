#include<iostream>
#include<string>
using namespace std;

int main(){
   int teaCups;
//    cout << "Enter the no of cups u want tp order:" ;
//    cin >> teaCups ;
//    while(teaCups){
//     cout << "Serving tea" << endl << "Remaining Cups :" << teaCups << endl;
//     teaCups -= 1;
//    }

   string response;
//    do{
//     cout << "Do you want ro study(yes/no):" <<  endl ;
//     getline(cin , response);
//    }while(response != "no" || response != "No");

    // for (int i = 1; i <= teaCups ; i++ ){
    //         cout << "Making " << i << " cup of tea ......." << endl;
    // }

    // while(true){
    //     cout << " Do u want more cup of tea (type for no 'stop')" ;
    //     getline(cin , response);
    //     if(response == "stop"){
    //         break;
    //     }
    //     cout << " Here is your cup of tea !!!!" << endl ;
    // }
    //         cout << " Thank You !! Your bill is This. ";


    string teaType[5] = {"Black Tea","Milk Tea","Orange Tea","Ollang Tea","Apple Tea"};

    // for (int i = 0 ;i < 5 ;i++){
    //     if( teaType[i] == "Orange Tea"){
    //         cout << "Skipped the type " << teaType[i] << endl;
    //         continue;
    //     }
    //     cout << "Brewing ... "<< teaType[i] <<endl;
    // }




    
    for (int i = 0 ;i < 5 ;i++){
        cout << "Brewing ... "<< teaType[i] <<endl;
        for(int j =1; j <4;j++){
            cout << "Breawing " << j <<"cup of "<< teaType[i] <<"......."<<endl ;
        }
    }












    return 0;

}