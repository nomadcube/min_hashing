/*
 * File:   MinHashing.h
 * Author: wumengling
 *
 * Created on 2015年11月26日, 下午6:58
 */

#ifndef MINHASHING_H
#define MINHASHING_H

#include <map>
#include <string>
#include <array>
#include <random>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <iostream>

typedef std::vector<std::string> doc;
typedef std::vector<doc> all_doc;
typedef std::set<std::string> doc_set;

typedef std::vector<std::string> signature;
typedef std::vector<signature> signature_matrix;



int hash_func(std::string, int);
std::string min_hashing(std::string, int);

signature_matrix read_into_signature(std::string, int);

float jaccard_similarity(signature_matrix);

all_doc read(std::string);
float jaccard_similarity(doc, doc);
#endif /* MINHASHING_H */
