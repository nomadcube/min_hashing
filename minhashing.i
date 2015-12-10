%module minhashing
%{
#include "minhashing.h"
%}

%include "std_vector.i"
%include "std_map.i"
%include "std_set.i"
%include "std_string.i"
// Instantiate templates used by example
namespace std {
   %template(t_set) set<string>;
   %template(t_all_set) vector<set<string> >;
   %template(t_hash_map) map<string, int>;
   %template(t_sig_row) vector<string>;
   %template(t_sig_matrix) vector<vector<string> >;
}

// Include the header file with above prototypes
%include "minhashing.h"
