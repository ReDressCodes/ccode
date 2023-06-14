#include <stdio.h>
#include <stdlib.h>


 /*
 * Peer manager
 *
 * The peer manager keeps track of neighbor nodes in a peer-to-peer
 * network.  This module might be used as part of a BitTorrent, BitCoin,
 * or Tor client.
 *
 * Every time there is activity from a peer, the peer manager is told about it.
 * The peer manager remembers the n most recently active unique peers.
 *
 * When we wish to communicate, the peer manager can select a random
 * peer.
 *
 * Example usage:
 *
 *   PeerManager mgr;
 *   peermgr_init(&mgr, 8);
 *
 *   peermgr_saw_peer(&mgr, 1234, time(NULL));
 *   peermgr_saw_peer(&mgr, 5432, time(NULL));
 *
 *   PeerId random_peer;
 *   if (peermgr_pick_random_peer(&mgr, &random_peer)) {
 *       printf("chosen peer = %" PRIu64 "\n", random_peer);
 *   }
 *
 *   peermgr_cleanup(&mgr);
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* TODO You may include additional C standard library headers and define
 * additional structs.  You cannot change the function prototypes, the API is
 * fixed.
 */

/** A unique identifier for a peer */
typedef uint64_t PeerId;

typedef struct Peer
{
	PeerId id;
	time_t timestamp;
}Peer;

typedef struct {

    Peer **peers;
    unsigned int totalpeers;
    unsigned int used;
} PeerManager;

/**
 * Initialize @mgr so that it can track up to @maxpeers peers.
 */
void peermgr_init(PeerManager *mgr, unsigned int maxpeers)
{
	if (!mgr)
		return;

	mgr->peers = malloc(sizeof(Peer*) * maxpeers);

	for (int i = 0; i < maxpeers; i++)
	{
		mgr->peers[i] = malloc(sizeof(Peer));
	}

	mgr->totalpeers = maxpeers;
	mgr->used = 0;
}

/**
 * Free any resources allocated by @mgr.
 */
void peermgr_cleanup(PeerManager *mgr)
{
	for (int i = 0; i < mgr->totalpeers; i++)
	{
		free(mgr->peers[i]);
	}

	free(mgr->peers);
}

/**
 * Update peer information with new activity from @peer at time @timestamp.
 * The peer manager retains a fixed number of unique peers with the most recent
 * timestamps.  The maximum number of peers to remember was set in
 * peermgr_init().
 *
 * If the maximum number of peers to remember has been reached, it may be
 * necessary to forget about the peer with the oldest timestamp so that there
 * is space for the newer peer.
 */
void peermgr_saw_peer(PeerManager *mgr, PeerId peer, time_t timestamp)
{
	if (mgr->used < mgr->totalpeers)
	{
		Peer *add_to = mgr->peers[mgr->used];

		add_to->id = peer;
		add_to->timestamp = timestamp;
		mgr->used++;
	}
}

/**
 * Select a peer at random and store its identifier in @peer.
 *
 * Returns: true on success
 */
bool peermgr_pick_random_peer(PeerManager *mgr, PeerId *peer)
{
	if (mgr->used != 0)
	{
		srand(time(NULL));
		int rand = random() % mgr->used;
		Peer *selected = mgr->peers[rand];
		*peer = selected->id;
		return true;
	} else
		return false;
}

int main(int argc, char *argv[])
{

   PeerManager mgr;
   peermgr_init(&mgr, 10);

   peermgr_saw_peer(&mgr, 1234, time(NULL));
   peermgr_saw_peer(&mgr, 5432, time(NULL));
   peermgr_saw_peer(&mgr, 11134, time(NULL));
   peermgr_saw_peer(&mgr, 542, time(NULL));
   peermgr_saw_peer(&mgr, 134, time(NULL));
   peermgr_saw_peer(&mgr, 5422, time(NULL));
   peermgr_saw_peer(&mgr, 234, time(NULL));
   peermgr_saw_peer(&mgr, 6432, time(NULL));
   peermgr_saw_peer(&mgr, 834, time(NULL));
   peermgr_saw_peer(&mgr, 1532, time(NULL));

   PeerId random_peer;
   if (peermgr_pick_random_peer(&mgr, &random_peer)) {
       printf("chosen peer = %ld \n", random_peer);
   }

   peermgr_cleanup(&mgr);

   return 0;
}
