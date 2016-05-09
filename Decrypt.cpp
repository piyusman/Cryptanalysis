/* @author Piyush */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <list>
#include <fstream>


using namespace std;

int keylength;
int flag=0;
int flag2=0;
string cipher;
string ciphertext;
int dictionary_len;
string dictionary1;
int used_key[100];
char repeat ='y';
int main()
{
	string line;
	string ciphertext;
	string duplicate;
	int i=0;
	int l=0;
	int s=0;
	int k =0;
	int j;
	i=0;
	cout<<"Enter the ciphertext to decrypt: ";
	getline(cin, cipher);
	cout<<"Enter the keylength: ";
	cin>>keylength;
	
	//cout<<"Searching in dictionary 1...";
	ifstream myfile("Dictionary1.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{	
		dictionary1 = dictionary1 + line;   //copying the contents of the given DICTIONARY1.txt to dictionary1 variable
		duplicate =  duplicate + line;
	
		}
		myfile.close();
	}
	
	/*for (i=19400;i<19500;i++)
	{
		if(s==23)
		{
			s=0;
		}
		if(dictionary[i]==' ')
		{
			dictionary[i]=dictionary[i]+64;
		}
		
			ciphertext[l]=dictionary[i]+s;
		if(ciphertext[l]>122)
	{
		ciphertext[l]=ciphertext[l]-27;
		if(ciphertext[l]==96)
		{
			ciphertext[l]=ciphertext[l]-64;
		}
	}
		cout<<ciphertext[l];
		l++;
		s++;
	}*/
//	string check = "tclovojphtuctclovojphtucswoops swoops tclqvmjphvuatclqvmjphvuafkjfpvucwfbvicpnkqhbtjdpojoictjdpojoictjdpojoictjdpojoictjdpojoictjdpojoictjdpojoictjdpojoic";
//	string check = "courtship swoops memphis attentional pintsized rustics hermeneutics dismissive delimiting proposes between postilion repress racecourse";

	//cout<<check;
	string check = "viduals orders and so on enables unscrupulous characters to run roughshod over your business the cha";
	
	
	while(i<200)					//Starts searching in Dictionary1
	{
		
		for(j=0;j<100;j++)
		{
			
			used_key[j] = cipher[j]-dictionary1[k];
			if (used_key[j]<-27)
			{
				used_key[j]=used_key[j]+91;
			    k++;
			}
			else if(used_key[j]<0 && used_key[j]>-27)
			{
				used_key[j]=used_key[j]+27;
				
			k++;
			}
			else if(used_key[j]>27)
			{
				used_key[j]=used_key[j]-64;
				
			k++;
			}
			else
			{
			        k++;	
			}
		
		}
		std::list<int> keys(used_key,used_key+100);
		keys.sort();
	 	keys.unique();
		//cout<<keys.size();
	
		if(keys.size()<=keylength)
		{
		flag=1;
		//cout<<"\nKey Used is";										//keys used in dictionary 1 to crack
		//for (std::list<int>::iterator it=keys.begin(); it!=keys.end(); ++it)			
    	//std::cout << ' ' << *it;
  		//std::cout << '\n';
		break;
		}
		
		i++;
		
	}
	
	/*
for(j=0;j<100;j++)
{
	cout<<used_key[j]<<" ";
	}*/	


	
	/*while(i<keys.size())
	{
		cout<<keys;
	}*/
	
	if(flag==1)
	{
		cout<<"Plaintext is: ";		//plaintext in dictionary 1 found :)
	
		for(i=k-100;i<=k-1;i++)
		{
			cout<<duplicate[i];
		}
		
	}
	
	
										//Code for searching plaintext in Dictionary2
	
	else
	{
		                             
		int keyset[10000];
		int keycheck[20000];
		std::string dictionary2[20000];
		int cal[10000];
		int count=0;
		int x=0;
		int size =0;
		int run=0;
		i=0;
		
//		cout<<"\nText didn't match in dictionary one\n"<<"\nSearching in Dictionary 2..."<<"\n";
		
		string line1;
	    ifstream myfile2("Dictionary2.txt");
	    
		if(myfile2.is_open())
		{		
			while(getline(myfile2,line))
			{	
				//cout<<"\n"<<cal[count];
				ifstream myfile2copy("Dictionary2.txt");
		
				if(myfile2copy.is_open())
				{
		
				while(getline(myfile2copy,line1))
				{
					dictionary2[x] = line + ' ' + line1 + ' ';   //making combination of two words possible from the DICTIONARY2
					cal[count]=dictionary2[x].size();
					//cout<<cal[count];
					x++;
					count++; 	
				}
				myfile2copy.close();
				}		
	
			}	
			myfile2.close();
		}
			
	                                      //Started Searching in Dictionary2
		while(i<10000)
		{
			run=0;
			//triple=triplicate[i];	
			
			for(j=size;j<size+cal[i];j++)
			{
				
		
				//used_key2[i][j] = check[j] - triplicate[i][j];
				keycheck[run]=cipher[j]-dictionary2[i][run];
				//cout<<"\ncipher"<<check[j]<<" - and  "<<j;
				
				if (keycheck[run]<-27)
				{
					//used_key2[i][j]=used_key2[i][j]+91;
					keycheck[run]=keycheck[run]+91;
			    	run++;
				}
				else if(keycheck[run]<0 && keycheck[j]>-27)
				{
					//used_key2[i][j]=used_key2[i][j]+27;
					keycheck[run]=keycheck[run]+27;
					run++;
		
				}
				else if(keycheck[run]>27)
				{
					//used_key2[i][j]=used_key2[i][j]-64;
					keycheck[run]=keycheck[run]-64;
					run++;
				}
				else
				{
					run++;
			        continue;
				}
			
			}
			
			
			for(j=0;j<cal[i];j++)
			{
				keyset[j]=keycheck[j];				//copying the keys used to crack
				//cout<<"sub"<<sub[j];
			}
		
			std::list<int> keys(keyset,keyset+30);
			keys.sort();
	
	 		keys.unique();							//taking the unique keys
	 
			//cout<<"\n key size"<<keys.size();
	
	 		//cout<<keys.size();
	 		//	cout<<"    key length: "<<keylength;
	 			if(keys.size()<=keylength+1)
	 			{
				 		flag2=1;
	 					flag=1;						//to confirm we found one part of plaintext :)
	 					k=i;
					/*cout<<" "<<keys.size();
						for(j=0;j<cal[i];j++)
						{	
						//sub[j]=keycheck[j];
						cout<<" sub "<<sub[j];
						cout<<"\n  triplicate  "<<triplicate[i][j];
						}
						for(j=size;j<size+cal[i];j++)
						{
							cout<<check[j];
						}*/
						 
	 			}
	 			
				 for(j=0;j<30;j++)
	 			{
	 				
	 				keyset[j]='\0';
			 	}
	 				
				i++;
				
				if(flag==1)
				{	if(size==0)
					{
					cout<<"Plaintext is:\n";
					}
					cout<<dictionary2[k]<<" ";							//Printing the part of plaintext 
					size = size +dictionary2[k].size();     			//To shift the ciphertext window for the next set of all possible combination dictionary2
				//	cout<<size;
					i=0;
					flag=0;
					run=0;
						/*cout<<"\nKey Used is\n";
						for (std::list<int>::iterator ita=keys.begin(); ita!=keys.end(); ++ita)
    					std::cout << ' ' << *ita;
  						std::cout << '\n';*/
					if(size>100)
					{
						break;
					}
				}
				else
				{
				continue;
				}
		
		}		//end of while loop 


	}			//end of 'else' part which is seraching for dictionary 2 after the failure of dictionary1
}
