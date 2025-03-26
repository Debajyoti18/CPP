#include <iostream>
#include <vector>
using namespace std;

class Chai{
    // If No Access-Modifiers then Private is bydefault so no access to datamebers
    public:
        //date members or attributes
        string teaName;
        int servings;
        vector<string> ingredients;

        //Member functions
        void displayChaiDetails(){
            cout << "Tea Names :" <<teaName <<endl <<"Name of Serving:"<< 
            servings << endl;
            for(string x : ingredients){
                cout << x << " " ;
            }
            cout << endl;
        }
    private:
        string name;
};
int main(){

        Chai blackChai ;
        blackChai.teaName = "Black-Tea";
        blackChai.servings = 3;
        blackChai.ingredients = {"water" , "Tea" ," Ginger" ,"Lemon" ,"Honey" };
        blackChai.displayChaiDetails();

        




    return 0;
}