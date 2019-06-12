//
//  BRCoinParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRCoinParams_h
#define BRCoinParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Biblepay 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define BBP_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRCoinDNSSeeds[] = {
    "dns1.biblepay.org", "dns2.biblepay.org","dnsseed.biblepay.org", NULL
};

static const char *BRCoinTestNetDNSSeeds[] = {
    "testnet-seed.biblepaydot.io", "test.dnsseed.masternode.io", NULL
};

static const BRCheckPoint BRCoinTestNetCheckpoints[] = {
    {       1, uint256("18b37b60b422ea27d57ceea9dd794b5f74c561565ecc03e85a22ecdf74cbb33a"), 1511964848, 0x1d00ffff }       // timestamp and target bits probably not ok... just taking info directly from BBP chainparams.cpp
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRCoinCheckpoints[] = {
    {      7, uint256("00022b1be28b1deb9a51d4d69f3fa393f4ea36621039b6313a6c0796546621de"), 1500845066, 0x1f0575c5 },
    {    120, uint256("00002fc6c9e4889a8d1a9bd5919a6bd4a4b09091e55049480509da14571e5653"), 1500909333, 0x1f00cb06 },
    {   6999, uint256("000000dfbcdec4e6b0ab899f04d7ce8e4d8bc8a725a47169b626acd207ccea8d"), 1505075365, 0x1e01a097 },
    {  18900, uint256("94a1ff5e84a31219d5472536215f5a77b00cfd61f3fb99d0e9d3ab392f2ed2a6"), 1511954034, 0x1b0a6ecf },
    {  20900, uint256("23d0b5887ca89fc2dddb2f34810675cb1826371172a91b1211be4677fd260490"), 1513114026, 0x1b0306ed },
    {  21650, uint256("756e18f6a20d02d7af0a32c5705960d58adc4daba24c6a7dd9a8b80776bcca73"), 1513595068, 0x1c028131 },
    {  21960, uint256("dd7e0acd7b9569b6fbf84a8262bb5fe3ea28af259f12d060acbcd62d4241fb51"), 1513776131, 0x1c00f22d },
    {  32500, uint256("acb4534f70da9624fee2b9032d2fe47fe6d7d3e8cffdbfbca4d0a3a63394045a"), 1519902767, 0x1b1af846 },
    {  33460, uint256("e64ff92ae97c2978c14d97ae45c618c1f2140339ce9ccb770945d3efb7d5e0f5"), 1520469785, 0x1c4c0e1b }
};

static int BRCoinVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    // +++ BBP difficulty verification

    return 1;
}

static int BRCoinTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRCoinParams = {
    BRCoinDNSSeeds,
    40000,                // standardPort
    0xbd6b0cbf,          // magicNumber
    0, // services
    BRCoinVerifyDifficulty,
    BRCoinCheckpoints,
    sizeof(BRCoinCheckpoints)/sizeof(*BRCoinCheckpoints),
};

static const BRChainParams BRCoinTestNetParams = {
    BRCoinTestNetDNSSeeds,
    40001,               // standardPort
    0xffcae2ce,          // magicNumber
    0, // services
    BRCoinTestNetVerifyDifficulty,
    BRCoinTestNetCheckpoints,
    sizeof(BRCoinTestNetCheckpoints)/sizeof(*BRCoinTestNetCheckpoints)
};

#endif // BRChainParams_h
