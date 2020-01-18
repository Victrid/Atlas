#include <iostream>
using namespace std;

void output(int***,int,int,int);

int main(){
    int totalMatricesCount;
    cin >> totalMatricesCount;
    int ***totalMatricesPointer=new int**[totalMatricesCount];
    int *MatrixFloorPointer=new int[totalMatricesCount];
    int *MatrixRotatePointer=new int[totalMatricesCount];
    for(int Matrixnum=0;Matrixnum<totalMatricesCount;Matrixnum++){
        cin >> *(MatrixFloorPointer+Matrixnum);
        cin >> *(MatrixRotatePointer+Matrixnum);
        *(totalMatricesPointer+Matrixnum)=new int *[*(MatrixFloorPointer+Matrixnum)];
        for(int row=0;row<*(MatrixFloorPointer+Matrixnum);row++)
            *(*(totalMatricesPointer+Matrixnum)+row)=new int [*(MatrixFloorPointer+Matrixnum)];
        for(int row=0;row<*(MatrixFloorPointer+Matrixnum);row++)
        for(int column=0;column<*(MatrixFloorPointer+Matrixnum);column++)
            cin >>*(*(*(totalMatricesPointer+Matrixnum)+row)+column);
    }
    for(int Matrixnum=0;Matrixnum<totalMatricesCount;Matrixnum++){
        output(totalMatricesPointer+Matrixnum,*(MatrixFloorPointer+Matrixnum),*(MatrixRotatePointer+Matrixnum),Matrixnum);
    }
    return 0;
}
void output(int*** totalMatricesPointer,int floor,int rotate,int NOT_FIRST_MATIRX_FLAG){
    if(NOT_FIRST_MATIRX_FLAG)cout << endl;
    bool NOT_FIRST_ROW_FLAG=false;
    bool NOT_FIRST_COLUMN_FLAG=false;
    for(int row=0;row<floor;row++){
        if(NOT_FIRST_ROW_FLAG)cout << endl;
        NOT_FIRST_ROW_FLAG = true;
        for(int column=0;column<floor;column++){
            if(NOT_FIRST_COLUMN_FLAG)cout << ' ';
            NOT_FIRST_COLUMN_FLAG = true;
            if(rotate==2)cout << *(*(*(totalMatricesPointer)+column)+row);
            if(rotate==1)cout << *(*(*(totalMatricesPointer)+(floor-row-1))+column);
            if(rotate==0)cout << *(*(*(totalMatricesPointer)+row)+(floor-column-1));
        }
            NOT_FIRST_COLUMN_FLAG = false;
    }
    return;
}