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
#include <random>

typedef std::vector<std::string> doc;
typedef std::vector<doc> all_doc;
typedef std::set<std::string> doc_set;

typedef std::vector<std::string> signature;
typedef std::vector<signature> signature_matrix;



//构造哈希函数
int hash_func(std::string, int ,int);
//计算单个最小哈希值
std::string min_hashing(std::string, int, int);

//从文件中读入数据，并根据已构造的哈希函数和指定最小哈希序列长度，转成最小哈希签名储存
signature_matrix read_into_signature(std::string, int);

//用最小哈希签名估计Jaccard相似度
float jaccard_similarity(signature_matrix);

//从文件读数据入doc_vec
all_doc read(std::string);
float jaccard_similarity(doc, doc);
#endif /* MINHASHING_H */
