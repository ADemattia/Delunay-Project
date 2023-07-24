# BlockChain

## Description

A blockchain can be thought as lists of records (blocks) that are securely linked together via cryptographic hashes. 

Each block contains a cryptographic hash of the previous block, the ``Unix'' timestamp and the transaction data. 

The timestamp proves that the transaction data existed when the block was created. 

The transaction data cannot be modified.

The miners build the blocks and send it to the blockchain. If the block is valid, then the blockChain adds the new block.

A block is not valid if it does not refer to the previous block.

Only the blockchain can access to the property of each stored block, but the block list must be printable in order to be available to everyone.

Each miner must do the so-called proof-of-work while creating a block which depends on the difficulty parameter of the blockchain.


## Requirements

Write a software which implements and test a blockchain which can store generic data and which follows the the specifications mentioned above.
