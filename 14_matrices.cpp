
#include <iostream>
#include <cctype>
using namespace std;
class Matrix{
    private:
        int *A,n;
    public:
        Matrix(int n);
        void Create();
        int get(int i,int j);
        void set(int i);
        void Display();
        ~Matrix();
};
Matrix :: Matrix (int n){
    this->n=n;
    A=new int[n*(n-1)/2]; //Lower Tringular Matrix
}
Matrix:: ~Matrix(){
    delete []A;
}
void Matrix :: Create(){
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
            if(i > j){
                A[i*i-1/2+j-1]=x;
            }

        }
    }
}
void Matrix :: Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << A[i*i-1/2+j-1] <<" "<< endl;

        }
    }
} 
int Matrix :: get(int i ,int j){
             return A[i*i-1/2+j-1];
}
void Matrix :: set(int x){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             A[i*i-1/2+j-1]=x;

        }
    }
    
}
int main(){
    Matrix a(3);
    a.Create();
    a.set(32);
    a.get(2,3);
    a.Display();
    return 0;
}