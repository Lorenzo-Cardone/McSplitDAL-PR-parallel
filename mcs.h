#ifndef MCSPLIT_MCS_H
#define MCSPLIT_MCS_H

#include <vector>
#include "graph.h"
#include "args.h"
#include "stats.h"
#include <unordered_set>
#include <set>
#include <memory>
#include <list>
#include <condition_variable>
#include <atomic>


using namespace std;
using gtype = double;

struct VtxPair {
    int v;
    int w;

    VtxPair(int v, int w) : v(v), w(w) {}
};

struct Bidomain {
    vector<int> left;
    vector<int> right;
    bool is_adjacent;

    // Bidomain(list<int> left, list<int> right, bool is_adjacent) : left(left), right(right), is_adjacent(is_adjacent) {};
    Bidomain(const vector<int>& left, const vector<int>& right, bool is_adjacent): left(left), right(right), is_adjacent(is_adjacent) {}

    int get_max_len() const { return max(left.size(), right.size()); }
};

struct NewBidomainResult {
    vector<Bidomain> *new_domains;
    int reward;

    NewBidomainResult(vector<Bidomain> *new_domains, int reward): new_domains(new_domains), reward(reward) {}

};

struct Step {
    vector<Bidomain> *domains;
    unordered_set<int> wselected;
    int w_iter;
    Bidomain *bd;
    int bd_idx;
    int v;
    vector<VtxPair> *current;
    int bound;
    int tot_bds_explorable_size;
    int cur_bds_explored_size;
    
    int compute_explorable_size (const vector<Bidomain> &domains) {
        int size = 0;
        for (const Bidomain &bd: domains) {
            size += bd.left.size() * bd.right.size();
        }
        return size;
    }

    Step(vector<Bidomain> *domains, int w_iter, int v, vector<VtxPair> *current) {
        this->wselected = unordered_set<int>();
        this->domains = domains;
        this->w_iter = w_iter;
        this->v = v;
        this->current = current;
        this->bd = nullptr;
        this->bd_idx = -1;
        this->tot_bds_explorable_size = compute_explorable_size(*domains);
        this->cur_bds_explored_size = 0;
    };

    ~Step() {
        delete this->domains;
        delete this->current;
    }
};

vector<VtxPair> mcs(const Graph &g0, const Graph &g1, void *rewards_p, Stats *stats);

#endif