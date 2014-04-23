//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef BINDINGCACHE_H_
#define BINDINGCACHE_H_

#include <string>
#include "stdint.h"

/*
 * Each binding update list entry conceptually contains the following
 * fields
 * */

class BindingCache {
    // Unique identifier for binding cache used for search
    int id;

    // The IP address of the node to which a Bindind Update was sent (correspondent node)
    std::string ip_cn;
    // The home address for which that Binding Update was sent
    std::string ip_homeaddress;
    // The care of address sent in that Binding Update
    std::string ip_coa;
    // The initial value of the Lifetime field
    int init_lifetime;
    // The remaining lifetime of that binding
    int lifetime;
    // The macimum value of the sequence number field sent in previous binding
    // updates to this destination. compare MUST be done in modulo 2^16
    int16_t sequence;
    // The time at which a Binding Update was last sent to this destination
    int timestamp;
    // The state of any retransmissions needed for this Binding Update
    // This state includes the time remaining until the next
    // retransmission attempt for the Ninding Update and the current
    // state of the exponential back-off mechanism for retransmission
    int retransmission_time;
    int retransmission_state;
    // A flag specifying whether or not future Binding Update should be sent
    // to this destination
    bool accepting;

    /* The Binding Update List also conceptually contains the following data
     * related to running the return routability procedure. This data is
     * relevant only for Binding Update sent to correspondent node
     * */
    // The time at which a Home Test Init or Care-of Test Init message
    // was last sent to this destination
    int test_timestamp;
    // The state of any retransmissions needed for this return routability procedure
    int routability_time;
    int routability_state;
    // Cookie values used in the Home Test Init and Care-of Test Init messages
    int test_cookie;
    // Home and care-of keygen tokens recieved from CN
    int keygen_tokens;
    // Home and care-of nonce indices recieved from CN
    int nonce;
    // The time at which each of the tokens and nonces were received from CN
    int keygen_timestamp;
    int nonce_timestamp;
public:
    BindingCache();
    virtual ~BindingCache();

    bool isAccepting() const {
        return accepting;
    }

    void setAccepting(bool accepting) {
        this->accepting = accepting;
    }

    int getInitLifetime() const {
        return init_lifetime;
    }

    void setInitLifetime(int initLifetime) {
        init_lifetime = initLifetime;
    }

    std::string getIpCn() const {
        return ip_cn;
    }

    void setIpCn(std::string ipCn) {
        ip_cn = ipCn;
    }

    std::string getIpCoa() const {
        return ip_coa;
    }

    void setIpCoa(std::string ipCoa) {
        ip_coa = ipCoa;
    }

    std::string getIpHomeaddress() const {
        return ip_homeaddress;
    }

    void setIpHomeaddress(std::string ipHomeaddress) {
        ip_homeaddress = ipHomeaddress;
    }

    int getKeygenTimestamp() const {
        return keygen_timestamp;
    }

    void setKeygenTimestamp(int keygenTimestamp) {
        keygen_timestamp = keygenTimestamp;
    }

    int getKeygenTokens() const {
        return keygen_tokens;
    }

    void setKeygenTokens(int keygenTokens) {
        keygen_tokens = keygenTokens;
    }

    int getLifetime() const {
        return lifetime;
    }

    void setLifetime(int lifetime) {
        this->lifetime = lifetime;
    }

    int getNonce() const {
        return nonce;
    }

    void setNonce(int nonce) {
        this->nonce = nonce;
    }

    int getNonceTimestamp() const {
        return nonce_timestamp;
    }

    void setNonceTimestamp(int nonceTimestamp) {
        nonce_timestamp = nonceTimestamp;
    }

    int getRetransmissionState() const {
        return retransmission_state;
    }

    void setRetransmissionState(int retransmissionState) {
        retransmission_state = retransmissionState;
    }

    int getRetransmissionTime() const {
        return retransmission_time;
    }

    void setRetransmissionTime(int retransmissionTime) {
        retransmission_time = retransmissionTime;
    }

    int getRoutabilityState() const {
        return routability_state;
    }

    void setRoutabilityState(int routabilityState) {
        routability_state = routabilityState;
    }

    int getRoutabilityTime() const {
        return routability_time;
    }

    void setRoutabilityTime(int routabilityTime) {
        routability_time = routabilityTime;
    }

    int16_t getSequence() const {
        return sequence;
    }

    void setSequence(int16_t sequence) {
        this->sequence = sequence;
    }

    int getTestCookie() const {
        return test_cookie;
    }

    void setTestCookie(int testCookie) {
        test_cookie = testCookie;
    }

    int getTestTimestamp() const {
        return test_timestamp;
    }

    void setTestTimestamp(int testTimestamp) {
        test_timestamp = testTimestamp;
    }

    int getTimestamp() const {
        return timestamp;
    }

    void setTimestamp(int timestamp) {
        this->timestamp = timestamp;
    }

    int getId() const {
        return id;
    }
};

#endif /* BINDINGCACHE_H_ */
