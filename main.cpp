#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;


class Palavra{
    // 32 bits
    public:
        string p;
    Palavra(){
        p = "vazio"
    }
};

class Bloco{
    // 4 palavras de 32 bits
    public:
        vector<Palavra> b;
        Bloco(){
            b.resize(4);
        }

};


class Cache{
    //64 blocos. cada bloco com 4 palavras de 32 bits
    public:
        vector<Bloco> c;
        Cache(){
            c.resize(64);
        }
};

class MemoriaDados{
    // 1024 palavras de 32 bits
    public:
    void escreveMemoriaDados(){ //para o write back

    }
};

int main(){

/*  22 bits de tag
    6 bits indice 
    2 bits offset bloco
    2 bits offset palavra
*/

/*  A memória usa o byte adressing. Por exemplo, o endereço nº 6 se refere ao terceiro byte da segunda palavra da memória.
    Tem tanto o offset da palavra no bloco quanto o offset do byte na palavra.
    Repare que o offset de bloco no endereço 6 ficaria 01 (segunda palavra?) e o offset na palavra seria 10 (terceiro byte da palavra?).
*/

    Cache cache;
    int N = 0, tipoOperacao, numeroBloco = 0;
    string dado;
    Palavra palavra;
    while(cin){
        cin >> N;
        cin >> tipoOperacao;
            if(tipoOperacao == 1){ //escrita
                cin >> dado;
                palavra.p = dado;
                bitset<sizeof(N) *__CHAR_BIT__> bitsN(N);
                bitset<sizeof(6) *__CHAR_BIT__> bitsIndice;
                for(int i = 4; i <= 10; i++){
                    bitsIndice[i - 4] = bitsN[i];
                }
                numeroBloco = bitsIndice.to_ulong();
            }else{//leitura
                
            }
    }    


    return 0;
}