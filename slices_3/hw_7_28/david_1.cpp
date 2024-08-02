#include<iostream>
#include<vector>
using namespace std;

//slice3 7补全
pair<double,double> getMinAndMax(const vector<double>&n){
    double min=n[0];
    double max=n[0];
    for(int i=0;i<n.size();++i){
     if(n[i]>=n[0]){
        max=n[i];
     }
     else if(n[i]<n[0]){
        min=n[i];
     }
    }
    cout<<"min:"<<min<<"max:"<<max;
    return pair<double,double>(min,max);
}

int main(){
    //{1,2,3,4}
    vector<double> n;
    n.push_back(1);
    n.push_back(2);
    n.push_back(3);
    n.push_back(4);
    getMinAndMax(n);
    


}