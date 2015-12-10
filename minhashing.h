#include <set>
#include <map>
#include <string>
#include <random>
#include <vector>
#include <fstream>
#include <sstream>


typedef std::set<std::string> t_set;
typedef std::vector<t_set> t_all_set;
typedef std::map<std::string, int> t_hash_map;

typedef std::vector<std::string> t_sig_row;
typedef std::vector<t_sig_row> t_sig_matrix;


t_hash_map construce_hash(t_set);
std::string min_hash(t_set, t_hash_map);
t_sig_matrix generate_sig(t_all_set, t_set, int);

t_all_set read(std::string);