#ifndef IO_HPP
#define IO_HPP

#define MIN_PARAM_NB 4
#define OPTIONS "i:s:k:g:f:t:q:c:m:X:n:d:r"
#define BUILD_COMMAND "Build"
#define SEARCH_COMMAND "Search"
#define RUNTIME_FLAG_DEFAULT false
#define PREPROS_FLAG_DEFAULT -1
#define GFA_FILE_ENDING ".gfa"
#define COLOR_FILE_ENDING ".bfg_colors"
#define INDEX_FILE_ENDING ".idx"
#define SEARCH_STRAND_DEFAULT Both
#define PLUS_STRAND '+'
#define MINUS_STRAND '-'

//All variations of strands we may perform a search
enum SrchStrd {Plus, Minus, Both};

#include "Search.h"

//This function reads in a file in which colors are stored the search will be based on
const list<pair<string, size_t>> loadSearchColors(const char* filename, uint32_t& nbCols);

//This function parses the program parameters. Returns false if given arguments are not valid
const bool parseArgs(int& nb_args, char** argList, int16_t& prepros, string& filePref, int32_t& s, int32_t& k, int32_t& g, vector<string>& seqs, int32_t& t, string& qFile, string& c, uint32_t& m, SrchStrd& strd, bool& r, int16_t &X, uint16_t &nRes);

//This function prints usage infos
inline void dispHelp(){
	cerr << "PLAST [COMMAND] [COMMAND_PARAMETERS]" << endl << endl;//TODO: Change program name!
	cerr << "[COMMAND]:" << endl << endl;
	cerr << "   Build    Build index (and graph)" << endl;
	cerr << "   Search   Search inside an indexed graph" << endl << endl;
	cerr << "[COMMAND_PARAMETERS]: Build" << endl << endl;
	cerr << "   >Mandatory with required argument:" << endl << endl;
	cerr << "   -i   --graph-prefix   File prefix of a graph which already exists or has to be built" << endl << endl;
	cerr << "   >Optional with required argument:" << endl << endl;
	cerr << "   -s   --seed-length   Minimal seed length an index is built for (default is 11)" << endl;
	cerr << "   -k   --kmer-length   Length of k-mers in a newly built graph (default is 31)" << endl;
	cerr << "   -g   --min-length    Length of minimizers in a newly built graph (default is 23)" << endl;
	cerr << "   -f   --fasta         Names of input sequence file(s) (FASTA/FASTQ) to build a new graph from (sequences from a file will share a color in the graph)" << endl;
	cerr << "   -t   --threads       Number of threads to be used for graph construction (default is 1)" << endl << endl;
	cerr << "[COMMAND_PARAMETERS]: Search" << endl << endl;
	cerr << "   >Mandatory with required argument:" << endl << endl;
	cerr << "   -q   --query          Query sequence file (1 query per line)" << endl;
	cerr << "   -i   --graph-prefix   Graph, color and index file prefix" << endl << endl;
	cerr << "   >Optional with required argument:" << endl << endl;
	cerr << "   -s   --seed-length    Minimal seed length (default is 11)" << endl;
	cerr << "   -c   --colors         Search color set file with one color name per line to consider during the search (default is all colors)" << endl;
	cerr << "   -m   --quorum         Quorum" << endl;
	cerr << "   -X   --X-dropoff      X-dropoff value" << endl;
	cerr << "   -n   --max-results    Maximum number of alignments to be outputted (default is " << DEFAULT_NB_RES << ")" << endl;
	cerr << "   -d   --strand         DNA strands to consider during search. Can be '+','-' (default is both)" << endl << endl;
	cerr << "   >Optional without argument:" << endl << endl;
	cerr << "   -r   --runtimes   Runtime measurement flag" << endl;
}

//This function loads query sequences from a file and stores it in a list
void loadQueries(const string &filename, vector<string> &qList);

#endif