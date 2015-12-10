#include "minhashing.h"
#include <iostream>

t_hash_map construce_hash(t_set whole_set) {
    int total_element_num = whole_set.size();
    t_hash_map res;
    for (std::string element : whole_set) {
        int val = std::rand() % total_element_num;
        res.insert(std::pair<std::string, int> (element, val));
    }
    return res;
}

std::string min_hash(t_set s, t_hash_map hm) {
    std::string res;
    int res_val = hm.size() + 1;
    for (std::string e : s) {
        if (hm[e] < res_val) {
            res_val = hm[e];
            res = e;
        }
    }
    return res;
}

t_sig_matrix generate_sig(t_all_set original_all_set, t_set whole_set, int sigature_length) {
    t_sig_matrix res;
    int n_signature = original_all_set.size();
    for (int i = 0; i < sigature_length; i++) {
        t_sig_row tmp_res;
        t_hash_map hm = construce_hash(whole_set);
        for (int j = 0; j < n_signature; j++) {
            std::string sig_element = min_hash(original_all_set[j], hm);
            tmp_res.push_back(sig_element);
        }
        res.push_back(tmp_res);
    }
    return res;
}

t_all_set read(std::string fp){
    t_all_set res;
    std::ifstream data(fp);
    std::string str;
    while(std::getline(data, str)){
        t_set tmp_res;
        std::istringstream str_stream(str);
        std::string e;
        while(str_stream >> e)
            tmp_res.insert(e);
        res.push_back(tmp_res);
    }
    return res;
}