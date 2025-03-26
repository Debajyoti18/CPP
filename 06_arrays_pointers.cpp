#include <iostream>

using namespace std;


int totalCostumers(int humans[],int n){
        int totalHumans = 0;
        for(int i =0 ;i< n;i++){
            totalHumans += i;
        }
        return totalHumans;
}
    int* countCustomer(int cust){
                
        int* customers = new int[cust];//holds memory of the arrays in dynamic-memory
            for(int i =0 ; i < cust ; i++){
                customers[i] = (i+1)*10;//if cust is 4 then it create array of size 4 with memory in contgeous as like
                // 10,20,30,40
            }
            return customers;//store the refernce of the first element of the array
        }

int main(){

      int chaiCustomers[9] = {12,12,11,23,12,11};
      int totalCutomers = totalCostumers(chaiCustomers,9);
      cout << totalCostumers ;

      int customer = 5;
      int* noOfCusts = countCustomer(customer);
      for(int i = 0 ; i< customer ;i++){
        cout << "Customers:" << noOfCusts[i] << endl;
      }
        delete[] noOfCusts;





    return 0;
}