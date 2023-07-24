#ifndef __BLOCKCHAIN_H
#define __BLOCKCHAIN_H

#include "iostream"
#include "list"
#include "Eigen/Eigen"
#include "chrono"

using namespace std;
using namespace Eigen;

namespace BlockChainLibrary {

  template<typename T>
  class Block{
      template<typename U> friend class BlockChain;

      const unsigned int timestamp; // when the block is created
      const T objData; // data
      const unsigned int nonce;
      const size_t previousHash;
      const size_t hash;

    public:
      Block(const unsigned int& timestamp,
            const T& objData,
            const size_t& previousHash,
             const unsigned int nonce,
            const size_t& hash):
        timestamp(timestamp),
        objData(objData),
        nonce(nonce),
        previousHash(previousHash),
        hash(hash)
      {
      }

      template<typename C> friend ostream& operator<<(ostream& os, const Block<C>& block);

  };

  template<typename T>
  ostream& operator<<(ostream& os, const Block<T>& block)
  {
    os << "timestamp: " << block.timestamp << ";\n"
        << "nonce: " << block.nonce << ";\n"
        << "previousHash: " << block.previousHash << ";\n"
        << "hash: " << block.hash << ";\n"
        << "obj: " << block.objData;
    return os;
  }

  template<typename T>
  class BlockChain{

    private:
      list<Block<T>> blocks;

      Block<T> createGenesisBlock()
      {
        unsigned int timestamp = std::time(nullptr);

        size_t hash = hashFunction(timestamp, T(), 0, 0);

        return Block<T>(timestamp, T(), 0, 0, hash);
      }

    protected:
      const size_t& nBits;
      size_t hashFunction(const unsigned int& timestamp,
                          const unsigned int& nonce,
                          const T& objData,
                          const size_t& previousHash)
      {
        string inputHash;
        ostringstream convert(inputHash);
        convert << timestamp << objData << previousHash << nonce;
        return std::hash<string>{}(convert.str());
      }

    public:
      BlockChain(const size_t& nBits): nBits(nBits){
        Block<T> genesisBlock = createGenesisBlock();
        blocks.push_back(genesisBlock);
      }

      bool addBlock(const Block<T>& block)
      {
        if(block.hash <= nBits)
        {
          if(blocks.back().hash == block.previousHash)
          {
             blocks.push_back(block);
             return true;
          }
          else
            return false;
        }
        else
          return false;
      }

      size_t getLatestBlockHash()
      {
        return blocks.back().hash;
      }

      template<typename C> friend ostream& operator<<(ostream& os, const BlockChain<T>& blockChain);

  };

  template<typename T>
  ostream& operator<<(ostream& os, const BlockChain<T>& blockChain)
  {
    for(Block<T> block : blockChain.blocks)
    {
      os << "{timestamp: " << block.timestamp << ";\n"
          << "nonce: " << block.nonce << ";\n"
          << "previousHash: " << block.previousHash << ";\n"
          << "hash: " << block.hash << ";\n"
          << "obj: " << block.objData << "}\n";
    }
    return os;
  }
}




#endif // __BLOCKCHAIN_H
