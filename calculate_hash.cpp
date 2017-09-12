/*
Cybersecurity Principles.
Author: Bhagyashree Borate
Problem Statement: C++ Program to implement MD5, SHA256, SHA-1 and RIPEMD-160 hash function.
Input: A File and Runtime user input ( a text )
Output: Respective hash of the input.

*/

#include <openssl/sha.h>  	// header file to include SHA declarations
#include <openssl/md5.h>  	// header file to include MD5 declarations
#include <openssl/ripemd.h>	// header file to include RIPEMD declarations
#include <stdio.h>  		// header file to include standard input output i.e. printf, putchar
#include <fstream>		// header file to include 
#include <iostream>		// header file to include input output streams i.e. cout, cin
#include <string.h>		// header file to include string declarations


typedef unsigned char byte;  	// Declaration to make the byte as unsigned char

using namespace std;		// to not to use std:: all the time


int main( ) {
    
    /** MD5 Variable Declarations **/
    
    byte MD5digest[MD5_DIGEST_LENGTH];			//32 char * 8 byte characters
    MD5_CTX md5ctx; 					//Formatted Struct or context
    MD5_Init(&md5ctx); 					//Creates a Blank Struct or hash context
    
    /** SHA256 Variable Declarations **/
    byte SHA256digest[SHA256_DIGEST_LENGTH];		// length of the SHA256 digest
    SHA256_CTX sha256ctx;				//Formatted Struct or context
    SHA256_Init(&sha256ctx);				//Creates a Blank Struct or hash context
 
    /** SHA1 Variable Declrations **/    
    byte SHA1digest[SHA_DIGEST_LENGTH];			// length of the SHA1 digest
    SHA_CTX sha1ctx;					//Formatted Struct or context
    SHA1_Init(&sha1ctx);				//Creates a Blank Struct or hash context

    /** SHA1 Variable Declrations **/    
    byte RIPEMD160digest[RIPEMD160_DIGEST_LENGTH];	// length of the RIPEMD160 digest
    RIPEMD160_CTX ripemd160ctx;				//Formatted Struct or context
    RIPEMD160_Init(&ripemd160ctx);			//Creates a Blank Struct or hash context



    /** Program Variable Declarations **/
    string filename = "";				// variable declaration for filename
    byte data;						// variable declaration for runtime input
    
    cout << "/** COURSE: CSCI 5800 (Graduate)"<< endl <<"Program by NAME: BHAGYASHREE BORATE"<< endl<<"Student ID: 107536335    **/" << endl;
    cout<<endl<<"HASH FOR FILE";
    cout << endl << "Please enter Full Filename: ";
    cin >> filename;						
    fstream file(filename, ios::in | ios::binary);	//read in bytes not text, so binary
    
    /** MD5, SHA256, SHA1, RIPEMD-160 of a Binary or Text File **/
    if (!file)
    {
        cout << "Sorry, the file dosent exist or file name is not correct" << endl;
    }
    else
    {
        while (file.read((char *)&data, sizeof(data)))
        {
	    // Add chunks of data both structures. UPDATE : update the new hash context strictly with bytestring,	
            MD5_Update(&md5ctx, &data, sizeof(data));		//MD5
	    SHA256_Update(&sha256ctx, &data, sizeof(data));	//SHA256
	    SHA1_Update(&sha1ctx, &data, sizeof(data));		//SHA1
	    RIPEMD160_Update(&ripemd160ctx, &data, sizeof(data)); //RIPEMD-160
        }
        
        //Finalizes the input and places it in digest
        MD5_Final(MD5digest, &md5ctx);
	SHA256_Final(SHA256digest, &sha256ctx);
	SHA1_Final(SHA1digest, &sha1ctx);
	RIPEMD160_Final(RIPEMD160digest, &ripemd160ctx);        
	
	cout << "The MD5 hash digest for " << filename << " is:";
        for (int i = 0; i<MD5_DIGEST_LENGTH; i++)
            printf("%02x", MD5digest[i]);
        //Far less complicated than formatting with cout
        cout << endl << endl;

	cout << "The SHA256 hash digest for "<<filename << " is:";
	for (int i=0; i<SHA256_DIGEST_LENGTH; i++)
	    printf("%02x", SHA256digest[i]);
	cout << endl << endl;
	
	cout << "The SHA1 hash digest for "<<filename << " is:";
	for (int i=0; i<SHA_DIGEST_LENGTH; i++)
	    printf("%02x", SHA1digest[i]);
	cout << endl << endl;

	cout << "The RIPEMD-160 hash digest for "<<filename << " is:";
	for (int i=0; i<RIPEMD160_DIGEST_LENGTH; i++)
	    printf("%02x", RIPEMD160digest[i]);
	cout << endl << endl;


    } 
    
    /** MD5 and SHA256 of runtime input i.e. Text **/
    cout<<endl<<"/** HASH FOR TEXT **/"<<endl;
    char buffer[256];
    cout << "Enter Text: ";
    cin.ignore();						//
    cin.getline(buffer, 256);
    
    //Use when you have in memory the entire data
    MD5((byte*) &buffer, strlen( (char*)buffer ), (byte *)&MD5digest); 
    SHA256((byte*) &buffer, strlen( (char*)buffer ), (byte *)&SHA256digest);
    SHA1((byte*) &buffer, strlen((char*) buffer), (byte *)&SHA1digest);
    RIPEMD160((byte*) &buffer, strlen((char*) buffer), (byte *)&RIPEMD160digest);
    
    //digest is not a string, so must be printed one char at a time 
    cout << "The MD5 hash digest for " << buffer << " is: ";
    for (int i = 0; i<MD5_DIGEST_LENGTH; i++)
        printf("%02x", MD5digest[i]); 
    cout << endl<<endl; 

    //SHA256	
    cout << "The SHA256 hash digest for " << buffer << " is: ";
    for (int i = 0; i<SHA256_DIGEST_LENGTH; i++)
        printf("%02x", SHA256digest[i]); 

    cout<<endl<<endl;

    //SHA1
    cout << "The SHA1 hash digest for " << buffer << " is: ";
    for (int i = 0; i<SHA_DIGEST_LENGTH; i++)
        printf("%02x", SHA1digest[i]); 

    cout<<endl<<endl;

    //SHA1
    cout << "The SHA1 hash digest for " << buffer << " is: ";
    for (int i = 0; i<RIPEMD160_DIGEST_LENGTH; i++)
        printf("%02x", RIPEMD160digest[i]); 

    cout<<endl<<endl;
    
    return 0; 
    
} 

