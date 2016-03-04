#ifndef MINHASHING_H
#define MINHASHING_H

#include <map>
#include <string>
#include <vector>
#include <set>

#include <algorithm>

#include <functional>
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

typedef std::vector<std::string> doc;
typedef std::vector<std::vector<std::string> > all_doc;
typedef std::set<std::string> doc_set;


all_doc read(std::string);

int hash_func(std::string, int);

std::string min_hashing(doc, int);
all_doc get_signature(all_doc, int);

float jaccard_similarity(all_doc);
float jaccard_similarity(doc, doc);
#endif /* MINHASHING_H */
