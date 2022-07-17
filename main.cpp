#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <math.h>
/*Não entenda o código, sinta o código :D o.o */
using namespace std;
/*  22 bits de tag
    6 bits indice 
    2 bits offset bloco
    2 bits offset palavra
*/

/*  A memória usa o byte adressing. Por exemplo, o endereço nº 6 se refere ao terceiro byte da segunda palavra da memória.
    Tem tanto o offset da palavra no bloco quanto o offset do byte na palavra.
    Repare que o offset de bloco no endereço 6 ficaria 01 (segunda palavra?) e o offset na palavra seria 10 (terceiro byte da palavra?).
*/

class Palavra{
    // 32 bits
    public:
        string p;
    Palavra(){
        p = "vazio";
    }
};

class Bloco{
    // 4 palavras de 32 bits
    public:
        vector<Palavra> b;
        bool sujo = false;
        bool valido = false;
        int tag;
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
    void escreve(Bloco bloco){ //para o write back
        cout << "escrita na memoria de dados bloco " << endl;
    }
};



int main(int argc, char **argv){
    string nomeEntrada = argv[1]; 

    Cache cache;
    MemoriaDados memoriaDados;

    int N = 0, tipoOperacao, numeroBloco = 0, numeroPalavra, numeroTag;
    int numMiss = 0; 
    int numHit = 0;
    int missRate, hitRate;
    int numOperacoes = 0;
    int numReads = 0;
    int numWrites = 0;
    int teste = 0;
   
    string dado;
    Palavra palavra;
    while(cin>>N){
        bitset<sizeof(N) *__CHAR_BIT__> bitsN(N); //endereço
        bitset<sizeof(6) *__CHAR_BIT__> bitsIndice;
        for(int i = 4; i <= 9; i++){
             bitsIndice[i - 4] = bitsN[i];
        }
        numeroBloco = bitsIndice.to_ulong();
        bitset<sizeof(2) *__CHAR_BIT__> bitsOffsetBloco;
        bitsOffsetBloco[0] = bitsN[2];
        bitsOffsetBloco[1] = bitsN[3];
        numeroPalavra = bitsOffsetBloco.to_ulong();
        bitset<sizeof(22) *__CHAR_BIT__> bitsTag;
        for(int i = 10; i <= 31; i++){
             bitsTag[i - 10] = bitsN[i];
        }
        numeroTag = bitsTag.to_ulong();

        cin >> tipoOperacao;

        if(cache.c[numeroBloco].valido && cache.c[numeroBloco].sujo && 
           cache.c[numeroBloco].tag != numeroTag){ //substituição de bloco
            memoriaDados.escreve(cache.c[numeroBloco]); //atualiza memoria de dados com os dados do bloco
            //substitui bloco na cache
            cache.c[numeroBloco].sujo = false;
            cache.c[numeroBloco].tag = numeroTag;
        }

        if(tipoOperacao == 1){ //escrita
            numWrites++;
            cin >> dado;
            palavra.p = dado;
            if(!cache.c[numeroBloco].valido){ 
                cout << "miss de escrita" << endl;
                cache.c[numeroBloco].valido = true;           
                cache.c[numeroBloco].tag = numeroTag;
            }
            cache.c[numeroBloco].b[numeroPalavra].p = dado;
            cache.c[numeroBloco].sujo = true;           
        }else{  //leitura
            numReads++;
            if(!cache.c[numeroBloco].valido){//deu miss
                numMiss++;
                cout<<"o endereço "<<N<<" deu miss"<<endl;
                cache.c[numeroBloco].valido = true; //traz bloco
                cache.c[numeroBloco].tag = numeroTag;
            }else{ //deu o hit
                numHit++;
                cout<<"o endereço "<<N<<" deu hit"<<endl;
            }


        }
    }

    float missRate2, hitRate2;
    string nomeSaida = nomeEntrada.erase(nomeEntrada.length() - 4, 4);
    nomeSaida += "-out.txt";
    ofstream saida(nomeSaida);
    saida << "READS: " << numReads << "\n";
    saida << "WRITES: "<< numWrites << "\n";
    saida << "HITS: "<< numHit << "\n";
    saida <<"MISSES: "<< numMiss << "\n";
    missRate2 = (float)numMiss/numReads;
    hitRate2 = 1 - missRate2 ;
    saida <<"HIT RATE:"<< hitRate2 << "\n";
    saida <<"MISS RATE:"<< missRate2 << "\n";

    saida.close();
    return 0;
}