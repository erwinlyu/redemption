#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string romanInt;
        while(num > 0){
            if(num >= 1000){
                for(int i = 0; i < num / 1000; i++){
                    romanInt += "M";
                }
                num = num % 1000;
            }
            else if(num >= 900){
                romanInt += "CM";
                num -= 900;
            }
            else if(num >= 500){
                for(int i = 0; i < num / 500; i++){
                    romanInt += "D";
                }
                num = num % 500;
            }
            else if(num >= 400){
                romanInt += "CD";
                num -= 400;
            }
            else if(num >= 100){
                for(int i = 0; i < num / 100; i++){
                    romanInt += "C";
                }
                num = num % 100;
            }
            else if(num >= 90){
                romanInt += "XC";
                num -= 90;
            }
            else if(num >= 50){
                for(int i = 0; i < num / 50; i++){
                    romanInt += "L";
                }
                num = num % 50;
            }
            else if(num >= 40){
                romanInt += "XL";
                num -= 40;
            }
            else if(num >= 10){
                for(int i = 0; i < num / 10; i++){
                    romanInt += "X";
                }
                num = num % 10;
            }
            else if(num >= 9){
                romanInt += "IX";
                num -= 9;
            }
            else if(num >= 5){
                for(int i = 0; i < num / 5; i++){
                    romanInt += "V";
                }
                num = num % 5;
            }
            else if(num >= 4){
                romanInt += "IV";
                num -= 4;
            }
            else{
                for(int i = 0; i < num; i++){
                    romanInt += "I";
                }
                num = 0;
            }
        }
        return romanInt;
    }
};
int main(){}