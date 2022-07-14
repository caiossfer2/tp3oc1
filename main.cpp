#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Palavra{
    // 32 bits
    public:
        vector<int> p;

    Palavra(){
        //inicializando 32 bits com 0s
        p.resize(32);
        fill(p.begin(), p.end(), 0);
    }


};

class Bloco{
    // 4 palavras de 32 bits
    public:

};

class MemoriaDados{
    // 1024 palavras de 32 bits
    public:
};

class Cache{
    //64 blocos. cada bloco com 4 palavras de 32 bits
    public:
};

int main(){



    return 0;
}