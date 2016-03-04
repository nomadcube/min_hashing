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
   %template(doc) vector<string>;
   %template(all_doc) vector<vector<string> >;
   %template(doc_set) set<string>;
}

// Include the header file with above prototypes
%include "minhashing.h"
