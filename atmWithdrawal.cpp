#include<iostream>
#include<vector>
using namespace std;

vector<int> withdraw(vector<int>available,int amount){
    vector<int>usedNotes;
    vector<int>notes;
    notes.push_back(20);
    notes.push_back(50);
    notes.push_back(100);
    notes.push_back(200);
    notes.push_back(500);
    for(int i=0;i<5;i++){
        usedNotes.push_back(0);
    }
    int i=4,found=0;
    for(;i>=0;i--){
        int temp = amount/notes[i];
        if(temp<=available[i]){
            available[i]-=temp;
            amount-=notes[i]*temp;
            usedNotes[i]+=temp;
        }else{
            temp=available[i];
            available[i]-=temp;
            amount-=notes[i]*temp;
            usedNotes[i]+=temp;
        }

        // cout<<amount<<" ";
        if(amount==0){
            found=1;
            break;
        }

    }
    if(found==0){
        for(int i=0;i<6;i++){
            usedNotes[i] = -1;
        }
    }
    return usedNotes;
}

void display(vector<int>usedNotes){
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<usedNotes[i]<<" ";
    }
}

int main(){
    vector<int>available;
    available.push_back(1);
    available.push_back(1);
    available.push_back(0);
    available.push_back(2);
    available.push_back(1);
    int arr[] = {0,0,0,0,0};
    vector<int>usedNotes(arr,arr+5);
    usedNotes = withdraw(available,550);
    display(usedNotes);

    return 0;
}