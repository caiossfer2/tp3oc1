#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/*  6 bits indice 
    2 bits offset bloco
    2 bits offset palavra
    22 bits de tag
*/
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
};

int main(){

/*A memória usa o byte adressing. Por exemplo, o endereço nº 6 se refere ao terceiro byte da segunda palavra da memória.
Tem tanto o offset da palavra no bloco quanto o offset do byte na palavra.
Repare que o offset de bloco no endereço 6 ficaria 01 (segunda palavra?) e o offset na palavra seria 11(terceiro byte da palavra?).
*/

    int a = 7;
    bitset<sizeof(a) *__CHAR_BIT__> bits(a);
    cout << bits.to_string() << endl;


    return 0;
}