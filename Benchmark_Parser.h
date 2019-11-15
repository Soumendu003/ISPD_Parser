#ifndef BENCHMARK_PARSER_H
#define BENCHMARK_PARSER_H
#include <map>
#include<vector>
#include <stdlib.h>
#include<fstream>
#include"Tokenizer.h"
#include"Header.h"

#define FILE_SIZE 32

using namespace std;

struct node{
    uint16_t id;
    uint32_t area;
};

class Benchmark_Parser{
    private:
        vector<node> N;
        char bench_file[FILE_SIZE];
        char wts_file[FILE_SIZE];
        char net_file[FILE_SIZE];
    public:
        Benchmark_Parser(char* bench_file, char* wts_file, char* net_file);
        void Generate_Block_File();
        void Generate_Net_File();

};


#endif