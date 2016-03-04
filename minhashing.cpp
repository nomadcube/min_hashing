#include "minhashing.h"

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

int hash_func(std::string word, int random_int) {
    std::hash<std::string> str_hash;
    return (random_int * str_hash(word) + 1) % 11;
}

std::string min_hashing(doc one_doc, int random_int) {
    std::string min_hashing_result = "";
    int smallest_val = 11;
    for (auto one_word : one_doc) {
        int hash_val = hash_func(one_word, random_int);
        if (hash_val < smallest_val) {
            smallest_val = hash_val;
            min_hashing_result = one_word;
        }
    }
    return min_hashing_result;
}

all_doc get_signature(all_doc all_docs, int signature_size) {
    all_doc sig_mat;
    for (int i = 0; i < signature_size; i++) {
        doc signature_pair;
        for (auto d : all_docs)
            signature_pair.push_back(min_hashing(d, i + 1));
        sig_mat.push_back(signature_pair);
    }
    return sig_mat;
}

float jaccard_similarity(all_doc sig_mat) {
    float s = 0.0;
    for (auto sig_pair : sig_mat) {
        if (sig_pair[0] == sig_pair[1])
            s += 1.0;
    }
    return s / sig_mat.size();
}

float jaccard_similarity(doc d1, doc d2) {
    float num_inter = 0.0;
    float num_union = 0.0;
    doc_set d2_set;
    for (auto w : d2) {
        d2_set.insert(w);
        num_union += 1.0;
    }
    for (auto each_word : d1) {
        if (d2_set.count(each_word) > 0)
            num_inter += 1.0;
        else
            num_union += 1.0;
    }
    return num_inter / num_union;
}