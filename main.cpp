#include "Blockchain.h"
#include "Block.h"
#include "TransactionData.h"
#include "Miner.h"
using namespace std;

double getTotalVolume(Blockchain &chain){
    double amount = 0;
    for(auto const &to : chain.chain){
        amount += to.getTransactionData().amount;
    }
    return amount;
}
void new_thread1(Blockchain *blockchain, TransactionData data, Miner miner){
    bool ans = miner.miner(*blockchain, data);
    if(ans)
    blockchain->addBlock(data);
    else cout<<"No data has been added"<<endl;
}
void new_thread2(Blockchain *blockchain, TransactionData data, Miner miner){
    bool ans = miner.miner2(*blockchain, data);
    if(ans) blockchain->addBlock(data);
    else cout<<"No data has been added"<<endl;

}
int main(){
    Blockchain *blockchain = new Blockchain();

    blockchain->addBlock(*new TransactionData(100, "Manat", "Yerassyl", time(0)));
    blockchain->addBlock(*new TransactionData(50, "Abdu", "Yerassyl", time(0)));
    blockchain->addBlock(*new TransactionData(150, "Yerassyl", "Andrey", time(0)));

    blockchain->printBlockchain();

    TransactionData data = *new TransactionData(1000, "Eren", "Mikasa", time(0));
    TransactionData data1 = *new TransactionData(500, "Zoro", "Batman", time(0));

    Miner miner;

    thread th1(new_thread1, blockchain, data, miner);
    th1.join();
    thread th2(new_thread2, blockchain, data1, miner);
    th2.join();

    blockchain->printBlockchain();

    cout << (blockchain->isBlockchainValid() ? "Valid" : "Invalid");
}
