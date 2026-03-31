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

struct alignas(64) ThreadStats {
    long long work_time_us = 0;
    unsigned int best_sol_found = 0;
    unsigned long long steps_explored = 0;
};

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
    std::unique_ptr<vector<Bidomain>> new_domains;
    int reward;

    NewBidomainResult(std::unique_ptr<vector<Bidomain>> new_domains, int reward)
        : new_domains(std::move(new_domains)), reward(reward) {}
};

struct Step {
    std::unique_ptr<vector<Bidomain>> domains;
    unordered_set<int> wselected;
    int w_iter;
    int bd_idx;
    int v;
    std::unique_ptr<vector<VtxPair>> current;

    Step(std::unique_ptr<vector<Bidomain>> domains, int w_iter, int v, std::unique_ptr<vector<VtxPair>> current)
        : domains(std::move(domains)),
          wselected(),
          w_iter(w_iter),
          bd_idx(-1),
          v(v),
          current(std::move(current)) {}
};

vector<VtxPair> mcs(const Graph &g0, const Graph &g1, void *rewards_p, Stats *stats);

#endif