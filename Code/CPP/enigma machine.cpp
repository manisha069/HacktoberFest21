#include <iostream>
using namespace std;


string encryption(int leng_str,int tot_mot_val,string giv_string,char arr1[26],char arr2[26]){
    string ret_str;
    int j;
    int val_chang;
    for (int i=0;i<leng_str;i++) {
        int value=giv_string[i];
        val_chang=value+tot_mot_val;
        while(val_chang>122){
            val_chang=val_chang-26;
        }
        char res_value=val_chang;
        for(j=0;j<26;j++){
            if (res_value==arr2[j]){
                break;
            }
        }
        char act_value;
        if(value==32){
            act_value=value;
        }
        else{
            act_value=arr1[j];
        }
        ret_str=ret_str+act_value;
        tot_mot_val=tot_mot_val+1;
    }
    return ret_str;
}

string decryption(int leng_str,string giv_string,int tot_mot_val,char arr1[26],char arr2[26]){
    string ret_str;
    char fin_val;
    int k,l,m,valiable,count=0;
    for(l=0;l<leng_str;l++){
        for(m=0;m<26;m++){
            valiable=giv_string[l];
            if(arr1[m]==giv_string[l]){
                break;
            }    
        }
        char act_value=arr2[m];
        int ch_value=act_value;
        ch_value=ch_value-tot_mot_val;
        while(ch_value<97){
            ch_value=ch_value+26;
        }
        if(giv_string[l]==32){
            ch_value=32;           
        }
        fin_val=ch_value;
        ret_str=ret_str+fin_val;
        // ret_str=ret_str+act_value;
        tot_mot_val=tot_mot_val+1;
        
        
    }
    cout<<endl;
    return ret_str;
}

int main(){
    char simple[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
     char mixed[26]={'n','s','d','m','b','o','e','r','c','t','p','k','z','l','q','u','f','v','a','w','j','g','x','i','h','y'};
    int chang_value;
    string input_string="hello hello";
    int str_leng=input_string.length();

    int motor1=25;
    int motor2=01;
    int motor3=21;

    int to_inc=motor1+motor2+motor3;
    
    string encryp_string,decryp_string;
    encryp_string=encryption(str_leng,to_inc,input_string,mixed,simple);    
    cout<<encryp_string;
    decryp_string=decryption(str_leng,encryp_string,to_inc,mixed,simple);
    cout<<decryp_string;
    return 0;
}