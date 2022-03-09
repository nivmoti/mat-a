#ifndef MATALA_MAT_HPP
#define MATALA_MAT_HPP
#include "mat.hpp"
#include <iostream>
#include <vector>

#include <string>
using  namespace std;

namespace ariel{
    string mat(int col, int row, char a,char b ){
        char main=a;
        vector<vector<char>> matrix (row,vector<char>(col));
        string ans;
        if  (((col*row)%2==0)||(col<0)||(row<0)||(a=='\0')||(b=='\0')) {throw std::out_of_range("Mat size is always odd");}
        for (int count = 0; count <min(col,row)/2+1; count++)
        {
            if(count%2==0){
                main=a;
            }
            else{
                main=b;
            }
            for (int i = count; i < row-count; i++)
            {
                matrix[i][count]=main;
                matrix[i][col-1-count]=main;
            }
            for (int i = count; i < col-count; i++)
            {
                matrix[count][i]=main;
                matrix[row-1-count][i]=main;
            }
            
        }
        if((col==1)&&(row>1)){
            matrix[row/2][0]=b;
        }
        if((row==1)&&(col>1)){
            matrix[0][col/2]=b;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans+=matrix[i][j];
            }
            ans+='\n';
            
        }
        return ans;
        
        
    }
       
}

#endif //MATALA_MAT_HP