@startuml
set separator :::
class "Block<T>" as BlockChainLibrary:::Block_T{
- const unsigned int timestamp
- const T objData
- const unsigned int nonce
- const size_t previousHash
- const size_t hash
+ Block(timestamp, objData, nonce, previousHash, hash)
+ ostream& operator<<(ostream& os, const Block<T>& block)
}

class "BlockChain<T>" as BlockChainLibrary:::BlockChain_T{
- list<Block<T>> blocks
- Block<T> createGenesisBlock()
# const size_t& nBits
# size_t hashFunction(timestamp, nonce, objData, previousHash)
+ BlockChain(const size_t& nBits)
+ bool addBlock(const Block<T>& block)
+ ostream& operator<<(ostream& os, const BlockChain<T>& blockChain)
}

Block_T ..> BlockChain_T : friendship

package Test <<Rectangle>>
{
class "HonestMiner<T>" as HonestMiner_T{
+ HonestMiner(const BlockChain<T>& blockChain)
+ Block<T> mining(const T& objData)
}

class "DishonestMiner<T>" as DishonestMiner_T{
+ DishonestMiner(const BlockChain<T>& blockChain)
+ Block<T> mining(const T& objData, const size_t& previousHash)
}

}
Block_T <.. HonestMiner_T : instantiate
Block_T <.. DishonestMiner_T : instantiate

BlockChain_T <|-down- HonestMiner_T 
BlockChain_T <|-down- DishonestMiner_T 

note right of Block_T : <b> operator<< </b> is a non-member function, but is a friend
note right of BlockChain_T : <b> operator<< </b> is a non-member function, but is a friend
@enduml
