#include<iostream>
#include<vector>
using namespace std;

void transposearrVector(vector<vector<int>> &brr, vector<vector<int>> &crr) {
    int row = brr.size();
    int col = brr[0].size();
    crr.assign(col, vector<int>(row));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            crr[j][i] = brr[i][j];
        }
    }
}

void transposearr(int brr[][4],int row,int col,int crr[][3]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            // swap(brr[i][j],brr[j][i]);
            crr[j][i]=brr[i][j];
        }
    }
}

void printarray(int crr[][3],int row,int col){
    cout<<"printing transpose matrix"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<crr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void maxInt(int brr[3][3],int row,int col){
    int max=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(brr[i][j]>max){
               max=brr[i][j];     
            }
        }
    }
    cout<<"printing maximum number"<<" - "<<max<<endl;

}

void minInt(int brr[3][3],int row,int col){
    int min=brr[0][0];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(brr[i][j]< min){
               min=brr[i][j];     
            }
        }
    }
    cout<<"printing maximum number"<<" - "<<min<<endl;

}

bool ispresent(int brr[3][3],int target,int row,int col){
    for(int row=0;row<3;row++){
        for( int col=0;col<3;col++){
            if(brr[row][col]==target){
                return 1;
            }
        }
    }
    return 0;
}

void printsumCOL(int brr[3][3], int row,int col){
   cout<<"printing sum"<<endl;
   for(int row=0;row<3;row++){
    int sum=0;
        for(int col=0;col<3;col++){
            sum += brr[row][col];
        }
        cout<< sum <<" ";
    } 
    cout<<endl;
}

void printsumROW(int brr[3][3], int row,int col){
   cout<<"printing sum"<<endl;
   for(int col=0;col<3;col++){
    int sum=0;
        for(int row=0;row<3;row++){
            sum += brr[row][col];
        }
        cout<< sum <<" ";
    } 
    cout<<endl;
}

int main()
{

    //CREATE 2D ARRRAY ROW WISE
    // int arr[3][4];
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cin>>arr[i][j];
    //     }
    // }

    //PRINT 2D ARRAY ROW WISE
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }

    //CREATE 2D ARRRAY COL WISE
    // int brr[3][3],n;
    // for(int col=0;col<3;col++){
    //     for(int row=0;row<3;row++){
    //         cin>>brr[row][col];
    //     }
    // }

    // //PRINT 2D ARRAY COL WISE
    // for(int col=0;col<3;col++){
    //     for(int row=0;row<3;row++){
    //         cout<<brr[col][row]<<" ";
    //     }cout<<endl;
    // }
    // cout<<"enter the element to found"<<endl;
    // cin>>n;

    // if(ispresent(brr , n , 3 , 3)){
    //     cout<<"FOUND"<<endl;
    //     }
    // else{
    //     cout<<"NOT FOUND"<<endl;
    // }    

    //CREATE 2D ARRRAY COLUMN WISE
    // int brr[3][4],crr[4][3];
    // for(int row=0;row<3;row++){
    //     for(int col=0;col<4;col++){
    //         cin>>brr[row][col];
    //     }
    // }
    
    // //PRINT 2D ARRAY COLUMN WISE
    // for(int row=0;row<3;row++){
    //     for(int col=0;col<4;col++){
    //         cout<<brr[row][col]<<" ";
    //     }cout<<endl;
    // }

    //FINDING SUM COLUMN WISE
    // printsumROW(brr,3,3);
    // printsumCOL(brr,3,3);

    //FINDING MAX AND MIN FROM THE 2D ARRAY
    // maxInt(brr,3,3);
    // minInt(brr,3,3);

    //FINDING TRANSPOSE OF A MATRIX
    // transposearr(brr,3,4,crr);
    // printarray(crr,4,3);
  
    // int row=5;
    // int col=10;
    // vector<vector<int> > arr(row, vector<int>(col,1));
    // vector<int> a{1,2,3};
    // vector<int> b{4,5,6};
    // vector<int> c{7,8,9};
    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);
    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<arr[0].size();j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    
    return 0;
}