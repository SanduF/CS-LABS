#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int s1[4][16] = {{14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7},
      {0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8},
      {4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0},
     {15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13}};

int s2[4][16] = {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10}
,{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5}
,{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15}
,{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}};

int s3[4][16] = {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8}
,{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1}
,{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7}
,{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}};

int s4[4][16]= {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15}
,{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9}
,{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4}
,{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}};

int s5[4][16] = {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9}
,{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6}
,{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14}
,{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}};

int s6[4][16] = {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11}
,{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8}
,{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6}
,{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}};

int s7[4][16] = {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1}
,{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6}
,{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2}
,{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}};

int s8[4][16] = {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7}
,{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2}
,{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8}
,{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}};

int p_table[32] = {16,7,20,21
,29,12,28,17
,1,15,23,26
,5,18,31,10
,2,8,24,14
,32,27,3,9
,19,13,30,6
,22,11,4,25};

int ip[64] = { 58,    50,   42,    34,    26,   18,    10,    2,
            60,    52,   44,    36,    28,   20,    12,    4,
            62,    54,   46,    38,    30,   22,    14,    6,
            64,    56,   48,    40,    32,   24,    16,    8,
            57,    49,   41,    33,    25,   17,     9,    1,
            59,    51,   43,    35,    27,   19,    11,    3,
            61,    53,   45,    37,    29,   21,    13,    5,
            63,    55,   47,    39,    31,   23,    15,    7};

int reversed_ip[64] = {40,8,48,16,56,24,64,32
,39,7,47,15,55,23,63,31
,38,6,46,14,54,22,62,30
,37,5,45,13,53,21,61,29
,36,4,44,12,52,20,60,28
,35,3,43,11,51,19,59,27
,34,2,42,10,50,18,58,26
,33,1,41,9,49,17,57,25};

int pc_1[56] = {57,   49,    41,   33,    25,    17,    9,
               1,   58,    50,   42,    34,    26,   18,
              10,    2,    59,   51,    43,    35,   27,
              19,   11,     3,   60,    52,    44,   36,
              63,   55,    47,   39,    31,    23,   15,
               7,   62,    54,   46,    38,    30,   22,
              14,    6,    61,   53,    45,    37,   29,
              21,   13,     5,   28,    20,    12,    4};

int pc_2[48] = {14,    17,   11,    24,     1,    5,
                  3,    28,   15,     6,    21,   10,
                 23,    19,   12,     4,    26,    8,
                 16,     7,   27,    20,    13,    2,
                 41,    52,   31,    37,    47,   55,
                 30,    40,   51,    45,    33,   48,
                 44,    49,   39,    56,    34,   53,
                 46,    42,   50,    36,    29,   32};

int e_table[48] = {32,     1,    2,     3,     4,    5,
                  4,     5,    6,     7,     8,    9,
                  8,     9,   10,    11,    12,   13,
                 12,    13,   14,    15,    16,   17,
                 16,    17,   18,    19,    20,   21,
                 20,    21,   22,    23,    24,   25,
                 24,    25,   26,    27,    28,   29,
                 28,    29,   30,    31,    32,    1};


string e_bit_transformation(string message){
    string message_e = "";
    for(int i = 0; i < 48; i++){
        message_e+=message[e_table[i]-1];
    }
    return message_e;
}

string permutation(string message){
    string permutation_message = "";
    for(int i = 0; i < 48; i++){
        permutation_message+=message[p_table[i]-1];
    }
    return permutation_message;
}

string s_function(int working_table, string bytes1, string bytes2){
    int w_table[4][16];
    string number_binary = "";
    int counter = 8;
    if(working_table == 1){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s1[i][j];
            }
        }
    }else if(working_table == 2){
       for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s2[i][j];
            }
        }
    }else if(working_table == 3){
       for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s3[i][j];
            }
        }
    }else if(working_table == 4){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s4[i][j];
            }
        }
    }else if(working_table == 5){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s5[i][j];
            }
        }
    }else if(working_table == 6){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s6[i][j];
            }
        }
    }else if(working_table == 7){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s7[i][j];
            }
        }
    }else if(working_table == 8){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 16; j++){
                w_table[i][j]=s8[i][j];
            }
        }
    }
    int row_number = (2*stoi(bytes1.substr(0,1)))+(1*stoi(bytes1.substr(1,1)));
    int column_number = (8*stoi(bytes2.substr(0,1)))+(4*stoi(bytes2.substr(1,1)))+(2*stoi(bytes2.substr(2,1)))+(1*stoi(bytes2.substr(3,1)));
    int number = w_table[row_number][column_number];
    for(int i = 0; i < 4; i++){
        if(number - counter >=0){
            number_binary+="1";
            number-=counter;
        }else{
            number_binary+="0";
        }
        counter=round(counter/2);
    }
    return number_binary;
}

string xor_function(string s1, string s2){
 string response = "";
 for(int i = 0; i < 32; i++){
     if(s1[i] == s2[i]){
            response+="0";
        }else{
            response+="1";
        }
 }
 return response;
}

string f_function(string message, string key){
    string f_message = "";
    string message_32_bit = "";
    for(int i = 0; i < 48; i++){
        if(message[i] == key[i]){
            f_message+="0";
        }else{
            f_message+="1";
        }
    }
    for(int i = 0; i < 8; i++){
        string first_message = f_message.substr(i*6,1);
        first_message+=f_message.substr((i*6)+5,1);
        message_32_bit+=s_function(i+1,first_message,f_message.substr((i*6)+1,4));
    }
    message_32_bit = permutation(message_32_bit);
    return message_32_bit;
}

string reverse_message(string message){
    string final_message = "";
    for(int i = 31; i >= 0; i--){
        final_message+=message[i];
    }
    return final_message;
}

string encoding_block(string message, string* round_keys){
    string split_message[2][17];
    split_message[0][0] = message.substr(0,32);
    split_message[1][0] = message.substr(32);
    for(int i = 1; i < 17; i++){
        split_message[0][i] = split_message[1][i-1];
        split_message[1][i] = xor_function(split_message[0][i-1],f_function(e_bit_transformation(split_message[1][i-1]),round_keys[i-1]));
    }

    cout << "L16: " + split_message[0][16] + " , R16: " + split_message[1][16] << endl;

    // return reverse_message(split_message[0][16])+reverse_message(split_message[1][16]);
    return split_message[1][16]+split_message[0][16];
}
string* split_and_permutation(string message_56_bit){
    string* final_rounds = new string[16];
    string** rounds = new string*[2];
    rounds[0] = new string[17];
    rounds[1] = new string[17];
    rounds[0][0] = message_56_bit.substr(0,28);
    rounds[1][0] = message_56_bit.substr(28);
    cout << "C0: " + rounds[0][0] + " , D0: " + rounds[1][0] << endl;
    for(int i = 1; i < 17; i++){
        if(((i >=3) && (i <=8)) || ((i >=10) && (i <=15))){
            rounds[0][i] = rounds[0][i-1].substr(2)+rounds[0][i-1].substr(0,2);
            rounds[1][i] = rounds[1][i-1].substr(2)+rounds[1][i-1].substr(0,2);
        }else{
            rounds[0][i] = rounds[0][i-1].substr(1)+rounds[0][i-1].substr(0,1);
            rounds[1][i] = rounds[1][i-1].substr(1)+rounds[1][i-1].substr(0,1);
        }
        cout << "C" << i << ": " + rounds[0][i] + " , D" << i << ": " + rounds[1][i] << endl;
        final_rounds[i-1] =rounds[0][i] + rounds[1][i];
    }

    return final_rounds;
}

string final_permutation(string message){
 string f_message = "";
    for(int i = 0; i < 64; i++){
        f_message+=message[reversed_ip[i]-1];
    }
    cout << "The message with final permutation: " + f_message << endl;
    return f_message;
}

string permutation_string(string binary_message){
    string permutated_message = "";
    for(int i = 0; i < 64; i++){
        permutated_message+=binary_message[ip[i]-1];
    }
    return permutated_message;
}

string permutation_64_to_56_bits(string message_64_bit){
    string message_56_bit = "";
    for(int i = 0; i < 56; i++){
        message_56_bit+=message_64_bit[pc_1[i]-1];
    }
    cout << "The 56 bit key is: " + message_56_bit << endl;
    return message_56_bit;
}

string permutation_56_to_48_bits(string message_56_bit){
    string message_48_bit = "";
    for(int i = 0; i < 48; i++){
        message_48_bit+=message_56_bit[pc_2[i]-1];
    }
    return message_48_bit;
}

string* r_keys(string* c_d_keys){
    string* round_keys;
    round_keys = new string[16];
    for(int i = 0; i < 16; i++){
        round_keys[i] = permutation_56_to_48_bits(c_d_keys[i]);
        cout << "K" << i+1 << ": " + round_keys[i] << endl;
    }
    return round_keys;
}

string HexToBin(string hexdec)
{
    size_t i = (hexdec[1] == 'x' || hexdec[1] == 'X')? 2 : 0;
    string binary_message = "";
    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            binary_message+="0000";
            break;
        case '1':
            binary_message+="0001";
            break;
        case '2':
            binary_message+="0010";
            break;
        case '3':
            binary_message+="0011";
            break;
        case '4':
            binary_message+="0100";
            break;
        case '5':
            binary_message+="0101";
            break;
        case '6':
            binary_message+="0110";
            break;
        case '7':
            binary_message+="0111";
            break;
        case '8':
            binary_message+="1000";
            break;
        case '9':
            binary_message+="1001";
            break;
        case 'A':
        case 'a':
            binary_message+="1010";
            break;
        case 'B':
        case 'b':
            binary_message+="1011";
            break;
        case 'C':
        case 'c':
            binary_message+="1100";
            break;
        case 'D':
        case 'd':
            binary_message+="1101";
            break;
        case 'E':
        case 'e':
            binary_message+="1110";
            break;
        case 'F':
        case 'f':
            binary_message+="1111";
            break;
        }
        i++;
    }
    cout << "The binary of the hex string " + hexdec + " is: " + binary_message << endl;
    return binary_message;
}

string BinToHex(string message){
    string hex_message = "";
    for(int i = 0; i < 16; i++){
        string temp_str = message.substr(i*4,4);
        if(temp_str == "0000")
            hex_message+="0";
        else if(temp_str == "0001")
            hex_message+="1";
        else if(temp_str == "0010")
            hex_message+="2";
        else if(temp_str == "0011")
            hex_message+="3";
        else if(temp_str == "0100")
            hex_message+="4";
        else if(temp_str == "0101")
            hex_message+="5";
        else if(temp_str == "0110")
            hex_message+="6";
        else if(temp_str == "0111")
            hex_message+="7";
        else if(temp_str == "1000")
            hex_message+="8";
        else if(temp_str == "1001")
            hex_message+="9";
        else if(temp_str == "1010")
            hex_message+="A";
        else if(temp_str == "1011")
            hex_message+="B";
        else if(temp_str == "1100")
            hex_message+="C";
        else if(temp_str == "1101")
            hex_message+="D";
        else if(temp_str == "1110")
            hex_message+="E";
        else if(temp_str == "1111")
            hex_message+="F";
        }
        cout << "The encoded message is: " + hex_message << endl;
    return hex_message;
    }




int main()
{
  string key, k, k_plus, message, permutated_message,rounded_message,reversed_message,f_permutation;
  string* keys_c_d;
  string* round_keys;
  cout << "Type in the message: ";
  cin >> message;
  cout << "Type in the key: ";
  cin >> key;
  k = HexToBin(key);
  k_plus = permutation_64_to_56_bits(k);
  keys_c_d = split_and_permutation(k_plus);
  round_keys = r_keys(keys_c_d);
  permutated_message = permutation_string(HexToBin(message));
  rounded_message = encoding_block(permutated_message, round_keys);
  f_permutation = final_permutation(rounded_message);
  message=BinToHex(f_permutation);
}