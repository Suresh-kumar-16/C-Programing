CRC
#include<stdio.h>                         // Include headers
#include<string.h>
#define N strlen(gen_poly)          // length of the generator polynomial
Char data[28];                             // data to be transmitted and received
Char check_value[28];                             // CRC value
Char gen_poly[10];                                 // generator polynomial
Intdata_length,I,j;                                    // variables 

Void XOR()                                             // function that performs XOR operation
{                      
    For(j = 1;j < N; j++)                                                                   // if both bits are the same, the output is 0
    Check_value[j] = (( check_value[j] == gen_poly[j])?’0’:’1’);
                                                                                                        // if the bits are different the output is 1
}
Void receiver()                                                    // Function to check for errors on the receiver side
{
Printf(“Enter the received data: “);                     // get the received data
Scanf(“%s”, data);
Printf(“\n-----------------------------\n”);
Printf(“Data received: %s”, data);
Crc();         // Cyclic Redundancy Check
    For(i=0;(i<N-1) && (check_value[i]!=’1’);i++);           // Check if the remainder is zero to find the error
    If(i<N-1)
    Printf(“\nError detected\n\n”);
        Else
    Printf(“\nNo error detected\n\n”);
}

Void crc(){
    For(i=0;i<N;i++)                                      // initializing check_value
Check_value[i]=data[i];
    Do{
        If(check_value[0]==’1’)                      // check if the first bit is 1 and calls XOR function
        XOR();
        For(j=0;j<N-1;j++)                               // Move the bits by 1 position for the next computation
        Check_value[j]=check_value[j+1];
        Check_value[j]=data[i++];                   // appending a bit from data
    }while(i<=data_length+N-1);
}                                                                    // loop until the data ends
Int main()
{
Printf(“\nEnter data to be transmitted: “);              // get the data to be transmitted
Scanf(“%s”,data);
Printf(“\n Enter the Generating polynomial: “);
Scanf(“%s”,gen_poly);                                                // get the generator polynomial
Data_length=strlen(data);	                                // find the length of data
   For(i=data_length;i<data_length+N-1;i++)             // appending n-1 zeros to the data
   Data[i]=’0’;
Printf(“\n----------------------------------------“);
Printf(“\n Data padded with n-1 zeros : %s”,data);     // print the data with padded zeros
Printf(“\n----------------------------------------“);
Crc();                                                                                    // Cyclic Redundancy Check
Printf(“\nCRC or Check value is : %s”,check_value);	 // print the computed check value
    For(i=data_length;i<data_length+N-1;i++)	           // Append data with check_value(CRC)
        Data[i]=check_value[i-data_length];
Printf(“\n----------------------------------------“);
Printf(“\n Final data to be sent : %s”,data);                        // printing the final data to be sent
Printf(“\n----------------------------------------\n”);
    Receiver();                                                                     // Calling the receiver function to check errors
    Return 0;
}
