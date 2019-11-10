#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

string DNA_to_mRNA (string strand);
string dictionary_read (ifstream &dict, string codon);
string mRNA_to_protein(string s);
string splice(string s);



int main()
{
	string evenDNAstrand;
	string oddDNAstrand;
	string mrna_strand;
	ifstream fin("frameshift_mutations.txt");
	if (fin.fail())
	{
		cerr<< "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	
	while(getline(fin, evenDNAstrand))
	{
		getline(fin, oddDNAstrand);
		cout<<mRNA_to_protein(evenDNAstrand)<<endl;
		cout<<mRNA_to_protein(oddDNAstrand)<<endl;
		
	}
	fin.close();
}
string mRNA_to_protein(string s)
{
	string codon="";
	string acid_seq;
	string mrna_strand;
	bool z = false;
	mrna_strand= DNA_to_mRNA(s);
	ifstream acids("codons.tsv");
	
	for (int i=0; i <mrna_strand.length(); i++)
	{
		codon = mrna_strand.substr(i,3);//if codon.length()%3==0
		if (codon == "AUG")
		{
			z = true;
			acid_seq = dictionary_read(acids, codon);
			i=i+2;
		}
		else if ((codon== "UAA" || codon== "UGA" || codon == "UAG") && (acid_seq != ""))
		{
			z=false; 
			return acid_seq;
		}
		else if (z)
		{
			if (dictionary_read(acids, codon)=="")
			{
				acid_seq = acid_seq;
			}
			else
			{
				acid_seq = acid_seq + "-" + dictionary_read(acids, codon);
			}
			i=i+2;
		}
	}
	return acid_seq;
	acids.close();
	
}
string DNA_to_mRNA(string DNAstrand)
{
	string strand = DNAstrand;
	for (int i= 0; i < strand.length(); i++)
	{
		if (strand[i]== 'C' || strand[i]== 'c')
		{
			strand.replace(i, 1, "G");
		}
		else if (strand[i]== 'G' || strand[i]== 'g')
		{
			strand.replace(i, 1, "C");
		}
		else if (strand[i]== 'A' || strand[i]== 'a')
		{
			strand.replace(i, 1, "U");
		}
		else if (strand[i]== 'T' || strand[i]== 't')
		{
			strand.replace(i, 1, "A");
		}
	}
	return strand;
}

string dictionary_read(ifstream &dict, string s)
{
	string codon, amino, acid;
	dict.clear();
	dict.seekg(0);
	while (dict>>codon>>amino)
	{
		if (codon == s)
		{
			acid = amino;
		}
	}
	return acid;
}
