# McSplit-DAL + heuristics
McSplit-DAL is an enhanced version of the McSplit algorithm for maximum common subgraph problems, integrating the Domain Action Learning (DAL) optimization. The DAL technique is inspired by the research article "Hybrid Learning with New Value Function for the Maximum CommonSubgraph Problem" ([arxiv:2208.08620](https://arxiv.org/abs/2208.08620)), which introduced the concept but did not provide source code. This implementation is a recreation based on the paper's ideas.

For reference, the previous version called McSplit+LL from the DAL authors is available at [https://github.com/JHL-HUST/McSplit-LL](https://github.com/JHL-HUST/McSplit-LL). Although heavily modified, portions of the source code might have some overlapping.

> **Update:** The parallel option (`--threads` or `-p`) should currently be functional. More testing is needed to ensure the MCS is always reported correctly.

## Usage
Usage: mcs_dal_circuit [OPTION...] HEURISTIC FILENAME1 FILENAME2

Find a maximum clique in a graph in DIMACS format

| Short option | Long option                 | Description                                                                              |
|----|---------------------------------------|-----------------------------------------------------------------------------------------|
| -a | --labelled                            | Use edge and vertex labels                                                              |
| -A | --ascii                               | Read ASCII format                                                                       |
| -b | --big-first                           | First try to find an induced subgraph isomorphism then decrement the target size        |
| -B | --max_thread_blocks=blocks            | Specify the number of steps a thread can work on locally                                |
| -c | --connected                           | Solve max common CONNECTED subgraph problem                                             |
| -d | --dimacs                              | Read DIMACS format                                                                      |
| -D | --dal_reward_policy=dal_reward_policy | Specify the dal reward policy (num max avg)                                             |
| -i | --directed                            | Use directed graphs                                                                     |
| -I | --iterations=iterations               | Specify a maximum number of iterations                                                  |
| -l | --lad                                 | Read LAD format                                                                         |
| -p | --threads=threads                     | Specify the number of threads                                                           |
| -P | --pruning                             | Specify if the first thread goes on until pruning or not before pushing to global queue |
| -q | --quiet                               | Quiet output                                                                            |
| -r | --random_start                        | Set random start to 1                                                                   |
| -s | --sort_heuristic=sort_heuristic       | Specify the sort heuristic (degree pagerank betweenness closeness clustering katz)      |
| -t | --timeout=timeout                     | Specify a timeout (seconds)                                                             |
| -v | --verbose                             | Verbose output                                                                          |
| -x | --vertex-labelled-only                | Use vertex labels but not edge labels                                                   |
| -? | --help                                | Give this help list                                                                     |
|    | --usage                               | Give a short usage message                                                              |

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

HEURISTIC can be min_max or min_product or rewards_based or heuristic_based
