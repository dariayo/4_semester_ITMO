#include <iostream>
#include <map>
#include <vector>

std::multimap<int, int> block_of_size;
std::map<int, int> block_of_index;

void delete_elements(const std::map<int, int>::iterator &it) {
    auto size_block_pair = block_of_size.equal_range(it->second);
    for (auto x = size_block_pair.first; x != size_block_pair.second; ++x) {
        if (x->second == it->first) {
            block_of_size.erase(x);
            break;
        }
    }
    block_of_index.erase(it);
}

void add(const std::pair<int, int> &pair) {
    block_of_index.insert(pair);
    block_of_size.insert({pair.second, pair.first});
}

void erase(int s, int index) {
    block_of_size.erase(block_of_size.lower_bound(s));
    block_of_index.erase(index);
}

void print_result(const std::vector<int> &result) {
    for (int i: result) {
        std::cout << i << std::endl;
    }
}

int allocate(int s, int index) {
    index = -1;
    if (block_of_size.lower_bound(s) != block_of_size.end()) {
        int size = block_of_size.lower_bound(s)->first - s;
        index = block_of_size.lower_bound(s)->second;
        erase(s, index);
        if (size > 0) {
            block_of_index.insert({index + s, size});
            block_of_size.insert({size, index + s});
        }
    }
    return index;
}

void merge_blocks(bool merge_left, bool merge_right, int index_of_free, int size_of_free,
                  const std::map<int, int>::iterator left, const std::map<int, int>::iterator right) {
    if (!merge_right && !merge_left) {
        add({index_of_free, size_of_free});
    }
    if (merge_right && !merge_left) {
        delete_elements(right);
        add({index_of_free, right->second + size_of_free});
    }
    if (merge_right && merge_left) {
        delete_elements(left);
        delete_elements(right);
        add({left->first, left->second + right->second + size_of_free});
    }
    if (!merge_right && merge_left) {
        delete_elements(left);
        add({left->first, left->second + size_of_free});
    }
}

int main() {
    int n, m, s;
    int index;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> numbers(m + 1);
    add({1, n});
    std::vector<int> result;
    for (int i = 0; i < m; numbers[i + 1] = {s, index}, i++) {
        index = 0;
        std::cin >> s;
        if (s > 0) {
            index = allocate(s, index);
            result.push_back(index);
        } else {
            int index_of_free = numbers.at(-s).second;
            int size_of_free = numbers.at(-s).first;
            if (index_of_free != -1) {
                auto right = block_of_index.lower_bound(index_of_free);
                auto left = (right != block_of_index.begin()) ? std::prev(right) : block_of_index.end();
                bool merge_left = (left != block_of_index.end() && left->first + left->second == index_of_free);
                bool merge_right = (right != block_of_index.end() && right->first == index_of_free + size_of_free);
                merge_blocks(merge_left, merge_right, index_of_free, size_of_free, left, right);
            }
        }
    }
    print_result(result);
    return 0;
}
