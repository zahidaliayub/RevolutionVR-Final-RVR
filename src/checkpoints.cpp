// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013-2015 Voxels Developers

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
		(    0, uint256("0xbfdda5aeef5636603269447c47824950975f0d1218dac99143961b29f4c89ce4"))
		(17653, uint256("0xbaec8d4fb5329c145992caae89ff99f0953fffa3daaea1ffa23680cf628b59ca"))
		(36288, uint256("0xb995c4c571a18879ffc2e7108f0e77c0e816dd9d8ca28e6292be2ebf4005df28"))
		(201600, uint256("0x9f787e0391e53730a53f4be8984c4ee257bba405709f2ad1c63c226c1eca104e"))
		(501984, uint256("0x478bc854cf77642ee5adc437faed7a07d4f3e44de4b1f2fba76015e5d80559f5"))
		(788256, uint256("0xc248a6d91f11a670f65f8bc7d2d48f34c4609cc13cbdd74d7e34358b917af637"))
            	;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    uint256 GetLatestHardenedCheckpoint()
    {
        const MapCheckpoints& checkpoints = mapCheckpoints;
        return (checkpoints.rbegin()->second);
    }
}
