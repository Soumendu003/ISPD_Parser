#include "Benchmark_Parser.h"

Benchmark_Parser::Benchmark_Parser(char* bench_file, char* wts_file, char* net_file){
    strcpy(this->bench_file, bench_file);
    strcpy(this->net_file, net_file);
    strcpy(this->wts_file, wts_file);
}


void Benchmark_Parser::Generate_Block_File(){
    cout<<"Generate_Block_File() called "<<endl;
    char delimeters[20];
    strncpy(delimeters, "{},\t ()\n\r:",20);
    Tokenizer Tok(wts_file, delimeters, '\n');
    cout<<"Tokenizer created "<<endl;
    char* tok = Tok.get_token();
    cout<<"tok = "<<string(tok)<<endl;
    uint8_t state = 0;
    uint16_t nodes;
    uint16_t terminals;
    while (tok != 0)
    {
        //cout<<"Tok = "<<tok<<endl;
        if(strcmp(tok,"NumNodes") == 0)
        {
            nodes = atoi(Tok.get_token());
            state = 1;
            cout<<"State = "<<state<<endl;
        }
        else if(strcmp(tok,"NumTerminals") == 0)
        {
            terminals = atoi(Tok.get_token());
            state = 1;
        }
        else if(state == 1 && tok[0] == 'a'){
            uint16_t id = atoi(tok+1);
            node tem;
            tem.id = id;
            tem.area = atoi(Tok.get_token());
            N.push_back(tem);
        }
        tok = Tok.get_token();
    }
    cout<<"Size of N = "<<N.size()<<endl;
    ofstream ofs;
    string outfile = string(bench_file)+".blocks";
    string write_string;
    ofs.open(outfile, ofstream::out);
    //write_string = to_string(nodes-terminals)+"\n"+to_string(terminals)+"\n";
    //ofs.write(write_string.c_str(), strlen(write_string.c_str()));

    for(uint16_t i = 0; i < N.size(); i++){
        write_string = string("bk"+to_string(N[i].id)+"\tsoftrectangular\t"+to_string(N[i].area)+"\n");
        ofs.write(write_string.c_str(), strlen(write_string.c_str()));
    }
    ofs.close(); 
}

void Benchmark_Parser::Generate_Net_File(){
    char delimeters[20];
    strncpy(delimeters, "{},\t ()\n\r:",20);
    Tokenizer Tok(net_file, delimeters, '\n');
    char* tok = Tok.get_token();
    uint8_t state = 0;
    uint16_t count = 0;
    ofstream ofs;
    string outfile = string(bench_file)+".n";
    string write_string;
    ofs.open(outfile, ofstream::out);
    while (tok != 0)
    {
        if(strcmp(tok, "NumPins") == 0){
            //write_string = string(Tok.get_token())+"\n00\n";
            //ofs.write(write_string.c_str(), strlen(write_string.c_str()));
            state = 1;
        }
        else if(strcmp(tok, "NetDegree") == 0){
            write_string = "NetDegree\t:\t"+string(Tok.get_token())+"\n";
            ofs.write(write_string.c_str(), strlen(write_string.c_str()));
            count += 1;
            //cout<<"count = "<<count<<endl;   
        }
        else if(state == 1 && tok[0] == 'a')
        {
            write_string = "bk"+string(tok+1)+"\n";
            ofs.write(write_string.c_str(), strlen(write_string.c_str()));
        }
        else if(state == 1 && tok[0] == 'p')
        {
            write_string = string(tok)+"\n";
            ofs.write(write_string.c_str(), strlen(write_string.c_str()));
        }
        
        tok = Tok.get_token();
    }
    cout<<"Total net = "<<count<<endl;
    ofs.close();
}