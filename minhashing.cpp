#include "minhashing.h"


//以两个文档为例，构造哈希函数

int hash_func(std::string word, int iter_time, int signature_size) {
    std::hash<std::string> str_hash;
    return ((iter_time * str_hash(word) + 1) % 10037) % signature_size;
}

//计算单个最小哈希值

std::string min_hashing(std::string one_doc, int iter_time, int signature_size) {
    std::string min_hashing_result = "";
    int smallest_val = signature_size;

    std::istringstream in_string(one_doc);
    std::string one_word;

    while (in_string >> one_word){
        int hash_val = hash_func(one_word, iter_time, signature_size);
        if (hash_val < smallest_val) {
            smallest_val = hash_val;
            min_hashing_result = one_word;
        }
    }
    return min_hashing_result;
}

//根据已构造的哈希函数和指定最小哈希序列长度，计算文档的最小哈希签名

signature_matrix read_into_signature(std::string file_path, int signature_size) {
    signature_matrix sig_mat;

    for (int i = 0; i < signature_size; i++) {
        signature signature_pair;
        std::ifstream in_file(file_path);
        std::string one_doc;

        while (std::getline(in_file, one_doc))
            signature_pair.push_back(min_hashing(one_doc, i + 1, signature_size));
        sig_mat.push_back(signature_pair);
    }
    return sig_mat;
}

//根据最小哈希签名估计Jaccard相似度

float jaccard_similarity(signature_matrix sig_mat) {
    float s = 0.0;
    for (auto sig_pair : sig_mat) {
        if (sig_pair[0] == sig_pair[1])
            s += 1.0;
    }
    return s / sig_mat.size();
}

//从文件读数据入doc_vec

all_doc read(std::string file_path) {
    all_doc all_docs;
    std::ifstream in_file(file_path);
    std::string line;
    while (std::getline(in_file, line)) {
        doc one_doc;
        std::istringstream in_string(line);
        std::string one_word;
        while (in_string >> one_word)
            one_doc.push_back(one_word);
        all_docs.push_back(one_doc);
    }
    return all_docs;
}

//计算文档对的Jaccard相似度

float jaccard_similarity(doc d1, doc d2) {
//需要先将两个集合去重，否则会出错
    float num_inter = 0.0;
    doc_set d1_set;
    doc_set d2_set;
    for (auto w: d1){
        d1_set.insert(w);
    }
    for (auto w : d2) {
        d2_set.insert(w);
    }
    for (auto each_word : d1_set) {
        if (d2_set.count(each_word) > 0)
            num_inter += 1.0;
    }
    return num_inter / (d1_set.size() + d2_set.size() - num_inter);
}