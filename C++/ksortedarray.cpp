#include <iostream>
#include<queue>
using namespace std;

class Info{
  public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c) {
      this->data = a;
      this->rowIndex = b;
      this->colIndex = c;
    }
    ~Info(){
        cout<<this->data<<" "<<this->rowIndex<<" "<<this->colIndex<<" is deleted"<<endl;
    }
};

class compare{
  public:
    bool operator()(Info* a, Info* b) {
      return a->data > b->data;
    } 
};

void mergeKSortedArrays(int arr[][4], int n, int k , vector<int> &ans) {

    priority_queue<Info*, vector<Info*>, compare> pq;

    //1 step : process firsk k elements
    for(int row =0; row<k; row++) {
      int element = arr[row][0];
      Info* temp = new Info(element, row,0);
      pq.push(temp);
    }
    while(!pq.empty()) {
      Info* temp = pq.top();
      pq.pop();
      int topData = temp->data;
      int topRow = temp->rowIndex;
      int topCol = temp->colIndex;

      //store in ans vector
      ans.push_back(topData);

      //next element for the same row, jisme se pop kia h just abhi
      //use insert bhi toh karna hai
      if(topCol + 1 < n) {
        //iska matlab row me or element abhi present hai
        Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1);
        pq.push(newInfo);
       
      }
       delete temp;
    }
}

int main() {
  int arr[3][4] = {
                {1,4,8,11},
                {2,3,6,10},
                {5,7,12,14}
  };
  int n = 4;
  int k = 3;

  vector<int> ans;
  mergeKSortedArrays(arr, n, k , ans);

  cout << "printing Ans array: " << endl;
  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
