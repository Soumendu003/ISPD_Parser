#include"Benchmark_Parser.h"

int main(int argc, char** argv){
    if(argc == 1 || (Strcmpi(argv[1], "-help") == 0) || (Strcmpi(argv[1], "-h") ==0))
    {
        cout<<"Syntax to run:"<<endl;
        cout<<"./exe [-blocks filename] [-nets filename] [-benchmark bechmarkname]"<<endl;
        exit(0);
    }
    int blockfile_index = 0, netfile_index = 0, benchname_index = 0;
    for(int i =1 ; i < argc ; i ++){
        if(Strcmpi(argv[i], "-blocks") == 0){
            i += 1;
            blockfile_index = i;
        }
        else if(Strcmpi(argv[i], "-nets") == 0){
            i += 1;
            netfile_index = i;
        }
        else if(Strcmpi(argv[i], "-benchmark") == 0){
            i += 1;
            benchname_index = i;
        }
        else
        {
            cout<<"Syntax to run:"<<endl;
            cout<<"./exe [-blocks filename] [-nets filename] [-benchmark bechmarkname]"<<endl;
            exit(0);     
        }
        
    }
    try{
        Benchmark_Parser BP(argv[benchname_index], argv[blockfile_index], argv[netfile_index]);
        BP.Generate_Block_File();
        BP.Generate_Net_File();
    }
    catch(exception e){
        cout<<e.what()<<endl;
    }
    
    return 0;

}


/*int main(){
    char benchfile[FILE_SIZE];
    char wtsfile[FILE_SIZE];
    char netfile[FILE_SIZE];
    strncpy(benchfile, "IBM17D_L3_C11-33", FILE_SIZE);
    strncpy(wtsfile, "IBM17D_L3_C11-33.wts", FILE_SIZE);
    strncpy(netfile, "IBM17D_L3_C11-33.nets", FILE_SIZE);
    try{
        Benchmark_Parser BP(benchfile, wtsfile, netfile);
        BP.Generate_Block_File();
        BP.Generate_Net_File();
    }
    catch(exception e){
        cout<<e.what()<<endl;
    }
    
    return 0;
}*/