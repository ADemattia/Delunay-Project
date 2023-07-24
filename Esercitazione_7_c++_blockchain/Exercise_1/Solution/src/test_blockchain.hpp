#ifndef __TEST_BLOCKCHAIN_H
#define __TEST_BLOCKCHAIN_H

#include <gtest/gtest.h>
#include "iostream"
#include "blockchain.hpp"

using namespace testing;
using namespace std;

template<typename T>
class HonestMiner: public BlockChainLibrary::BlockChain<T>
{
  public:
    HonestMiner(const BlockChainLibrary::BlockChain<T>& blockChain): BlockChainLibrary::BlockChain<T>(blockChain) {
    }

    BlockChainLibrary::Block<T> mining(const T& objData)
    {
      const size_t previousHash = BlockChainLibrary::BlockChain<T>::getLatestBlockHash();
      unsigned int timestamp = std::time(nullptr);
      unsigned int nonce = 0;
      size_t hash = BlockChainLibrary::BlockChain<T>::nBits + 1;
      do
      {
        hash = BlockChainLibrary::BlockChain<T>::hashFunction(timestamp, objData, previousHash, nonce);
        nonce++;
      }
      while(hash > BlockChainLibrary::BlockChain<T>::nBits);

      BlockChainLibrary::Block<T> block = BlockChainLibrary::Block<T>(timestamp, objData, previousHash, nonce, hash);
      return block;
    }
};


template<typename T>
class DishonestMiner: public BlockChainLibrary::BlockChain<T>
{
  public:
    DishonestMiner(const BlockChainLibrary::BlockChain<T>& blockChain): BlockChainLibrary::BlockChain<T>(blockChain) {
    }

    BlockChainLibrary::Block<T> mining(const T& objData, const size_t& previousHash)
    {
      unsigned int timestamp = std::time(nullptr);
      unsigned int nonce = 0;
      size_t hash = BlockChainLibrary::BlockChain<T>::nBits + 1;
      do
      {
        hash = BlockChainLibrary::BlockChain<T>::hashFunction(timestamp, objData, previousHash, nonce);
        nonce++;
      }
      while(hash > BlockChainLibrary::BlockChain<T>::nBits);

      BlockChainLibrary::Block<T> block
          = BlockChainLibrary::Block<T>(timestamp, objData, previousHash, nonce, hash);
      return block;
    }
};


TEST(TestBlockChain, TestBlock)
{
  BlockChainLibrary::BlockChain<int> blockchain(pow(2,50));

  HonestMiner<int> honestMiner(blockchain);
  size_t previousHash = blockchain.getLatestBlockHash();
  BlockChainLibrary::Block<int> honestBlock = honestMiner.mining(1);
  bool honestAdd =blockchain.addBlock(honestBlock);

  EXPECT_TRUE(honestAdd);

  DishonestMiner<int> dishonestMiner(blockchain);
  BlockChainLibrary::Block<int> dishonestBlock = dishonestMiner.mining(2, previousHash);
  bool dishonestAdd = blockchain.addBlock(dishonestBlock);

  EXPECT_FALSE(dishonestAdd);
}

TEST(TestBlockChain, TestDiffuculty)
{

  auto start_50 = std::chrono::steady_clock::now();
  BlockChainLibrary::BlockChain<int> blockchain50(pow(2,50));

  HonestMiner<int> honestMiner50(blockchain50);
  honestMiner50.mining(1);

  auto end_50 = std::chrono::steady_clock::now();
  double elapsedTime_50 = std::chrono::duration_cast<std::chrono::microseconds>(end_50 - start_50).count();


  auto start_40 = std::chrono::steady_clock::now();
  BlockChainLibrary::BlockChain<int> blockchain40(pow(2,40));

  HonestMiner<int> honestMiner40(blockchain40);
  honestMiner40.mining(1);

  auto end_40 = std::chrono::steady_clock::now();
  double elapsedTime_40 = std::chrono::duration_cast<std::chrono::microseconds>(end_40 - start_40).count();

  EXPECT_LE(elapsedTime_50, elapsedTime_40);
  cout << elapsedTime_50 * 1.0e-6 << " s versus " << elapsedTime_40 * 1.0e-6 <<" s " << endl;

}





#endif // __TEST_BLOCKCHAIN_H
